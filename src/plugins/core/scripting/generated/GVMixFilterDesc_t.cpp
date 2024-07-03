#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixFilterDesc_t::GVMixFilterDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixFilterDesc_t::GVMixFilterDesc_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GVMixFilterDesc_t::GetFilterType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VMixFilterDesc_t", "m_nFilterType");
}
void GVMixFilterDesc_t::SetFilterType(uint64_t value) {
    SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_nFilterType", true, value);
}
uint64_t GVMixFilterDesc_t::GetFilterSlope() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VMixFilterDesc_t", "m_nFilterSlope");
}
void GVMixFilterDesc_t::SetFilterSlope(uint64_t value) {
    SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_nFilterSlope", true, value);
}
bool GVMixFilterDesc_t::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "VMixFilterDesc_t", "m_bEnabled");
}
void GVMixFilterDesc_t::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_bEnabled", true, value);
}
float GVMixFilterDesc_t::GetFldbGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixFilterDesc_t", "m_fldbGain");
}
void GVMixFilterDesc_t::SetFldbGain(float value) {
    SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_fldbGain", true, value);
}
float GVMixFilterDesc_t::GetCutoffFreq() const {
    return GetSchemaValue<float>(m_ptr, "VMixFilterDesc_t", "m_flCutoffFreq");
}
void GVMixFilterDesc_t::SetCutoffFreq(float value) {
    SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_flCutoffFreq", true, value);
}
float GVMixFilterDesc_t::GetQ() const {
    return GetSchemaValue<float>(m_ptr, "VMixFilterDesc_t", "m_flQ");
}
void GVMixFilterDesc_t::SetQ(float value) {
    SetSchemaValue(m_ptr, "VMixFilterDesc_t", "m_flQ", true, value);
}
std::string GVMixFilterDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixFilterDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixFilterDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixFilterDesc_t>("VMixFilterDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterType", &GVMixFilterDesc_t::GetFilterType, &GVMixFilterDesc_t::SetFilterType)
        .addProperty("FilterSlope", &GVMixFilterDesc_t::GetFilterSlope, &GVMixFilterDesc_t::SetFilterSlope)
        .addProperty("Enabled", &GVMixFilterDesc_t::GetEnabled, &GVMixFilterDesc_t::SetEnabled)
        .addProperty("FldbGain", &GVMixFilterDesc_t::GetFldbGain, &GVMixFilterDesc_t::SetFldbGain)
        .addProperty("CutoffFreq", &GVMixFilterDesc_t::GetCutoffFreq, &GVMixFilterDesc_t::SetCutoffFreq)
        .addProperty("Q", &GVMixFilterDesc_t::GetQ, &GVMixFilterDesc_t::SetQ)
        .addFunction("ToPtr", &GVMixFilterDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixFilterDesc_t::IsValid)
        .endClass();
}