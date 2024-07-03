#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEconItemAttribute::GCEconItemAttribute(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEconItemAttribute::GCEconItemAttribute(void *ptr) {
    m_ptr = ptr;
}
uint16_t GCEconItemAttribute::GetAttributeDefinitionIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEconItemAttribute", "m_iAttributeDefinitionIndex");
}
void GCEconItemAttribute::SetAttributeDefinitionIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CEconItemAttribute", "m_iAttributeDefinitionIndex", false, value);
}
float GCEconItemAttribute::GetValue() const {
    return GetSchemaValue<float>(m_ptr, "CEconItemAttribute", "m_flValue");
}
void GCEconItemAttribute::SetValue(float value) {
    SetSchemaValue(m_ptr, "CEconItemAttribute", "m_flValue", false, value);
}
float GCEconItemAttribute::GetInitialValue() const {
    return GetSchemaValue<float>(m_ptr, "CEconItemAttribute", "m_flInitialValue");
}
void GCEconItemAttribute::SetInitialValue(float value) {
    SetSchemaValue(m_ptr, "CEconItemAttribute", "m_flInitialValue", false, value);
}
int32_t GCEconItemAttribute::GetRefundableCurrency() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEconItemAttribute", "m_nRefundableCurrency");
}
void GCEconItemAttribute::SetRefundableCurrency(int32_t value) {
    SetSchemaValue(m_ptr, "CEconItemAttribute", "m_nRefundableCurrency", false, value);
}
bool GCEconItemAttribute::GetSetBonus() const {
    return GetSchemaValue<bool>(m_ptr, "CEconItemAttribute", "m_bSetBonus");
}
void GCEconItemAttribute::SetSetBonus(bool value) {
    SetSchemaValue(m_ptr, "CEconItemAttribute", "m_bSetBonus", false, value);
}
std::string GCEconItemAttribute::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEconItemAttribute::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEconItemAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconItemAttribute>("CEconItemAttribute")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttributeDefinitionIndex", &GCEconItemAttribute::GetAttributeDefinitionIndex, &GCEconItemAttribute::SetAttributeDefinitionIndex)
        .addProperty("Value", &GCEconItemAttribute::GetValue, &GCEconItemAttribute::SetValue)
        .addProperty("InitialValue", &GCEconItemAttribute::GetInitialValue, &GCEconItemAttribute::SetInitialValue)
        .addProperty("RefundableCurrency", &GCEconItemAttribute::GetRefundableCurrency, &GCEconItemAttribute::SetRefundableCurrency)
        .addProperty("SetBonus", &GCEconItemAttribute::GetSetBonus, &GCEconItemAttribute::SetSetBonus)
        .addFunction("ToPtr", &GCEconItemAttribute::ToPtr)
        .addFunction("IsValid", &GCEconItemAttribute::IsValid)
        .endClass();
}