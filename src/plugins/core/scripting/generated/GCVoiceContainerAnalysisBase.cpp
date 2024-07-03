#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerAnalysisBase::GCVoiceContainerAnalysisBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerAnalysisBase::GCVoiceContainerAnalysisBase(void *ptr) {
    m_ptr = ptr;
}
bool GCVoiceContainerAnalysisBase::GetRegenerateCurveOnCompile() const {
    return GetSchemaValue<bool>(m_ptr, "CVoiceContainerAnalysisBase", "m_bRegenerateCurveOnCompile");
}
void GCVoiceContainerAnalysisBase::SetRegenerateCurveOnCompile(bool value) {
    SetSchemaValue(m_ptr, "CVoiceContainerAnalysisBase", "m_bRegenerateCurveOnCompile", false, value);
}
std::string GCVoiceContainerAnalysisBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerAnalysisBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCVoiceContainerAnalysisBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerAnalysisBase>("CVoiceContainerAnalysisBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RegenerateCurveOnCompile", &GCVoiceContainerAnalysisBase::GetRegenerateCurveOnCompile, &GCVoiceContainerAnalysisBase::SetRegenerateCurveOnCompile)
        .addFunction("ToPtr", &GCVoiceContainerAnalysisBase::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerAnalysisBase::IsValid)
        .endClass();
}