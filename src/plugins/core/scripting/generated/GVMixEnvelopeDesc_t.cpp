#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixEnvelopeDesc_t::GVMixEnvelopeDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixEnvelopeDesc_t::GVMixEnvelopeDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixEnvelopeDesc_t::GetAttackTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixEnvelopeDesc_t", "m_flAttackTimeMS");
}
void GVMixEnvelopeDesc_t::SetAttackTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixEnvelopeDesc_t", "m_flAttackTimeMS", true, value);
}
float GVMixEnvelopeDesc_t::GetHoldTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixEnvelopeDesc_t", "m_flHoldTimeMS");
}
void GVMixEnvelopeDesc_t::SetHoldTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixEnvelopeDesc_t", "m_flHoldTimeMS", true, value);
}
float GVMixEnvelopeDesc_t::GetReleaseTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixEnvelopeDesc_t", "m_flReleaseTimeMS");
}
void GVMixEnvelopeDesc_t::SetReleaseTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixEnvelopeDesc_t", "m_flReleaseTimeMS", true, value);
}
std::string GVMixEnvelopeDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixEnvelopeDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixEnvelopeDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixEnvelopeDesc_t>("VMixEnvelopeDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttackTimeMS", &GVMixEnvelopeDesc_t::GetAttackTimeMS, &GVMixEnvelopeDesc_t::SetAttackTimeMS)
        .addProperty("HoldTimeMS", &GVMixEnvelopeDesc_t::GetHoldTimeMS, &GVMixEnvelopeDesc_t::SetHoldTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixEnvelopeDesc_t::GetReleaseTimeMS, &GVMixEnvelopeDesc_t::SetReleaseTimeMS)
        .addFunction("ToPtr", &GVMixEnvelopeDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixEnvelopeDesc_t::IsValid)
        .endClass();
}