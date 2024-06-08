#include "../../../core/scripting/generated/classes/GC_OP_RemapDensityToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDensityToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDensityToVector>("C_OP_RemapDensityToVector")
        .addProperty("RadiusScale", &GC_OP_RemapDensityToVector::GetRadiusScale, &GC_OP_RemapDensityToVector::SetRadiusScale)
        .addProperty("FieldOutput", &GC_OP_RemapDensityToVector::GetFieldOutput, &GC_OP_RemapDensityToVector::SetFieldOutput)
        .addProperty("DensityMin", &GC_OP_RemapDensityToVector::GetDensityMin, &GC_OP_RemapDensityToVector::SetDensityMin)
        .addProperty("DensityMax", &GC_OP_RemapDensityToVector::GetDensityMax, &GC_OP_RemapDensityToVector::SetDensityMax)
        .addProperty("OutputMin", &GC_OP_RemapDensityToVector::GetOutputMin, &GC_OP_RemapDensityToVector::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapDensityToVector::GetOutputMax, &GC_OP_RemapDensityToVector::SetOutputMax)
        .addProperty("UseParentDensity", &GC_OP_RemapDensityToVector::GetUseParentDensity, &GC_OP_RemapDensityToVector::SetUseParentDensity)
        .addProperty("VoxelGridResolution", &GC_OP_RemapDensityToVector::GetVoxelGridResolution, &GC_OP_RemapDensityToVector::SetVoxelGridResolution)
        .endClass();
}