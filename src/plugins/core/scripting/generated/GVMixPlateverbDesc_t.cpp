#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixPlateverbDesc_t::GVMixPlateverbDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixPlateverbDesc_t::GVMixPlateverbDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixPlateverbDesc_t::GetPrefilter() const {
    return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flPrefilter");
}
void GVMixPlateverbDesc_t::SetPrefilter(float value) {
    SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flPrefilter", true, value);
}
float GVMixPlateverbDesc_t::GetInputDiffusion1() const {
    return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion1");
}
void GVMixPlateverbDesc_t::SetInputDiffusion1(float value) {
    SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion1", true, value);
}
float GVMixPlateverbDesc_t::GetInputDiffusion2() const {
    return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion2");
}
void GVMixPlateverbDesc_t::SetInputDiffusion2(float value) {
    SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flInputDiffusion2", true, value);
}
float GVMixPlateverbDesc_t::GetDecay() const {
    return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flDecay");
}
void GVMixPlateverbDesc_t::SetDecay(float value) {
    SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flDecay", true, value);
}
float GVMixPlateverbDesc_t::GetDamp() const {
    return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flDamp");
}
void GVMixPlateverbDesc_t::SetDamp(float value) {
    SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flDamp", true, value);
}
float GVMixPlateverbDesc_t::GetFeedbackDiffusion1() const {
    return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion1");
}
void GVMixPlateverbDesc_t::SetFeedbackDiffusion1(float value) {
    SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion1", true, value);
}
float GVMixPlateverbDesc_t::GetFeedbackDiffusion2() const {
    return GetSchemaValue<float>(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion2");
}
void GVMixPlateverbDesc_t::SetFeedbackDiffusion2(float value) {
    SetSchemaValue(m_ptr, "VMixPlateverbDesc_t", "m_flFeedbackDiffusion2", true, value);
}
std::string GVMixPlateverbDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixPlateverbDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixPlateverbDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixPlateverbDesc_t>("VMixPlateverbDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Prefilter", &GVMixPlateverbDesc_t::GetPrefilter, &GVMixPlateverbDesc_t::SetPrefilter)
        .addProperty("InputDiffusion1", &GVMixPlateverbDesc_t::GetInputDiffusion1, &GVMixPlateverbDesc_t::SetInputDiffusion1)
        .addProperty("InputDiffusion2", &GVMixPlateverbDesc_t::GetInputDiffusion2, &GVMixPlateverbDesc_t::SetInputDiffusion2)
        .addProperty("Decay", &GVMixPlateverbDesc_t::GetDecay, &GVMixPlateverbDesc_t::SetDecay)
        .addProperty("Damp", &GVMixPlateverbDesc_t::GetDamp, &GVMixPlateverbDesc_t::SetDamp)
        .addProperty("FeedbackDiffusion1", &GVMixPlateverbDesc_t::GetFeedbackDiffusion1, &GVMixPlateverbDesc_t::SetFeedbackDiffusion1)
        .addProperty("FeedbackDiffusion2", &GVMixPlateverbDesc_t::GetFeedbackDiffusion2, &GVMixPlateverbDesc_t::SetFeedbackDiffusion2)
        .addFunction("ToPtr", &GVMixPlateverbDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixPlateverbDesc_t::IsValid)
        .endClass();
}