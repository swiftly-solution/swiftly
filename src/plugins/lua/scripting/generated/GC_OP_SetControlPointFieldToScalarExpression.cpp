#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointFieldToScalarExpression.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointFieldToScalarExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointFieldToScalarExpression>("C_OP_SetControlPointFieldToScalarExpression")
        .addProperty("Expression", &GC_OP_SetControlPointFieldToScalarExpression::GetExpression, &GC_OP_SetControlPointFieldToScalarExpression::SetExpression)
        .addProperty("Input1", &GC_OP_SetControlPointFieldToScalarExpression::GetInput1, &GC_OP_SetControlPointFieldToScalarExpression::SetInput1)
        .addProperty("Input2", &GC_OP_SetControlPointFieldToScalarExpression::GetInput2, &GC_OP_SetControlPointFieldToScalarExpression::SetInput2)
        .addProperty("OutputRemap", &GC_OP_SetControlPointFieldToScalarExpression::GetOutputRemap, &GC_OP_SetControlPointFieldToScalarExpression::SetOutputRemap)
        .addProperty("OutputCP", &GC_OP_SetControlPointFieldToScalarExpression::GetOutputCP, &GC_OP_SetControlPointFieldToScalarExpression::SetOutputCP)
        .addProperty("OutVectorField", &GC_OP_SetControlPointFieldToScalarExpression::GetOutVectorField, &GC_OP_SetControlPointFieldToScalarExpression::SetOutVectorField)
        .endClass();
}