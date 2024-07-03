#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDSPMixgroupModifier::GCDSPMixgroupModifier(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDSPMixgroupModifier::GCDSPMixgroupModifier(void *ptr) {
    m_ptr = ptr;
}
std::string GCDSPMixgroupModifier::GetMixgroup() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CDSPMixgroupModifier", "m_mixgroup").Get();
}
void GCDSPMixgroupModifier::SetMixgroup(std::string value) {
    SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_mixgroup", false, CUtlString(value.c_str()));
}
float GCDSPMixgroupModifier::GetModifier() const {
    return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flModifier");
}
void GCDSPMixgroupModifier::SetModifier(float value) {
    SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flModifier", false, value);
}
float GCDSPMixgroupModifier::GetModifierMin() const {
    return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flModifierMin");
}
void GCDSPMixgroupModifier::SetModifierMin(float value) {
    SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flModifierMin", false, value);
}
float GCDSPMixgroupModifier::GetSourceModifier() const {
    return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifier");
}
void GCDSPMixgroupModifier::SetSourceModifier(float value) {
    SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifier", false, value);
}
float GCDSPMixgroupModifier::GetSourceModifierMin() const {
    return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifierMin");
}
void GCDSPMixgroupModifier::SetSourceModifierMin(float value) {
    SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flSourceModifierMin", false, value);
}
float GCDSPMixgroupModifier::GetListenerReverbModifierWhenSourceReverbIsActive() const {
    return GetSchemaValue<float>(m_ptr, "CDSPMixgroupModifier", "m_flListenerReverbModifierWhenSourceReverbIsActive");
}
void GCDSPMixgroupModifier::SetListenerReverbModifierWhenSourceReverbIsActive(float value) {
    SetSchemaValue(m_ptr, "CDSPMixgroupModifier", "m_flListenerReverbModifierWhenSourceReverbIsActive", false, value);
}
std::string GCDSPMixgroupModifier::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDSPMixgroupModifier::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDSPMixgroupModifier(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDSPMixgroupModifier>("CDSPMixgroupModifier")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mixgroup", &GCDSPMixgroupModifier::GetMixgroup, &GCDSPMixgroupModifier::SetMixgroup)
        .addProperty("Modifier", &GCDSPMixgroupModifier::GetModifier, &GCDSPMixgroupModifier::SetModifier)
        .addProperty("ModifierMin", &GCDSPMixgroupModifier::GetModifierMin, &GCDSPMixgroupModifier::SetModifierMin)
        .addProperty("SourceModifier", &GCDSPMixgroupModifier::GetSourceModifier, &GCDSPMixgroupModifier::SetSourceModifier)
        .addProperty("SourceModifierMin", &GCDSPMixgroupModifier::GetSourceModifierMin, &GCDSPMixgroupModifier::SetSourceModifierMin)
        .addProperty("ListenerReverbModifierWhenSourceReverbIsActive", &GCDSPMixgroupModifier::GetListenerReverbModifierWhenSourceReverbIsActive, &GCDSPMixgroupModifier::SetListenerReverbModifierWhenSourceReverbIsActive)
        .addFunction("ToPtr", &GCDSPMixgroupModifier::ToPtr)
        .addFunction("IsValid", &GCDSPMixgroupModifier::IsValid)
        .endClass();
}