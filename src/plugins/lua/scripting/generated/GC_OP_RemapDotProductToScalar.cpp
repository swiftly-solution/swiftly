#include "../../../core/scripting/generated/classes/GC_OP_RemapDotProductToScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDotProductToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDotProductToScalar>("C_OP_RemapDotProductToScalar")
        .addProperty("InputCP1", &GC_OP_RemapDotProductToScalar::GetInputCP1, &GC_OP_RemapDotProductToScalar::SetInputCP1)
        .addProperty("InputCP2", &GC_OP_RemapDotProductToScalar::GetInputCP2, &GC_OP_RemapDotProductToScalar::SetInputCP2)
        .addProperty("FieldOutput", &GC_OP_RemapDotProductToScalar::GetFieldOutput, &GC_OP_RemapDotProductToScalar::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapDotProductToScalar::GetInputMin, &GC_OP_RemapDotProductToScalar::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapDotProductToScalar::GetInputMax, &GC_OP_RemapDotProductToScalar::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapDotProductToScalar::GetOutputMin, &GC_OP_RemapDotProductToScalar::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapDotProductToScalar::GetOutputMax, &GC_OP_RemapDotProductToScalar::SetOutputMax)
        .addProperty("UseParticleVelocity", &GC_OP_RemapDotProductToScalar::GetUseParticleVelocity, &GC_OP_RemapDotProductToScalar::SetUseParticleVelocity)
        .addProperty("SetMethod", &GC_OP_RemapDotProductToScalar::GetSetMethod, &GC_OP_RemapDotProductToScalar::SetSetMethod)
        .addProperty("ActiveRange", &GC_OP_RemapDotProductToScalar::GetActiveRange, &GC_OP_RemapDotProductToScalar::SetActiveRange)
        .addProperty("UseParticleNormal", &GC_OP_RemapDotProductToScalar::GetUseParticleNormal, &GC_OP_RemapDotProductToScalar::SetUseParticleNormal)
        .endClass();
}