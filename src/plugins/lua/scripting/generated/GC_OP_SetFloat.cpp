#include "../../../core/scripting/generated/classes/GC_OP_SetFloat.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetFloat>("C_OP_SetFloat")
        .addProperty("InputValue", &GC_OP_SetFloat::GetInputValue, &GC_OP_SetFloat::SetInputValue)
        .addProperty("OutputField", &GC_OP_SetFloat::GetOutputField, &GC_OP_SetFloat::SetOutputField)
        .addProperty("SetMethod", &GC_OP_SetFloat::GetSetMethod, &GC_OP_SetFloat::SetSetMethod)
        .addProperty("Lerp", &GC_OP_SetFloat::GetLerp, &GC_OP_SetFloat::SetLerp)
        .endClass();
}