#include "../../../core/scripting/generated/classes/GC_OP_RemapParticleCountToScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapParticleCountToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapParticleCountToScalar>("C_OP_RemapParticleCountToScalar")
        .addProperty("FieldOutput", &GC_OP_RemapParticleCountToScalar::GetFieldOutput, &GC_OP_RemapParticleCountToScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapParticleCountToScalar::GetInputMin, &GC_OP_RemapParticleCountToScalar::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapParticleCountToScalar::GetInputMax, &GC_OP_RemapParticleCountToScalar::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapParticleCountToScalar::GetOutputMin, &GC_OP_RemapParticleCountToScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapParticleCountToScalar::GetOutputMax, &GC_OP_RemapParticleCountToScalar::SetOutputMax)
        .addProperty("ActiveRange", &GC_OP_RemapParticleCountToScalar::GetActiveRange, &GC_OP_RemapParticleCountToScalar::SetActiveRange)
        .addProperty("SetMethod", &GC_OP_RemapParticleCountToScalar::GetSetMethod, &GC_OP_RemapParticleCountToScalar::SetSetMethod)
        .endClass();
}