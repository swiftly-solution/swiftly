#ifndef _swiftly_curlrequest_h
#define _swiftly_curlrequest_h

#include "../../utils.h"
#include <curl/curl.h>
#include <string>
#include <map>

class CurlRequest
{
public:
    CurlRequest()
    {
        this->req = curl_easy_init();
    }

    void SetUrl(const std::string &url)
    {
        curl_easy_setopt(this->req, CURLOPT_URL, url.c_str());
    }

    void SetUserAgent(const std::string &user_agent)
    {
        curl_easy_setopt(this->req, CURLOPT_USERAGENT, user_agent.c_str());
    }

    void SetTimeout(int timeout_secs)
    {
        curl_easy_setopt(this->req, CURLOPT_TIMEOUT, timeout_secs);
    }

    void SetFollowLocation(bool follow)
    {
        curl_easy_setopt(this->req, CURLOPT_FOLLOWLOCATION, follow ? 1L : 0L);
    }

    void SetHeaders(std::map<std::string, std::string> mapHeaders)
    {
        curl_slist_free_all(this->headersList);
        for (std::map<std::string, std::string>::iterator it = mapHeaders.begin(); it != mapHeaders.end(); ++it)
            this->headersList = curl_slist_append(this->headersList, string_format("%s: %s", it->first.c_str(), it->second.c_str()).c_str());
    }

    std::string GetResponseBody()
    {
        return this->responseBody;
    }

    int GetStatusCode()
    {
        int http_code = 0;
        curl_easy_getinfo(this->req, CURLINFO_RESPONSE_CODE, &http_code);
        return http_code;
    }

    std::string GetError()
    {
        if (this->code == CURLE_OK)
            return "Success (no errors)";
        else
            return curl_easy_strerror(this->code);
    }

    void Get()
    {
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, &WriteResponse);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        this->code = curl_easy_perform(this->req);
    }

    void Post(std::string body)
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(this->req, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, &WriteResponse);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        this->code = curl_easy_perform(this->req);
    }

    void Put(std::string body)
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(this->req, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, &WriteResponse);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        this->code = curl_easy_perform(this->req);
    }

    void Patch(std::string body)
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "PATCH");
        curl_easy_setopt(this->req, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, &WriteResponse);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        this->code = curl_easy_perform(this->req);
    }

    void Delete()
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "DELETE");
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, &WriteResponse);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        this->code = curl_easy_perform(this->req);
    }

    ~CurlRequest()
    {
        curl_slist_free_all(this->headersList);
        curl_easy_cleanup(this->req);
        delete this->req;
    }

private:
    CURL *req;
    struct curl_slist *headersList;
    std::string responseBody;
    CURLcode code;

    static size_t WriteResponse(void *ptr, size_t size, size_t nmemb, void *userdata)
    {
        size_t real_size = size * nmemb;
        std::string *response = static_cast<std::string *>(userdata);
        response->append(static_cast<char *>(ptr), real_size);
        return real_size;
    }
};

#endif