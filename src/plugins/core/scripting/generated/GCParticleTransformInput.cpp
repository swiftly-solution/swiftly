#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleTransformInput::GCParticleTransformInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleTransformInput::GCParticleTransformInput(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCParticleTransformInput::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleTransformInput", "m_nType");
}
void GCParticleTransformInput::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleTransformInput", "m_nType", false, value);
}
bool GCParticleTransformInput::GetFollowNamedValue() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleTransformInput", "m_bFollowNamedValue");
}
void GCParticleTransformInput::SetFollowNamedValue(bool value) {
    SetSchemaValue(m_ptr, "CParticleTransformInput", "m_bFollowNamedValue", false, value);
}
bool GCParticleTransformInput::GetSupportsDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleTransformInput", "m_bSupportsDisabled");
}
void GCParticleTransformInput::SetSupportsDisabled(bool value) {
    SetSchemaValue(m_ptr, "CParticleTransformInput", "m_bSupportsDisabled", false, value);
}
bool GCParticleTransformInput::GetUseOrientation() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleTransformInput", "m_bUseOrientation");
}
void GCParticleTransformInput::SetUseOrientation(bool value) {
    SetSchemaValue(m_ptr, "CParticleTransformInput", "m_bUseOrientation", false, value);
}
int32_t GCParticleTransformInput::GetControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleTransformInput", "m_nControlPoint");
}
void GCParticleTransformInput::SetControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleTransformInput", "m_nControlPoint", false, value);
}
int32_t GCParticleTransformInput::GetControlPointRangeMax() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleTransformInput", "m_nControlPointRangeMax");
}
void GCParticleTransformInput::SetControlPointRangeMax(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleTransformInput", "m_nControlPointRangeMax", false, value);
}
float GCParticleTransformInput::GetEndCPGrowthTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleTransformInput", "m_flEndCPGrowthTime");
}
void GCParticleTransformInput::SetEndCPGrowthTime(float value) {
    SetSchemaValue(m_ptr, "CParticleTransformInput", "m_flEndCPGrowthTime", false, value);
}
std::string GCParticleTransformInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleTransformInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleInput GCParticleTransformInput::GetParent() const {
    GCParticleInput value(m_ptr);
    return value;
}
void GCParticleTransformInput::SetParent(GCParticleInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleTransformInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleTransformInput>("CParticleTransformInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GCParticleTransformInput::GetType, &GCParticleTransformInput::SetType)
        .addProperty("FollowNamedValue", &GCParticleTransformInput::GetFollowNamedValue, &GCParticleTransformInput::SetFollowNamedValue)
        .addProperty("SupportsDisabled", &GCParticleTransformInput::GetSupportsDisabled, &GCParticleTransformInput::SetSupportsDisabled)
        .addProperty("UseOrientation", &GCParticleTransformInput::GetUseOrientation, &GCParticleTransformInput::SetUseOrientation)
        .addProperty("ControlPoint", &GCParticleTransformInput::GetControlPoint, &GCParticleTransformInput::SetControlPoint)
        .addProperty("ControlPointRangeMax", &GCParticleTransformInput::GetControlPointRangeMax, &GCParticleTransformInput::SetControlPointRangeMax)
        .addProperty("EndCPGrowthTime", &GCParticleTransformInput::GetEndCPGrowthTime, &GCParticleTransformInput::SetEndCPGrowthTime)
        .addProperty("Parent", &GCParticleTransformInput::GetParent, &GCParticleTransformInput::SetParent)
        .addFunction("ToPtr", &GCParticleTransformInput::ToPtr)
        .addFunction("IsValid", &GCParticleTransformInput::IsValid)
        .endClass();
}