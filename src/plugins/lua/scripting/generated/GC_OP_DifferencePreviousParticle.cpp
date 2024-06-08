#include "../../../core/scripting/generated/classes/GC_OP_DifferencePreviousParticle.h"
#include "../core.h"

void SetupLuaClassGC_OP_DifferencePreviousParticle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DifferencePreviousParticle>("C_OP_DifferencePreviousParticle")
        .addProperty("FieldInput", &GC_OP_DifferencePreviousParticle::GetFieldInput, &GC_OP_DifferencePreviousParticle::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_DifferencePreviousParticle::GetFieldOutput, &GC_OP_DifferencePreviousParticle::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_DifferencePreviousParticle::GetInputMin, &GC_OP_DifferencePreviousParticle::SetInputMin)
        .addProperty("InputMax", &GC_OP_DifferencePreviousParticle::GetInputMax, &GC_OP_DifferencePreviousParticle::SetInputMax)
        .addProperty("OutputMin", &GC_OP_DifferencePreviousParticle::GetOutputMin, &GC_OP_DifferencePreviousParticle::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_DifferencePreviousParticle::GetOutputMax, &GC_OP_DifferencePreviousParticle::SetOutputMax)
        .addProperty("SetMethod", &GC_OP_DifferencePreviousParticle::GetSetMethod, &GC_OP_DifferencePreviousParticle::SetSetMethod)
        .addProperty("ActiveRange", &GC_OP_DifferencePreviousParticle::GetActiveRange, &GC_OP_DifferencePreviousParticle::SetActiveRange)
        .addProperty("SetPreviousParticle", &GC_OP_DifferencePreviousParticle::GetSetPreviousParticle, &GC_OP_DifferencePreviousParticle::SetSetPreviousParticle)
        .endClass();
}