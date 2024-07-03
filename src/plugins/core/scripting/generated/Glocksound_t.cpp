#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Glocksound_t::Glocksound_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Glocksound_t::Glocksound_t(void *ptr) {
    m_ptr = ptr;
}
std::string Glocksound_t::GetLockedSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "locksound_t", "sLockedSound").String();
}
void Glocksound_t::SetLockedSound(std::string value) {
    SetSchemaValue(m_ptr, "locksound_t", "sLockedSound", true, CUtlSymbolLarge(value.c_str()));
}
std::string Glocksound_t::GetUnlockedSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "locksound_t", "sUnlockedSound").String();
}
void Glocksound_t::SetUnlockedSound(std::string value) {
    SetSchemaValue(m_ptr, "locksound_t", "sUnlockedSound", true, CUtlSymbolLarge(value.c_str()));
}
float Glocksound_t::GetFlwaitSound() const {
    return GetSchemaValue<float>(m_ptr, "locksound_t", "flwaitSound");
}
void Glocksound_t::SetFlwaitSound(float value) {
    SetSchemaValue(m_ptr, "locksound_t", "flwaitSound", true, value);
}
std::string Glocksound_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Glocksound_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClasslocksound_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Glocksound_t>("locksound_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LockedSound", &Glocksound_t::GetLockedSound, &Glocksound_t::SetLockedSound)
        .addProperty("UnlockedSound", &Glocksound_t::GetUnlockedSound, &Glocksound_t::SetUnlockedSound)
        .addProperty("FlwaitSound", &Glocksound_t::GetFlwaitSound, &Glocksound_t::SetFlwaitSound)
        .addFunction("ToPtr", &Glocksound_t::ToPtr)
        .addFunction("IsValid", &Glocksound_t::IsValid)
        .endClass();
}