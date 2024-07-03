#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixUtilityDesc_t::GVMixUtilityDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixUtilityDesc_t::GVMixUtilityDesc_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GVMixUtilityDesc_t::GetOp() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VMixUtilityDesc_t", "m_nOp");
}
void GVMixUtilityDesc_t::SetOp(uint64_t value) {
    SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_nOp", true, value);
}
float GVMixUtilityDesc_t::GetInputPan() const {
    return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_flInputPan");
}
void GVMixUtilityDesc_t::SetInputPan(float value) {
    SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_flInputPan", true, value);
}
float GVMixUtilityDesc_t::GetOutputBalance() const {
    return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_flOutputBalance");
}
void GVMixUtilityDesc_t::SetOutputBalance(float value) {
    SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_flOutputBalance", true, value);
}
float GVMixUtilityDesc_t::GetFldbOutputGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_fldbOutputGain");
}
void GVMixUtilityDesc_t::SetFldbOutputGain(float value) {
    SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_fldbOutputGain", true, value);
}
bool GVMixUtilityDesc_t::GetBassMono() const {
    return GetSchemaValue<bool>(m_ptr, "VMixUtilityDesc_t", "m_bBassMono");
}
void GVMixUtilityDesc_t::SetBassMono(bool value) {
    SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_bBassMono", true, value);
}
float GVMixUtilityDesc_t::GetBassFreq() const {
    return GetSchemaValue<float>(m_ptr, "VMixUtilityDesc_t", "m_flBassFreq");
}
void GVMixUtilityDesc_t::SetBassFreq(float value) {
    SetSchemaValue(m_ptr, "VMixUtilityDesc_t", "m_flBassFreq", true, value);
}
std::string GVMixUtilityDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixUtilityDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixUtilityDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixUtilityDesc_t>("VMixUtilityDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Op", &GVMixUtilityDesc_t::GetOp, &GVMixUtilityDesc_t::SetOp)
        .addProperty("InputPan", &GVMixUtilityDesc_t::GetInputPan, &GVMixUtilityDesc_t::SetInputPan)
        .addProperty("OutputBalance", &GVMixUtilityDesc_t::GetOutputBalance, &GVMixUtilityDesc_t::SetOutputBalance)
        .addProperty("FldbOutputGain", &GVMixUtilityDesc_t::GetFldbOutputGain, &GVMixUtilityDesc_t::SetFldbOutputGain)
        .addProperty("BassMono", &GVMixUtilityDesc_t::GetBassMono, &GVMixUtilityDesc_t::SetBassMono)
        .addProperty("BassFreq", &GVMixUtilityDesc_t::GetBassFreq, &GVMixUtilityDesc_t::SetBassFreq)
        .addFunction("ToPtr", &GVMixUtilityDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixUtilityDesc_t::IsValid)
        .endClass();
}