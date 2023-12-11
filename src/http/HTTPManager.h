#ifndef _httpmanager_h
#define _httpmanager_h

#include "HTTPRequest.h"

class HTTPManager
{
private:
    std::map<uint64_t, HTTPRequest *> requests;
    uint64_t requestIndex = 0;

public:
    HTTPManager();

    uint64_t CreateRequest(std::string url);
    void DeleteRequest(uint64_t requestID);
    HTTPRequest *FetchRequest(uint64_t requestID);
};

extern HTTPManager *g_httpManager;

#endif