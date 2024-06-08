#include "../../../core/scripting/generated/classes/GC_OP_QuantizeCPComponent.h"
#include "../core.h"

void SetupLuaClassGC_OP_QuantizeCPComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_QuantizeCPComponent>("C_OP_QuantizeCPComponent")
        .addProperty("InputValue", &GC_OP_QuantizeCPComponent::GetInputValue, &GC_OP_QuantizeCPComponent::SetInputValue)
        .addProperty("CPOutput", &GC_OP_QuantizeCPComponent::GetCPOutput, &GC_OP_QuantizeCPComponent::SetCPOutput)
        .addProperty("OutVectorField", &GC_OP_QuantizeCPComponent::GetOutVectorField, &GC_OP_QuantizeCPComponent::SetOutVectorField)
        .addProperty("QuantizeValue", &GC_OP_QuantizeCPComponent::GetQuantizeValue, &GC_OP_QuantizeCPComponent::SetQuantizeValue)
        .endClass();
}