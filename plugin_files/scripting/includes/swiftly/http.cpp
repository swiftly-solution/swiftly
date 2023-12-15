#include "http.h"

HTTP::HTTP() {}

HTTPRequest *HTTP::GenerateRequest(const char *domain)
{
    HTTPRequest *request = new HTTPRequest(domain);
    return request;
}

void HTTP::CloseRequest(HTTPRequest *request)
{
    request->Close();
    delete request;
}
