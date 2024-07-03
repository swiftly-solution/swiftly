#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerStaticAdditiveSynth::GCVoiceContainerStaticAdditiveSynth(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerStaticAdditiveSynth::GCVoiceContainerStaticAdditiveSynth(void *ptr) {
    m_ptr = ptr;
}
float GCVoiceContainerStaticAdditiveSynth::GetMinVolume() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMinVolume");
}
void GCVoiceContainerStaticAdditiveSynth::SetMinVolume(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMinVolume", false, value);
}
int32_t GCVoiceContainerStaticAdditiveSynth::GetInstancesAtMinVolume() const {
    return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMinVolume");
}
void GCVoiceContainerStaticAdditiveSynth::SetInstancesAtMinVolume(int32_t value) {
    SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMinVolume", false, value);
}
float GCVoiceContainerStaticAdditiveSynth::GetMaxVolume() const {
    return GetSchemaValue<float>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMaxVolume");
}
void GCVoiceContainerStaticAdditiveSynth::SetMaxVolume(float value) {
    SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_flMaxVolume", false, value);
}
int32_t GCVoiceContainerStaticAdditiveSynth::GetInstancesAtMaxVolume() const {
    return GetSchemaValue<int32_t>(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMaxVolume");
}
void GCVoiceContainerStaticAdditiveSynth::SetInstancesAtMaxVolume(int32_t value) {
    SetSchemaValue(m_ptr, "CVoiceContainerStaticAdditiveSynth", "m_nInstancesAtMaxVolume", false, value);
}
std::string GCVoiceContainerStaticAdditiveSynth::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerStaticAdditiveSynth::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCVoiceContainerStaticAdditiveSynth(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerStaticAdditiveSynth>("CVoiceContainerStaticAdditiveSynth")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinVolume", &GCVoiceContainerStaticAdditiveSynth::GetMinVolume, &GCVoiceContainerStaticAdditiveSynth::SetMinVolume)
        .addProperty("InstancesAtMinVolume", &GCVoiceContainerStaticAdditiveSynth::GetInstancesAtMinVolume, &GCVoiceContainerStaticAdditiveSynth::SetInstancesAtMinVolume)
        .addProperty("MaxVolume", &GCVoiceContainerStaticAdditiveSynth::GetMaxVolume, &GCVoiceContainerStaticAdditiveSynth::SetMaxVolume)
        .addProperty("InstancesAtMaxVolume", &GCVoiceContainerStaticAdditiveSynth::GetInstancesAtMaxVolume, &GCVoiceContainerStaticAdditiveSynth::SetInstancesAtMaxVolume)
        .addFunction("ToPtr", &GCVoiceContainerStaticAdditiveSynth::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerStaticAdditiveSynth::IsValid)
        .endClass();
}