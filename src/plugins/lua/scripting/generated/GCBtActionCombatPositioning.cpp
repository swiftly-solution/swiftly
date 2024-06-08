#include "../../../core/scripting/generated/classes/GCBtActionCombatPositioning.h"
#include "../core.h"

void SetupLuaClassGCBtActionCombatPositioning(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionCombatPositioning>("CBtActionCombatPositioning")
        .addProperty("SensorInputKey", &GCBtActionCombatPositioning::GetSensorInputKey, &GCBtActionCombatPositioning::SetSensorInputKey)
        .addProperty("IsAttackingKey", &GCBtActionCombatPositioning::GetIsAttackingKey, &GCBtActionCombatPositioning::SetIsAttackingKey)
        .addProperty("ActionTimer", &GCBtActionCombatPositioning::GetActionTimer, &GCBtActionCombatPositioning::SetActionTimer)
        .addProperty("Crouching", &GCBtActionCombatPositioning::GetCrouching, &GCBtActionCombatPositioning::SetCrouching)
        .endClass();
}