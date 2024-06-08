#include "../../../core/scripting/generated/classes/GC_OP_SetFloatAttributeToVectorExpression.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetFloatAttributeToVectorExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetFloatAttributeToVectorExpression>("C_OP_SetFloatAttributeToVectorExpression")
        .addProperty("Expression", &GC_OP_SetFloatAttributeToVectorExpression::GetExpression, &GC_OP_SetFloatAttributeToVectorExpression::SetExpression)
        .addProperty("Input1", &GC_OP_SetFloatAttributeToVectorExpression::GetInput1, &GC_OP_SetFloatAttributeToVectorExpression::SetInput1)
        .addProperty("Input2", &GC_OP_SetFloatAttributeToVectorExpression::GetInput2, &GC_OP_SetFloatAttributeToVectorExpression::SetInput2)
        .addProperty("OutputRemap", &GC_OP_SetFloatAttributeToVectorExpression::GetOutputRemap, &GC_OP_SetFloatAttributeToVectorExpression::SetOutputRemap)
        .addProperty("OutputField", &GC_OP_SetFloatAttributeToVectorExpression::GetOutputField, &GC_OP_SetFloatAttributeToVectorExpression::SetOutputField)
        .addProperty("SetMethod", &GC_OP_SetFloatAttributeToVectorExpression::GetSetMethod, &GC_OP_SetFloatAttributeToVectorExpression::SetSetMethod)
        .endClass();
}