#include "../../../core/scripting/generated/classes/GC_OP_SpringToVectorConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_SpringToVectorConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SpringToVectorConstraint>("C_OP_SpringToVectorConstraint")
        .addProperty("RestLength", &GC_OP_SpringToVectorConstraint::GetRestLength, &GC_OP_SpringToVectorConstraint::SetRestLength)
        .addProperty("MinDistance", &GC_OP_SpringToVectorConstraint::GetMinDistance, &GC_OP_SpringToVectorConstraint::SetMinDistance)
        .addProperty("MaxDistance", &GC_OP_SpringToVectorConstraint::GetMaxDistance, &GC_OP_SpringToVectorConstraint::SetMaxDistance)
        .addProperty("RestingLength", &GC_OP_SpringToVectorConstraint::GetRestingLength, &GC_OP_SpringToVectorConstraint::SetRestingLength)
        .addProperty("AnchorVector", &GC_OP_SpringToVectorConstraint::GetAnchorVector, &GC_OP_SpringToVectorConstraint::SetAnchorVector)
        .endClass();
}