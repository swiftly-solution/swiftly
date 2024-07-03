#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCColorCorrectionVolume::GCColorCorrectionVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCColorCorrectionVolume::GCColorCorrectionVolume(void *ptr) {
    m_ptr = ptr;
}
bool GCColorCorrectionVolume::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CColorCorrectionVolume", "m_bEnabled");
}
void GCColorCorrectionVolume::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_bEnabled", false, value);
}
float GCColorCorrectionVolume::GetMaxWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_MaxWeight");
}
void GCColorCorrectionVolume::SetMaxWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_MaxWeight", false, value);
}
float GCColorCorrectionVolume::GetFadeDuration() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_FadeDuration");
}
void GCColorCorrectionVolume::SetFadeDuration(float value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_FadeDuration", false, value);
}
bool GCColorCorrectionVolume::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CColorCorrectionVolume", "m_bStartDisabled");
}
void GCColorCorrectionVolume::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_bStartDisabled", false, value);
}
float GCColorCorrectionVolume::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_Weight");
}
void GCColorCorrectionVolume::SetWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_Weight", false, value);
}
std::string GCColorCorrectionVolume::GetLookupFilename() const {
    return GetSchemaValuePtr<char>(m_ptr, "CColorCorrectionVolume", "m_lookupFilename");
}
void GCColorCorrectionVolume::SetLookupFilename(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CColorCorrectionVolume", "m_lookupFilename", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
float GCColorCorrectionVolume::GetLastEnterWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_LastEnterWeight");
}
void GCColorCorrectionVolume::SetLastEnterWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_LastEnterWeight", false, value);
}
float GCColorCorrectionVolume::GetLastEnterTime() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_LastEnterTime");
}
void GCColorCorrectionVolume::SetLastEnterTime(float value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_LastEnterTime", false, value);
}
float GCColorCorrectionVolume::GetLastExitWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_LastExitWeight");
}
void GCColorCorrectionVolume::SetLastExitWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_LastExitWeight", false, value);
}
float GCColorCorrectionVolume::GetLastExitTime() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrectionVolume", "m_LastExitTime");
}
void GCColorCorrectionVolume::SetLastExitTime(float value) {
    SetSchemaValue(m_ptr, "CColorCorrectionVolume", "m_LastExitTime", false, value);
}
std::string GCColorCorrectionVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCColorCorrectionVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCColorCorrectionVolume::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCColorCorrectionVolume::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCColorCorrectionVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCColorCorrectionVolume>("CColorCorrectionVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCColorCorrectionVolume::GetEnabled, &GCColorCorrectionVolume::SetEnabled)
        .addProperty("MaxWeight", &GCColorCorrectionVolume::GetMaxWeight, &GCColorCorrectionVolume::SetMaxWeight)
        .addProperty("FadeDuration", &GCColorCorrectionVolume::GetFadeDuration, &GCColorCorrectionVolume::SetFadeDuration)
        .addProperty("StartDisabled", &GCColorCorrectionVolume::GetStartDisabled, &GCColorCorrectionVolume::SetStartDisabled)
        .addProperty("Weight", &GCColorCorrectionVolume::GetWeight, &GCColorCorrectionVolume::SetWeight)
        .addProperty("LookupFilename", &GCColorCorrectionVolume::GetLookupFilename, &GCColorCorrectionVolume::SetLookupFilename)
        .addProperty("LastEnterWeight", &GCColorCorrectionVolume::GetLastEnterWeight, &GCColorCorrectionVolume::SetLastEnterWeight)
        .addProperty("LastEnterTime", &GCColorCorrectionVolume::GetLastEnterTime, &GCColorCorrectionVolume::SetLastEnterTime)
        .addProperty("LastExitWeight", &GCColorCorrectionVolume::GetLastExitWeight, &GCColorCorrectionVolume::SetLastExitWeight)
        .addProperty("LastExitTime", &GCColorCorrectionVolume::GetLastExitTime, &GCColorCorrectionVolume::SetLastExitTime)
        .addProperty("Parent", &GCColorCorrectionVolume::GetParent, &GCColorCorrectionVolume::SetParent)
        .addFunction("ToPtr", &GCColorCorrectionVolume::ToPtr)
        .addFunction("IsValid", &GCColorCorrectionVolume::IsValid)
        .endClass();
}