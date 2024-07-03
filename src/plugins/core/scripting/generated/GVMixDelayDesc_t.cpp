#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixDelayDesc_t::GVMixDelayDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixDelayDesc_t::GVMixDelayDesc_t(void *ptr) {
    m_ptr = ptr;
}
GVMixFilterDesc_t GVMixDelayDesc_t::GetFeedbackFilter() const {
    GVMixFilterDesc_t value(GetSchemaPtr(m_ptr, "VMixDelayDesc_t", "m_feedbackFilter"));
    return value;
}
void GVMixDelayDesc_t::SetFeedbackFilter(GVMixFilterDesc_t value) {
    SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_feedbackFilter", true, value);
}
bool GVMixDelayDesc_t::GetEnableFilter() const {
    return GetSchemaValue<bool>(m_ptr, "VMixDelayDesc_t", "m_bEnableFilter");
}
void GVMixDelayDesc_t::SetEnableFilter(bool value) {
    SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_bEnableFilter", true, value);
}
float GVMixDelayDesc_t::GetDelay() const {
    return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flDelay");
}
void GVMixDelayDesc_t::SetDelay(float value) {
    SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flDelay", true, value);
}
float GVMixDelayDesc_t::GetDirectGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flDirectGain");
}
void GVMixDelayDesc_t::SetDirectGain(float value) {
    SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flDirectGain", true, value);
}
float GVMixDelayDesc_t::GetDelayGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flDelayGain");
}
void GVMixDelayDesc_t::SetDelayGain(float value) {
    SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flDelayGain", true, value);
}
float GVMixDelayDesc_t::GetFeedbackGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flFeedbackGain");
}
void GVMixDelayDesc_t::SetFeedbackGain(float value) {
    SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flFeedbackGain", true, value);
}
float GVMixDelayDesc_t::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixDelayDesc_t", "m_flWidth");
}
void GVMixDelayDesc_t::SetWidth(float value) {
    SetSchemaValue(m_ptr, "VMixDelayDesc_t", "m_flWidth", true, value);
}
std::string GVMixDelayDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixDelayDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixDelayDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDelayDesc_t>("VMixDelayDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FeedbackFilter", &GVMixDelayDesc_t::GetFeedbackFilter, &GVMixDelayDesc_t::SetFeedbackFilter)
        .addProperty("EnableFilter", &GVMixDelayDesc_t::GetEnableFilter, &GVMixDelayDesc_t::SetEnableFilter)
        .addProperty("Delay", &GVMixDelayDesc_t::GetDelay, &GVMixDelayDesc_t::SetDelay)
        .addProperty("DirectGain", &GVMixDelayDesc_t::GetDirectGain, &GVMixDelayDesc_t::SetDirectGain)
        .addProperty("DelayGain", &GVMixDelayDesc_t::GetDelayGain, &GVMixDelayDesc_t::SetDelayGain)
        .addProperty("FeedbackGain", &GVMixDelayDesc_t::GetFeedbackGain, &GVMixDelayDesc_t::SetFeedbackGain)
        .addProperty("Width", &GVMixDelayDesc_t::GetWidth, &GVMixDelayDesc_t::SetWidth)
        .addFunction("ToPtr", &GVMixDelayDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixDelayDesc_t::IsValid)
        .endClass();
}