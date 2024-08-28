#ifndef _http_manager_h
#define _http_manager_h

#include <steam/steam_gameserver.h>
#include <vector>
#include <map>
#include <string>
#include <functional>

#define RequestCB std::function<void(HTTPRequestHandle, int, std::string, std::string, std::string, std::string)>

class TrackedRequest
{
public:
    TrackedRequest(const TrackedRequest& req) = delete;
    TrackedRequest(HTTPRequestHandle hndl, SteamAPICall_t hCall, std::string requestID, RequestCB callback);
    ~TrackedRequest();
private:
    void OnHTTPRequestCompleted(HTTPRequestCompleted_t* arg, bool bFailed);

    HTTPRequestHandle m_hHTTPReq;
    CCallResult<TrackedRequest, HTTPRequestCompleted_t> m_CallResult;
    std::string m_requestID;

    RequestCB m_callback;
};

class HTTPManager
{
public:
    HTTPManager() = default;
    ~HTTPManager() = default;

    void ProcessPendingHTTPRequests();

    std::vector<TrackedRequest*> m_PendingRequests;
    std::map<std::string, std::map<std::string, std::string>> m_PendingHTTPRequests;
};

extern HTTPManager* g_httpManager;

#endif