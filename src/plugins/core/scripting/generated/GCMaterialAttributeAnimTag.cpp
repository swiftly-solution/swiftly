#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMaterialAttributeAnimTag::GCMaterialAttributeAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMaterialAttributeAnimTag::GCMaterialAttributeAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCMaterialAttributeAnimTag::GetAttributeName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeName").Get();
}
void GCMaterialAttributeAnimTag::SetAttributeName(std::string value) {
    SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeName", false, CUtlString(value.c_str()));
}
uint64_t GCMaterialAttributeAnimTag::GetAttributeType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeType");
}
void GCMaterialAttributeAnimTag::SetAttributeType(uint64_t value) {
    SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_AttributeType", false, value);
}
float GCMaterialAttributeAnimTag::GetValue() const {
    return GetSchemaValue<float>(m_ptr, "CMaterialAttributeAnimTag", "m_flValue");
}
void GCMaterialAttributeAnimTag::SetValue(float value) {
    SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_flValue", false, value);
}
Color GCMaterialAttributeAnimTag::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CMaterialAttributeAnimTag", "m_Color");
}
void GCMaterialAttributeAnimTag::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CMaterialAttributeAnimTag", "m_Color", false, value);
}
std::string GCMaterialAttributeAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMaterialAttributeAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCMaterialAttributeAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCMaterialAttributeAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMaterialAttributeAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMaterialAttributeAnimTag>("CMaterialAttributeAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttributeName", &GCMaterialAttributeAnimTag::GetAttributeName, &GCMaterialAttributeAnimTag::SetAttributeName)
        .addProperty("AttributeType", &GCMaterialAttributeAnimTag::GetAttributeType, &GCMaterialAttributeAnimTag::SetAttributeType)
        .addProperty("Value", &GCMaterialAttributeAnimTag::GetValue, &GCMaterialAttributeAnimTag::SetValue)
        .addProperty("Color", &GCMaterialAttributeAnimTag::GetColor, &GCMaterialAttributeAnimTag::SetColor)
        .addProperty("Parent", &GCMaterialAttributeAnimTag::GetParent, &GCMaterialAttributeAnimTag::SetParent)
        .addFunction("ToPtr", &GCMaterialAttributeAnimTag::ToPtr)
        .addFunction("IsValid", &GCMaterialAttributeAnimTag::IsValid)
        .endClass();
}