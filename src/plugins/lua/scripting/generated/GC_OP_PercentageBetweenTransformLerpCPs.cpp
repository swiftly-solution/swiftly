#include "../../../core/scripting/generated/classes/GC_OP_PercentageBetweenTransformLerpCPs.h"
#include "../core.h"

void SetupLuaClassGC_OP_PercentageBetweenTransformLerpCPs(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PercentageBetweenTransformLerpCPs>("C_OP_PercentageBetweenTransformLerpCPs")
        .addProperty("FieldOutput", &GC_OP_PercentageBetweenTransformLerpCPs::GetFieldOutput, &GC_OP_PercentageBetweenTransformLerpCPs::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_PercentageBetweenTransformLerpCPs::GetInputMin, &GC_OP_PercentageBetweenTransformLerpCPs::SetInputMin)
        .addProperty("InputMax", &GC_OP_PercentageBetweenTransformLerpCPs::GetInputMax, &GC_OP_PercentageBetweenTransformLerpCPs::SetInputMax)
        .addProperty("TransformStart", &GC_OP_PercentageBetweenTransformLerpCPs::GetTransformStart, &GC_OP_PercentageBetweenTransformLerpCPs::SetTransformStart)
        .addProperty("TransformEnd", &GC_OP_PercentageBetweenTransformLerpCPs::GetTransformEnd, &GC_OP_PercentageBetweenTransformLerpCPs::SetTransformEnd)
        .addProperty("OutputStartCP", &GC_OP_PercentageBetweenTransformLerpCPs::GetOutputStartCP, &GC_OP_PercentageBetweenTransformLerpCPs::SetOutputStartCP)
        .addProperty("OutputStartField", &GC_OP_PercentageBetweenTransformLerpCPs::GetOutputStartField, &GC_OP_PercentageBetweenTransformLerpCPs::SetOutputStartField)
        .addProperty("OutputEndCP", &GC_OP_PercentageBetweenTransformLerpCPs::GetOutputEndCP, &GC_OP_PercentageBetweenTransformLerpCPs::SetOutputEndCP)
        .addProperty("OutputEndField", &GC_OP_PercentageBetweenTransformLerpCPs::GetOutputEndField, &GC_OP_PercentageBetweenTransformLerpCPs::SetOutputEndField)
        .addProperty("SetMethod", &GC_OP_PercentageBetweenTransformLerpCPs::GetSetMethod, &GC_OP_PercentageBetweenTransformLerpCPs::SetSetMethod)
        .addProperty("ActiveRange", &GC_OP_PercentageBetweenTransformLerpCPs::GetActiveRange, &GC_OP_PercentageBetweenTransformLerpCPs::SetActiveRange)
        .addProperty("RadialCheck", &GC_OP_PercentageBetweenTransformLerpCPs::GetRadialCheck, &GC_OP_PercentageBetweenTransformLerpCPs::SetRadialCheck)
        .endClass();
}