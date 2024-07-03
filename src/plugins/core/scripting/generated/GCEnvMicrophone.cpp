#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvMicrophone::GCEnvMicrophone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvMicrophone::GCEnvMicrophone(void *ptr) {
    m_ptr = ptr;
}
bool GCEnvMicrophone::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvMicrophone", "m_bDisabled");
}
void GCEnvMicrophone::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_bDisabled", false, value);
}
GCBaseEntity GCEnvMicrophone::GetMeasureTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvMicrophone", "m_hMeasureTarget"));
    return value;
}
void GCEnvMicrophone::SetMeasureTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureTarget' is not possible.\n");
}
uint64_t GCEnvMicrophone::GetSoundType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CEnvMicrophone", "m_nSoundType");
}
void GCEnvMicrophone::SetSoundType(uint64_t value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_nSoundType", false, value);
}
uint64_t GCEnvMicrophone::GetSoundFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CEnvMicrophone", "m_nSoundFlags");
}
void GCEnvMicrophone::SetSoundFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_nSoundFlags", false, value);
}
float GCEnvMicrophone::GetSensitivity() const {
    return GetSchemaValue<float>(m_ptr, "CEnvMicrophone", "m_flSensitivity");
}
void GCEnvMicrophone::SetSensitivity(float value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_flSensitivity", false, value);
}
float GCEnvMicrophone::GetSmoothFactor() const {
    return GetSchemaValue<float>(m_ptr, "CEnvMicrophone", "m_flSmoothFactor");
}
void GCEnvMicrophone::SetSmoothFactor(float value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_flSmoothFactor", false, value);
}
float GCEnvMicrophone::GetMaxRange() const {
    return GetSchemaValue<float>(m_ptr, "CEnvMicrophone", "m_flMaxRange");
}
void GCEnvMicrophone::SetMaxRange(float value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_flMaxRange", false, value);
}
std::string GCEnvMicrophone::GetSpeakerName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvMicrophone", "m_iszSpeakerName").String();
}
void GCEnvMicrophone::SetSpeakerName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iszSpeakerName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCEnvMicrophone::GetSpeaker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvMicrophone", "m_hSpeaker"));
    return value;
}
void GCEnvMicrophone::SetSpeaker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Speaker' is not possible.\n");
}
bool GCEnvMicrophone::GetAvoidFeedback() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvMicrophone", "m_bAvoidFeedback");
}
void GCEnvMicrophone::SetAvoidFeedback(bool value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_bAvoidFeedback", false, value);
}
int32_t GCEnvMicrophone::GetSpeakerDSPPreset() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvMicrophone", "m_iSpeakerDSPPreset");
}
void GCEnvMicrophone::SetSpeakerDSPPreset(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iSpeakerDSPPreset", false, value);
}
std::string GCEnvMicrophone::GetListenFilter() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvMicrophone", "m_iszListenFilter").String();
}
void GCEnvMicrophone::SetListenFilter(std::string value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iszListenFilter", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFilter GCEnvMicrophone::GetListenFilter1() const {
    GCBaseFilter value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvMicrophone", "m_hListenFilter"));
    return value;
}
void GCEnvMicrophone::SetListenFilter1(GCBaseFilter* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ListenFilter1' is not possible.\n");
}
GCEntityIOOutput GCEnvMicrophone::GetOnRoutedSound() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvMicrophone", "m_OnRoutedSound"));
    return value;
}
void GCEnvMicrophone::SetOnRoutedSound(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_OnRoutedSound", false, value);
}
GCEntityIOOutput GCEnvMicrophone::GetOnHeardSound() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvMicrophone", "m_OnHeardSound"));
    return value;
}
void GCEnvMicrophone::SetOnHeardSound(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_OnHeardSound", false, value);
}
std::string GCEnvMicrophone::GetLastSound() const {
    return GetSchemaValuePtr<char>(m_ptr, "CEnvMicrophone", "m_szLastSound");
}
void GCEnvMicrophone::SetLastSound(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CEnvMicrophone", "m_szLastSound", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 256);
}
int32_t GCEnvMicrophone::GetLastRoutedFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvMicrophone", "m_iLastRoutedFrame");
}
void GCEnvMicrophone::SetLastRoutedFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvMicrophone", "m_iLastRoutedFrame", false, value);
}
std::string GCEnvMicrophone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvMicrophone::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvMicrophone::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvMicrophone::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvMicrophone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvMicrophone>("CEnvMicrophone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCEnvMicrophone::GetDisabled, &GCEnvMicrophone::SetDisabled)
        .addProperty("MeasureTarget", &GCEnvMicrophone::GetMeasureTarget, &GCEnvMicrophone::SetMeasureTarget)
        .addProperty("SoundType", &GCEnvMicrophone::GetSoundType, &GCEnvMicrophone::SetSoundType)
        .addProperty("SoundFlags", &GCEnvMicrophone::GetSoundFlags, &GCEnvMicrophone::SetSoundFlags)
        .addProperty("Sensitivity", &GCEnvMicrophone::GetSensitivity, &GCEnvMicrophone::SetSensitivity)
        .addProperty("SmoothFactor", &GCEnvMicrophone::GetSmoothFactor, &GCEnvMicrophone::SetSmoothFactor)
        .addProperty("MaxRange", &GCEnvMicrophone::GetMaxRange, &GCEnvMicrophone::SetMaxRange)
        .addProperty("SpeakerName", &GCEnvMicrophone::GetSpeakerName, &GCEnvMicrophone::SetSpeakerName)
        .addProperty("Speaker", &GCEnvMicrophone::GetSpeaker, &GCEnvMicrophone::SetSpeaker)
        .addProperty("AvoidFeedback", &GCEnvMicrophone::GetAvoidFeedback, &GCEnvMicrophone::SetAvoidFeedback)
        .addProperty("SpeakerDSPPreset", &GCEnvMicrophone::GetSpeakerDSPPreset, &GCEnvMicrophone::SetSpeakerDSPPreset)
        .addProperty("ListenFilter", &GCEnvMicrophone::GetListenFilter, &GCEnvMicrophone::SetListenFilter)
        .addProperty("ListenFilter1", &GCEnvMicrophone::GetListenFilter1, &GCEnvMicrophone::SetListenFilter1)
        .addProperty("OnRoutedSound", &GCEnvMicrophone::GetOnRoutedSound, &GCEnvMicrophone::SetOnRoutedSound)
        .addProperty("OnHeardSound", &GCEnvMicrophone::GetOnHeardSound, &GCEnvMicrophone::SetOnHeardSound)
        .addProperty("LastSound", &GCEnvMicrophone::GetLastSound, &GCEnvMicrophone::SetLastSound)
        .addProperty("LastRoutedFrame", &GCEnvMicrophone::GetLastRoutedFrame, &GCEnvMicrophone::SetLastRoutedFrame)
        .addProperty("Parent", &GCEnvMicrophone::GetParent, &GCEnvMicrophone::SetParent)
        .addFunction("ToPtr", &GCEnvMicrophone::ToPtr)
        .addFunction("IsValid", &GCEnvMicrophone::IsValid)
        .endClass();
}