#include "HTTPManager.h"

HTTPManager::HTTPManager() {}

uint64_t HTTPManager::CreateRequest(std::string url)
{
    ++this->requestIndex;
    HTTPRequest *request = new HTTPRequest(url);
    this->requests.insert(std::make_pair(this->requestIndex, request));
    return this->requestIndex;
}

void HTTPManager::DeleteRequest(uint64_t requestID)
{
    if (this->requests.find(requestID) == this->requests.end())
        return;

    HTTPRequest *request = this->requests.at(requestID);

    delete request;
    this->requests.erase(requestID);
}

HTTPRequest *HTTPManager::FetchRequest(uint64_t requestID)
{
    if (this->requests.find(requestID) == this->requests.end())
        return nullptr;

    return this->requests.at(requestID);
}