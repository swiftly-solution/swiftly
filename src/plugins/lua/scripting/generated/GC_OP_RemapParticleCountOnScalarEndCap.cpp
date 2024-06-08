#include "../../../core/scripting/generated/classes/GC_OP_RemapParticleCountOnScalarEndCap.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapParticleCountOnScalarEndCap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapParticleCountOnScalarEndCap>("C_OP_RemapParticleCountOnScalarEndCap")
        .addProperty("FieldOutput", &GC_OP_RemapParticleCountOnScalarEndCap::GetFieldOutput, &GC_OP_RemapParticleCountOnScalarEndCap::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapParticleCountOnScalarEndCap::GetInputMin, &GC_OP_RemapParticleCountOnScalarEndCap::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapParticleCountOnScalarEndCap::GetInputMax, &GC_OP_RemapParticleCountOnScalarEndCap::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapParticleCountOnScalarEndCap::GetOutputMin, &GC_OP_RemapParticleCountOnScalarEndCap::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapParticleCountOnScalarEndCap::GetOutputMax, &GC_OP_RemapParticleCountOnScalarEndCap::SetOutputMax)
        .addProperty("Backwards", &GC_OP_RemapParticleCountOnScalarEndCap::GetBackwards, &GC_OP_RemapParticleCountOnScalarEndCap::SetBackwards)
        .addProperty("SetMethod", &GC_OP_RemapParticleCountOnScalarEndCap::GetSetMethod, &GC_OP_RemapParticleCountOnScalarEndCap::SetSetMethod)
        .endClass();
}