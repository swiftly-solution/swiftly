#include "../core.h"

LoadLuaScriptingComponent(
    ip,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginIPAPI>("IPAPI")
            .addConstructor<void (*)(std::string)>()
            .addFunction("GetIsoCode", &PluginIPAPI::GetIsoCode)
            .addFunction("GetContinent", &PluginIPAPI::GetContinent)
            .addFunction("GetCountry", &PluginIPAPI::GetCountry)
            .addFunction("GetRegion", &PluginIPAPI::GetRegion)
            .addFunction("GetCity", &PluginIPAPI::GetCity)
            .addFunction("GetTimezone", &PluginIPAPI::GetTimezone)
            .addFunction("GetLatitude", &PluginIPAPI::GetLatitude)
            .addFunction("GetLongitude", &PluginIPAPI::GetLongitude)
            .addFunction("GetASN", &PluginIPAPI::GetASN)
            .endClass();

        luaL_dostring(state, "ip = IPAPI(GetCurrentPluginName())");
    }
)
