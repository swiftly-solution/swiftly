#ifndef _swiftly_http_httprequest_h
#define _swiftly_http_httprequest_h

#include "../swiftly_memory.h"
#include "../types.h"
#include <string>

class HTTPRequest
{
private:
    uint64_t requestID = 0;
    bool executed = false;

public:
    HTTPRequest(const char *domain);

    HTTPRequest *SetBody(const char *body);
    HTTPRequest *AddHeader(const char *key, const char *value);
    HTTPRequest *DeleteHeader(const char *key);
    HTTPRequest *AddMultipartFile(const char *field, const char *content, const char *filename, const char *file_content_type);
    HTTPRequest *SetContentType(ContentType content_type);
    HTTPRequest *SetBasicAuthentication(const char *username, const char *password);
    HTTPRequest *SetBearerAuthenticationToken(const char *token);
    HTTPRequest *SetFollowRedirect(bool follow);

    HTTPRequest *Get(const char *path, bool await);
    HTTPRequest *Delete(const char *path, bool await);
    HTTPRequest *Post(const char *path, bool await);
    HTTPRequest *Put(const char *path, bool await);
    HTTPRequest *Patch(const char *path, bool await);

    void Close();

    const char *GetBody();
    int GetStatusCode();
    const char *GetError();
};

#endif