#include "../../../core/scripting/generated/classes/GC_OP_SetVectorAttributeToVectorExpression.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetVectorAttributeToVectorExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetVectorAttributeToVectorExpression>("C_OP_SetVectorAttributeToVectorExpression")
        .addProperty("Expression", &GC_OP_SetVectorAttributeToVectorExpression::GetExpression, &GC_OP_SetVectorAttributeToVectorExpression::SetExpression)
        .addProperty("Input1", &GC_OP_SetVectorAttributeToVectorExpression::GetInput1, &GC_OP_SetVectorAttributeToVectorExpression::SetInput1)
        .addProperty("Input2", &GC_OP_SetVectorAttributeToVectorExpression::GetInput2, &GC_OP_SetVectorAttributeToVectorExpression::SetInput2)
        .addProperty("OutputField", &GC_OP_SetVectorAttributeToVectorExpression::GetOutputField, &GC_OP_SetVectorAttributeToVectorExpression::SetOutputField)
        .addProperty("SetMethod", &GC_OP_SetVectorAttributeToVectorExpression::GetSetMethod, &GC_OP_SetVectorAttributeToVectorExpression::SetSetMethod)
        .addProperty("NormalizedOutput", &GC_OP_SetVectorAttributeToVectorExpression::GetNormalizedOutput, &GC_OP_SetVectorAttributeToVectorExpression::SetNormalizedOutput)
        .endClass();
}