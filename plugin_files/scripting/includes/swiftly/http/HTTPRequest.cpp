#include "HTTPRequest.h"
#include "../swiftly.h"

HTTPRequest::HTTPRequest(const char *domain)
{
    void *http_CreateRequest = FetchFunctionPtr(nullptr, "scripting_HTTP_CreateRequest");
    if (http_CreateRequest)
        this->requestID = reinterpret_cast<HTTP_CreateRequest>(http_CreateRequest)(domain);
    else
        NOT_SUPPORTED("scripting_HTTP_CreateRequest");
}

HTTPRequest *HTTPRequest::SetBody(const char *body)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_SetBody = FetchFunctionPtr(nullptr, "scripting_HTTP_SetBody");
    if (http_SetBody)
        reinterpret_cast<HTTP_SetBody>(http_SetBody)(this->requestID, body);
    else
        NOT_SUPPORTED("scripting_HTTP_SetBody");

    return this;
}

HTTPRequest *HTTPRequest::AddHeader(const char *key, const char *value)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_AddHeader = FetchFunctionPtr(nullptr, "scripting_HTTP_AddHeader");
    if (http_AddHeader)
        reinterpret_cast<HTTP_AddHeader>(http_AddHeader)(this->requestID, key, value);
    else
        NOT_SUPPORTED("scripting_HTTP_AddHeader");

    return this;
}

HTTPRequest *HTTPRequest::DeleteHeader(const char *key)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_DeleteHeader = FetchFunctionPtr(nullptr, "scripting_HTTP_DeleteHeader");
    if (http_DeleteHeader)
        reinterpret_cast<HTTP_DeleteHeader>(http_DeleteHeader)(this->requestID, key);
    else
        NOT_SUPPORTED("scripting_HTTP_DeleteHeader");

    return this;
}

HTTPRequest *HTTPRequest::AddMultipartFile(const char *field, const char *content, const char *filename, const char *file_content_type)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_AddMultipartFile = FetchFunctionPtr(nullptr, "scripting_HTTP_AddMultipartFile");
    if (http_AddMultipartFile)
        reinterpret_cast<HTTP_AddMultipartFile>(http_AddMultipartFile)(this->requestID, field, content, filename, file_content_type);
    else
        NOT_SUPPORTED("scripting_HTTP_AddMultipartFile");

    return this;
}

HTTPRequest *HTTPRequest::SetContentType(ContentType content_type)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_SetContentType = FetchFunctionPtr(nullptr, "scripting_HTTP_SetContentType");
    if (http_SetContentType)
        reinterpret_cast<HTTP_SetContentType>(http_SetContentType)(this->requestID, content_type);
    else
        NOT_SUPPORTED("scripting_HTTP_SetContentType");

    return this;
}

HTTPRequest *HTTPRequest::SetBasicAuthentication(const char *username, const char *password)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_SetBasicAuthentication = FetchFunctionPtr(nullptr, "scripting_HTTP_SetBasicAuthentication");
    if (http_SetBasicAuthentication)
        reinterpret_cast<HTTP_SetBasicAuthentication>(http_SetBasicAuthentication)(this->requestID, username, password);
    else
        NOT_SUPPORTED("scripting_HTTP_SetBasicAuthentication");

    return this;
}

HTTPRequest *HTTPRequest::SetBearerAuthenticationToken(const char *token)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_SetBearerAuthenticationToken = FetchFunctionPtr(nullptr, "scripting_HTTP_SetBearerAuthenticationToken");
    if (http_SetBearerAuthenticationToken)
        reinterpret_cast<HTTP_SetBearerAuthenticationToken>(http_SetBearerAuthenticationToken)(this->requestID, token);
    else
        NOT_SUPPORTED("scripting_HTTP_SetBearerAuthenticationToken");

    return this;
}

HTTPRequest *HTTPRequest::SetFollowRedirect(bool follow)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_SetFollowRedirect = FetchFunctionPtr(nullptr, "scripting_HTTP_SetFollowRedirect");
    if (http_SetFollowRedirect)
        reinterpret_cast<HTTP_SetFollowRedirect>(http_SetFollowRedirect)(this->requestID, follow);
    else
        NOT_SUPPORTED("scripting_HTTP_SetFollowRedirect");

    return this;
}

const char *HTTPRequest::GetBody()
{
    if (!this->executed)
    {
        print("[Swiftly] You can't use %s because the request was not executed. (Get, Post, ...)\n", __FUNCTION__);
        return "";
    }

    void *http_GetBody = FetchFunctionPtr(nullptr, "scripting_HTTP_GetBody");
    if (http_GetBody)
        return reinterpret_cast<HTTP_GetBody>(http_GetBody)(this->requestID);
    else
    {
        NOT_SUPPORTED("scripting_HTTP_GetBody");
        return "";
    }
}

int HTTPRequest::GetStatusCode()
{
    if (!this->executed)
    {
        print("[Swiftly] You can't use %s because the request was not executed. (Get, Post, ...)\n", __FUNCTION__);
        return 0;
    }

    void *http_GetStatusCode = FetchFunctionPtr(nullptr, "scripting_HTTP_GetStatusCode");
    if (http_GetStatusCode)
        return reinterpret_cast<HTTP_GetStatusCode>(http_GetStatusCode)(this->requestID);
    else
    {
        NOT_SUPPORTED("scripting_HTTP_GetStatusCode");
        return 0;
    }
}

const char *HTTPRequest::GetError()
{
    if (!this->executed)
    {
        print("[Swiftly] You can't use %s because the request was not executed. (Get, Post, ...)\n", __FUNCTION__);
        return "";
    }

    void *http_GetError = FetchFunctionPtr(nullptr, "scripting_HTTP_GetError");
    if (http_GetError)
        return reinterpret_cast<HTTP_GetError>(http_GetError)(this->requestID);
    else
    {
        NOT_SUPPORTED("scripting_HTTP_GetError");
        return "";
    }
}

HTTPRequest *HTTPRequest::Get(const char *path)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_Get = FetchFunctionPtr(nullptr, "scripting_HTTP_Get");
    if (http_Get)
    {
        reinterpret_cast<HTTP_Get>(http_Get)(this->requestID, path);
        this->executed = true;
    }
    else
        NOT_SUPPORTED("scripting_HTTP_Get");

    return this;
}

HTTPRequest *HTTPRequest::Delete(const char *path)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_Delete = FetchFunctionPtr(nullptr, "scripting_HTTP_Delete");
    if (http_Delete)
    {
        reinterpret_cast<HTTP_Delete>(http_Delete)(this->requestID, path);
        this->executed = true;
    }
    else
        NOT_SUPPORTED("scripting_HTTP_Delete");

    return this;
}

HTTPRequest *HTTPRequest::Post(const char *path)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_Post = FetchFunctionPtr(nullptr, "scripting_HTTP_Post");
    if (http_Post)
    {
        reinterpret_cast<HTTP_Post>(http_Post)(this->requestID, path);
        this->executed = true;
    }
    else
        NOT_SUPPORTED("scripting_HTTP_Post");

    return this;
}

HTTPRequest *HTTPRequest::Put(const char *path)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_Put = FetchFunctionPtr(nullptr, "scripting_HTTP_Put");
    if (http_Put)
    {
        reinterpret_cast<HTTP_Put>(http_Put)(this->requestID, path);
        this->executed = true;
    }
    else
        NOT_SUPPORTED("scripting_HTTP_Put");

    return this;
}

HTTPRequest *HTTPRequest::Patch(const char *path)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    void *http_Patch = FetchFunctionPtr(nullptr, "scripting_HTTP_Patch");
    if (http_Patch)
    {
        reinterpret_cast<HTTP_Patch>(http_Patch)(this->requestID, path);
        this->executed = true;
    }
    else
        NOT_SUPPORTED("scripting_HTTP_Patch");

    return this;
}

void HTTPRequest::Close()
{
    if (this->requestID == 0)
        return print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);

    void *http_Close = FetchFunctionPtr(nullptr, "scripting_HTTP_Close");
    if (http_Close)
        reinterpret_cast<HTTP_Close>(http_Close)(this->requestID);
    else
        NOT_SUPPORTED("scripting_HTTP_Close");
}