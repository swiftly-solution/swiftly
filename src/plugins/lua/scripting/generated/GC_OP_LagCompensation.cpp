#include "../../../core/scripting/generated/classes/GC_OP_LagCompensation.h"
#include "../core.h"

void SetupLuaClassGC_OP_LagCompensation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LagCompensation>("C_OP_LagCompensation")
        .addProperty("DesiredVelocityCP", &GC_OP_LagCompensation::GetDesiredVelocityCP, &GC_OP_LagCompensation::SetDesiredVelocityCP)
        .addProperty("LatencyCP", &GC_OP_LagCompensation::GetLatencyCP, &GC_OP_LagCompensation::SetLatencyCP)
        .addProperty("LatencyCPField", &GC_OP_LagCompensation::GetLatencyCPField, &GC_OP_LagCompensation::SetLatencyCPField)
        .addProperty("DesiredVelocityCPField", &GC_OP_LagCompensation::GetDesiredVelocityCPField, &GC_OP_LagCompensation::SetDesiredVelocityCPField)
        .endClass();
}