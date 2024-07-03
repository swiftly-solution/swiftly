#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRenderInputLayoutField_t::GRenderInputLayoutField_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRenderInputLayoutField_t::GRenderInputLayoutField_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint8_t> GRenderInputLayoutField_t::GetSemanticName() const {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "RenderInputLayoutField_t", "m_pSemanticName"); std::vector<uint8_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRenderInputLayoutField_t::SetSemanticName(std::vector<uint8_t> value) {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "RenderInputLayoutField_t", "m_pSemanticName"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_pSemanticName", true, outValue);
}
int32_t GRenderInputLayoutField_t::GetSemanticIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nSemanticIndex");
}
void GRenderInputLayoutField_t::SetSemanticIndex(int32_t value) {
    SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nSemanticIndex", true, value);
}
uint32_t GRenderInputLayoutField_t::GetFormat() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RenderInputLayoutField_t", "m_Format");
}
void GRenderInputLayoutField_t::SetFormat(uint32_t value) {
    SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_Format", true, value);
}
int32_t GRenderInputLayoutField_t::GetOffset() const {
    return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nOffset");
}
void GRenderInputLayoutField_t::SetOffset(int32_t value) {
    SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nOffset", true, value);
}
int32_t GRenderInputLayoutField_t::GetSlot() const {
    return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nSlot");
}
void GRenderInputLayoutField_t::SetSlot(int32_t value) {
    SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nSlot", true, value);
}
uint64_t GRenderInputLayoutField_t::GetSlotType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "RenderInputLayoutField_t", "m_nSlotType");
}
void GRenderInputLayoutField_t::SetSlotType(uint64_t value) {
    SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nSlotType", true, value);
}
int32_t GRenderInputLayoutField_t::GetInstanceStepRate() const {
    return GetSchemaValue<int32_t>(m_ptr, "RenderInputLayoutField_t", "m_nInstanceStepRate");
}
void GRenderInputLayoutField_t::SetInstanceStepRate(int32_t value) {
    SetSchemaValue(m_ptr, "RenderInputLayoutField_t", "m_nInstanceStepRate", true, value);
}
std::string GRenderInputLayoutField_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRenderInputLayoutField_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRenderInputLayoutField_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderInputLayoutField_t>("RenderInputLayoutField_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SemanticName", &GRenderInputLayoutField_t::GetSemanticName, &GRenderInputLayoutField_t::SetSemanticName)
        .addProperty("SemanticIndex", &GRenderInputLayoutField_t::GetSemanticIndex, &GRenderInputLayoutField_t::SetSemanticIndex)
        .addProperty("Format", &GRenderInputLayoutField_t::GetFormat, &GRenderInputLayoutField_t::SetFormat)
        .addProperty("Offset", &GRenderInputLayoutField_t::GetOffset, &GRenderInputLayoutField_t::SetOffset)
        .addProperty("Slot", &GRenderInputLayoutField_t::GetSlot, &GRenderInputLayoutField_t::SetSlot)
        .addProperty("SlotType", &GRenderInputLayoutField_t::GetSlotType, &GRenderInputLayoutField_t::SetSlotType)
        .addProperty("InstanceStepRate", &GRenderInputLayoutField_t::GetInstanceStepRate, &GRenderInputLayoutField_t::SetInstanceStepRate)
        .addFunction("ToPtr", &GRenderInputLayoutField_t::ToPtr)
        .addFunction("IsValid", &GRenderInputLayoutField_t::IsValid)
        .endClass();
}