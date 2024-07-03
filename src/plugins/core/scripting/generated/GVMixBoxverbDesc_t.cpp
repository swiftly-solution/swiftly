#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixBoxverbDesc_t::GVMixBoxverbDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixBoxverbDesc_t::GVMixBoxverbDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixBoxverbDesc_t::GetSizeMax() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMax");
}
void GVMixBoxverbDesc_t::SetSizeMax(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMax", true, value);
}
float GVMixBoxverbDesc_t::GetSizeMin() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMin");
}
void GVMixBoxverbDesc_t::SetSizeMin(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flSizeMin", true, value);
}
float GVMixBoxverbDesc_t::GetComplexity() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flComplexity");
}
void GVMixBoxverbDesc_t::SetComplexity(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flComplexity", true, value);
}
float GVMixBoxverbDesc_t::GetDiffusion() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flDiffusion");
}
void GVMixBoxverbDesc_t::SetDiffusion(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flDiffusion", true, value);
}
float GVMixBoxverbDesc_t::GetModDepth() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flModDepth");
}
void GVMixBoxverbDesc_t::SetModDepth(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flModDepth", true, value);
}
float GVMixBoxverbDesc_t::GetModRate() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flModRate");
}
void GVMixBoxverbDesc_t::SetModRate(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flModRate", true, value);
}
bool GVMixBoxverbDesc_t::GetParallel() const {
    return GetSchemaValue<bool>(m_ptr, "VMixBoxverbDesc_t", "m_bParallel");
}
void GVMixBoxverbDesc_t::SetParallel(bool value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_bParallel", true, value);
}
GVMixFilterDesc_t GVMixBoxverbDesc_t::GetFilterType() const {
    GVMixFilterDesc_t value(GetSchemaPtr(m_ptr, "VMixBoxverbDesc_t", "m_filterType"));
    return value;
}
void GVMixBoxverbDesc_t::SetFilterType(GVMixFilterDesc_t value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_filterType", true, value);
}
float GVMixBoxverbDesc_t::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flWidth");
}
void GVMixBoxverbDesc_t::SetWidth(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flWidth", true, value);
}
float GVMixBoxverbDesc_t::GetHeight() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flHeight");
}
void GVMixBoxverbDesc_t::SetHeight(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flHeight", true, value);
}
float GVMixBoxverbDesc_t::GetDepth() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flDepth");
}
void GVMixBoxverbDesc_t::SetDepth(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flDepth", true, value);
}
float GVMixBoxverbDesc_t::GetFeedbackScale() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackScale");
}
void GVMixBoxverbDesc_t::SetFeedbackScale(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackScale", true, value);
}
float GVMixBoxverbDesc_t::GetFeedbackWidth() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackWidth");
}
void GVMixBoxverbDesc_t::SetFeedbackWidth(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackWidth", true, value);
}
float GVMixBoxverbDesc_t::GetFeedbackHeight() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackHeight");
}
void GVMixBoxverbDesc_t::SetFeedbackHeight(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackHeight", true, value);
}
float GVMixBoxverbDesc_t::GetFeedbackDepth() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackDepth");
}
void GVMixBoxverbDesc_t::SetFeedbackDepth(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flFeedbackDepth", true, value);
}
float GVMixBoxverbDesc_t::GetOutputGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flOutputGain");
}
void GVMixBoxverbDesc_t::SetOutputGain(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flOutputGain", true, value);
}
float GVMixBoxverbDesc_t::GetTaps() const {
    return GetSchemaValue<float>(m_ptr, "VMixBoxverbDesc_t", "m_flTaps");
}
void GVMixBoxverbDesc_t::SetTaps(float value) {
    SetSchemaValue(m_ptr, "VMixBoxverbDesc_t", "m_flTaps", true, value);
}
std::string GVMixBoxverbDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixBoxverbDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixBoxverbDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixBoxverbDesc_t>("VMixBoxverbDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SizeMax", &GVMixBoxverbDesc_t::GetSizeMax, &GVMixBoxverbDesc_t::SetSizeMax)
        .addProperty("SizeMin", &GVMixBoxverbDesc_t::GetSizeMin, &GVMixBoxverbDesc_t::SetSizeMin)
        .addProperty("Complexity", &GVMixBoxverbDesc_t::GetComplexity, &GVMixBoxverbDesc_t::SetComplexity)
        .addProperty("Diffusion", &GVMixBoxverbDesc_t::GetDiffusion, &GVMixBoxverbDesc_t::SetDiffusion)
        .addProperty("ModDepth", &GVMixBoxverbDesc_t::GetModDepth, &GVMixBoxverbDesc_t::SetModDepth)
        .addProperty("ModRate", &GVMixBoxverbDesc_t::GetModRate, &GVMixBoxverbDesc_t::SetModRate)
        .addProperty("Parallel", &GVMixBoxverbDesc_t::GetParallel, &GVMixBoxverbDesc_t::SetParallel)
        .addProperty("FilterType", &GVMixBoxverbDesc_t::GetFilterType, &GVMixBoxverbDesc_t::SetFilterType)
        .addProperty("Width", &GVMixBoxverbDesc_t::GetWidth, &GVMixBoxverbDesc_t::SetWidth)
        .addProperty("Height", &GVMixBoxverbDesc_t::GetHeight, &GVMixBoxverbDesc_t::SetHeight)
        .addProperty("Depth", &GVMixBoxverbDesc_t::GetDepth, &GVMixBoxverbDesc_t::SetDepth)
        .addProperty("FeedbackScale", &GVMixBoxverbDesc_t::GetFeedbackScale, &GVMixBoxverbDesc_t::SetFeedbackScale)
        .addProperty("FeedbackWidth", &GVMixBoxverbDesc_t::GetFeedbackWidth, &GVMixBoxverbDesc_t::SetFeedbackWidth)
        .addProperty("FeedbackHeight", &GVMixBoxverbDesc_t::GetFeedbackHeight, &GVMixBoxverbDesc_t::SetFeedbackHeight)
        .addProperty("FeedbackDepth", &GVMixBoxverbDesc_t::GetFeedbackDepth, &GVMixBoxverbDesc_t::SetFeedbackDepth)
        .addProperty("OutputGain", &GVMixBoxverbDesc_t::GetOutputGain, &GVMixBoxverbDesc_t::SetOutputGain)
        .addProperty("Taps", &GVMixBoxverbDesc_t::GetTaps, &GVMixBoxverbDesc_t::SetTaps)
        .addFunction("ToPtr", &GVMixBoxverbDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixBoxverbDesc_t::IsValid)
        .endClass();
}