#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerBase::GCVoiceContainerBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerBase::GCVoiceContainerBase(void *ptr) {
    m_ptr = ptr;
}
bool GCVoiceContainerBase::GetHideAnalyzers() const {
    return GetSchemaValue<bool>(m_ptr, "CVoiceContainerBase", "m_bHideAnalyzers");
}
void GCVoiceContainerBase::SetHideAnalyzers(bool value) {
    SetSchemaValue(m_ptr, "CVoiceContainerBase", "m_bHideAnalyzers", false, value);
}
std::vector<GCVoiceContainerAnalysisBase*> GCVoiceContainerBase::GetAnalysisContainers() const {
    CUtlVector<GCVoiceContainerAnalysisBase*>* vec = GetSchemaValue<CUtlVector<GCVoiceContainerAnalysisBase*>*>(m_ptr, "CVoiceContainerBase", "m_analysisContainers"); std::vector<GCVoiceContainerAnalysisBase*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCVoiceContainerBase::SetAnalysisContainers(std::vector<GCVoiceContainerAnalysisBase*> value) {
    SetSchemaValueCUtlVector<GCVoiceContainerAnalysisBase*>(m_ptr, "CVoiceContainerBase", "m_analysisContainers", false, value);
}
std::string GCVoiceContainerBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCVoiceContainerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerBase>("CVoiceContainerBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HideAnalyzers", &GCVoiceContainerBase::GetHideAnalyzers, &GCVoiceContainerBase::SetHideAnalyzers)
        .addProperty("AnalysisContainers", &GCVoiceContainerBase::GetAnalysisContainers, &GCVoiceContainerBase::SetAnalysisContainers)
        .addFunction("ToPtr", &GCVoiceContainerBase::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerBase::IsValid)
        .endClass();
}