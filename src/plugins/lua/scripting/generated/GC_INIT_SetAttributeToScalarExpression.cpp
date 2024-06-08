#include "../../../core/scripting/generated/classes/GC_INIT_SetAttributeToScalarExpression.h"
#include "../core.h"

void SetupLuaClassGC_INIT_SetAttributeToScalarExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_SetAttributeToScalarExpression>("C_INIT_SetAttributeToScalarExpression")
        .addProperty("Expression", &GC_INIT_SetAttributeToScalarExpression::GetExpression, &GC_INIT_SetAttributeToScalarExpression::SetExpression)
        .addProperty("Input1", &GC_INIT_SetAttributeToScalarExpression::GetInput1, &GC_INIT_SetAttributeToScalarExpression::SetInput1)
        .addProperty("Input2", &GC_INIT_SetAttributeToScalarExpression::GetInput2, &GC_INIT_SetAttributeToScalarExpression::SetInput2)
        .addProperty("OutputRemap", &GC_INIT_SetAttributeToScalarExpression::GetOutputRemap, &GC_INIT_SetAttributeToScalarExpression::SetOutputRemap)
        .addProperty("OutputField", &GC_INIT_SetAttributeToScalarExpression::GetOutputField, &GC_INIT_SetAttributeToScalarExpression::SetOutputField)
        .addProperty("SetMethod", &GC_INIT_SetAttributeToScalarExpression::GetSetMethod, &GC_INIT_SetAttributeToScalarExpression::SetSetMethod)
        .endClass();
}