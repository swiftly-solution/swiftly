#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerDecayingSineWave::GCVoiceContainerDecayingSineWave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerDecayingSineWave::GCVoiceContainerDecayingSineWave(void *ptr) {
    m_ptr = ptr;
}
float GCVoiceContainerDecayingSineWave::GetFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerDecayingSineWave", "m_flFrequency");
}
void GCVoiceContainerDecayingSineWave::SetFrequency(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerDecayingSineWave", "m_flFrequency", false, value);
}
float GCVoiceContainerDecayingSineWave::GetDecayTime() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerDecayingSineWave", "m_flDecayTime");
}
void GCVoiceContainerDecayingSineWave::SetDecayTime(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerDecayingSineWave", "m_flDecayTime", false, value);
}
std::string GCVoiceContainerDecayingSineWave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerDecayingSineWave::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerDecayingSineWave::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerDecayingSineWave::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerDecayingSineWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerDecayingSineWave>("CVoiceContainerDecayingSineWave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Frequency", &GCVoiceContainerDecayingSineWave::GetFrequency, &GCVoiceContainerDecayingSineWave::SetFrequency)
        .addProperty("DecayTime", &GCVoiceContainerDecayingSineWave::GetDecayTime, &GCVoiceContainerDecayingSineWave::SetDecayTime)
        .addProperty("Parent", &GCVoiceContainerDecayingSineWave::GetParent, &GCVoiceContainerDecayingSineWave::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerDecayingSineWave::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerDecayingSineWave::IsValid)
        .endClass();
}