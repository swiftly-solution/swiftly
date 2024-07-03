#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventEntity::GCSoundEventEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventEntity::GCSoundEventEntity(void *ptr) {
    m_ptr = ptr;
}
bool GCSoundEventEntity::GetStartOnSpawn() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bStartOnSpawn");
}
void GCSoundEventEntity::SetStartOnSpawn(bool value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bStartOnSpawn", false, value);
}
bool GCSoundEventEntity::GetToLocalPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bToLocalPlayer");
}
void GCSoundEventEntity::SetToLocalPlayer(bool value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bToLocalPlayer", false, value);
}
bool GCSoundEventEntity::GetStopOnNew() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bStopOnNew");
}
void GCSoundEventEntity::SetStopOnNew(bool value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bStopOnNew", false, value);
}
bool GCSoundEventEntity::GetSaveRestore() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bSaveRestore");
}
void GCSoundEventEntity::SetSaveRestore(bool value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bSaveRestore", false, value);
}
bool GCSoundEventEntity::GetSavedIsPlaying() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundEventEntity", "m_bSavedIsPlaying");
}
void GCSoundEventEntity::SetSavedIsPlaying(bool value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_bSavedIsPlaying", false, value);
}
float GCSoundEventEntity::GetSavedElapsedTime() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEventEntity", "m_flSavedElapsedTime");
}
void GCSoundEventEntity::SetSavedElapsedTime(float value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_flSavedElapsedTime", false, value);
}
std::string GCSoundEventEntity::GetSourceEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventEntity", "m_iszSourceEntityName").String();
}
void GCSoundEventEntity::SetSourceEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_iszSourceEntityName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundEventEntity::GetAttachmentName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventEntity", "m_iszAttachmentName").String();
}
void GCSoundEventEntity::SetAttachmentName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_iszAttachmentName", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCSoundEventEntity::GetOnSoundFinished() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSoundEventEntity", "m_onSoundFinished"));
    return value;
}
void GCSoundEventEntity::SetOnSoundFinished(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_onSoundFinished", false, value);
}
std::string GCSoundEventEntity::GetSoundName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventEntity", "m_iszSoundName").String();
}
void GCSoundEventEntity::SetSoundName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_iszSoundName", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityInstance GCSoundEventEntity::GetSource() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CSoundEventEntity", "m_hSource"));
    return value;
}
void GCSoundEventEntity::SetSource(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Source' is not possible.\n");
}
int32_t GCSoundEventEntity::GetEntityIndexSelection() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundEventEntity", "m_nEntityIndexSelection");
}
void GCSoundEventEntity::SetEntityIndexSelection(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundEventEntity", "m_nEntityIndexSelection", false, value);
}
std::string GCSoundEventEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCSoundEventEntity::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCSoundEventEntity::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEventEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventEntity>("CSoundEventEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartOnSpawn", &GCSoundEventEntity::GetStartOnSpawn, &GCSoundEventEntity::SetStartOnSpawn)
        .addProperty("ToLocalPlayer", &GCSoundEventEntity::GetToLocalPlayer, &GCSoundEventEntity::SetToLocalPlayer)
        .addProperty("StopOnNew", &GCSoundEventEntity::GetStopOnNew, &GCSoundEventEntity::SetStopOnNew)
        .addProperty("SaveRestore", &GCSoundEventEntity::GetSaveRestore, &GCSoundEventEntity::SetSaveRestore)
        .addProperty("SavedIsPlaying", &GCSoundEventEntity::GetSavedIsPlaying, &GCSoundEventEntity::SetSavedIsPlaying)
        .addProperty("SavedElapsedTime", &GCSoundEventEntity::GetSavedElapsedTime, &GCSoundEventEntity::SetSavedElapsedTime)
        .addProperty("SourceEntityName", &GCSoundEventEntity::GetSourceEntityName, &GCSoundEventEntity::SetSourceEntityName)
        .addProperty("AttachmentName", &GCSoundEventEntity::GetAttachmentName, &GCSoundEventEntity::SetAttachmentName)
        .addProperty("OnSoundFinished", &GCSoundEventEntity::GetOnSoundFinished, &GCSoundEventEntity::SetOnSoundFinished)
        .addProperty("SoundName", &GCSoundEventEntity::GetSoundName, &GCSoundEventEntity::SetSoundName)
        .addProperty("Source", &GCSoundEventEntity::GetSource, &GCSoundEventEntity::SetSource)
        .addProperty("EntityIndexSelection", &GCSoundEventEntity::GetEntityIndexSelection, &GCSoundEventEntity::SetEntityIndexSelection)
        .addProperty("Parent", &GCSoundEventEntity::GetParent, &GCSoundEventEntity::SetParent)
        .addFunction("ToPtr", &GCSoundEventEntity::ToPtr)
        .addFunction("IsValid", &GCSoundEventEntity::IsValid)
        .endClass();
}