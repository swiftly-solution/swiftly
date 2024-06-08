#include "../../../core/scripting/generated/classes/GC_OP_RemapDensityGradientToVectorAttribute.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDensityGradientToVectorAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDensityGradientToVectorAttribute>("C_OP_RemapDensityGradientToVectorAttribute")
        .addProperty("RadiusScale", &GC_OP_RemapDensityGradientToVectorAttribute::GetRadiusScale, &GC_OP_RemapDensityGradientToVectorAttribute::SetRadiusScale)
        .addProperty("FieldOutput", &GC_OP_RemapDensityGradientToVectorAttribute::GetFieldOutput, &GC_OP_RemapDensityGradientToVectorAttribute::SetFieldOutput)
        .endClass();
}