#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerRandomSampler::GCVoiceContainerRandomSampler(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerRandomSampler::GCVoiceContainerRandomSampler(void *ptr) {
    m_ptr = ptr;
}
float GCVoiceContainerRandomSampler::GetAmplitude() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitude");
}
void GCVoiceContainerRandomSampler::SetAmplitude(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitude", false, value);
}
float GCVoiceContainerRandomSampler::GetAmplitudeJitter() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitudeJitter");
}
void GCVoiceContainerRandomSampler::SetAmplitudeJitter(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flAmplitudeJitter", false, value);
}
float GCVoiceContainerRandomSampler::GetTimeJitter() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flTimeJitter");
}
void GCVoiceContainerRandomSampler::SetTimeJitter(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flTimeJitter", false, value);
}
float GCVoiceContainerRandomSampler::GetMaxLength() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerRandomSampler", "m_flMaxLength");
}
void GCVoiceContainerRandomSampler::SetMaxLength(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_flMaxLength", false, value);
}
int32_t GCVoiceContainerRandomSampler::GetNumDelayVariations() const {
    return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerRandomSampler", "m_nNumDelayVariations");
}
void GCVoiceContainerRandomSampler::SetNumDelayVariations(int32_t value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRandomSampler", "m_nNumDelayVariations", false, value);
}
std::string GCVoiceContainerRandomSampler::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerRandomSampler::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerRandomSampler::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerRandomSampler::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerRandomSampler(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerRandomSampler>("CVoiceContainerRandomSampler")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Amplitude", &GCVoiceContainerRandomSampler::GetAmplitude, &GCVoiceContainerRandomSampler::SetAmplitude)
        .addProperty("AmplitudeJitter", &GCVoiceContainerRandomSampler::GetAmplitudeJitter, &GCVoiceContainerRandomSampler::SetAmplitudeJitter)
        .addProperty("TimeJitter", &GCVoiceContainerRandomSampler::GetTimeJitter, &GCVoiceContainerRandomSampler::SetTimeJitter)
        .addProperty("MaxLength", &GCVoiceContainerRandomSampler::GetMaxLength, &GCVoiceContainerRandomSampler::SetMaxLength)
        .addProperty("NumDelayVariations", &GCVoiceContainerRandomSampler::GetNumDelayVariations, &GCVoiceContainerRandomSampler::SetNumDelayVariations)
        .addProperty("Parent", &GCVoiceContainerRandomSampler::GetParent, &GCVoiceContainerRandomSampler::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerRandomSampler::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerRandomSampler::IsValid)
        .endClass();
}