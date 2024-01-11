#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaHTTPClass
{
public:
    LuaHTTPClass() {}
};

class LuaHTTPRequestClass
{
private:
    uint64_t requestID = 0;

public:
    LuaHTTPRequestClass(const char *domain)
    {
        this->requestID = scripting_HTTP_CreateRequest(domain);
    }

    void Close()
    {
        scripting_HTTP_Close(this->requestID);
    }

    uint64_t GetRequestID()
    {
        return this->requestID;
    }
};

void SetupLuaHTTP(luacpp::LuaState *state, Plugin *plugin)
{
    auto httpClass = state->CreateClass<LuaHTTPClass>("HTTP").DefConstructor();
    auto httpRequestClass = state->CreateClass<LuaHTTPRequestClass>("HTTPRequest").DefConstructor<const char *>();

    httpClass.DefMember("CreateRequest", [httpRequestClass](LuaHTTPClass *base, const char *domain) -> luacpp::LuaObject
                        { return httpRequestClass.CreateInstance(domain); })
        .DefMember("CloseRequest", [](LuaHTTPClass *base, luacpp::LuaObject requestObject) -> void
                   {
                LuaHTTPRequestClass* req = static_cast<LuaHTTPRequestClass*>(requestObject.ToPointer());
                req->Close(); });

    httpRequestClass.DefMember("AddHeader", [](LuaHTTPRequestClass *base, const char *key, const char *value) -> void
                               { scripting_HTTP_AddHeader(base->GetRequestID(), key, value); })
        .DefMember("AddMultipartFile", [](LuaHTTPRequestClass *base, const char *field, const char *content, const char *filename, const char *file_content_type) -> void
                   { scripting_HTTP_AddMultipartFile(base->GetRequestID(), field, content, filename, file_content_type); })
        .DefMember("Delete", [](LuaHTTPRequestClass *base, const char *path) -> void
                   { scripting_HTTP_Delete(base->GetRequestID(), path); })
        .DefMember("DeleteHeader", [](LuaHTTPRequestClass *base, const char *key) -> void
                   { scripting_HTTP_DeleteHeader(base->GetRequestID(), key); })
        .DefMember("Get", [](LuaHTTPRequestClass *base, const char *path) -> void
                   { scripting_HTTP_Get(base->GetRequestID(), path); })
        .DefMember("GetBody", [](LuaHTTPRequestClass *base) -> const char *
                   { return scripting_HTTP_GetBody(base->GetRequestID()); })
        .DefMember("GetError", [](LuaHTTPRequestClass *base) -> const char *
                   { return scripting_HTTP_GetError(base->GetRequestID()); })
        .DefMember("GetStatusCode", [](LuaHTTPRequestClass *base) -> int
                   { return scripting_HTTP_GetStatusCode(base->GetRequestID()); })
        .DefMember("Patch", [](LuaHTTPRequestClass *base, const char *path) -> void
                   { scripting_HTTP_Patch(base->GetRequestID(), path); })
        .DefMember("Post", [](LuaHTTPRequestClass *base, const char *path) -> void
                   { scripting_HTTP_Post(base->GetRequestID(), path); })
        .DefMember("Put", [](LuaHTTPRequestClass *base, const char *path) -> void
                   { scripting_HTTP_Put(base->GetRequestID(), path); })
        .DefMember("SetBasicAuthentication", [](LuaHTTPRequestClass *base, const char *username, const char *password) -> void
                   { scripting_HTTP_SetBasicAuthentication(base->GetRequestID(), username, password); })
        .DefMember("SetBearerAuthenticationToken", [](LuaHTTPRequestClass *base, const char *token) -> void
                   { scripting_HTTP_SetBearerAuthenticationToken(base->GetRequestID(), token); })
        .DefMember("SetBody", [](LuaHTTPRequestClass *base, const char *body) -> void
                   { scripting_HTTP_SetBody(base->GetRequestID(), body); })
        .DefMember("SetContentType", [](LuaHTTPRequestClass *base, int contentType) -> void
                   { scripting_HTTP_SetContentType(base->GetRequestID(), (ContentType)contentType); })
        .DefMember("SetFollowRedirect", [](LuaHTTPRequestClass *base, bool follow) -> void
                   { scripting_HTTP_SetFollowRedirect(base->GetRequestID(), follow); });

    state->DoString("http = HTTP()");

    PRINT("Scripting - Lua", "HTTP loaded.\n");
}