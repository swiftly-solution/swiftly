#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAmbientGeneric::GCAmbientGeneric(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAmbientGeneric::GCAmbientGeneric(void *ptr) {
    m_ptr = ptr;
}
float GCAmbientGeneric::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CAmbientGeneric", "m_radius");
}
void GCAmbientGeneric::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_radius", false, value);
}
float GCAmbientGeneric::GetMaxRadius() const {
    return GetSchemaValue<float>(m_ptr, "CAmbientGeneric", "m_flMaxRadius");
}
void GCAmbientGeneric::SetMaxRadius(float value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_flMaxRadius", false, value);
}
uint64_t GCAmbientGeneric::GetSoundLevel() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAmbientGeneric", "m_iSoundLevel");
}
void GCAmbientGeneric::SetSoundLevel(uint64_t value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_iSoundLevel", false, value);
}
Gdynpitchvol_t GCAmbientGeneric::GetDpv() const {
    Gdynpitchvol_t value(GetSchemaPtr(m_ptr, "CAmbientGeneric", "m_dpv"));
    return value;
}
void GCAmbientGeneric::SetDpv(Gdynpitchvol_t value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_dpv", false, value);
}
bool GCAmbientGeneric::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CAmbientGeneric", "m_fActive");
}
void GCAmbientGeneric::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_fActive", false, value);
}
bool GCAmbientGeneric::GetLooping() const {
    return GetSchemaValue<bool>(m_ptr, "CAmbientGeneric", "m_fLooping");
}
void GCAmbientGeneric::SetLooping(bool value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_fLooping", false, value);
}
std::string GCAmbientGeneric::GetSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAmbientGeneric", "m_iszSound").String();
}
void GCAmbientGeneric::SetSound(std::string value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_iszSound", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCAmbientGeneric::GetSourceEntName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAmbientGeneric", "m_sSourceEntName").String();
}
void GCAmbientGeneric::SetSourceEntName(std::string value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_sSourceEntName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCAmbientGeneric::GetSoundSource() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CAmbientGeneric", "m_hSoundSource"));
    return value;
}
void GCAmbientGeneric::SetSoundSource(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'SoundSource' is not possible.\n");
}
CEntityIndex GCAmbientGeneric::GetSoundSourceEntIndex() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "CAmbientGeneric", "m_nSoundSourceEntIndex");
}
void GCAmbientGeneric::SetSoundSourceEntIndex(CEntityIndex value) {
    SetSchemaValue(m_ptr, "CAmbientGeneric", "m_nSoundSourceEntIndex", false, value);
}
std::string GCAmbientGeneric::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAmbientGeneric::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCAmbientGeneric::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCAmbientGeneric::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAmbientGeneric(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAmbientGeneric>("CAmbientGeneric")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Radius", &GCAmbientGeneric::GetRadius, &GCAmbientGeneric::SetRadius)
        .addProperty("MaxRadius", &GCAmbientGeneric::GetMaxRadius, &GCAmbientGeneric::SetMaxRadius)
        .addProperty("SoundLevel", &GCAmbientGeneric::GetSoundLevel, &GCAmbientGeneric::SetSoundLevel)
        .addProperty("Dpv", &GCAmbientGeneric::GetDpv, &GCAmbientGeneric::SetDpv)
        .addProperty("Active", &GCAmbientGeneric::GetActive, &GCAmbientGeneric::SetActive)
        .addProperty("Looping", &GCAmbientGeneric::GetLooping, &GCAmbientGeneric::SetLooping)
        .addProperty("Sound", &GCAmbientGeneric::GetSound, &GCAmbientGeneric::SetSound)
        .addProperty("SourceEntName", &GCAmbientGeneric::GetSourceEntName, &GCAmbientGeneric::SetSourceEntName)
        .addProperty("SoundSource", &GCAmbientGeneric::GetSoundSource, &GCAmbientGeneric::SetSoundSource)
        .addProperty("SoundSourceEntIndex", &GCAmbientGeneric::GetSoundSourceEntIndex, &GCAmbientGeneric::SetSoundSourceEntIndex)
        .addProperty("Parent", &GCAmbientGeneric::GetParent, &GCAmbientGeneric::SetParent)
        .addFunction("ToPtr", &GCAmbientGeneric::ToPtr)
        .addFunction("IsValid", &GCAmbientGeneric::IsValid)
        .endClass();
}