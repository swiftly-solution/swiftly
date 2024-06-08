#include "../../../core/scripting/generated/classes/GCSimpleSimTimer.h"
#include "../core.h"

void SetupLuaClassGCSimpleSimTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimpleSimTimer>("CSimpleSimTimer")
        .addProperty("WorldGroupId", &GCSimpleSimTimer::GetWorldGroupId, &GCSimpleSimTimer::SetWorldGroupId)
        .endClass();
}