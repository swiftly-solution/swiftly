#include "../../../core/scripting/generated/classes/GC_INIT_SetVectorAttributeToVectorExpression.h"
#include "../core.h"

void SetupLuaClassGC_INIT_SetVectorAttributeToVectorExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_SetVectorAttributeToVectorExpression>("C_INIT_SetVectorAttributeToVectorExpression")
        .addProperty("Expression", &GC_INIT_SetVectorAttributeToVectorExpression::GetExpression, &GC_INIT_SetVectorAttributeToVectorExpression::SetExpression)
        .addProperty("Input1", &GC_INIT_SetVectorAttributeToVectorExpression::GetInput1, &GC_INIT_SetVectorAttributeToVectorExpression::SetInput1)
        .addProperty("Input2", &GC_INIT_SetVectorAttributeToVectorExpression::GetInput2, &GC_INIT_SetVectorAttributeToVectorExpression::SetInput2)
        .addProperty("OutputField", &GC_INIT_SetVectorAttributeToVectorExpression::GetOutputField, &GC_INIT_SetVectorAttributeToVectorExpression::SetOutputField)
        .addProperty("SetMethod", &GC_INIT_SetVectorAttributeToVectorExpression::GetSetMethod, &GC_INIT_SetVectorAttributeToVectorExpression::SetSetMethod)
        .addProperty("NormalizedOutput", &GC_INIT_SetVectorAttributeToVectorExpression::GetNormalizedOutput, &GC_INIT_SetVectorAttributeToVectorExpression::SetNormalizedOutput)
        .endClass();
}