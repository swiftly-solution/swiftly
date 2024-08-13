#include "core.h"

void SetupLuaUtils(LuaPlugin* plugin, lua_State* state)
{
    luabridge::getGlobalNamespace(state)
        .addFunction("GetPluginPath", scripting_GetPluginPath)
        .addFunction("GetTime", GetTime)
        .addFunction("IsWindows", scripting_IsWindows)
        .addFunction("IsLinux", scripting_IsLinux)
        .addFunction("GetOS", scripting_GetOS)
        .addFunction("StateUpdate", scripting_StateUpdate)
        .addFunction("GetPluginState", +[](std::string plugin_name) -> int
            {
                if (!g_pluginManager->PluginExists(plugin_name)) return (int)PluginState_t::Stopped;
                Plugin* plugin = g_pluginManager->FetchPlugin(plugin_name);
                if (!plugin) return (int)PluginState_t::Stopped;

                return (int)plugin->GetPluginState(); })
        .addFunction("GetCCSGameRules", scripting_GetCCSGameRules);
}