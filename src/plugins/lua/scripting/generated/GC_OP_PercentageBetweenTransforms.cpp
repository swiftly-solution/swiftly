#include "../../../core/scripting/generated/classes/GC_OP_PercentageBetweenTransforms.h"
#include "../core.h"

void SetupLuaClassGC_OP_PercentageBetweenTransforms(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PercentageBetweenTransforms>("C_OP_PercentageBetweenTransforms")
        .addProperty("FieldOutput", &GC_OP_PercentageBetweenTransforms::GetFieldOutput, &GC_OP_PercentageBetweenTransforms::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_PercentageBetweenTransforms::GetInputMin, &GC_OP_PercentageBetweenTransforms::SetInputMin)
        .addProperty("InputMax", &GC_OP_PercentageBetweenTransforms::GetInputMax, &GC_OP_PercentageBetweenTransforms::SetInputMax)
        .addProperty("OutputMin", &GC_OP_PercentageBetweenTransforms::GetOutputMin, &GC_OP_PercentageBetweenTransforms::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_PercentageBetweenTransforms::GetOutputMax, &GC_OP_PercentageBetweenTransforms::SetOutputMax)
        .addProperty("TransformStart", &GC_OP_PercentageBetweenTransforms::GetTransformStart, &GC_OP_PercentageBetweenTransforms::SetTransformStart)
        .addProperty("TransformEnd", &GC_OP_PercentageBetweenTransforms::GetTransformEnd, &GC_OP_PercentageBetweenTransforms::SetTransformEnd)
        .addProperty("SetMethod", &GC_OP_PercentageBetweenTransforms::GetSetMethod, &GC_OP_PercentageBetweenTransforms::SetSetMethod)
        .addProperty("ActiveRange", &GC_OP_PercentageBetweenTransforms::GetActiveRange, &GC_OP_PercentageBetweenTransforms::SetActiveRange)
        .addProperty("RadialCheck", &GC_OP_PercentageBetweenTransforms::GetRadialCheck, &GC_OP_PercentageBetweenTransforms::SetRadialCheck)
        .endClass();
}