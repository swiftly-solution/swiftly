#include "core.h"

void SetupLuaTypes(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginNamespace("PluginState_t")
        .addConstant("Started", (uint64_t)PluginState_t::Started)
        .addConstant("Stopped", (uint64_t)PluginState_t::Stopped)
        .endNamespace();
}