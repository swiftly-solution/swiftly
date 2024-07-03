#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixDynamicsDesc_t::GVMixDynamicsDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixDynamicsDesc_t::GVMixDynamicsDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixDynamicsDesc_t::GetFldbGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbGain");
}
void GVMixDynamicsDesc_t::SetFldbGain(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbGain", true, value);
}
float GVMixDynamicsDesc_t::GetFldbNoiseGateThreshold() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbNoiseGateThreshold");
}
void GVMixDynamicsDesc_t::SetFldbNoiseGateThreshold(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbNoiseGateThreshold", true, value);
}
float GVMixDynamicsDesc_t::GetFldbCompressionThreshold() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbCompressionThreshold");
}
void GVMixDynamicsDesc_t::SetFldbCompressionThreshold(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbCompressionThreshold", true, value);
}
float GVMixDynamicsDesc_t::GetFldbLimiterThreshold() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbLimiterThreshold");
}
void GVMixDynamicsDesc_t::SetFldbLimiterThreshold(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbLimiterThreshold", true, value);
}
float GVMixDynamicsDesc_t::GetFldbKneeWidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_fldbKneeWidth");
}
void GVMixDynamicsDesc_t::SetFldbKneeWidth(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_fldbKneeWidth", true, value);
}
float GVMixDynamicsDesc_t::GetRatio() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flRatio");
}
void GVMixDynamicsDesc_t::SetRatio(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flRatio", true, value);
}
float GVMixDynamicsDesc_t::GetLimiterRatio() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flLimiterRatio");
}
void GVMixDynamicsDesc_t::SetLimiterRatio(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flLimiterRatio", true, value);
}
float GVMixDynamicsDesc_t::GetAttackTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flAttackTimeMS");
}
void GVMixDynamicsDesc_t::SetAttackTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flAttackTimeMS", true, value);
}
float GVMixDynamicsDesc_t::GetReleaseTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flReleaseTimeMS");
}
void GVMixDynamicsDesc_t::SetReleaseTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flReleaseTimeMS", true, value);
}
float GVMixDynamicsDesc_t::GetRMSTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flRMSTimeMS");
}
void GVMixDynamicsDesc_t::SetRMSTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flRMSTimeMS", true, value);
}
float GVMixDynamicsDesc_t::GetWetMix() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsDesc_t", "m_flWetMix");
}
void GVMixDynamicsDesc_t::SetWetMix(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_flWetMix", true, value);
}
bool GVMixDynamicsDesc_t::GetPeakMode() const {
    return GetSchemaValue<bool>(m_ptr, "VMixDynamicsDesc_t", "m_bPeakMode");
}
void GVMixDynamicsDesc_t::SetPeakMode(bool value) {
    SetSchemaValue(m_ptr, "VMixDynamicsDesc_t", "m_bPeakMode", true, value);
}
std::string GVMixDynamicsDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixDynamicsDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixDynamicsDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamicsDesc_t>("VMixDynamicsDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FldbGain", &GVMixDynamicsDesc_t::GetFldbGain, &GVMixDynamicsDesc_t::SetFldbGain)
        .addProperty("FldbNoiseGateThreshold", &GVMixDynamicsDesc_t::GetFldbNoiseGateThreshold, &GVMixDynamicsDesc_t::SetFldbNoiseGateThreshold)
        .addProperty("FldbCompressionThreshold", &GVMixDynamicsDesc_t::GetFldbCompressionThreshold, &GVMixDynamicsDesc_t::SetFldbCompressionThreshold)
        .addProperty("FldbLimiterThreshold", &GVMixDynamicsDesc_t::GetFldbLimiterThreshold, &GVMixDynamicsDesc_t::SetFldbLimiterThreshold)
        .addProperty("FldbKneeWidth", &GVMixDynamicsDesc_t::GetFldbKneeWidth, &GVMixDynamicsDesc_t::SetFldbKneeWidth)
        .addProperty("Ratio", &GVMixDynamicsDesc_t::GetRatio, &GVMixDynamicsDesc_t::SetRatio)
        .addProperty("LimiterRatio", &GVMixDynamicsDesc_t::GetLimiterRatio, &GVMixDynamicsDesc_t::SetLimiterRatio)
        .addProperty("AttackTimeMS", &GVMixDynamicsDesc_t::GetAttackTimeMS, &GVMixDynamicsDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixDynamicsDesc_t::GetReleaseTimeMS, &GVMixDynamicsDesc_t::SetReleaseTimeMS)
        .addProperty("RMSTimeMS", &GVMixDynamicsDesc_t::GetRMSTimeMS, &GVMixDynamicsDesc_t::SetRMSTimeMS)
        .addProperty("WetMix", &GVMixDynamicsDesc_t::GetWetMix, &GVMixDynamicsDesc_t::SetWetMix)
        .addProperty("PeakMode", &GVMixDynamicsDesc_t::GetPeakMode, &GVMixDynamicsDesc_t::SetPeakMode)
        .addFunction("ToPtr", &GVMixDynamicsDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixDynamicsDesc_t::IsValid)
        .endClass();
}