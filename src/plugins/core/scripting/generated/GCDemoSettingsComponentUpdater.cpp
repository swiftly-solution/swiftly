#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDemoSettingsComponentUpdater::GCDemoSettingsComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDemoSettingsComponentUpdater::GCDemoSettingsComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
GCAnimDemoCaptureSettings GCDemoSettingsComponentUpdater::GetSettings() const {
    GCAnimDemoCaptureSettings value(GetSchemaPtr(m_ptr, "CDemoSettingsComponentUpdater", "m_settings"));
    return value;
}
void GCDemoSettingsComponentUpdater::SetSettings(GCAnimDemoCaptureSettings value) {
    SetSchemaValue(m_ptr, "CDemoSettingsComponentUpdater", "m_settings", false, value);
}
std::string GCDemoSettingsComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDemoSettingsComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCDemoSettingsComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCDemoSettingsComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDemoSettingsComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDemoSettingsComponentUpdater>("CDemoSettingsComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Settings", &GCDemoSettingsComponentUpdater::GetSettings, &GCDemoSettingsComponentUpdater::SetSettings)
        .addProperty("Parent", &GCDemoSettingsComponentUpdater::GetParent, &GCDemoSettingsComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCDemoSettingsComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCDemoSettingsComponentUpdater::IsValid)
        .endClass();
}