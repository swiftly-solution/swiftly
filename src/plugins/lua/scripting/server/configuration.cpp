#include "../core.h"

void SetupLuaConfiguration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginConfiguration>("Configuration")
        .addConstructor<void (*)(std::string)>()
        .addFunction("Exists", &PluginConfiguration::Exists)
        .addFunction("Reload", &PluginConfiguration::Reload)
        .addFunction("FetchArraySize", &PluginConfiguration::FetchArraySize)
        .addFunction("Fetch", &PluginConfiguration::Fetch)
        .addFunction("Create", &PluginConfiguration::CreateLua)
        .endClass();

    luaL_dostring(state, "config = Configuration(GetCurrentPluginName())");
}