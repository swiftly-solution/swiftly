#include "../../../core/scripting/generated/classes/GCFuncPropRespawnZone.h"
#include "../core.h"

void SetupLuaClassGCFuncPropRespawnZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncPropRespawnZone>("CFuncPropRespawnZone")

        .endClass();
}