#include "../../../core/scripting/generated/classes/GC_OP_DensityForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_DensityForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DensityForce>("C_OP_DensityForce")
        .addProperty("RadiusScale", &GC_OP_DensityForce::GetRadiusScale, &GC_OP_DensityForce::SetRadiusScale)
        .addProperty("ForceScale", &GC_OP_DensityForce::GetForceScale, &GC_OP_DensityForce::SetForceScale)
        .addProperty("TargetDensity", &GC_OP_DensityForce::GetTargetDensity, &GC_OP_DensityForce::SetTargetDensity)
        .endClass();
}