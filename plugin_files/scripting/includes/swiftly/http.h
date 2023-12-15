#ifndef _swiftly_http_h
#define _swiftly_http_h

#include "http/HTTPRequest.h"

class HTTP
{
private:
public:
    HTTP();

    HTTPRequest *GenerateRequest(const char *domain);
    void CloseRequest(HTTPRequest *request);
};

extern HTTP *http;

#endif