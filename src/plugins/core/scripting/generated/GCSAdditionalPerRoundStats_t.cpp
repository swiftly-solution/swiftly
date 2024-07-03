#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSAdditionalPerRoundStats_t::GCSAdditionalPerRoundStats_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSAdditionalPerRoundStats_t::GCSAdditionalPerRoundStats_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSAdditionalPerRoundStats_t::GetNumChickensKilled() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_numChickensKilled");
}
void GCSAdditionalPerRoundStats_t::SetNumChickensKilled(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_numChickensKilled", true, value);
}
int32_t GCSAdditionalPerRoundStats_t::GetKillsWhileBlind() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_killsWhileBlind");
}
void GCSAdditionalPerRoundStats_t::SetKillsWhileBlind(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_killsWhileBlind", true, value);
}
int32_t GCSAdditionalPerRoundStats_t::GetBombCarrierkills() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_bombCarrierkills");
}
void GCSAdditionalPerRoundStats_t::SetBombCarrierkills(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_bombCarrierkills", true, value);
}
int32_t GCSAdditionalPerRoundStats_t::GetBurnDamageInflicted() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBurnDamageInflicted");
}
void GCSAdditionalPerRoundStats_t::SetBurnDamageInflicted(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBurnDamageInflicted", true, value);
}
int32_t GCSAdditionalPerRoundStats_t::GetBlastDamageInflicted() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBlastDamageInflicted");
}
void GCSAdditionalPerRoundStats_t::SetBlastDamageInflicted(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_iBlastDamageInflicted", true, value);
}
int32_t GCSAdditionalPerRoundStats_t::GetDinks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSAdditionalPerRoundStats_t", "m_iDinks");
}
void GCSAdditionalPerRoundStats_t::SetDinks(int32_t value) {
    SetSchemaValue(m_ptr, "CSAdditionalPerRoundStats_t", "m_iDinks", true, value);
}
std::string GCSAdditionalPerRoundStats_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSAdditionalPerRoundStats_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSAdditionalPerRoundStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSAdditionalPerRoundStats_t>("CSAdditionalPerRoundStats_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NumChickensKilled", &GCSAdditionalPerRoundStats_t::GetNumChickensKilled, &GCSAdditionalPerRoundStats_t::SetNumChickensKilled)
        .addProperty("KillsWhileBlind", &GCSAdditionalPerRoundStats_t::GetKillsWhileBlind, &GCSAdditionalPerRoundStats_t::SetKillsWhileBlind)
        .addProperty("BombCarrierkills", &GCSAdditionalPerRoundStats_t::GetBombCarrierkills, &GCSAdditionalPerRoundStats_t::SetBombCarrierkills)
        .addProperty("BurnDamageInflicted", &GCSAdditionalPerRoundStats_t::GetBurnDamageInflicted, &GCSAdditionalPerRoundStats_t::SetBurnDamageInflicted)
        .addProperty("BlastDamageInflicted", &GCSAdditionalPerRoundStats_t::GetBlastDamageInflicted, &GCSAdditionalPerRoundStats_t::SetBlastDamageInflicted)
        .addProperty("Dinks", &GCSAdditionalPerRoundStats_t::GetDinks, &GCSAdditionalPerRoundStats_t::SetDinks)
        .addFunction("ToPtr", &GCSAdditionalPerRoundStats_t::ToPtr)
        .addFunction("IsValid", &GCSAdditionalPerRoundStats_t::IsValid)
        .endClass();
}