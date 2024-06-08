#include "../../../core/scripting/generated/classes/GRenderInputLayoutField_t.h"
#include "../core.h"

void SetupLuaClassGRenderInputLayoutField_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderInputLayoutField_t>("RenderInputLayoutField_t")
        .addProperty("SemanticName", &GRenderInputLayoutField_t::GetSemanticName, &GRenderInputLayoutField_t::SetSemanticName)
        .addProperty("SemanticIndex", &GRenderInputLayoutField_t::GetSemanticIndex, &GRenderInputLayoutField_t::SetSemanticIndex)
        .addProperty("Format", &GRenderInputLayoutField_t::GetFormat, &GRenderInputLayoutField_t::SetFormat)
        .addProperty("Offset", &GRenderInputLayoutField_t::GetOffset, &GRenderInputLayoutField_t::SetOffset)
        .addProperty("Slot", &GRenderInputLayoutField_t::GetSlot, &GRenderInputLayoutField_t::SetSlot)
        .addProperty("SlotType", &GRenderInputLayoutField_t::GetSlotType, &GRenderInputLayoutField_t::SetSlotType)
        .addProperty("InstanceStepRate", &GRenderInputLayoutField_t::GetInstanceStepRate, &GRenderInputLayoutField_t::SetInstanceStepRate)
        .endClass();
}