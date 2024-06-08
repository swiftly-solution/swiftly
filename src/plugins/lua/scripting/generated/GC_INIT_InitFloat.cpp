#include "../../../core/scripting/generated/classes/GC_INIT_InitFloat.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitFloat>("C_INIT_InitFloat")
        .addProperty("InputValue", &GC_INIT_InitFloat::GetInputValue, &GC_INIT_InitFloat::SetInputValue)
        .addProperty("OutputField", &GC_INIT_InitFloat::GetOutputField, &GC_INIT_InitFloat::SetOutputField)
        .addProperty("SetMethod", &GC_INIT_InitFloat::GetSetMethod, &GC_INIT_InitFloat::SetSetMethod)
        .addProperty("InputStrength", &GC_INIT_InitFloat::GetInputStrength, &GC_INIT_InitFloat::SetInputStrength)
        .endClass();
}