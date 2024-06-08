#include "../../../core/scripting/generated/classes/GCPropDoorRotatingBreakable.h"
#include "../core.h"

void SetupLuaClassGCPropDoorRotatingBreakable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPropDoorRotatingBreakable>("CPropDoorRotatingBreakable")
        .addProperty("Breakable", &GCPropDoorRotatingBreakable::GetBreakable, &GCPropDoorRotatingBreakable::SetBreakable)
        .addProperty("IsAbleToCloseAreaPortals", &GCPropDoorRotatingBreakable::GetIsAbleToCloseAreaPortals, &GCPropDoorRotatingBreakable::SetIsAbleToCloseAreaPortals)
        .addProperty("CurrentDamageState", &GCPropDoorRotatingBreakable::GetCurrentDamageState, &GCPropDoorRotatingBreakable::SetCurrentDamageState)
        .addProperty("DamageStates", &GCPropDoorRotatingBreakable::GetDamageStates, &GCPropDoorRotatingBreakable::SetDamageStates)
        .endClass();
}