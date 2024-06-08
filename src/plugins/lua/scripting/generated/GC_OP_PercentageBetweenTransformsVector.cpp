#include "../../../core/scripting/generated/classes/GC_OP_PercentageBetweenTransformsVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_PercentageBetweenTransformsVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PercentageBetweenTransformsVector>("C_OP_PercentageBetweenTransformsVector")
        .addProperty("FieldOutput", &GC_OP_PercentageBetweenTransformsVector::GetFieldOutput, &GC_OP_PercentageBetweenTransformsVector::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_PercentageBetweenTransformsVector::GetInputMin, &GC_OP_PercentageBetweenTransformsVector::SetInputMin)
        .addProperty("InputMax", &GC_OP_PercentageBetweenTransformsVector::GetInputMax, &GC_OP_PercentageBetweenTransformsVector::SetInputMax)
        .addProperty("OutputMin", &GC_OP_PercentageBetweenTransformsVector::GetOutputMin, &GC_OP_PercentageBetweenTransformsVector::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_PercentageBetweenTransformsVector::GetOutputMax, &GC_OP_PercentageBetweenTransformsVector::SetOutputMax)
        .addProperty("TransformStart", &GC_OP_PercentageBetweenTransformsVector::GetTransformStart, &GC_OP_PercentageBetweenTransformsVector::SetTransformStart)
        .addProperty("TransformEnd", &GC_OP_PercentageBetweenTransformsVector::GetTransformEnd, &GC_OP_PercentageBetweenTransformsVector::SetTransformEnd)
        .addProperty("SetMethod", &GC_OP_PercentageBetweenTransformsVector::GetSetMethod, &GC_OP_PercentageBetweenTransformsVector::SetSetMethod)
        .addProperty("ActiveRange", &GC_OP_PercentageBetweenTransformsVector::GetActiveRange, &GC_OP_PercentageBetweenTransformsVector::SetActiveRange)
        .addProperty("RadialCheck", &GC_OP_PercentageBetweenTransformsVector::GetRadialCheck, &GC_OP_PercentageBetweenTransformsVector::SetRadialCheck)
        .endClass();
}