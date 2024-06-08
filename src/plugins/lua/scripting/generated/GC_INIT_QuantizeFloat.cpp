#include "../../../core/scripting/generated/classes/GC_INIT_QuantizeFloat.h"
#include "../core.h"

void SetupLuaClassGC_INIT_QuantizeFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_QuantizeFloat>("C_INIT_QuantizeFloat")
        .addProperty("InputValue", &GC_INIT_QuantizeFloat::GetInputValue, &GC_INIT_QuantizeFloat::SetInputValue)
        .addProperty("OutputField", &GC_INIT_QuantizeFloat::GetOutputField, &GC_INIT_QuantizeFloat::SetOutputField)
        .endClass();
}