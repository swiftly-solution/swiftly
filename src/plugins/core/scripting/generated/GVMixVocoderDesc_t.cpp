#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixVocoderDesc_t::GVMixVocoderDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixVocoderDesc_t::GVMixVocoderDesc_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GVMixVocoderDesc_t::GetBandCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "VMixVocoderDesc_t", "m_nBandCount");
}
void GVMixVocoderDesc_t::SetBandCount(int32_t value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_nBandCount", true, value);
}
float GVMixVocoderDesc_t::GetBandwidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flBandwidth");
}
void GVMixVocoderDesc_t::SetBandwidth(float value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flBandwidth", true, value);
}
float GVMixVocoderDesc_t::GetFldBModGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_fldBModGain");
}
void GVMixVocoderDesc_t::SetFldBModGain(float value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_fldBModGain", true, value);
}
float GVMixVocoderDesc_t::GetFreqRangeStart() const {
    return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeStart");
}
void GVMixVocoderDesc_t::SetFreqRangeStart(float value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeStart", true, value);
}
float GVMixVocoderDesc_t::GetFreqRangeEnd() const {
    return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeEnd");
}
void GVMixVocoderDesc_t::SetFreqRangeEnd(float value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flFreqRangeEnd", true, value);
}
float GVMixVocoderDesc_t::GetFldBUnvoicedGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_fldBUnvoicedGain");
}
void GVMixVocoderDesc_t::SetFldBUnvoicedGain(float value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_fldBUnvoicedGain", true, value);
}
float GVMixVocoderDesc_t::GetAttackTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flAttackTimeMS");
}
void GVMixVocoderDesc_t::SetAttackTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flAttackTimeMS", true, value);
}
float GVMixVocoderDesc_t::GetReleaseTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixVocoderDesc_t", "m_flReleaseTimeMS");
}
void GVMixVocoderDesc_t::SetReleaseTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_flReleaseTimeMS", true, value);
}
int32_t GVMixVocoderDesc_t::GetDebugBand() const {
    return GetSchemaValue<int32_t>(m_ptr, "VMixVocoderDesc_t", "m_nDebugBand");
}
void GVMixVocoderDesc_t::SetDebugBand(int32_t value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_nDebugBand", true, value);
}
bool GVMixVocoderDesc_t::GetPeakMode() const {
    return GetSchemaValue<bool>(m_ptr, "VMixVocoderDesc_t", "m_bPeakMode");
}
void GVMixVocoderDesc_t::SetPeakMode(bool value) {
    SetSchemaValue(m_ptr, "VMixVocoderDesc_t", "m_bPeakMode", true, value);
}
std::string GVMixVocoderDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixVocoderDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixVocoderDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixVocoderDesc_t>("VMixVocoderDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BandCount", &GVMixVocoderDesc_t::GetBandCount, &GVMixVocoderDesc_t::SetBandCount)
        .addProperty("Bandwidth", &GVMixVocoderDesc_t::GetBandwidth, &GVMixVocoderDesc_t::SetBandwidth)
        .addProperty("FldBModGain", &GVMixVocoderDesc_t::GetFldBModGain, &GVMixVocoderDesc_t::SetFldBModGain)
        .addProperty("FreqRangeStart", &GVMixVocoderDesc_t::GetFreqRangeStart, &GVMixVocoderDesc_t::SetFreqRangeStart)
        .addProperty("FreqRangeEnd", &GVMixVocoderDesc_t::GetFreqRangeEnd, &GVMixVocoderDesc_t::SetFreqRangeEnd)
        .addProperty("FldBUnvoicedGain", &GVMixVocoderDesc_t::GetFldBUnvoicedGain, &GVMixVocoderDesc_t::SetFldBUnvoicedGain)
        .addProperty("AttackTimeMS", &GVMixVocoderDesc_t::GetAttackTimeMS, &GVMixVocoderDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixVocoderDesc_t::GetReleaseTimeMS, &GVMixVocoderDesc_t::SetReleaseTimeMS)
        .addProperty("DebugBand", &GVMixVocoderDesc_t::GetDebugBand, &GVMixVocoderDesc_t::SetDebugBand)
        .addProperty("PeakMode", &GVMixVocoderDesc_t::GetPeakMode, &GVMixVocoderDesc_t::SetPeakMode)
        .addFunction("ToPtr", &GVMixVocoderDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixVocoderDesc_t::IsValid)
        .endClass();
}