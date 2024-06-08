#include "../../../core/scripting/generated/classes/GC_OP_SDFConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_SDFConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SDFConstraint>("C_OP_SDFConstraint")
        .addProperty("MinDist", &GC_OP_SDFConstraint::GetMinDist, &GC_OP_SDFConstraint::SetMinDist)
        .addProperty("MaxDist", &GC_OP_SDFConstraint::GetMaxDist, &GC_OP_SDFConstraint::SetMaxDist)
        .addProperty("MaxIterations", &GC_OP_SDFConstraint::GetMaxIterations, &GC_OP_SDFConstraint::SetMaxIterations)
        .endClass();
}