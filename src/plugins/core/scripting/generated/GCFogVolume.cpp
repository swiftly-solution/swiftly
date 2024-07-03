#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFogVolume::GCFogVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFogVolume::GCFogVolume(void *ptr) {
    m_ptr = ptr;
}
std::string GCFogVolume::GetFogName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFogVolume", "m_fogName").String();
}
void GCFogVolume::SetFogName(std::string value) {
    SetSchemaValue(m_ptr, "CFogVolume", "m_fogName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFogVolume::GetPostProcessName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFogVolume", "m_postProcessName").String();
}
void GCFogVolume::SetPostProcessName(std::string value) {
    SetSchemaValue(m_ptr, "CFogVolume", "m_postProcessName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFogVolume::GetColorCorrectionName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFogVolume", "m_colorCorrectionName").String();
}
void GCFogVolume::SetColorCorrectionName(std::string value) {
    SetSchemaValue(m_ptr, "CFogVolume", "m_colorCorrectionName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCFogVolume::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFogVolume", "m_bDisabled");
}
void GCFogVolume::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CFogVolume", "m_bDisabled", false, value);
}
bool GCFogVolume::GetInFogVolumesList() const {
    return GetSchemaValue<bool>(m_ptr, "CFogVolume", "m_bInFogVolumesList");
}
void GCFogVolume::SetInFogVolumesList(bool value) {
    SetSchemaValue(m_ptr, "CFogVolume", "m_bInFogVolumesList", false, value);
}
std::string GCFogVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFogVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyModelEntity GCFogVolume::GetParent() const {
    GCServerOnlyModelEntity value(m_ptr);
    return value;
}
void GCFogVolume::SetParent(GCServerOnlyModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFogVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFogVolume>("CFogVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FogName", &GCFogVolume::GetFogName, &GCFogVolume::SetFogName)
        .addProperty("PostProcessName", &GCFogVolume::GetPostProcessName, &GCFogVolume::SetPostProcessName)
        .addProperty("ColorCorrectionName", &GCFogVolume::GetColorCorrectionName, &GCFogVolume::SetColorCorrectionName)
        .addProperty("Disabled", &GCFogVolume::GetDisabled, &GCFogVolume::SetDisabled)
        .addProperty("InFogVolumesList", &GCFogVolume::GetInFogVolumesList, &GCFogVolume::SetInFogVolumesList)
        .addProperty("Parent", &GCFogVolume::GetParent, &GCFogVolume::SetParent)
        .addFunction("ToPtr", &GCFogVolume::ToPtr)
        .addFunction("IsValid", &GCFogVolume::IsValid)
        .endClass();
}