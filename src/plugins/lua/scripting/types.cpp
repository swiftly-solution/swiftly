#include "core.h"

#include "../../../types/LogType.h"

void SetupLuaTypes(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)

        .beginNamespace("PluginState_t")
        .addConstant("Started", (uint64_t)PluginState_t::Started)
        .addConstant("Stopped", (uint64_t)PluginState_t::Stopped)
        .endNamespace()

        .beginNamespace("LogType_t")
        .addConstant("Debug", (uint64_t)LogType_t::Debug)
        .addConstant("Warning", (uint64_t)LogType_t::Warning)
        .addConstant("Error", (uint64_t)LogType_t::Error)
        .addConstant("Common", (uint64_t)LogType_t::Common)
        .endNamespace();
}