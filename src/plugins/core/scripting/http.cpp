#include "../scripting.h"

#include <msgpack.hpp>

#include <thread>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

extern "C"
{
#include <curl/curl.h>
};

#include <deque>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::vector<std::string> *userp)
{
    size_t totalSize = size * nmemb;
    userp->emplace_back((char *)contents, totalSize);
    return totalSize;
}

static size_t HeaderCallback(char *buffer, size_t size, size_t nitems, std::vector<std::string> *headers)
{
    size_t totalSize = size * nitems;
    headers->emplace_back(buffer, totalSize);
    return totalSize;
}

struct Request
{
    std::string url;
    std::string data;
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> files;
    std::string method;
    std::string requestUUID;
};

std::deque<Request> requestsQueue;

void RunCurlRequest(std::string url, std::string data, std::map<std::string, std::string> headers, std::map<std::string, std::string> files, std::string method, std::string requestUUID)
{
    std::vector<std::string> responseBody;
    std::vector<std::string> responseHeaders;
    curl_mime *mime = nullptr;
    CURL *curlRequest = curl_easy_init();
    if (!curlRequest)
        return;

    if (Files::ExistsPath("/etc/pki/tls/certs/ca-bundle.crt"))
        curl_easy_setopt(curlRequest, CURLOPT_CAINFO, "/etc/pki/tls/certs/ca-bundle.crt");

    curl_easy_setopt(curlRequest, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlRequest, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curlRequest, CURLOPT_TIMEOUT, 5000);
    if (headers.find("User-Agent") != headers.end())
        curl_easy_setopt(curlRequest, CURLOPT_USERAGENT, headers.at("User-Agent").c_str());

    struct curl_slist *headersList = nullptr;
    for (auto it = headers.begin(); it != headers.end(); ++it)
        headersList = curl_slist_append(headersList, (string_format("%s: %s", it->first.c_str(), it->second.c_str()) + "\0").c_str());

    if (files.size() > 0)
    {
        mime = curl_mime_init(curlRequest);

        for (auto &file : files)
        {
            curl_mimepart *part = curl_mime_addpart(mime);
            curl_mime_name(part, file.first.c_str());
            curl_mime_filedata(part, file.second.c_str());
        }

        curl_easy_setopt(curlRequest, CURLOPT_MIMEPOST, mime);
    }

    curl_easy_setopt(curlRequest, CURLOPT_HTTPHEADER, headersList);
    if (method != "GET")
    {
        curl_easy_setopt(curlRequest, CURLOPT_CUSTOMREQUEST, method.c_str());
        if (method != "DELETE" && method != "GET")
            curl_easy_setopt(curlRequest, CURLOPT_COPYPOSTFIELDS, (data + "\0").c_str());
    }

    curl_easy_setopt(curlRequest, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curlRequest, CURLOPT_WRITEDATA, &responseBody);

    curl_easy_setopt(curlRequest, CURLOPT_HEADERFUNCTION, HeaderCallback);
    curl_easy_setopt(curlRequest, CURLOPT_HEADERDATA, &responseHeaders);

    CURLcode code = curl_easy_perform(curlRequest);

    int httpStatusCode = 0;
    curl_easy_getinfo(curlRequest, CURLINFO_RESPONSE_CODE, &httpStatusCode);
    std::string error = (code == CURLE_OK ? "Success (no errors)" : curl_easy_strerror(code));

    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    rapidjson::Document doc(rapidjson::kObjectType);

    for (size_t i = 1; i < responseHeaders.size(); i++)
    {
        std::vector<std::string> splitted = explode(responseHeaders[i], ":");
        if (splitted.size() < 2)
            continue;

        std::string headerName = splitted[0];
        splitted.erase(splitted.begin());
        std::string headerValue = implode(splitted, ":");

        doc.AddMember(rapidjson::Value().SetString(headerName.c_str(), doc.GetAllocator()), rapidjson::Value().SetString(headerValue.c_str(), doc.GetAllocator()), doc.GetAllocator());
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    eventData.push_back(msgpack::object(httpStatusCode));
    eventData.push_back(msgpack::object(implode(responseBody, "").c_str()));
    eventData.push_back(msgpack::object(buffer.GetString()));
    eventData.push_back(msgpack::object(error.c_str()));
    eventData.push_back(msgpack::object(requestUUID.c_str()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHTTPActionPerformed", ss.str(), event);

    delete event;

    if (headersList)
        curl_slist_free_all(headersList);

    if (mime)
        curl_mime_free(mime);
    if (curlRequest)
        curl_easy_cleanup(curlRequest);
}

void ProcessingHTTPThread()
{
    while (true)
    {
        while (!requestsQueue.empty())
        {
            Request req = requestsQueue.front();
            RunCurlRequest(req.url, req.data, req.headers, req.files, req.method, req.requestUUID);
            requestsQueue.pop_front();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

PluginHTTP::PluginHTTP(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

static bool httpThread = false;

std::string PluginHTTP::PerformHTTP(std::string receivedData)
{
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
    std::map<std::string, std::string> headers;
    std::map<std::string, std::string> files;

    if (request.HasMember("headers"))
    {
        if (request["headers"].IsObject() && !request["headers"].IsArray())
        {
            for (auto &header : request["headers"].GetObject())
            {
                std::string headerName = header.name.GetString();
                if (!header.value.IsString())
                    continue;

                std::string headerValue = header.value.GetString();

                headers.insert({headerName, headerValue});
            }
        }
    }

    if (request.HasMember("files"))
    {
        if (request["files"].IsObject() && !request["files"].IsArray())
        {
            for (auto &file : request["files"].GetObject())
            {
                std::string fileName = file.name.GetString();
                if (!file.value.IsString())
                    continue;

                std::string fileValue = file.value.GetString();
                if (!Files::ExistsPath(fileValue))
                    continue;

                files.insert({fileName, fileValue});
            }
        }
    }

    std::string requestUUID = get_uuid();

    Request req = {url, data, headers, files, method, requestUUID};
    requestsQueue.push_back(req);

    if (!httpThread)
    {
        httpThread = true;
        std::thread(ProcessingHTTPThread).detach();
    }

    return requestUUID;
}