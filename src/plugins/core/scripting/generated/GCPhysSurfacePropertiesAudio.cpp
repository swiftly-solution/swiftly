#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysSurfacePropertiesAudio::GCPhysSurfacePropertiesAudio(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysSurfacePropertiesAudio::GCPhysSurfacePropertiesAudio(void *ptr) {
    m_ptr = ptr;
}
float GCPhysSurfacePropertiesAudio::GetReflectivity() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_reflectivity");
}
void GCPhysSurfacePropertiesAudio::SetReflectivity(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_reflectivity", false, value);
}
float GCPhysSurfacePropertiesAudio::GetHardnessFactor() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardnessFactor");
}
void GCPhysSurfacePropertiesAudio::SetHardnessFactor(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardnessFactor", false, value);
}
float GCPhysSurfacePropertiesAudio::GetRoughnessFactor() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughnessFactor");
}
void GCPhysSurfacePropertiesAudio::SetRoughnessFactor(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughnessFactor", false, value);
}
float GCPhysSurfacePropertiesAudio::GetRoughThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughThreshold");
}
void GCPhysSurfacePropertiesAudio::SetRoughThreshold(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_roughThreshold", false, value);
}
float GCPhysSurfacePropertiesAudio::GetHardThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardThreshold");
}
void GCPhysSurfacePropertiesAudio::SetHardThreshold(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardThreshold", false, value);
}
float GCPhysSurfacePropertiesAudio::GetHardVelocityThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardVelocityThreshold");
}
void GCPhysSurfacePropertiesAudio::SetHardVelocityThreshold(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_hardVelocityThreshold", false, value);
}
float GCPhysSurfacePropertiesAudio::GetStaticImpactVolume() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_flStaticImpactVolume");
}
void GCPhysSurfacePropertiesAudio::SetStaticImpactVolume(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_flStaticImpactVolume", false, value);
}
float GCPhysSurfacePropertiesAudio::GetOcclusionFactor() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesAudio", "m_flOcclusionFactor");
}
void GCPhysSurfacePropertiesAudio::SetOcclusionFactor(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesAudio", "m_flOcclusionFactor", false, value);
}
std::string GCPhysSurfacePropertiesAudio::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysSurfacePropertiesAudio::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPhysSurfacePropertiesAudio(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfacePropertiesAudio>("CPhysSurfacePropertiesAudio")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Reflectivity", &GCPhysSurfacePropertiesAudio::GetReflectivity, &GCPhysSurfacePropertiesAudio::SetReflectivity)
        .addProperty("HardnessFactor", &GCPhysSurfacePropertiesAudio::GetHardnessFactor, &GCPhysSurfacePropertiesAudio::SetHardnessFactor)
        .addProperty("RoughnessFactor", &GCPhysSurfacePropertiesAudio::GetRoughnessFactor, &GCPhysSurfacePropertiesAudio::SetRoughnessFactor)
        .addProperty("RoughThreshold", &GCPhysSurfacePropertiesAudio::GetRoughThreshold, &GCPhysSurfacePropertiesAudio::SetRoughThreshold)
        .addProperty("HardThreshold", &GCPhysSurfacePropertiesAudio::GetHardThreshold, &GCPhysSurfacePropertiesAudio::SetHardThreshold)
        .addProperty("HardVelocityThreshold", &GCPhysSurfacePropertiesAudio::GetHardVelocityThreshold, &GCPhysSurfacePropertiesAudio::SetHardVelocityThreshold)
        .addProperty("StaticImpactVolume", &GCPhysSurfacePropertiesAudio::GetStaticImpactVolume, &GCPhysSurfacePropertiesAudio::SetStaticImpactVolume)
        .addProperty("OcclusionFactor", &GCPhysSurfacePropertiesAudio::GetOcclusionFactor, &GCPhysSurfacePropertiesAudio::SetOcclusionFactor)
        .addFunction("ToPtr", &GCPhysSurfacePropertiesAudio::ToPtr)
        .addFunction("IsValid", &GCPhysSurfacePropertiesAudio::IsValid)
        .endClass();
}