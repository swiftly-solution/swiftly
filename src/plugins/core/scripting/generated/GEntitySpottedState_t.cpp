#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEntitySpottedState_t::GEntitySpottedState_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEntitySpottedState_t::GEntitySpottedState_t(void *ptr) {
    m_ptr = ptr;
}
bool GEntitySpottedState_t::GetSpotted() const {
    return GetSchemaValue<bool>(m_ptr, "EntitySpottedState_t", "m_bSpotted");
}
void GEntitySpottedState_t::SetSpotted(bool value) {
    SetSchemaValue(m_ptr, "EntitySpottedState_t", "m_bSpotted", true, value);
}
std::vector<uint32_t> GEntitySpottedState_t::GetSpottedByMask() const {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "EntitySpottedState_t", "m_bSpottedByMask"); std::vector<uint32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GEntitySpottedState_t::SetSpottedByMask(std::vector<uint32_t> value) {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "EntitySpottedState_t", "m_bSpottedByMask"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "EntitySpottedState_t", "m_bSpottedByMask", true, outValue);
}
std::string GEntitySpottedState_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEntitySpottedState_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEntitySpottedState_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntitySpottedState_t>("EntitySpottedState_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Spotted", &GEntitySpottedState_t::GetSpotted, &GEntitySpottedState_t::SetSpotted)
        .addProperty("SpottedByMask", &GEntitySpottedState_t::GetSpottedByMask, &GEntitySpottedState_t::SetSpottedByMask)
        .addFunction("ToPtr", &GEntitySpottedState_t::ToPtr)
        .addFunction("IsValid", &GEntitySpottedState_t::IsValid)
        .endClass();
}