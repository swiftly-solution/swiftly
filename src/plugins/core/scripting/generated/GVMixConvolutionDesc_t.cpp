#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixConvolutionDesc_t::GVMixConvolutionDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixConvolutionDesc_t::GVMixConvolutionDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixConvolutionDesc_t::GetFldbGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbGain");
}
void GVMixConvolutionDesc_t::SetFldbGain(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbGain", true, value);
}
float GVMixConvolutionDesc_t::GetPreDelayMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flPreDelayMS");
}
void GVMixConvolutionDesc_t::SetPreDelayMS(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flPreDelayMS", true, value);
}
float GVMixConvolutionDesc_t::GetWetMix() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flWetMix");
}
void GVMixConvolutionDesc_t::SetWetMix(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flWetMix", true, value);
}
float GVMixConvolutionDesc_t::GetFldbLow() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbLow");
}
void GVMixConvolutionDesc_t::SetFldbLow(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbLow", true, value);
}
float GVMixConvolutionDesc_t::GetFldbMid() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbMid");
}
void GVMixConvolutionDesc_t::SetFldbMid(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbMid", true, value);
}
float GVMixConvolutionDesc_t::GetFldbHigh() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_fldbHigh");
}
void GVMixConvolutionDesc_t::SetFldbHigh(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_fldbHigh", true, value);
}
float GVMixConvolutionDesc_t::GetLowCutoffFreq() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flLowCutoffFreq");
}
void GVMixConvolutionDesc_t::SetLowCutoffFreq(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flLowCutoffFreq", true, value);
}
float GVMixConvolutionDesc_t::GetHighCutoffFreq() const {
    return GetSchemaValue<float>(m_ptr, "VMixConvolutionDesc_t", "m_flHighCutoffFreq");
}
void GVMixConvolutionDesc_t::SetHighCutoffFreq(float value) {
    SetSchemaValue(m_ptr, "VMixConvolutionDesc_t", "m_flHighCutoffFreq", true, value);
}
std::string GVMixConvolutionDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixConvolutionDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixConvolutionDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixConvolutionDesc_t>("VMixConvolutionDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FldbGain", &GVMixConvolutionDesc_t::GetFldbGain, &GVMixConvolutionDesc_t::SetFldbGain)
        .addProperty("PreDelayMS", &GVMixConvolutionDesc_t::GetPreDelayMS, &GVMixConvolutionDesc_t::SetPreDelayMS)
        .addProperty("WetMix", &GVMixConvolutionDesc_t::GetWetMix, &GVMixConvolutionDesc_t::SetWetMix)
        .addProperty("FldbLow", &GVMixConvolutionDesc_t::GetFldbLow, &GVMixConvolutionDesc_t::SetFldbLow)
        .addProperty("FldbMid", &GVMixConvolutionDesc_t::GetFldbMid, &GVMixConvolutionDesc_t::SetFldbMid)
        .addProperty("FldbHigh", &GVMixConvolutionDesc_t::GetFldbHigh, &GVMixConvolutionDesc_t::SetFldbHigh)
        .addProperty("LowCutoffFreq", &GVMixConvolutionDesc_t::GetLowCutoffFreq, &GVMixConvolutionDesc_t::SetLowCutoffFreq)
        .addProperty("HighCutoffFreq", &GVMixConvolutionDesc_t::GetHighCutoffFreq, &GVMixConvolutionDesc_t::SetHighCutoffFreq)
        .addFunction("ToPtr", &GVMixConvolutionDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixConvolutionDesc_t::IsValid)
        .endClass();
}