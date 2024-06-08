#include "../../../core/scripting/generated/classes/GC_OP_RopeSpringConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_RopeSpringConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RopeSpringConstraint>("C_OP_RopeSpringConstraint")
        .addProperty("RestLength", &GC_OP_RopeSpringConstraint::GetRestLength, &GC_OP_RopeSpringConstraint::SetRestLength)
        .addProperty("MinDistance", &GC_OP_RopeSpringConstraint::GetMinDistance, &GC_OP_RopeSpringConstraint::SetMinDistance)
        .addProperty("MaxDistance", &GC_OP_RopeSpringConstraint::GetMaxDistance, &GC_OP_RopeSpringConstraint::SetMaxDistance)
        .addProperty("AdjustmentScale", &GC_OP_RopeSpringConstraint::GetAdjustmentScale, &GC_OP_RopeSpringConstraint::SetAdjustmentScale)
        .addProperty("InitialRestingLength", &GC_OP_RopeSpringConstraint::GetInitialRestingLength, &GC_OP_RopeSpringConstraint::SetInitialRestingLength)
        .endClass();
}