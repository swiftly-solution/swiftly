#include "../../../../common.h"
#include "../../../../utils/memstr.h"
#include "../../../../http/HTTPManager.h"

SMM_API uint64_t scripting_HTTP_CreateRequest(const char *domain)
{
    if (domain == nullptr)
        return 0;

    uint64_t requestID = g_httpManager->CreateRequest(domain);
    return requestID;
}

SMM_API void scripting_HTTP_SetBody(uint64_t requestID, const char *body)
{
    if (requestID == 0 || body == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->SetBody(body);
}

SMM_API void scripting_HTTP_AddHeader(uint64_t requestID, const char *key, const char *value)
{
    if (requestID == 0 || key == nullptr || value == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->AddHeader(key, value);
}

SMM_API void scripting_HTTP_DeleteHeader(uint64_t requestID, const char *key)
{
    if (requestID == 0 || key == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->DeleteHeader(key);
}

SMM_API void scripting_HTTP_AddMultipartFile(uint64_t requestID, const char *field, const char *content, const char *filename, const char *file_content_type)
{
    if (requestID == 0 || field == nullptr || content == nullptr || filename == nullptr || file_content_type == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->AddMultipartFile(field, content, filename, file_content_type);
}

SMM_API void scripting_HTTP_SetContentType(uint64_t requestID, ContentType content_type)
{
    if (content_type < 1 || content_type > 9 || requestID == 0)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->SetContentType(content_type);
}

SMM_API void scripting_HTTP_SetBasicAuthentication(uint64_t requestID, const char *username, const char *password)
{
    if (requestID == 0 || username == nullptr || password == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->SetBasicAuthentication(username, password);
}

SMM_API void scripting_HTTP_SetBearerAuthenticationToken(uint64_t requestID, const char *token)
{
    if (requestID == 0 || token == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->SetBearerAuthenticationToken(token);
}

SMM_API void scripting_HTTP_SetFollowRedirect(uint64_t requestID, bool follow)
{
    if (requestID == 0)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->SetFollowRedirect(follow);
}

SMM_API const char *scripting_HTTP_GetBody(uint64_t requestID)
{
    if (requestID == 0)
        return "";

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    std::string body = request->GetBody();

    MemStr str(body);
    str.DeleteAfter(500);
    return str.Get();
}

SMM_API int scripting_HTTP_GetStatusCode(uint64_t requestID)
{
    if (requestID == 0)
        return 0;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    return request->GetStatusCode();
}

SMM_API const char *scripting_HTTP_GetError(uint64_t requestID)
{
    if (requestID == 0)
        return "";

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    std::string error = request->GetError();

    MemStr str(error);
    str.DeleteAfter(500);
    return str.Get();
}

SMM_API void scripting_HTTP_Get(uint64_t requestID, const char *path)
{
    if (requestID == 0 || path == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->Get(path);
}

SMM_API void scripting_HTTP_Delete(uint64_t requestID, const char *path)
{
    if (requestID == 0 || path == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->Delete(path);
}

SMM_API void scripting_HTTP_Post(uint64_t requestID, const char *path)
{
    if (requestID == 0 || path == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->Post(path);
}

SMM_API void scripting_HTTP_Put(uint64_t requestID, const char *path)
{
    if (requestID == 0 || path == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->Put(path);
}

SMM_API void scripting_HTTP_Patch(uint64_t requestID, const char *path)
{
    if (requestID == 0 || path == nullptr)
        return;

    HTTPRequest *request = g_httpManager->FetchRequest(requestID);
    request->Patch(path);
}

SMM_API void scripting_HTTP_Close(uint64_t requestID)
{
    if (requestID == 0)
        return;

    g_httpManager->DeleteRequest(requestID);
}
