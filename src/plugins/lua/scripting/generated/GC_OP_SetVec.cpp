#include "../../../core/scripting/generated/classes/GC_OP_SetVec.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetVec(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetVec>("C_OP_SetVec")
        .addProperty("InputValue", &GC_OP_SetVec::GetInputValue, &GC_OP_SetVec::SetInputValue)
        .addProperty("OutputField", &GC_OP_SetVec::GetOutputField, &GC_OP_SetVec::SetOutputField)
        .addProperty("SetMethod", &GC_OP_SetVec::GetSetMethod, &GC_OP_SetVec::SetSetMethod)
        .addProperty("Lerp", &GC_OP_SetVec::GetLerp, &GC_OP_SetVec::SetLerp)
        .addProperty("NormalizedOutput", &GC_OP_SetVec::GetNormalizedOutput, &GC_OP_SetVec::SetNormalizedOutput)
        .endClass();
}