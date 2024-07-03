#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixModDelayDesc_t::GVMixModDelayDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixModDelayDesc_t::GVMixModDelayDesc_t(void *ptr) {
    m_ptr = ptr;
}
GVMixFilterDesc_t GVMixModDelayDesc_t::GetFeedbackFilter() const {
    GVMixFilterDesc_t value(GetSchemaPtr(m_ptr, "VMixModDelayDesc_t", "m_feedbackFilter"));
    return value;
}
void GVMixModDelayDesc_t::SetFeedbackFilter(GVMixFilterDesc_t value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_feedbackFilter", true, value);
}
bool GVMixModDelayDesc_t::GetPhaseInvert() const {
    return GetSchemaValue<bool>(m_ptr, "VMixModDelayDesc_t", "m_bPhaseInvert");
}
void GVMixModDelayDesc_t::SetPhaseInvert(bool value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_bPhaseInvert", true, value);
}
float GVMixModDelayDesc_t::GetGlideTime() const {
    return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flGlideTime");
}
void GVMixModDelayDesc_t::SetGlideTime(float value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flGlideTime", true, value);
}
float GVMixModDelayDesc_t::GetDelay() const {
    return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flDelay");
}
void GVMixModDelayDesc_t::SetDelay(float value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flDelay", true, value);
}
float GVMixModDelayDesc_t::GetOutputGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flOutputGain");
}
void GVMixModDelayDesc_t::SetOutputGain(float value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flOutputGain", true, value);
}
float GVMixModDelayDesc_t::GetFeedbackGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flFeedbackGain");
}
void GVMixModDelayDesc_t::SetFeedbackGain(float value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flFeedbackGain", true, value);
}
float GVMixModDelayDesc_t::GetModRate() const {
    return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flModRate");
}
void GVMixModDelayDesc_t::SetModRate(float value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flModRate", true, value);
}
float GVMixModDelayDesc_t::GetModDepth() const {
    return GetSchemaValue<float>(m_ptr, "VMixModDelayDesc_t", "m_flModDepth");
}
void GVMixModDelayDesc_t::SetModDepth(float value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_flModDepth", true, value);
}
bool GVMixModDelayDesc_t::GetApplyAntialiasing() const {
    return GetSchemaValue<bool>(m_ptr, "VMixModDelayDesc_t", "m_bApplyAntialiasing");
}
void GVMixModDelayDesc_t::SetApplyAntialiasing(bool value) {
    SetSchemaValue(m_ptr, "VMixModDelayDesc_t", "m_bApplyAntialiasing", true, value);
}
std::string GVMixModDelayDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixModDelayDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixModDelayDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixModDelayDesc_t>("VMixModDelayDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FeedbackFilter", &GVMixModDelayDesc_t::GetFeedbackFilter, &GVMixModDelayDesc_t::SetFeedbackFilter)
        .addProperty("PhaseInvert", &GVMixModDelayDesc_t::GetPhaseInvert, &GVMixModDelayDesc_t::SetPhaseInvert)
        .addProperty("GlideTime", &GVMixModDelayDesc_t::GetGlideTime, &GVMixModDelayDesc_t::SetGlideTime)
        .addProperty("Delay", &GVMixModDelayDesc_t::GetDelay, &GVMixModDelayDesc_t::SetDelay)
        .addProperty("OutputGain", &GVMixModDelayDesc_t::GetOutputGain, &GVMixModDelayDesc_t::SetOutputGain)
        .addProperty("FeedbackGain", &GVMixModDelayDesc_t::GetFeedbackGain, &GVMixModDelayDesc_t::SetFeedbackGain)
        .addProperty("ModRate", &GVMixModDelayDesc_t::GetModRate, &GVMixModDelayDesc_t::SetModRate)
        .addProperty("ModDepth", &GVMixModDelayDesc_t::GetModDepth, &GVMixModDelayDesc_t::SetModDepth)
        .addProperty("ApplyAntialiasing", &GVMixModDelayDesc_t::GetApplyAntialiasing, &GVMixModDelayDesc_t::SetApplyAntialiasing)
        .addFunction("ToPtr", &GVMixModDelayDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixModDelayDesc_t::IsValid)
        .endClass();
}