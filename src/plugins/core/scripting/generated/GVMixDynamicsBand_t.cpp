#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixDynamicsBand_t::GVMixDynamicsBand_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixDynamicsBand_t::GVMixDynamicsBand_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixDynamicsBand_t::GetFldbGainInput() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbGainInput");
}
void GVMixDynamicsBand_t::SetFldbGainInput(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbGainInput", true, value);
}
float GVMixDynamicsBand_t::GetFldbGainOutput() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbGainOutput");
}
void GVMixDynamicsBand_t::SetFldbGainOutput(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbGainOutput", true, value);
}
float GVMixDynamicsBand_t::GetFldbThresholdBelow() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdBelow");
}
void GVMixDynamicsBand_t::SetFldbThresholdBelow(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdBelow", true, value);
}
float GVMixDynamicsBand_t::GetFldbThresholdAbove() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdAbove");
}
void GVMixDynamicsBand_t::SetFldbThresholdAbove(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_fldbThresholdAbove", true, value);
}
float GVMixDynamicsBand_t::GetRatioBelow() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flRatioBelow");
}
void GVMixDynamicsBand_t::SetRatioBelow(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flRatioBelow", true, value);
}
float GVMixDynamicsBand_t::GetRatioAbove() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flRatioAbove");
}
void GVMixDynamicsBand_t::SetRatioAbove(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flRatioAbove", true, value);
}
float GVMixDynamicsBand_t::GetAttackTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flAttackTimeMS");
}
void GVMixDynamicsBand_t::SetAttackTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flAttackTimeMS", true, value);
}
float GVMixDynamicsBand_t::GetReleaseTimeMS() const {
    return GetSchemaValue<float>(m_ptr, "VMixDynamicsBand_t", "m_flReleaseTimeMS");
}
void GVMixDynamicsBand_t::SetReleaseTimeMS(float value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_flReleaseTimeMS", true, value);
}
bool GVMixDynamicsBand_t::GetEnable() const {
    return GetSchemaValue<bool>(m_ptr, "VMixDynamicsBand_t", "m_bEnable");
}
void GVMixDynamicsBand_t::SetEnable(bool value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_bEnable", true, value);
}
bool GVMixDynamicsBand_t::GetSolo() const {
    return GetSchemaValue<bool>(m_ptr, "VMixDynamicsBand_t", "m_bSolo");
}
void GVMixDynamicsBand_t::SetSolo(bool value) {
    SetSchemaValue(m_ptr, "VMixDynamicsBand_t", "m_bSolo", true, value);
}
std::string GVMixDynamicsBand_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixDynamicsBand_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixDynamicsBand_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamicsBand_t>("VMixDynamicsBand_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FldbGainInput", &GVMixDynamicsBand_t::GetFldbGainInput, &GVMixDynamicsBand_t::SetFldbGainInput)
        .addProperty("FldbGainOutput", &GVMixDynamicsBand_t::GetFldbGainOutput, &GVMixDynamicsBand_t::SetFldbGainOutput)
        .addProperty("FldbThresholdBelow", &GVMixDynamicsBand_t::GetFldbThresholdBelow, &GVMixDynamicsBand_t::SetFldbThresholdBelow)
        .addProperty("FldbThresholdAbove", &GVMixDynamicsBand_t::GetFldbThresholdAbove, &GVMixDynamicsBand_t::SetFldbThresholdAbove)
        .addProperty("RatioBelow", &GVMixDynamicsBand_t::GetRatioBelow, &GVMixDynamicsBand_t::SetRatioBelow)
        .addProperty("RatioAbove", &GVMixDynamicsBand_t::GetRatioAbove, &GVMixDynamicsBand_t::SetRatioAbove)
        .addProperty("AttackTimeMS", &GVMixDynamicsBand_t::GetAttackTimeMS, &GVMixDynamicsBand_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixDynamicsBand_t::GetReleaseTimeMS, &GVMixDynamicsBand_t::SetReleaseTimeMS)
        .addProperty("Enable", &GVMixDynamicsBand_t::GetEnable, &GVMixDynamicsBand_t::SetEnable)
        .addProperty("Solo", &GVMixDynamicsBand_t::GetSolo, &GVMixDynamicsBand_t::SetSolo)
        .addFunction("ToPtr", &GVMixDynamicsBand_t::ToPtr)
        .addFunction("IsValid", &GVMixDynamicsBand_t::IsValid)
        .endClass();
}