#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSoundscape::GCEnvSoundscape(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSoundscape::GCEnvSoundscape(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCEnvSoundscape::GetOnPlay() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvSoundscape", "m_OnPlay"));
    return value;
}
void GCEnvSoundscape::SetOnPlay(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_OnPlay", false, value);
}
float GCEnvSoundscape::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvSoundscape", "m_flRadius");
}
void GCEnvSoundscape::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_flRadius", false, value);
}
std::string GCEnvSoundscape::GetSoundscapeName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvSoundscape", "m_soundscapeName").String();
}
void GCEnvSoundscape::SetSoundscapeName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundscapeName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvSoundscape::GetSoundEventName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvSoundscape", "m_soundEventName").String();
}
void GCEnvSoundscape::SetSoundEventName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundEventName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCEnvSoundscape::GetOverrideWithEvent() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvSoundscape", "m_bOverrideWithEvent");
}
void GCEnvSoundscape::SetOverrideWithEvent(bool value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_bOverrideWithEvent", false, value);
}
int32_t GCEnvSoundscape::GetSoundscapeIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvSoundscape", "m_soundscapeIndex");
}
void GCEnvSoundscape::SetSoundscapeIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundscapeIndex", false, value);
}
int32_t GCEnvSoundscape::GetSoundscapeEntityListId() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvSoundscape", "m_soundscapeEntityListId");
}
void GCEnvSoundscape::SetSoundscapeEntityListId(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundscapeEntityListId", false, value);
}
uint32_t GCEnvSoundscape::GetSoundEventHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEnvSoundscape", "m_soundEventHash");
}
void GCEnvSoundscape::SetSoundEventHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_soundEventHash", false, value);
}
std::vector<CUtlSymbolLarge> GCEnvSoundscape::GetPositionNames() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvSoundscape", "m_positionNames"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCEnvSoundscape::SetPositionNames(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CEnvSoundscape", "m_positionNames"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CEnvSoundscape", "m_positionNames", false, outValue);
}
GCEnvSoundscape GCEnvSoundscape::GetProxySoundscape() const {
    GCEnvSoundscape value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvSoundscape", "m_hProxySoundscape"));
    return value;
}
void GCEnvSoundscape::SetProxySoundscape(GCEnvSoundscape* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ProxySoundscape' is not possible.\n");
}
bool GCEnvSoundscape::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvSoundscape", "m_bDisabled");
}
void GCEnvSoundscape::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvSoundscape", "m_bDisabled", false, value);
}
std::string GCEnvSoundscape::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSoundscape::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyEntity GCEnvSoundscape::GetParent() const {
    GCServerOnlyEntity value(m_ptr);
    return value;
}
void GCEnvSoundscape::SetParent(GCServerOnlyEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSoundscape(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscape>("CEnvSoundscape")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnPlay", &GCEnvSoundscape::GetOnPlay, &GCEnvSoundscape::SetOnPlay)
        .addProperty("Radius", &GCEnvSoundscape::GetRadius, &GCEnvSoundscape::SetRadius)
        .addProperty("SoundscapeName", &GCEnvSoundscape::GetSoundscapeName, &GCEnvSoundscape::SetSoundscapeName)
        .addProperty("SoundEventName", &GCEnvSoundscape::GetSoundEventName, &GCEnvSoundscape::SetSoundEventName)
        .addProperty("OverrideWithEvent", &GCEnvSoundscape::GetOverrideWithEvent, &GCEnvSoundscape::SetOverrideWithEvent)
        .addProperty("SoundscapeIndex", &GCEnvSoundscape::GetSoundscapeIndex, &GCEnvSoundscape::SetSoundscapeIndex)
        .addProperty("SoundscapeEntityListId", &GCEnvSoundscape::GetSoundscapeEntityListId, &GCEnvSoundscape::SetSoundscapeEntityListId)
        .addProperty("SoundEventHash", &GCEnvSoundscape::GetSoundEventHash, &GCEnvSoundscape::SetSoundEventHash)
        .addProperty("PositionNames", &GCEnvSoundscape::GetPositionNames, &GCEnvSoundscape::SetPositionNames)
        .addProperty("ProxySoundscape", &GCEnvSoundscape::GetProxySoundscape, &GCEnvSoundscape::SetProxySoundscape)
        .addProperty("Disabled", &GCEnvSoundscape::GetDisabled, &GCEnvSoundscape::SetDisabled)
        .addProperty("Parent", &GCEnvSoundscape::GetParent, &GCEnvSoundscape::SetParent)
        .addFunction("ToPtr", &GCEnvSoundscape::ToPtr)
        .addFunction("IsValid", &GCEnvSoundscape::IsValid)
        .endClass();
}