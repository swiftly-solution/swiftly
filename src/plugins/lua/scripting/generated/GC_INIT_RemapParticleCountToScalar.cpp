#include "../../../core/scripting/generated/classes/GC_INIT_RemapParticleCountToScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RemapParticleCountToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RemapParticleCountToScalar>("C_INIT_RemapParticleCountToScalar")
        .addProperty("FieldOutput", &GC_INIT_RemapParticleCountToScalar::GetFieldOutput, &GC_INIT_RemapParticleCountToScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_INIT_RemapParticleCountToScalar::GetInputMin, &GC_INIT_RemapParticleCountToScalar::SetInputMin)
        .addProperty("InputMax", &GC_INIT_RemapParticleCountToScalar::GetInputMax, &GC_INIT_RemapParticleCountToScalar::SetInputMax)
        .addProperty("ScaleControlPoint", &GC_INIT_RemapParticleCountToScalar::GetScaleControlPoint, &GC_INIT_RemapParticleCountToScalar::SetScaleControlPoint)
        .addProperty("ScaleControlPointField", &GC_INIT_RemapParticleCountToScalar::GetScaleControlPointField, &GC_INIT_RemapParticleCountToScalar::SetScaleControlPointField)
        .addProperty("OutputMin", &GC_INIT_RemapParticleCountToScalar::GetOutputMin, &GC_INIT_RemapParticleCountToScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_RemapParticleCountToScalar::GetOutputMax, &GC_INIT_RemapParticleCountToScalar::SetOutputMax)
        .addProperty("SetMethod", &GC_INIT_RemapParticleCountToScalar::GetSetMethod, &GC_INIT_RemapParticleCountToScalar::SetSetMethod)
        .addProperty("ActiveRange", &GC_INIT_RemapParticleCountToScalar::GetActiveRange, &GC_INIT_RemapParticleCountToScalar::SetActiveRange)
        .addProperty("Invert", &GC_INIT_RemapParticleCountToScalar::GetInvert, &GC_INIT_RemapParticleCountToScalar::SetInvert)
        .addProperty("Wrap", &GC_INIT_RemapParticleCountToScalar::GetWrap, &GC_INIT_RemapParticleCountToScalar::SetWrap)
        .addProperty("RemapBias", &GC_INIT_RemapParticleCountToScalar::GetRemapBias, &GC_INIT_RemapParticleCountToScalar::SetRemapBias)
        .endClass();
}