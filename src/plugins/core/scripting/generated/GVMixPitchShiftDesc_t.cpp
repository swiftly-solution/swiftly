#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixPitchShiftDesc_t::GVMixPitchShiftDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixPitchShiftDesc_t::GVMixPitchShiftDesc_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GVMixPitchShiftDesc_t::GetGrainSampleCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "VMixPitchShiftDesc_t", "m_nGrainSampleCount");
}
void GVMixPitchShiftDesc_t::SetGrainSampleCount(int32_t value) {
    SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_nGrainSampleCount", true, value);
}
float GVMixPitchShiftDesc_t::GetPitchShift() const {
    return GetSchemaValue<float>(m_ptr, "VMixPitchShiftDesc_t", "m_flPitchShift");
}
void GVMixPitchShiftDesc_t::SetPitchShift(float value) {
    SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_flPitchShift", true, value);
}
int32_t GVMixPitchShiftDesc_t::GetQuality() const {
    return GetSchemaValue<int32_t>(m_ptr, "VMixPitchShiftDesc_t", "m_nQuality");
}
void GVMixPitchShiftDesc_t::SetQuality(int32_t value) {
    SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_nQuality", true, value);
}
int32_t GVMixPitchShiftDesc_t::GetProcType() const {
    return GetSchemaValue<int32_t>(m_ptr, "VMixPitchShiftDesc_t", "m_nProcType");
}
void GVMixPitchShiftDesc_t::SetProcType(int32_t value) {
    SetSchemaValue(m_ptr, "VMixPitchShiftDesc_t", "m_nProcType", true, value);
}
std::string GVMixPitchShiftDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixPitchShiftDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixPitchShiftDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixPitchShiftDesc_t>("VMixPitchShiftDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GrainSampleCount", &GVMixPitchShiftDesc_t::GetGrainSampleCount, &GVMixPitchShiftDesc_t::SetGrainSampleCount)
        .addProperty("PitchShift", &GVMixPitchShiftDesc_t::GetPitchShift, &GVMixPitchShiftDesc_t::SetPitchShift)
        .addProperty("Quality", &GVMixPitchShiftDesc_t::GetQuality, &GVMixPitchShiftDesc_t::SetQuality)
        .addProperty("ProcType", &GVMixPitchShiftDesc_t::GetProcType, &GVMixPitchShiftDesc_t::SetProcType)
        .addFunction("ToPtr", &GVMixPitchShiftDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixPitchShiftDesc_t::IsValid)
        .endClass();
}