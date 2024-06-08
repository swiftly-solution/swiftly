#include "../../../core/scripting/generated/classes/GCLogicDistanceCheck.h"
#include "../core.h"

void SetupLuaClassGCLogicDistanceCheck(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicDistanceCheck>("CLogicDistanceCheck")
        .addProperty("EntityA", &GCLogicDistanceCheck::GetEntityA, &GCLogicDistanceCheck::SetEntityA)
        .addProperty("EntityB", &GCLogicDistanceCheck::GetEntityB, &GCLogicDistanceCheck::SetEntityB)
        .addProperty("Zone1Distance", &GCLogicDistanceCheck::GetZone1Distance, &GCLogicDistanceCheck::SetZone1Distance)
        .addProperty("Zone2Distance", &GCLogicDistanceCheck::GetZone2Distance, &GCLogicDistanceCheck::SetZone2Distance)
        .addProperty("InZone1", &GCLogicDistanceCheck::GetInZone1, &GCLogicDistanceCheck::SetInZone1)
        .addProperty("InZone2", &GCLogicDistanceCheck::GetInZone2, &GCLogicDistanceCheck::SetInZone2)
        .addProperty("InZone3", &GCLogicDistanceCheck::GetInZone3, &GCLogicDistanceCheck::SetInZone3)
        .endClass();
}