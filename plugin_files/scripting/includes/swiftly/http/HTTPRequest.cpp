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

    REGISTER_METHOD_VOID(scripting_HTTP_SetBody, this->requestID, body);

    return this;
}

HTTPRequest *HTTPRequest::AddHeader(const char *key, const char *value)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    REGISTER_METHOD_VOID(scripting_HTTP_AddHeader, this->requestID, key, value);

    return this;
}

HTTPRequest *HTTPRequest::DeleteHeader(const char *key)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    REGISTER_METHOD_VOID(scripting_HTTP_DeleteHeader, this->requestID, key);

    return this;
}

HTTPRequest *HTTPRequest::AddMultipartFile(const char *field, const char *content, const char *filename, const char *file_content_type)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    REGISTER_METHOD_VOID(scripting_HTTP_AddMultipartFile, this->requestID, field, content, filename, file_content_type);

    return this;
}

HTTPRequest *HTTPRequest::SetContentType(ContentType content_type)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    REGISTER_METHOD_VOID(scripting_HTTP_SetContentType, this->requestID, content_type);

    return this;
}

HTTPRequest *HTTPRequest::SetBasicAuthentication(const char *username, const char *password)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    REGISTER_METHOD_VOID(scripting_HTTP_SetBasicAuthentication, this->requestID, username, password);

    return this;
}

HTTPRequest *HTTPRequest::SetBearerAuthenticationToken(const char *token)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    REGISTER_METHOD_VOID(scripting_HTTP_SetBearerAuthenticationToken, this->requestID, token);

    return this;
}

HTTPRequest *HTTPRequest::SetFollowRedirect(bool follow)
{
    if (this->requestID == 0)
    {
        print("[Swiftly] You can't use %s because the request couldn't be created.\n", __FUNCTION__);
        return this;
    }

    REGISTER_METHOD_VOID(scripting_HTTP_SetFollowRedirect, this->requestID, follow);

    return this;
}

const char *HTTPRequest::GetBody()
{
    if (!this->executed)
    {
        print("[Swiftly] You can't use %s because the request was not executed. (Get, Post, ...)\n", __FUNCTION__);
        return "";
    }

    REGISTER_METHOD(const char *, "", scripting_HTTP_GetBody, this->requestID);
}

int HTTPRequest::GetStatusCode()
{
    if (!this->executed)
    {
        print("[Swiftly] You can't use %s because the request was not executed. (Get, Post, ...)\n", __FUNCTION__);
        return 0;
    }

    REGISTER_METHOD(int, 0, scripting_HTTP_GetStatusCode, this->requestID);
}

const char *HTTPRequest::GetError()
{
    if (!this->executed)
    {
        print("[Swiftly] You can't use %s because the request was not executed. (Get, Post, ...)\n", __FUNCTION__);
        return "";
    }

    REGISTER_METHOD(const char *, "", scripting_HTTP_GetError, this->requestID);
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

    REGISTER_METHOD_VOID(scripting_HTTP_Close, this->requestID);
}