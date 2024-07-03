#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvFireSource::GCEnvFireSource(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvFireSource::GCEnvFireSource(void *ptr) {
    m_ptr = ptr;
}
bool GCEnvFireSource::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvFireSource", "m_bEnabled");
}
void GCEnvFireSource::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvFireSource", "m_bEnabled", false, value);
}
float GCEnvFireSource::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFireSource", "m_radius");
}
void GCEnvFireSource::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvFireSource", "m_radius", false, value);
}
float GCEnvFireSource::GetDamage() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFireSource", "m_damage");
}
void GCEnvFireSource::SetDamage(float value) {
    SetSchemaValue(m_ptr, "CEnvFireSource", "m_damage", false, value);
}
std::string GCEnvFireSource::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvFireSource::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvFireSource::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvFireSource::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvFireSource(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFireSource>("CEnvFireSource")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCEnvFireSource::GetEnabled, &GCEnvFireSource::SetEnabled)
        .addProperty("Radius", &GCEnvFireSource::GetRadius, &GCEnvFireSource::SetRadius)
        .addProperty("Damage", &GCEnvFireSource::GetDamage, &GCEnvFireSource::SetDamage)
        .addProperty("Parent", &GCEnvFireSource::GetParent, &GCEnvFireSource::SetParent)
        .addFunction("ToPtr", &GCEnvFireSource::ToPtr)
        .addFunction("IsValid", &GCEnvFireSource::IsValid)
        .endClass();
}