#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixDynamics3BandDesc_t::GVMixDynamics3BandDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixDynamics3BandDesc_t::GVMixDynamics3BandDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixDynamics3BandDesc_t::GetFldbGainOutput() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbGainOutput");
}
void GVMixDynamics3BandDesc_t::SetFldbGainOutput(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbGainOutput", true, value);
}
float GVMixDynamics3BandDesc_t::GetRMSTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flRMSTimeMS");
}
void GVMixDynamics3BandDesc_t::SetRMSTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flRMSTimeMS", true, value);
}
float GVMixDynamics3BandDesc_t::GetFldbKneeWidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbKneeWidth");
}
void GVMixDynamics3BandDesc_t::SetFldbKneeWidth(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_fldbKneeWidth", true, value);
}
float GVMixDynamics3BandDesc_t::GetDepth() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flDepth");
}
void GVMixDynamics3BandDesc_t::SetDepth(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flDepth", true, value);
}
float GVMixDynamics3BandDesc_t::GetWetMix() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flWetMix");
}
void GVMixDynamics3BandDesc_t::SetWetMix(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flWetMix", true, value);
}
float GVMixDynamics3BandDesc_t::GetTimeScale() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flTimeScale");
}
void GVMixDynamics3BandDesc_t::SetTimeScale(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flTimeScale", true, value);
}
float GVMixDynamics3BandDesc_t::GetLowCutoffFreq() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flLowCutoffFreq");
}
void GVMixDynamics3BandDesc_t::SetLowCutoffFreq(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flLowCutoffFreq", true, value);
}
float GVMixDynamics3BandDesc_t::GetHighCutoffFreq() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamics3BandDesc_t", "m_flHighCutoffFreq");
}
void GVMixDynamics3BandDesc_t::SetHighCutoffFreq(float value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_flHighCutoffFreq", true, value);
}
bool GVMixDynamics3BandDesc_t::GetPeakMode() const {
    return GetSchemaValue<bool>(m_ptr, "VMixDynamics3BandDesc_t", "m_bPeakMode");
}
void GVMixDynamics3BandDesc_t::SetPeakMode(bool value) {
    SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_bPeakMode", true, value);
}
std::vector<GVMixDynamicsBand_t> GVMixDynamics3BandDesc_t::GetBandDesc() const {
    GVMixDynamicsBand_t* outValue = GetSchemaValue<GVMixDynamicsBand_t*>(m_ptr, "VMixDynamics3BandDesc_t", "m_bandDesc"); std::vector<GVMixDynamicsBand_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GVMixDynamics3BandDesc_t::SetBandDesc(std::vector<GVMixDynamicsBand_t> value) {
    GVMixDynamicsBand_t* outValue = GetSchemaValue<GVMixDynamicsBand_t*>(m_ptr, "VMixDynamics3BandDesc_t", "m_bandDesc"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "VMixDynamics3BandDesc_t", "m_bandDesc", true, outValue);
}
std::string GVMixDynamics3BandDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixDynamics3BandDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixDynamics3BandDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamics3BandDesc_t>("VMixDynamics3BandDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FldbGainOutput", &GVMixDynamics3BandDesc_t::GetFldbGainOutput, &GVMixDynamics3BandDesc_t::SetFldbGainOutput)
        .addProperty("RMSTimeMS", &GVMixDynamics3BandDesc_t::GetRMSTimeMS, &GVMixDynamics3BandDesc_t::SetRMSTimeMS)
        .addProperty("FldbKneeWidth", &GVMixDynamics3BandDesc_t::GetFldbKneeWidth, &GVMixDynamics3BandDesc_t::SetFldbKneeWidth)
        .addProperty("Depth", &GVMixDynamics3BandDesc_t::GetDepth, &GVMixDynamics3BandDesc_t::SetDepth)
        .addProperty("WetMix", &GVMixDynamics3BandDesc_t::GetWetMix, &GVMixDynamics3BandDesc_t::SetWetMix)
        .addProperty("TimeScale", &GVMixDynamics3BandDesc_t::GetTimeScale, &GVMixDynamics3BandDesc_t::SetTimeScale)
        .addProperty("LowCutoffFreq", &GVMixDynamics3BandDesc_t::GetLowCutoffFreq, &GVMixDynamics3BandDesc_t::SetLowCutoffFreq)
        .addProperty("HighCutoffFreq", &GVMixDynamics3BandDesc_t::GetHighCutoffFreq, &GVMixDynamics3BandDesc_t::SetHighCutoffFreq)
        .addProperty("PeakMode", &GVMixDynamics3BandDesc_t::GetPeakMode, &GVMixDynamics3BandDesc_t::SetPeakMode)
        .addProperty("BandDesc", &GVMixDynamics3BandDesc_t::GetBandDesc, &GVMixDynamics3BandDesc_t::SetBandDesc)
        .addFunction("ToPtr", &GVMixDynamics3BandDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixDynamics3BandDesc_t::IsValid)
        .endClass();
}