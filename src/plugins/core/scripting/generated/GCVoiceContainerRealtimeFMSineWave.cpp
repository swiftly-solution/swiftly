#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerRealtimeFMSineWave::GCVoiceContainerRealtimeFMSineWave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerRealtimeFMSineWave::GCVoiceContainerRealtimeFMSineWave(void *ptr) {
    m_ptr = ptr;
}
float GCVoiceContainerRealtimeFMSineWave::GetCarrierFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flCarrierFrequency");
}
void GCVoiceContainerRealtimeFMSineWave::SetCarrierFrequency(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flCarrierFrequency", false, value);
}
float GCVoiceContainerRealtimeFMSineWave::GetModulatorFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorFrequency");
}
void GCVoiceContainerRealtimeFMSineWave::SetModulatorFrequency(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorFrequency", false, value);
}
float GCVoiceContainerRealtimeFMSineWave::GetModulatorAmount() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorAmount");
}
void GCVoiceContainerRealtimeFMSineWave::SetModulatorAmount(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerRealtimeFMSineWave", "m_flModulatorAmount", false, value);
}
std::string GCVoiceContainerRealtimeFMSineWave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerRealtimeFMSineWave::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerRealtimeFMSineWave::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerRealtimeFMSineWave::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerRealtimeFMSineWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerRealtimeFMSineWave>("CVoiceContainerRealtimeFMSineWave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CarrierFrequency", &GCVoiceContainerRealtimeFMSineWave::GetCarrierFrequency, &GCVoiceContainerRealtimeFMSineWave::SetCarrierFrequency)
        .addProperty("ModulatorFrequency", &GCVoiceContainerRealtimeFMSineWave::GetModulatorFrequency, &GCVoiceContainerRealtimeFMSineWave::SetModulatorFrequency)
        .addProperty("ModulatorAmount", &GCVoiceContainerRealtimeFMSineWave::GetModulatorAmount, &GCVoiceContainerRealtimeFMSineWave::SetModulatorAmount)
        .addProperty("Parent", &GCVoiceContainerRealtimeFMSineWave::GetParent, &GCVoiceContainerRealtimeFMSineWave::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerRealtimeFMSineWave::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerRealtimeFMSineWave::IsValid)
        .endClass();
}