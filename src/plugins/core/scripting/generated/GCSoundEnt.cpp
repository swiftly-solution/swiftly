#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEnt::GCSoundEnt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEnt::GCSoundEnt(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSoundEnt::GetFreeSound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundEnt", "m_iFreeSound");
}
void GCSoundEnt::SetFreeSound(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundEnt", "m_iFreeSound", false, value);
}
int32_t GCSoundEnt::GetActiveSound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundEnt", "m_iActiveSound");
}
void GCSoundEnt::SetActiveSound(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundEnt", "m_iActiveSound", false, value);
}
int32_t GCSoundEnt::GetCLastActiveSounds() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundEnt", "m_cLastActiveSounds");
}
void GCSoundEnt::SetCLastActiveSounds(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundEnt", "m_cLastActiveSounds", false, value);
}
std::vector<GCSound> GCSoundEnt::GetSoundPool() const {
    GCSound* outValue = GetSchemaValue<GCSound*>(m_ptr, "CSoundEnt", "m_SoundPool"); std::vector<GCSound> ret; for(int i = 0; i < 128; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSoundEnt::SetSoundPool(std::vector<GCSound> value) {
    GCSound* outValue = GetSchemaValue<GCSound*>(m_ptr, "CSoundEnt", "m_SoundPool"); for(int i = 0; i < 128; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSoundEnt", "m_SoundPool", false, outValue);
}
std::string GCSoundEnt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEnt::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCSoundEnt::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCSoundEnt::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEnt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEnt>("CSoundEnt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FreeSound", &GCSoundEnt::GetFreeSound, &GCSoundEnt::SetFreeSound)
        .addProperty("ActiveSound", &GCSoundEnt::GetActiveSound, &GCSoundEnt::SetActiveSound)
        .addProperty("CLastActiveSounds", &GCSoundEnt::GetCLastActiveSounds, &GCSoundEnt::SetCLastActiveSounds)
        .addProperty("SoundPool", &GCSoundEnt::GetSoundPool, &GCSoundEnt::SetSoundPool)
        .addProperty("Parent", &GCSoundEnt::GetParent, &GCSoundEnt::SetParent)
        .addFunction("ToPtr", &GCSoundEnt::ToPtr)
        .addFunction("IsValid", &GCSoundEnt::IsValid)
        .endClass();
}