#include "../core.h"

LoadLuaScriptingComponent(
    http,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginHTTP>("HTTP")
            .addConstructor<void (*)(std::string)>()
            .addFunction("PerformHTTP", &PluginHTTP::PerformHTTP)
            .addFunction("Listen", &PluginHTTP::ListenLua)
            .endClass()
            
            .beginClass<PluginHTTPRequest>("HTTPRequest")
            .addProperty("path", &PluginHTTPRequest::m_path, false)
            .addProperty("method", &PluginHTTPRequest::m_method, false)
            .addProperty("body", &PluginHTTPRequest::m_body, false)
            .addProperty("files", &PluginHTTPRequest::m_files, false)
            .addProperty("headers", &PluginHTTPRequest::m_headers, false)
            .addProperty("params", &PluginHTTPRequest::m_params, false)
            .endClass()
            
            .beginClass<PluginHTTPResponse>("HTTPResponse")
            .addFunction("WriteBody", &PluginHTTPResponse::WriteBody)
            .addFunction("GetHeaders", &PluginHTTPResponse::GetHeaders)
            .addFunction("GetHeader", &PluginHTTPResponse::GetHeader)
            .addFunction("SetHeader", &PluginHTTPResponse::SetHeader)
            .addFunction("Send", &PluginHTTPResponse::Send)
            .addFunction("IsCompleted", &PluginHTTPResponse::IsCompleted)
            .endClass();

        luaL_dostring(state, "http = HTTP(GetCurrentPluginName())");
    }
)
