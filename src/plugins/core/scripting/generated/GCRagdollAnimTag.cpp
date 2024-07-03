#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollAnimTag::GCRagdollAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollAnimTag::GCRagdollAnimTag(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCRagdollAnimTag::GetPoseControl() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CRagdollAnimTag", "m_nPoseControl");
}
void GCRagdollAnimTag::SetPoseControl(uint64_t value) {
    SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_nPoseControl", false, value);
}
float GCRagdollAnimTag::GetFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flFrequency");
}
void GCRagdollAnimTag::SetFrequency(float value) {
    SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flFrequency", false, value);
}
float GCRagdollAnimTag::GetDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flDampingRatio");
}
void GCRagdollAnimTag::SetDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flDampingRatio", false, value);
}
float GCRagdollAnimTag::GetDecayDuration() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flDecayDuration");
}
void GCRagdollAnimTag::SetDecayDuration(float value) {
    SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flDecayDuration", false, value);
}
float GCRagdollAnimTag::GetDecayBias() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollAnimTag", "m_flDecayBias");
}
void GCRagdollAnimTag::SetDecayBias(float value) {
    SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_flDecayBias", false, value);
}
bool GCRagdollAnimTag::GetDestroy() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollAnimTag", "m_bDestroy");
}
void GCRagdollAnimTag::SetDestroy(bool value) {
    SetSchemaValue(m_ptr, "CRagdollAnimTag", "m_bDestroy", false, value);
}
std::string GCRagdollAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCRagdollAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCRagdollAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollAnimTag>("CRagdollAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PoseControl", &GCRagdollAnimTag::GetPoseControl, &GCRagdollAnimTag::SetPoseControl)
        .addProperty("Frequency", &GCRagdollAnimTag::GetFrequency, &GCRagdollAnimTag::SetFrequency)
        .addProperty("DampingRatio", &GCRagdollAnimTag::GetDampingRatio, &GCRagdollAnimTag::SetDampingRatio)
        .addProperty("DecayDuration", &GCRagdollAnimTag::GetDecayDuration, &GCRagdollAnimTag::SetDecayDuration)
        .addProperty("DecayBias", &GCRagdollAnimTag::GetDecayBias, &GCRagdollAnimTag::SetDecayBias)
        .addProperty("Destroy", &GCRagdollAnimTag::GetDestroy, &GCRagdollAnimTag::SetDestroy)
        .addProperty("Parent", &GCRagdollAnimTag::GetParent, &GCRagdollAnimTag::SetParent)
        .addFunction("ToPtr", &GCRagdollAnimTag::ToPtr)
        .addFunction("IsValid", &GCRagdollAnimTag::IsValid)
        .endClass();
}