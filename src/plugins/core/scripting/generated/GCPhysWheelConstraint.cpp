#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysWheelConstraint::GCPhysWheelConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysWheelConstraint::GCPhysWheelConstraint(void *ptr) {
    m_ptr = ptr;
}
float GCPhysWheelConstraint::GetSuspensionFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSuspensionFrequency");
}
void GCPhysWheelConstraint::SetSuspensionFrequency(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSuspensionFrequency", false, value);
}
float GCPhysWheelConstraint::GetSuspensionDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSuspensionDampingRatio");
}
void GCPhysWheelConstraint::SetSuspensionDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSuspensionDampingRatio", false, value);
}
float GCPhysWheelConstraint::GetSuspensionHeightOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSuspensionHeightOffset");
}
void GCPhysWheelConstraint::SetSuspensionHeightOffset(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSuspensionHeightOffset", false, value);
}
bool GCPhysWheelConstraint::GetEnableSuspensionLimit() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysWheelConstraint", "m_bEnableSuspensionLimit");
}
void GCPhysWheelConstraint::SetEnableSuspensionLimit(bool value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_bEnableSuspensionLimit", false, value);
}
float GCPhysWheelConstraint::GetMinSuspensionOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMinSuspensionOffset");
}
void GCPhysWheelConstraint::SetMinSuspensionOffset(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMinSuspensionOffset", false, value);
}
float GCPhysWheelConstraint::GetMaxSuspensionOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMaxSuspensionOffset");
}
void GCPhysWheelConstraint::SetMaxSuspensionOffset(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMaxSuspensionOffset", false, value);
}
bool GCPhysWheelConstraint::GetEnableSteeringLimit() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysWheelConstraint", "m_bEnableSteeringLimit");
}
void GCPhysWheelConstraint::SetEnableSteeringLimit(bool value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_bEnableSteeringLimit", false, value);
}
float GCPhysWheelConstraint::GetMinSteeringAngle() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMinSteeringAngle");
}
void GCPhysWheelConstraint::SetMinSteeringAngle(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMinSteeringAngle", false, value);
}
float GCPhysWheelConstraint::GetMaxSteeringAngle() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMaxSteeringAngle");
}
void GCPhysWheelConstraint::SetMaxSteeringAngle(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMaxSteeringAngle", false, value);
}
float GCPhysWheelConstraint::GetSteeringAxisFriction() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSteeringAxisFriction");
}
void GCPhysWheelConstraint::SetSteeringAxisFriction(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSteeringAxisFriction", false, value);
}
float GCPhysWheelConstraint::GetSpinAxisFriction() const {
    return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSpinAxisFriction");
}
void GCPhysWheelConstraint::SetSpinAxisFriction(float value) {
    SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSpinAxisFriction", false, value);
}
std::string GCPhysWheelConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysWheelConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCPhysWheelConstraint::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCPhysWheelConstraint::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysWheelConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysWheelConstraint>("CPhysWheelConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SuspensionFrequency", &GCPhysWheelConstraint::GetSuspensionFrequency, &GCPhysWheelConstraint::SetSuspensionFrequency)
        .addProperty("SuspensionDampingRatio", &GCPhysWheelConstraint::GetSuspensionDampingRatio, &GCPhysWheelConstraint::SetSuspensionDampingRatio)
        .addProperty("SuspensionHeightOffset", &GCPhysWheelConstraint::GetSuspensionHeightOffset, &GCPhysWheelConstraint::SetSuspensionHeightOffset)
        .addProperty("EnableSuspensionLimit", &GCPhysWheelConstraint::GetEnableSuspensionLimit, &GCPhysWheelConstraint::SetEnableSuspensionLimit)
        .addProperty("MinSuspensionOffset", &GCPhysWheelConstraint::GetMinSuspensionOffset, &GCPhysWheelConstraint::SetMinSuspensionOffset)
        .addProperty("MaxSuspensionOffset", &GCPhysWheelConstraint::GetMaxSuspensionOffset, &GCPhysWheelConstraint::SetMaxSuspensionOffset)
        .addProperty("EnableSteeringLimit", &GCPhysWheelConstraint::GetEnableSteeringLimit, &GCPhysWheelConstraint::SetEnableSteeringLimit)
        .addProperty("MinSteeringAngle", &GCPhysWheelConstraint::GetMinSteeringAngle, &GCPhysWheelConstraint::SetMinSteeringAngle)
        .addProperty("MaxSteeringAngle", &GCPhysWheelConstraint::GetMaxSteeringAngle, &GCPhysWheelConstraint::SetMaxSteeringAngle)
        .addProperty("SteeringAxisFriction", &GCPhysWheelConstraint::GetSteeringAxisFriction, &GCPhysWheelConstraint::SetSteeringAxisFriction)
        .addProperty("SpinAxisFriction", &GCPhysWheelConstraint::GetSpinAxisFriction, &GCPhysWheelConstraint::SetSpinAxisFriction)
        .addProperty("Parent", &GCPhysWheelConstraint::GetParent, &GCPhysWheelConstraint::SetParent)
        .addFunction("ToPtr", &GCPhysWheelConstraint::ToPtr)
        .addFunction("IsValid", &GCPhysWheelConstraint::IsValid)
        .endClass();
}