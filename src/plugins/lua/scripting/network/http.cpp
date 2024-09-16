#include "../core.h"

LoadLuaScriptingComponent(
    http,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginHTTP>("HTTP")
            .addConstructor<void (*)(std::string)>()
            .addFunction("PerformHTTP", &PluginHTTP::PerformHTTP)
            .endClass();

        luaL_dostring(state, "http = HTTP(GetCurrentPluginName())");
    }
)
