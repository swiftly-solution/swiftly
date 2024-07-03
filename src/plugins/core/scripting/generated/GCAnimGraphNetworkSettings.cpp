#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimGraphNetworkSettings::GCAnimGraphNetworkSettings(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimGraphNetworkSettings::GCAnimGraphNetworkSettings(void *ptr) {
    m_ptr = ptr;
}
bool GCAnimGraphNetworkSettings::GetNetworkingEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimGraphNetworkSettings", "m_bNetworkingEnabled");
}
void GCAnimGraphNetworkSettings::SetNetworkingEnabled(bool value) {
    SetSchemaValue(m_ptr, "CAnimGraphNetworkSettings", "m_bNetworkingEnabled", false, value);
}
std::string GCAnimGraphNetworkSettings::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimGraphNetworkSettings::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimGraphSettingsGroup GCAnimGraphNetworkSettings::GetParent() const {
    GCAnimGraphSettingsGroup value(m_ptr);
    return value;
}
void GCAnimGraphNetworkSettings::SetParent(GCAnimGraphSettingsGroup value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimGraphNetworkSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphNetworkSettings>("CAnimGraphNetworkSettings")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NetworkingEnabled", &GCAnimGraphNetworkSettings::GetNetworkingEnabled, &GCAnimGraphNetworkSettings::SetNetworkingEnabled)
        .addProperty("Parent", &GCAnimGraphNetworkSettings::GetParent, &GCAnimGraphNetworkSettings::SetParent)
        .addFunction("ToPtr", &GCAnimGraphNetworkSettings::ToPtr)
        .addFunction("IsValid", &GCAnimGraphNetworkSettings::IsValid)
        .endClass();
}