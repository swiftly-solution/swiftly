#include "HTTPManager.h"
#include "../plugins/core/scripting.h"

extern ISteamHTTP* g_http;

TrackedRequest::TrackedRequest(HTTPRequestHandle hndl, SteamAPICall_t hCall, std::string requestID, RequestCB callback)
{
    m_hHTTPReq = hndl;
    m_CallResult.SetGameserverFlag();
    m_CallResult.Set(hCall, this, &TrackedRequest::OnHTTPRequestCompleted);

    m_callback = callback;
    m_requestID = requestID;

    g_httpManager->m_PendingRequests.push_back(this);
}

TrackedRequest::~TrackedRequest()
{
    for (auto e = g_httpManager->m_PendingRequests.begin(); e != g_httpManager->m_PendingRequests.end(); ++e)
    {
        if (*e == this)
        {
            g_httpManager->m_PendingRequests.erase(e);
            break;
        }
    }
}

void TrackedRequest::OnHTTPRequestCompleted(HTTPRequestCompleted_t* arg, bool bFailed)
{
    int status = (bFailed ? 0 : arg->m_eStatusCode);
    std::string body = "";
    std::string error = "";
    uint8* response = nullptr;

    if (bFailed) error = "Failed to create request.";
    else if (status < 200 || status > 299) error = std::to_string(arg->m_eStatusCode);
    else error = "Success (no errors)";

    if (status >= 200 && status <= 299) {
        uint32_t bodySize;
        g_http->GetHTTPResponseBodySize(arg->m_hRequest, &bodySize);

        response = new uint8[bodySize + 1];
        g_http->GetHTTPResponseBodyData(arg->m_hRequest, response, bodySize);
        response[bodySize] = 0;

        body = (char*)response;
    }

    this->m_callback(arg->m_hRequest, status, body, "[]", error, this->m_requestID);

    if (response != nullptr) delete[] response;
    if (g_http) g_http->ReleaseHTTPRequest(arg->m_hRequest);

    delete this;
}

void HTTPManager::ProcessPendingHTTPRequests()
{
    for (auto it = m_PendingHTTPRequests.begin(); it != m_PendingHTTPRequests.end(); ++it)
    {
        if (it->second.size() == 0) continue;

        PluginHTTP h(it->first);
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            h.PerformHTTPWithRequestID(it2->second, it2->first);
    }

    m_PendingHTTPRequests.clear();
}