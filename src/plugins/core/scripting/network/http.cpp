#include "../../scripting.h"
#include "../../../../player/playermanager/PlayerManager.h"
#include "../../../../network/http/HTTPManager.h"
#include "../../../../network/http/HTTPServerManager.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <steam/steam_gameserver.h>

#include <deque>

extern ISteamHTTP* g_http;

static const std::map<std::string, EHTTPMethod> methodMap = {
    { "GET", EHTTPMethod::k_EHTTPMethodGET },
    { "POST", EHTTPMethod::k_EHTTPMethodPOST },
    { "HEAD", EHTTPMethod::k_EHTTPMethodHEAD },
    { "PUT", EHTTPMethod::k_EHTTPMethodPUT },
    { "DELETE", EHTTPMethod::k_EHTTPMethodDELETE },
    { "OPTIONS", EHTTPMethod::k_EHTTPMethodOPTIONS },
    { "PATCH", EHTTPMethod::k_EHTTPMethodPATCH },
};

void HTTPCallback(std::vector<std::any> values)
{
    int status = std::any_cast<int>(values[0]);
    std::string body = std::any_cast<std::string>(values[1]);
    std::string headers = std::any_cast<std::string>(values[2]);
    std::string err = std::any_cast<std::string>(values[3]);
    std::string reqID = std::any_cast<std::string>(values[4]);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHTTPActionPerformed", encoders::msgpack::SerializeToString({ status, body, headers, err, reqID }), event);
    delete event;
}

std::string CreateMultipartFormData(const std::map<std::string, std::string>& files, const std::string& boundary) {
    std::string formData;

    for (const auto& file : files) {
        std::vector<uint8> fileData;
        if (!Files::ExistsPath(file.second)) continue;
        auto content = explode(Files::Read(file.second), "");
        for (size_t i = 0; i < content.size(); i++) fileData.push_back((uint8)(content[i].at(0)));

        std::string filename = file.second.substr(file.second.find_last_of("/\\") + 1);

        formData += "--" + boundary + "\r\n";
        formData += "Content-Disposition: form-data; name=\"" + file.first + "\"; filename=\"" + filename + "\"\r\n";
        formData += "Content-Type: application/octet-stream\r\n\r\n";
        formData.append(fileData.begin(), fileData.end());
        formData += "\r\n";
    }

    formData += "--" + boundary + "--\r\n";

    return formData;
}

PluginHTTP::PluginHTTP(std::string m_plugin_name)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginHTTP::PluginHTTP(m_plugin_name=\"%s\")", m_plugin_name.c_str()));

    this->plugin_name = m_plugin_name;
}

PluginHTTP::~PluginHTTP()
{
    for(auto val : toDelete) {
        std::string ip_addr = std::any_cast<std::string>(val[0]);
        uint16_t port = std::any_cast<uint16_t>(val[1]);
        if(val[2].type() == typeid(void*)) {
            g_httpServerManager->UnregisterHTTPServerListener(ip_addr, port, std::any_cast<void*>(val[2]));
            delete (luabridge::LuaRef*)std::any_cast<void*>(val[2]);
        }
    }
}

void HTTPNextFrame(std::vector<std::any> args)
{
    PluginHTTPRequest* req = std::any_cast<PluginHTTPRequest*>(args[0]);
    PluginHTTPResponse* res = std::any_cast<PluginHTTPResponse*>(args[1]);
    void* cb = std::any_cast<void*>(args[2]);
    PluginKind_t kind = std::any_cast<PluginKind_t>(args[3]);

    if(kind == PluginKind_t::Lua)
        ((luabridge::LuaRef*)cb)->operator()(req, res);
}

void HTTPCB(const httplib::Request& req, httplib::Response& res, std::vector<std::any> additional)
{
    std::map<std::string, std::map<std::string, std::string>> files;
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> params;

    for(auto it = req.params.begin(); it != req.params.end(); ++it)
        params.insert({it->first, it->second});

    for(auto it = req.headers.begin(); it != req.headers.end(); ++it)
        headers.insert({it->first, it->second});

    for(auto it = req.files.begin(); it != req.files.end(); ++it)
        files.insert({ 
            it->first, 
            { 
                { "content", it->second.content }, 
                { "content_type", it->second.content_type }, 
                { "filename", it->second.filename }, 
                { "name", it->second.name }, 
            } 
        });

    PluginHTTPRequest* pReq = new PluginHTTPRequest(req.path, req.method, req.body, files, headers, params);
    PluginHTTPResponse* pRes = new PluginHTTPResponse(&res);

    g_Plugin.NextFrame(HTTPNextFrame, { pReq, pRes, additional[0], additional[1] });
    while(!pRes->IsCompleted()) std::this_thread::sleep_for(std::chrono::milliseconds(10));

    delete pReq;
    delete pRes;
}

void PluginHTTP::ListenLua(std::string ip_addr, uint16_t port, luabridge::LuaRef cb)
{
    auto revcb = new luabridge::LuaRef(cb);

    g_httpServerManager->RegisterHTTPServerListener(ip_addr, port, (void*)&HTTPCB, { (void*)revcb, PluginKind_t::Lua });

    toDelete.push_back({ ip_addr, port, (void*)revcb });
}

std::string PluginHTTP::PerformHTTP(std::string receivedData)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginHTTP::PerformHTTP(receivedData=\"%s\")", receivedData.c_str()));

    std::string requestUUID = get_uuid();
    if (!g_http) {
        if (g_httpManager->m_PendingHTTPRequests.find(this->plugin_name) == g_httpManager->m_PendingHTTPRequests.end())
            g_httpManager->m_PendingHTTPRequests.insert({ this->plugin_name, {} });

        g_httpManager->m_PendingHTTPRequests[this->plugin_name].insert_or_assign(requestUUID, receivedData);
        return requestUUID;
    }

    return PerformHTTPWithRequestID(receivedData, requestUUID);
}

std::string PluginHTTP::PerformHTTPWithRequestID(std::string receivedData, std::string requestID)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginHTTP::PerformHTTPWithRequestID(receivedData=\"%s\",requestID=\"%s\")", receivedData.c_str(), requestID.c_str()));

    rapidjson::Document request;
    request.Parse(receivedData.c_str());
    if (request.HasParseError())
    {
        PLUGIN_PRINTF("PerformHTTP", "An error has occured while trying to create the HTTP Request: %s\n", GetParseError_En(request.GetParseError()));
        return "00000000-0000-0000-0000-000000000000";
    }

    std::string url = request.HasMember("url") ? (request["url"].IsString() ? request["url"].GetString() : "") : "";
    std::string data = request.HasMember("data") ? (request["data"].IsString() ? request["data"].GetString() : "") : "";
    std::string method = request.HasMember("method") ? (request["method"].IsString() ? request["method"].GetString() : "") : "";
    if (methodMap.find(method) == methodMap.end()) {
        PLUGIN_PRINTF("PerformHTTP", "An error has occured while trying to create the HTTP Request: Invalid method \"%s\"\n", method.c_str());
        return "00000000-0000-0000-0000-000000000000";
    }

    std::vector<HTTPHeader> headers;
    std::map<std::string, std::string> files;
    std::string contentType = "text/plain";

    if (request.HasMember("headers"))
    {
        if (request["headers"].IsObject() && !request["headers"].IsArray())
        {
            for (auto headerIt = request["headers"].MemberBegin(); headerIt != request["headers"].MemberEnd(); ++headerIt)
            {
                std::string headerName = headerIt->name.GetString();
                if (!headerIt->value.IsString())
                    continue;

                std::string headerValue = headerIt->value.GetString();
                if (headerName == "Content-Type") contentType = headerValue;

                headers.push_back(HTTPHeader(headerName, headerValue));
            }
        }
    }

    if (request.HasMember("files"))
    {
        if (request["files"].IsObject() && !request["files"].IsArray())
        {
            for (auto filesIt = request["files"].MemberBegin(); filesIt != request["files"].MemberEnd(); ++filesIt)
            {
                std::string fileName = filesIt->name.GetString();
                if (!filesIt->value.IsString())
                    continue;

                std::string fileValue = filesIt->value.GetString();
                if (!Files::ExistsPath(fileValue))
                    continue;

                files.insert({ fileName, fileValue });
            }
        }
    }

    auto req = g_http->CreateHTTPRequest(methodMap.at(method), url.c_str());
    if (methodMap.at(method) != k_EHTTPMethodGET && methodMap.at(method) != k_EHTTPMethodDELETE) {
        if (!g_http->SetHTTPRequestRawPostBody(req, contentType.c_str(), (uint8*)(data.c_str()), data.size())) {
            PLUGIN_PRINT("PerformHTTP", "An error has occured while trying to create the HTTP Request: Couldn't copy the body data. Possibly invalid content type.\n");
            return "00000000-0000-0000-0000-000000000000";
        }
    }

    if (headers.size() > 0)
        for (auto header : headers)
            g_http->SetHTTPRequestHeaderValue(req, header.GetName(), header.GetValue());

    if (files.size() > 0) {
        std::string boundary = "------------------------boundaryString1234567890";
        std::string formData = CreateMultipartFormData(files, boundary);

        g_http->SetHTTPRequestHeaderValue(req, "Content-Type", ("multipart/form-data; boundary=" + boundary).c_str());

        g_http->SetHTTPRequestRawPostBody(req, "multipart/form-data", (uint8*)formData.data(), formData.size());
    }

    SteamAPICall_t call;
    g_http->SendHTTPRequest(req, &call);

    new TrackedRequest(
        req, call, requestID, 
        [](HTTPRequestHandle hndl, int status, std::string body, std::string headers, std::string err, std::string reqID) -> void {
            g_Plugin.NextFrame(HTTPCallback, { status, body, headers, err, reqID });
        }
    );

    return requestID;
}

PluginHTTPRequest::PluginHTTPRequest(std::string path, std::string method, std::string body, std::map<std::string, std::map<std::string, std::string>> files, std::map<std::string, std::string> headers, std::map<std::string, std::string> params)
{
    m_path = path;
    m_method = method;
    m_body = body;
    m_files = files;
    m_headers = headers;
    m_params = params;
}

PluginHTTPResponse::PluginHTTPResponse(httplib::Response* res)
{
    this->m_res = res;
    started = GetTime();
}

void PluginHTTPResponse::WriteBody(std::string content)
{
    this->m_res->set_content(content, "text/plain");
}

std::map<std::string, std::string> PluginHTTPResponse::GetHeaders()
{
    std::map<std::string, std::string> headers;
    for(auto it = m_res->headers.begin(); it != m_res->headers.end(); ++it)
        headers.insert({it->first, it->second});

    return headers;
}

std::string PluginHTTPResponse::GetHeader(std::string key)
{
    return m_res->get_header_value(key);
}

void PluginHTTPResponse::SetHeader(std::string key, std::string val)
{
    auto rng = m_res->headers.equal_range(key);
    m_res->headers.erase(rng.first, rng.second);
    m_res->set_header(key, val);
}

void PluginHTTPResponse::Send(uint16_t responseCode)
{
    m_res->status = responseCode;
    this->completed = true;
}

bool PluginHTTPResponse::IsCompleted()
{
    return (this->completed == true || this->started + 30000 <= GetTime());
}