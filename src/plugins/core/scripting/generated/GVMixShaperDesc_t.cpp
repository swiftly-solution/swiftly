#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixShaperDesc_t::GVMixShaperDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixShaperDesc_t::GVMixShaperDesc_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GVMixShaperDesc_t::GetShape() const {
    return GetSchemaValue<int32_t>(m_ptr, "VMixShaperDesc_t", "m_nShape");
}
void GVMixShaperDesc_t::SetShape(int32_t value) {
    SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_nShape", true, value);
}
float GVMixShaperDesc_t::GetFldbDrive() const {
    return GetSchemaValue<float>(m_ptr, "VMixShaperDesc_t", "m_fldbDrive");
}
void GVMixShaperDesc_t::SetFldbDrive(float value) {
    SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_fldbDrive", true, value);
}
float GVMixShaperDesc_t::GetFldbOutputGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixShaperDesc_t", "m_fldbOutputGain");
}
void GVMixShaperDesc_t::SetFldbOutputGain(float value) {
    SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_fldbOutputGain", true, value);
}
float GVMixShaperDesc_t::GetWetMix() const {
    return GetSchemaValue<float>(m_ptr, "VMixShaperDesc_t", "m_flWetMix");
}
void GVMixShaperDesc_t::SetWetMix(float value) {
    SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_flWetMix", true, value);
}
int32_t GVMixShaperDesc_t::GetOversampleFactor() const {
    return GetSchemaValue<int32_t>(m_ptr, "VMixShaperDesc_t", "m_nOversampleFactor");
}
void GVMixShaperDesc_t::SetOversampleFactor(int32_t value) {
    SetSchemaValue(m_ptr, "VMixShaperDesc_t", "m_nOversampleFactor", true, value);
}
std::string GVMixShaperDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixShaperDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixShaperDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixShaperDesc_t>("VMixShaperDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Shape", &GVMixShaperDesc_t::GetShape, &GVMixShaperDesc_t::SetShape)
        .addProperty("FldbDrive", &GVMixShaperDesc_t::GetFldbDrive, &GVMixShaperDesc_t::SetFldbDrive)
        .addProperty("FldbOutputGain", &GVMixShaperDesc_t::GetFldbOutputGain, &GVMixShaperDesc_t::SetFldbOutputGain)
        .addProperty("WetMix", &GVMixShaperDesc_t::GetWetMix, &GVMixShaperDesc_t::SetWetMix)
        .addProperty("OversampleFactor", &GVMixShaperDesc_t::GetOversampleFactor, &GVMixShaperDesc_t::SetOversampleFactor)
        .addFunction("ToPtr", &GVMixShaperDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixShaperDesc_t::IsValid)
        .endClass();
}