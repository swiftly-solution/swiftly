#include "../../../core/scripting/generated/classes/GC_OP_SetAttributeToScalarExpression.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetAttributeToScalarExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetAttributeToScalarExpression>("C_OP_SetAttributeToScalarExpression")
        .addProperty("Expression", &GC_OP_SetAttributeToScalarExpression::GetExpression, &GC_OP_SetAttributeToScalarExpression::SetExpression)
        .addProperty("Input1", &GC_OP_SetAttributeToScalarExpression::GetInput1, &GC_OP_SetAttributeToScalarExpression::SetInput1)
        .addProperty("Input2", &GC_OP_SetAttributeToScalarExpression::GetInput2, &GC_OP_SetAttributeToScalarExpression::SetInput2)
        .addProperty("OutputRemap", &GC_OP_SetAttributeToScalarExpression::GetOutputRemap, &GC_OP_SetAttributeToScalarExpression::SetOutputRemap)
        .addProperty("OutputField", &GC_OP_SetAttributeToScalarExpression::GetOutputField, &GC_OP_SetAttributeToScalarExpression::SetOutputField)
        .addProperty("SetMethod", &GC_OP_SetAttributeToScalarExpression::GetSetMethod, &GC_OP_SetAttributeToScalarExpression::SetSetMethod)
        .endClass();
}