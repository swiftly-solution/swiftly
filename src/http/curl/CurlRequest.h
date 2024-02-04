#ifndef _swiftly_curlrequest_h
#define _swiftly_curlrequest_h

#define CURL_STATICLIB
#include "../../utils.h"
#include <stdio.h>
extern "C"
{
#include <curl/curl.h>
};
#include <string>
#include <map>
#include <thread>

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
        if (this->headersList)
            curl_slist_free_all(this->headersList);
        for (std::map<std::string, std::string>::iterator it = mapHeaders.begin(); it != mapHeaders.end(); ++it)
            this->headersList = curl_slist_append(this->headersList, (string_format("%s: %s", it->first.c_str(), it->second.c_str()) + "\0").c_str());

        curl_easy_setopt(this->req, CURLOPT_HTTPHEADER, this->headersList);
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

    void Get(bool await)
    {
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        if (await)
        {
            std::thread th([this]()
                           { this->code = curl_easy_perform(this->req); });
            th.detach();
        }
        else
            this->code = curl_easy_perform(this->req);
    }

    void Post(const std::string &body, bool await)
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(this->req, CURLOPT_COPYPOSTFIELDS, (body + "\0").c_str());
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        if (await)
        {
            std::thread th([this]()
                           { this->code = curl_easy_perform(this->req); });
            th.detach();
        }
        else
            this->code = curl_easy_perform(this->req);
    }

    void Put(const std::string &body, bool await)
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(this->req, CURLOPT_COPYPOSTFIELDS, (body + "\0").c_str());
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        if (await)
        {
            std::thread th([this]()
                           { this->code = curl_easy_perform(this->req); });
            th.detach();
        }
        else
            this->code = curl_easy_perform(this->req);
    }

    void Patch(const std::string &body, bool await)
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "PATCH");
        curl_easy_setopt(this->req, CURLOPT_COPYPOSTFIELDS, (body + "\0").c_str());
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        if (await)
        {
            std::thread th([this]()
                           { this->code = curl_easy_perform(this->req); });
            th.detach();
        }
        else
            this->code = curl_easy_perform(this->req);
    }

    void Delete(bool await)
    {
        curl_easy_setopt(this->req, CURLOPT_CUSTOMREQUEST, "DELETE");
        curl_easy_setopt(this->req, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(this->req, CURLOPT_WRITEDATA, &this->responseBody);
        if (await)
        {
            std::thread th([this]()
                           { this->code = curl_easy_perform(this->req); });
            th.detach();
        }
        else
            this->code = curl_easy_perform(this->req);
    }

    ~CurlRequest()
    {
        if (this->headersList)
            curl_slist_free_all(this->headersList);

        if (this->req)
            curl_easy_cleanup(this->req);
    }

private:
    CURL *req;
    struct curl_slist *headersList = nullptr;
    std::string responseBody;
    CURLcode code;

    static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string *)userp)->append((char *)contents, size * nmemb);
        return size * nmemb;
    }
};

#endif