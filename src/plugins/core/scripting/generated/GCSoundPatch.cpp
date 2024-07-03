#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundPatch::GCSoundPatch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundPatch::GCSoundPatch(void *ptr) {
    m_ptr = ptr;
}
GCSoundEnvelope GCSoundPatch::GetPitch() const {
    GCSoundEnvelope value(GetSchemaPtr(m_ptr, "CSoundPatch", "m_pitch"));
    return value;
}
void GCSoundPatch::SetPitch(GCSoundEnvelope value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_pitch", false, value);
}
GCSoundEnvelope GCSoundPatch::GetVolume() const {
    GCSoundEnvelope value(GetSchemaPtr(m_ptr, "CSoundPatch", "m_volume"));
    return value;
}
void GCSoundPatch::SetVolume(GCSoundEnvelope value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_volume", false, value);
}
float GCSoundPatch::GetShutdownTime() const {
    return GetSchemaValue<float>(m_ptr, "CSoundPatch", "m_shutdownTime");
}
void GCSoundPatch::SetShutdownTime(float value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_shutdownTime", false, value);
}
float GCSoundPatch::GetLastTime() const {
    return GetSchemaValue<float>(m_ptr, "CSoundPatch", "m_flLastTime");
}
void GCSoundPatch::SetLastTime(float value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_flLastTime", false, value);
}
std::string GCSoundPatch::GetSoundScriptName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundPatch", "m_iszSoundScriptName").String();
}
void GCSoundPatch::SetSoundScriptName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_iszSoundScriptName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCSoundPatch::GetEnt() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSoundPatch", "m_hEnt"));
    return value;
}
void GCSoundPatch::SetEnt(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Ent' is not possible.\n");
}
CEntityIndex GCSoundPatch::GetSoundEntityIndex() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "CSoundPatch", "m_soundEntityIndex");
}
void GCSoundPatch::SetSoundEntityIndex(CEntityIndex value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_soundEntityIndex", false, value);
}
Vector GCSoundPatch::GetSoundOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundPatch", "m_soundOrigin");
}
void GCSoundPatch::SetSoundOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_soundOrigin", false, value);
}
int32_t GCSoundPatch::GetIsPlaying() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundPatch", "m_isPlaying");
}
void GCSoundPatch::SetIsPlaying(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_isPlaying", false, value);
}
GCCopyRecipientFilter GCSoundPatch::GetFilter() const {
    GCCopyRecipientFilter value(GetSchemaPtr(m_ptr, "CSoundPatch", "m_Filter"));
    return value;
}
void GCSoundPatch::SetFilter(GCCopyRecipientFilter value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_Filter", false, value);
}
float GCSoundPatch::GetCloseCaptionDuration() const {
    return GetSchemaValue<float>(m_ptr, "CSoundPatch", "m_flCloseCaptionDuration");
}
void GCSoundPatch::SetCloseCaptionDuration(float value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_flCloseCaptionDuration", false, value);
}
bool GCSoundPatch::GetUpdatedSoundOrigin() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundPatch", "m_bUpdatedSoundOrigin");
}
void GCSoundPatch::SetUpdatedSoundOrigin(bool value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_bUpdatedSoundOrigin", false, value);
}
std::string GCSoundPatch::GetClassName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundPatch", "m_iszClassName").String();
}
void GCSoundPatch::SetClassName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundPatch", "m_iszClassName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundPatch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundPatch::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSoundPatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundPatch>("CSoundPatch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Pitch", &GCSoundPatch::GetPitch, &GCSoundPatch::SetPitch)
        .addProperty("Volume", &GCSoundPatch::GetVolume, &GCSoundPatch::SetVolume)
        .addProperty("ShutdownTime", &GCSoundPatch::GetShutdownTime, &GCSoundPatch::SetShutdownTime)
        .addProperty("LastTime", &GCSoundPatch::GetLastTime, &GCSoundPatch::SetLastTime)
        .addProperty("SoundScriptName", &GCSoundPatch::GetSoundScriptName, &GCSoundPatch::SetSoundScriptName)
        .addProperty("Ent", &GCSoundPatch::GetEnt, &GCSoundPatch::SetEnt)
        .addProperty("SoundEntityIndex", &GCSoundPatch::GetSoundEntityIndex, &GCSoundPatch::SetSoundEntityIndex)
        .addProperty("SoundOrigin", &GCSoundPatch::GetSoundOrigin, &GCSoundPatch::SetSoundOrigin)
        .addProperty("IsPlaying", &GCSoundPatch::GetIsPlaying, &GCSoundPatch::SetIsPlaying)
        .addProperty("Filter", &GCSoundPatch::GetFilter, &GCSoundPatch::SetFilter)
        .addProperty("CloseCaptionDuration", &GCSoundPatch::GetCloseCaptionDuration, &GCSoundPatch::SetCloseCaptionDuration)
        .addProperty("UpdatedSoundOrigin", &GCSoundPatch::GetUpdatedSoundOrigin, &GCSoundPatch::SetUpdatedSoundOrigin)
        .addProperty("ClassName", &GCSoundPatch::GetClassName, &GCSoundPatch::SetClassName)
        .addFunction("ToPtr", &GCSoundPatch::ToPtr)
        .addFunction("IsValid", &GCSoundPatch::IsValid)
        .endClass();
}