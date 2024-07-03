#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixDynamicsCompressorDesc_t::GVMixDynamicsCompressorDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixDynamicsCompressorDesc_t::GVMixDynamicsCompressorDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixDynamicsCompressorDesc_t::GetFldbOutputGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbOutputGain");
}
void GVMixDynamicsCompressorDesc_t::SetFldbOutputGain(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbOutputGain", true, value);
}
float GVMixDynamicsCompressorDesc_t::GetFldbCompressionThreshold() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbCompressionThreshold");
}
void GVMixDynamicsCompressorDesc_t::SetFldbCompressionThreshold(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbCompressionThreshold", true, value);
}
float GVMixDynamicsCompressorDesc_t::GetFldbKneeWidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbKneeWidth");
}
void GVMixDynamicsCompressorDesc_t::SetFldbKneeWidth(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_fldbKneeWidth", true, value);
}
float GVMixDynamicsCompressorDesc_t::GetCompressionRatio() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flCompressionRatio");
}
void GVMixDynamicsCompressorDesc_t::SetCompressionRatio(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flCompressionRatio", true, value);
}
float GVMixDynamicsCompressorDesc_t::GetAttackTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flAttackTimeMS");
}
void GVMixDynamicsCompressorDesc_t::SetAttackTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flAttackTimeMS", true, value);
}
float GVMixDynamicsCompressorDesc_t::GetReleaseTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flReleaseTimeMS");
}
void GVMixDynamicsCompressorDesc_t::SetReleaseTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flReleaseTimeMS", true, value);
}
float GVMixDynamicsCompressorDesc_t::GetRMSTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flRMSTimeMS");
}
void GVMixDynamicsCompressorDesc_t::SetRMSTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flRMSTimeMS", true, value);
}
float GVMixDynamicsCompressorDesc_t::GetWetMix() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flWetMix");
}
void GVMixDynamicsCompressorDesc_t::SetWetMix(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_flWetMix", true, value);
}
bool GVMixDynamicsCompressorDesc_t::GetPeakMode() const {
    return GetSchemaValue<bool>(m_ptr, "VMixDynamicsCompressorDesc_t", "m_bPeakMode");
}
void GVMixDynamicsCompressorDesc_t::SetPeakMode(bool value) {
    SetSchemaValue(m_ptr, "VMixDynamicsCompressorDesc_t", "m_bPeakMode", true, value);
}
std::string GVMixDynamicsCompressorDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixDynamicsCompressorDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixDynamicsCompressorDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamicsCompressorDesc_t>("VMixDynamicsCompressorDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FldbOutputGain", &GVMixDynamicsCompressorDesc_t::GetFldbOutputGain, &GVMixDynamicsCompressorDesc_t::SetFldbOutputGain)
        .addProperty("FldbCompressionThreshold", &GVMixDynamicsCompressorDesc_t::GetFldbCompressionThreshold, &GVMixDynamicsCompressorDesc_t::SetFldbCompressionThreshold)
        .addProperty("FldbKneeWidth", &GVMixDynamicsCompressorDesc_t::GetFldbKneeWidth, &GVMixDynamicsCompressorDesc_t::SetFldbKneeWidth)
        .addProperty("CompressionRatio", &GVMixDynamicsCompressorDesc_t::GetCompressionRatio, &GVMixDynamicsCompressorDesc_t::SetCompressionRatio)
        .addProperty("AttackTimeMS", &GVMixDynamicsCompressorDesc_t::GetAttackTimeMS, &GVMixDynamicsCompressorDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixDynamicsCompressorDesc_t::GetReleaseTimeMS, &GVMixDynamicsCompressorDesc_t::SetReleaseTimeMS)
        .addProperty("RMSTimeMS", &GVMixDynamicsCompressorDesc_t::GetRMSTimeMS, &GVMixDynamicsCompressorDesc_t::SetRMSTimeMS)
        .addProperty("WetMix", &GVMixDynamicsCompressorDesc_t::GetWetMix, &GVMixDynamicsCompressorDesc_t::SetWetMix)
        .addProperty("PeakMode", &GVMixDynamicsCompressorDesc_t::GetPeakMode, &GVMixDynamicsCompressorDesc_t::SetPeakMode)
        .addFunction("ToPtr", &GVMixDynamicsCompressorDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixDynamicsCompressorDesc_t::IsValid)
        .endClass();
}