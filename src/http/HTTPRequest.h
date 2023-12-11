#ifndef _httprequest_h
#define _httprequest_h

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>
#include "ContentTypes.h"
#include "../common.h"
#include "../utils.h"

class HTTPRequest
{
private:
    httplib::Client *client;
    httplib::Result result;
    httplib::Headers headers;
    httplib::Params params;
    httplib::MultipartFormDataItems multipartItems;

    std::string body;
    ContentType content_type;
    bool executed = false;

public:
    HTTPRequest(std::string url)
    {
        this->client = new httplib::Client(url);

        this->client->set_default_headers({{"Accept-Encoding", "gzip, deflate"}});
    }

    ~HTTPRequest()
    {
        this->multipartItems.clear();
        this->params.clear();
        this->headers.clear();

        this->body.clear();
        delete this->client;
    }

    void Get(std::string path)
    {
        this->executed = true;
        this->result = this->client->Get(path, this->params, this->headers);
    }

    void Delete(std::string path)
    {
        this->executed = true;
        this->result = this->client->Delete(path, this->headers);
    }

    void Post(std::string path)
    {
        this->executed = true;
        std::string final_content_type = contentTypesMap.at(this->content_type);
        if (this->content_type == ContentType::MULTIPART_FORMDATA)
            this->result = this->client->Post(path, this->headers, this->multipartItems);
        else
            this->result = this->client->Post(path, this->headers, this->body, final_content_type);
    }

    void Put(std::string path)
    {
        this->executed = true;
        std::string final_content_type = contentTypesMap.at(this->content_type);
        if (this->content_type == ContentType::MULTIPART_FORMDATA)
            this->result = this->client->Put(path, this->headers, this->multipartItems);
        else
            this->result = this->client->Put(path, this->headers, this->body, final_content_type);
    }

    void Patch(std::string path)
    {
        this->executed = true;
        std::string final_content_type = contentTypesMap.at(this->content_type);
        this->result = this->client->Patch(path, this->headers, this->body, final_content_type);
    }

    void AddHeader(std::string key, std::string value)
    {
        this->headers.insert(std::make_pair(key, value));
    }

    void DeleteHeader(std::string key)
    {
        if (this->headers.find(key) != this->headers.end())
            this->headers.erase(key);
    }

    void AddMultipartFile(std::string field, std::string content, std::string filename, std::string file_content_type)
    {
        httplib::MultipartFormData data{field, content, filename, file_content_type};

        this->multipartItems.push_back(data);
    }

    void SetContentType(ContentType content_type)
    {
        this->content_type = content_type;
    }

    void SetBody(std::string body)
    {
        this->body = body;
    }

    void SetBasicAuthentication(std::string username, std::string password)
    {
        this->client->set_basic_auth(username, password);
    }

    void SetBearerAuthenticationToken(std::string token)
    {
        this->client->set_bearer_token_auth(token);
    }

    void SetFollowRedirect(bool follow)
    {
        this->client->set_follow_location(follow);
    }

    std::string GetBody()
    {
        if (!this->executed)
            return "";

        return this->result->body;
    }

    int GetStatusCode()
    {
        if (!this->executed)
            return 0;

        return this->result->status;
    }

    std::string GetError()
    {
        if (!this->result)
            return "";

        return httplib::to_string(this->result.error());
    }
};

#endif