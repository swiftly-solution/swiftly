#include "../../../core/scripting/generated/classes/GCLogicNPCCounterAABB.h"
#include "../core.h"

void SetupLuaClassGCLogicNPCCounterAABB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicNPCCounterAABB>("CLogicNPCCounterAABB")
        .addProperty("DistanceOuterMins", &GCLogicNPCCounterAABB::GetDistanceOuterMins, &GCLogicNPCCounterAABB::SetDistanceOuterMins)
        .addProperty("DistanceOuterMaxs", &GCLogicNPCCounterAABB::GetDistanceOuterMaxs, &GCLogicNPCCounterAABB::SetDistanceOuterMaxs)
        .addProperty("OuterMins", &GCLogicNPCCounterAABB::GetOuterMins, &GCLogicNPCCounterAABB::SetOuterMins)
        .addProperty("OuterMaxs", &GCLogicNPCCounterAABB::GetOuterMaxs, &GCLogicNPCCounterAABB::SetOuterMaxs)
        .endClass();
}