#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixOscDesc_t::GVMixOscDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixOscDesc_t::GVMixOscDesc_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GVMixOscDesc_t::GetOscType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VMixOscDesc_t", "oscType");
}
void GVMixOscDesc_t::SetOscType(uint64_t value) {
    SetSchemaValue(m_ptr, "VMixOscDesc_t", "oscType", true, value);
}
float GVMixOscDesc_t::GetFreq() const {
    return GetSchemaValue<float>(m_ptr, "VMixOscDesc_t", "m_freq");
}
void GVMixOscDesc_t::SetFreq(float value) {
    SetSchemaValue(m_ptr, "VMixOscDesc_t", "m_freq", true, value);
}
float GVMixOscDesc_t::GetPhase() const {
    return GetSchemaValue<float>(m_ptr, "VMixOscDesc_t", "m_flPhase");
}
void GVMixOscDesc_t::SetPhase(float value) {
    SetSchemaValue(m_ptr, "VMixOscDesc_t", "m_flPhase", true, value);
}
std::string GVMixOscDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixOscDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixOscDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixOscDesc_t>("VMixOscDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OscType", &GVMixOscDesc_t::GetOscType, &GVMixOscDesc_t::SetOscType)
        .addProperty("Freq", &GVMixOscDesc_t::GetFreq, &GVMixOscDesc_t::SetFreq)
        .addProperty("Phase", &GVMixOscDesc_t::GetPhase, &GVMixOscDesc_t::SetPhase)
        .addFunction("ToPtr", &GVMixOscDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixOscDesc_t::IsValid)
        .endClass();
}