#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerAmpedDecayingSineWave::GCVoiceContainerAmpedDecayingSineWave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerAmpedDecayingSineWave::GCVoiceContainerAmpedDecayingSineWave(void *ptr) {
    m_ptr = ptr;
}
float GCVoiceContainerAmpedDecayingSineWave::GetGainAmount() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerAmpedDecayingSineWave", "m_flGainAmount");
}
void GCVoiceContainerAmpedDecayingSineWave::SetGainAmount(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerAmpedDecayingSineWave", "m_flGainAmount", false, value);
}
std::string GCVoiceContainerAmpedDecayingSineWave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerAmpedDecayingSineWave::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerDecayingSineWave GCVoiceContainerAmpedDecayingSineWave::GetParent() const {
    GCVoiceContainerDecayingSineWave value(m_ptr);
    return value;
}
void GCVoiceContainerAmpedDecayingSineWave::SetParent(GCVoiceContainerDecayingSineWave value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerAmpedDecayingSineWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerAmpedDecayingSineWave>("CVoiceContainerAmpedDecayingSineWave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GainAmount", &GCVoiceContainerAmpedDecayingSineWave::GetGainAmount, &GCVoiceContainerAmpedDecayingSineWave::SetGainAmount)
        .addProperty("Parent", &GCVoiceContainerAmpedDecayingSineWave::GetParent, &GCVoiceContainerAmpedDecayingSineWave::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerAmpedDecayingSineWave::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerAmpedDecayingSineWave::IsValid)
        .endClass();
}