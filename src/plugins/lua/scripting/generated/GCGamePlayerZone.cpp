#include "../../../core/scripting/generated/classes/GCGamePlayerZone.h"
#include "../core.h"

void SetupLuaClassGCGamePlayerZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGamePlayerZone>("CGamePlayerZone")
        .addProperty("OnPlayerInZone", &GCGamePlayerZone::GetOnPlayerInZone, &GCGamePlayerZone::SetOnPlayerInZone)
        .addProperty("OnPlayerOutZone", &GCGamePlayerZone::GetOnPlayerOutZone, &GCGamePlayerZone::SetOnPlayerOutZone)
        .endClass();
}