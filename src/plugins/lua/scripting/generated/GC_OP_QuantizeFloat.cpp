#include "../../../core/scripting/generated/classes/GC_OP_QuantizeFloat.h"
#include "../core.h"

void SetupLuaClassGC_OP_QuantizeFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_QuantizeFloat>("C_OP_QuantizeFloat")
        .addProperty("InputValue", &GC_OP_QuantizeFloat::GetInputValue, &GC_OP_QuantizeFloat::SetInputValue)
        .addProperty("OutputField", &GC_OP_QuantizeFloat::GetOutputField, &GC_OP_QuantizeFloat::SetOutputField)
        .endClass();
}