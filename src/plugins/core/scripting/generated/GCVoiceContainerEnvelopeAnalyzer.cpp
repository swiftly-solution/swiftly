#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerEnvelopeAnalyzer::GCVoiceContainerEnvelopeAnalyzer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerEnvelopeAnalyzer::GCVoiceContainerEnvelopeAnalyzer(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCVoiceContainerEnvelopeAnalyzer::GetMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_mode");
}
void GCVoiceContainerEnvelopeAnalyzer::SetMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_mode", false, value);
}
int32_t GCVoiceContainerEnvelopeAnalyzer::GetSamples() const {
    return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_nSamples");
}
void GCVoiceContainerEnvelopeAnalyzer::SetSamples(int32_t value) {
    SetSchemaValue(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_nSamples", false, value);
}
float GCVoiceContainerEnvelopeAnalyzer::GetThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_flThreshold");
}
void GCVoiceContainerEnvelopeAnalyzer::SetThreshold(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerEnvelopeAnalyzer", "m_flThreshold", false, value);
}
std::string GCVoiceContainerEnvelopeAnalyzer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerEnvelopeAnalyzer::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerAnalysisBase GCVoiceContainerEnvelopeAnalyzer::GetParent() const {
    GCVoiceContainerAnalysisBase value(m_ptr);
    return value;
}
void GCVoiceContainerEnvelopeAnalyzer::SetParent(GCVoiceContainerAnalysisBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerEnvelopeAnalyzer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerEnvelopeAnalyzer>("CVoiceContainerEnvelopeAnalyzer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mode", &GCVoiceContainerEnvelopeAnalyzer::GetMode, &GCVoiceContainerEnvelopeAnalyzer::SetMode)
        .addProperty("Samples", &GCVoiceContainerEnvelopeAnalyzer::GetSamples, &GCVoiceContainerEnvelopeAnalyzer::SetSamples)
        .addProperty("Threshold", &GCVoiceContainerEnvelopeAnalyzer::GetThreshold, &GCVoiceContainerEnvelopeAnalyzer::SetThreshold)
        .addProperty("Parent", &GCVoiceContainerEnvelopeAnalyzer::GetParent, &GCVoiceContainerEnvelopeAnalyzer::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerEnvelopeAnalyzer::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerEnvelopeAnalyzer::IsValid)
        .endClass();
}