#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixAutoFilterDesc_t::GVMixAutoFilterDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixAutoFilterDesc_t::GVMixAutoFilterDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixAutoFilterDesc_t::GetEnvelopeAmount() const {
    return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flEnvelopeAmount");
}
void GVMixAutoFilterDesc_t::SetEnvelopeAmount(float value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flEnvelopeAmount", true, value);
}
float GVMixAutoFilterDesc_t::GetAttackTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flAttackTimeMS");
}
void GVMixAutoFilterDesc_t::SetAttackTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flAttackTimeMS", true, value);
}
float GVMixAutoFilterDesc_t::GetReleaseTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flReleaseTimeMS");
}
void GVMixAutoFilterDesc_t::SetReleaseTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flReleaseTimeMS", true, value);
}
GVMixFilterDesc_t GVMixAutoFilterDesc_t::GetFilter() const {
    GVMixFilterDesc_t value(GetSchemaPtr(m_ptr, "VMixAutoFilterDesc_t", "m_filter"));
    return value;
}
void GVMixAutoFilterDesc_t::SetFilter(GVMixFilterDesc_t value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_filter", true, value);
}
float GVMixAutoFilterDesc_t::GetLFOAmount() const {
    return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flLFOAmount");
}
void GVMixAutoFilterDesc_t::SetLFOAmount(float value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flLFOAmount", true, value);
}
float GVMixAutoFilterDesc_t::GetLFORate() const {
    return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flLFORate");
}
void GVMixAutoFilterDesc_t::SetLFORate(float value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flLFORate", true, value);
}
float GVMixAutoFilterDesc_t::GetPhase() const {
    return GetSchemaValue<float>(m_ptr, "VMixAutoFilterDesc_t", "m_flPhase");
}
void GVMixAutoFilterDesc_t::SetPhase(float value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_flPhase", true, value);
}
uint64_t GVMixAutoFilterDesc_t::GetLFOShape() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VMixAutoFilterDesc_t", "m_nLFOShape");
}
void GVMixAutoFilterDesc_t::SetLFOShape(uint64_t value) {
    SetSchemaValue(m_ptr, "VMixAutoFilterDesc_t", "m_nLFOShape", true, value);
}
std::string GVMixAutoFilterDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixAutoFilterDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixAutoFilterDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixAutoFilterDesc_t>("VMixAutoFilterDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EnvelopeAmount", &GVMixAutoFilterDesc_t::GetEnvelopeAmount, &GVMixAutoFilterDesc_t::SetEnvelopeAmount)
        .addProperty("AttackTimeMS", &GVMixAutoFilterDesc_t::GetAttackTimeMS, &GVMixAutoFilterDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixAutoFilterDesc_t::GetReleaseTimeMS, &GVMixAutoFilterDesc_t::SetReleaseTimeMS)
        .addProperty("Filter", &GVMixAutoFilterDesc_t::GetFilter, &GVMixAutoFilterDesc_t::SetFilter)
        .addProperty("LFOAmount", &GVMixAutoFilterDesc_t::GetLFOAmount, &GVMixAutoFilterDesc_t::SetLFOAmount)
        .addProperty("LFORate", &GVMixAutoFilterDesc_t::GetLFORate, &GVMixAutoFilterDesc_t::SetLFORate)
        .addProperty("Phase", &GVMixAutoFilterDesc_t::GetPhase, &GVMixAutoFilterDesc_t::SetPhase)
        .addProperty("LFOShape", &GVMixAutoFilterDesc_t::GetLFOShape, &GVMixAutoFilterDesc_t::SetLFOShape)
        .addFunction("ToPtr", &GVMixAutoFilterDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixAutoFilterDesc_t::IsValid)
        .endClass();
}