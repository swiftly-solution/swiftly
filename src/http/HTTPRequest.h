#ifndef _httprequest_h
#define _httprequest_h

#include "curl/CurlRequest.h"
#include "ContentTypes.h"
#include "../common.h"
#include "../utils.h"

class HTTPRequest
{
private:
    CurlRequest *req;
    std::map<std::string, std::string> headers;
    std::string body;
    std::string url;
    ContentType content_type = ContentType::APPLICATION_JSON;
    bool executed = false;

public:
    HTTPRequest(std::string url);
    ~HTTPRequest();
    void Get(std::string path);
    void Delete(std::string path);
    void Post(std::string path);
    void Put(std::string path);
    void Patch(std::string path);
    void AddHeader(std::string key, std::string value);
    void DeleteHeader(std::string key);
    void AddMultipartFile(std::string field, std::string content, std::string filename, std::string file_content_type);
    void SetContentType(ContentType content_type);
    void SetBody(std::string body);
    void SetBasicAuthentication(std::string username, std::string password);
    void SetBearerAuthenticationToken(std::string token);
    void SetFollowRedirect(bool follow);

    std::string GetBody();
    int GetStatusCode();
    std::string GetError();
};

#endif