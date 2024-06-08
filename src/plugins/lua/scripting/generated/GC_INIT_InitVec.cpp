#include "../../../core/scripting/generated/classes/GC_INIT_InitVec.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitVec(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitVec>("C_INIT_InitVec")
        .addProperty("InputValue", &GC_INIT_InitVec::GetInputValue, &GC_INIT_InitVec::SetInputValue)
        .addProperty("OutputField", &GC_INIT_InitVec::GetOutputField, &GC_INIT_InitVec::SetOutputField)
        .addProperty("SetMethod", &GC_INIT_InitVec::GetSetMethod, &GC_INIT_InitVec::SetSetMethod)
        .addProperty("NormalizedOutput", &GC_INIT_InitVec::GetNormalizedOutput, &GC_INIT_InitVec::SetNormalizedOutput)
        .addProperty("WritePreviousPosition", &GC_INIT_InitVec::GetWritePreviousPosition, &GC_INIT_InitVec::SetWritePreviousPosition)
        .endClass();
}