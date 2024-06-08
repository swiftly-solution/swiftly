#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToVectorExpression.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToVectorExpression(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToVectorExpression>("C_OP_SetControlPointToVectorExpression")
        .addProperty("Expression", &GC_OP_SetControlPointToVectorExpression::GetExpression, &GC_OP_SetControlPointToVectorExpression::SetExpression)
        .addProperty("OutputCP", &GC_OP_SetControlPointToVectorExpression::GetOutputCP, &GC_OP_SetControlPointToVectorExpression::SetOutputCP)
        .addProperty("NormalizedOutput", &GC_OP_SetControlPointToVectorExpression::GetNormalizedOutput, &GC_OP_SetControlPointToVectorExpression::SetNormalizedOutput)
        .endClass();
}