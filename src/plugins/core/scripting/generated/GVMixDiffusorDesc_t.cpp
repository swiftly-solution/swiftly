#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMixDiffusorDesc_t::GVMixDiffusorDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMixDiffusorDesc_t::GVMixDiffusorDesc_t(void *ptr) {
    m_ptr = ptr;
}
float GVMixDiffusorDesc_t::GetSize() const {
    return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flSize");
}
void GVMixDiffusorDesc_t::SetSize(float value) {
    SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flSize", true, value);
}
float GVMixDiffusorDesc_t::GetComplexity() const {
    return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flComplexity");
}
void GVMixDiffusorDesc_t::SetComplexity(float value) {
    SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flComplexity", true, value);
}
float GVMixDiffusorDesc_t::GetFeedback() const {
    return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flFeedback");
}
void GVMixDiffusorDesc_t::SetFeedback(float value) {
    SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flFeedback", true, value);
}
float GVMixDiffusorDesc_t::GetOutputGain() const {
    return GetSchemaValue<float>(m_ptr, "VMixDiffusorDesc_t", "m_flOutputGain");
}
void GVMixDiffusorDesc_t::SetOutputGain(float value) {
    SetSchemaValue(m_ptr, "VMixDiffusorDesc_t", "m_flOutputGain", true, value);
}
std::string GVMixDiffusorDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMixDiffusorDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMixDiffusorDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDiffusorDesc_t>("VMixDiffusorDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Size", &GVMixDiffusorDesc_t::GetSize, &GVMixDiffusorDesc_t::SetSize)
        .addProperty("Complexity", &GVMixDiffusorDesc_t::GetComplexity, &GVMixDiffusorDesc_t::SetComplexity)
        .addProperty("Feedback", &GVMixDiffusorDesc_t::GetFeedback, &GVMixDiffusorDesc_t::SetFeedback)
        .addProperty("OutputGain", &GVMixDiffusorDesc_t::GetOutputGain, &GVMixDiffusorDesc_t::SetOutputGain)
        .addFunction("ToPtr", &GVMixDiffusorDesc_t::ToPtr)
        .addFunction("IsValid", &GVMixDiffusorDesc_t::IsValid)
        .endClass();
}