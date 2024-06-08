#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointFieldFromVectorExpression.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointFieldFromVectorExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointFieldFromVectorExpression>("C_OP_SetControlPointFieldFromVectorExpression")
        .addProperty("Expression", &GC_OP_SetControlPointFieldFromVectorExpression::GetExpression, &GC_OP_SetControlPointFieldFromVectorExpression::SetExpression)
        .addProperty("OutputRemap", &GC_OP_SetControlPointFieldFromVectorExpression::GetOutputRemap, &GC_OP_SetControlPointFieldFromVectorExpression::SetOutputRemap)
        .addProperty("OutputCP", &GC_OP_SetControlPointFieldFromVectorExpression::GetOutputCP, &GC_OP_SetControlPointFieldFromVectorExpression::SetOutputCP)
        .addProperty("OutVectorField", &GC_OP_SetControlPointFieldFromVectorExpression::GetOutVectorField, &GC_OP_SetControlPointFieldFromVectorExpression::SetOutVectorField)
        .endClass();
}