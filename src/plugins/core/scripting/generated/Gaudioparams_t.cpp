#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gaudioparams_t::Gaudioparams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gaudioparams_t::Gaudioparams_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<Vector> Gaudioparams_t::GetLocalSound() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "audioparams_t", "localSound"); std::vector<Vector> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret;
}
void Gaudioparams_t::SetLocalSound(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "audioparams_t", "localSound"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "audioparams_t", "localSound", true, outValue);
}
int32_t Gaudioparams_t::GetSoundscapeIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "audioparams_t", "soundscapeIndex");
}
void Gaudioparams_t::SetSoundscapeIndex(int32_t value) {
    SetSchemaValue(m_ptr, "audioparams_t", "soundscapeIndex", true, value);
}
uint8_t Gaudioparams_t::GetLocalBits() const {
    return GetSchemaValue<uint8_t>(m_ptr, "audioparams_t", "localBits");
}
void Gaudioparams_t::SetLocalBits(uint8_t value) {
    SetSchemaValue(m_ptr, "audioparams_t", "localBits", true, value);
}
int32_t Gaudioparams_t::GetSoundscapeEntityListIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "audioparams_t", "soundscapeEntityListIndex");
}
void Gaudioparams_t::SetSoundscapeEntityListIndex(int32_t value) {
    SetSchemaValue(m_ptr, "audioparams_t", "soundscapeEntityListIndex", true, value);
}
uint32_t Gaudioparams_t::GetSoundEventHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "audioparams_t", "soundEventHash");
}
void Gaudioparams_t::SetSoundEventHash(uint32_t value) {
    SetSchemaValue(m_ptr, "audioparams_t", "soundEventHash", true, value);
}
std::string Gaudioparams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gaudioparams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassaudioparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gaudioparams_t>("audioparams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LocalSound", &Gaudioparams_t::GetLocalSound, &Gaudioparams_t::SetLocalSound)
        .addProperty("SoundscapeIndex", &Gaudioparams_t::GetSoundscapeIndex, &Gaudioparams_t::SetSoundscapeIndex)
        .addProperty("LocalBits", &Gaudioparams_t::GetLocalBits, &Gaudioparams_t::SetLocalBits)
        .addProperty("SoundscapeEntityListIndex", &Gaudioparams_t::GetSoundscapeEntityListIndex, &Gaudioparams_t::SetSoundscapeEntityListIndex)
        .addProperty("SoundEventHash", &Gaudioparams_t::GetSoundEventHash, &Gaudioparams_t::SetSoundEventHash)
        .addFunction("ToPtr", &Gaudioparams_t::ToPtr)
        .addFunction("IsValid", &Gaudioparams_t::IsValid)
        .endClass();
}