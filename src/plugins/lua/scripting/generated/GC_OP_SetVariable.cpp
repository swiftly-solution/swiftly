#include "../../../core/scripting/generated/classes/GC_OP_SetVariable.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetVariable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetVariable>("C_OP_SetVariable")
        .addProperty("TransformInput", &GC_OP_SetVariable::GetTransformInput, &GC_OP_SetVariable::SetTransformInput)
        .addProperty("PositionOffset", &GC_OP_SetVariable::GetPositionOffset, &GC_OP_SetVariable::SetPositionOffset)
        .addProperty("RotationOffset", &GC_OP_SetVariable::GetRotationOffset, &GC_OP_SetVariable::SetRotationOffset)
        .addProperty("FloatInput", &GC_OP_SetVariable::GetFloatInput, &GC_OP_SetVariable::SetFloatInput)
        .endClass();
}