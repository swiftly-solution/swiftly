#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAISound::GCAISound(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAISound::GCAISound(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCAISound::GetSoundType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAISound", "m_iSoundType");
}
void GCAISound::SetSoundType(uint64_t value) {
    SetSchemaValue(m_ptr, "CAISound", "m_iSoundType", false, value);
}
uint64_t GCAISound::GetSoundFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAISound", "m_iSoundFlags");
}
void GCAISound::SetSoundFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "CAISound", "m_iSoundFlags", false, value);
}
int32_t GCAISound::GetVolume() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAISound", "m_iVolume");
}
void GCAISound::SetVolume(int32_t value) {
    SetSchemaValue(m_ptr, "CAISound", "m_iVolume", false, value);
}
int32_t GCAISound::GetSoundIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAISound", "m_iSoundIndex");
}
void GCAISound::SetSoundIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAISound", "m_iSoundIndex", false, value);
}
float GCAISound::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CAISound", "m_flDuration");
}
void GCAISound::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CAISound", "m_flDuration", false, value);
}
std::string GCAISound::GetProxyEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAISound", "m_iszProxyEntityName").String();
}
void GCAISound::SetProxyEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CAISound", "m_iszProxyEntityName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCAISound::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAISound::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCAISound::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCAISound::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAISound(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAISound>("CAISound")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SoundType", &GCAISound::GetSoundType, &GCAISound::SetSoundType)
        .addProperty("SoundFlags", &GCAISound::GetSoundFlags, &GCAISound::SetSoundFlags)
        .addProperty("Volume", &GCAISound::GetVolume, &GCAISound::SetVolume)
        .addProperty("SoundIndex", &GCAISound::GetSoundIndex, &GCAISound::SetSoundIndex)
        .addProperty("Duration", &GCAISound::GetDuration, &GCAISound::SetDuration)
        .addProperty("ProxyEntityName", &GCAISound::GetProxyEntityName, &GCAISound::SetProxyEntityName)
        .addProperty("Parent", &GCAISound::GetParent, &GCAISound::SetParent)
        .addFunction("ToPtr", &GCAISound::ToPtr)
        .addFunction("IsValid", &GCAISound::IsValid)
        .endClass();
}