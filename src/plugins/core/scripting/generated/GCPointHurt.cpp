#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointHurt::GCPointHurt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointHurt::GCPointHurt(void *ptr) {
    m_ptr = ptr;
}
int32_t GCPointHurt::GetDamage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPointHurt", "m_nDamage");
}
void GCPointHurt::SetDamage(int32_t value) {
    SetSchemaValue(m_ptr, "CPointHurt", "m_nDamage", false, value);
}
int32_t GCPointHurt::GetBitsDamageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPointHurt", "m_bitsDamageType");
}
void GCPointHurt::SetBitsDamageType(int32_t value) {
    SetSchemaValue(m_ptr, "CPointHurt", "m_bitsDamageType", false, value);
}
float GCPointHurt::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPointHurt", "m_flRadius");
}
void GCPointHurt::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CPointHurt", "m_flRadius", false, value);
}
float GCPointHurt::GetDelay() const {
    return GetSchemaValue<float>(m_ptr, "CPointHurt", "m_flDelay");
}
void GCPointHurt::SetDelay(float value) {
    SetSchemaValue(m_ptr, "CPointHurt", "m_flDelay", false, value);
}
std::string GCPointHurt::GetStrTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointHurt", "m_strTarget").String();
}
void GCPointHurt::SetStrTarget(std::string value) {
    SetSchemaValue(m_ptr, "CPointHurt", "m_strTarget", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCPointHurt::GetActivator() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointHurt", "m_pActivator"));
    return value;
}
void GCPointHurt::SetActivator(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n");
}
std::string GCPointHurt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointHurt::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointHurt::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointHurt::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointHurt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointHurt>("CPointHurt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Damage", &GCPointHurt::GetDamage, &GCPointHurt::SetDamage)
        .addProperty("BitsDamageType", &GCPointHurt::GetBitsDamageType, &GCPointHurt::SetBitsDamageType)
        .addProperty("Radius", &GCPointHurt::GetRadius, &GCPointHurt::SetRadius)
        .addProperty("Delay", &GCPointHurt::GetDelay, &GCPointHurt::SetDelay)
        .addProperty("StrTarget", &GCPointHurt::GetStrTarget, &GCPointHurt::SetStrTarget)
        .addProperty("Activator", &GCPointHurt::GetActivator, &GCPointHurt::SetActivator)
        .addProperty("Parent", &GCPointHurt::GetParent, &GCPointHurt::SetParent)
        .addFunction("ToPtr", &GCPointHurt::ToPtr)
        .addFunction("IsValid", &GCPointHurt::IsValid)
        .endClass();
}