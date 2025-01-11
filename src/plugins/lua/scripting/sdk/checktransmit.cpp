#include "../core.h"

LoadLuaScriptingComponent(
    checktransmit,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginCCheckTransmitInfo>("CCheckTransmitInfo")
            .addConstructor<void(*)(luabridge::LuaRef)>()
            .addFunction("GetPlayers", &PluginCCheckTransmitInfo::GetPlayers)
            .addFunction("GetEntities", &PluginCCheckTransmitInfo::GetEntities)
            .addFunction("SetEntities", &PluginCCheckTransmitInfo::SetEntities)
            .endClass();
    }
)