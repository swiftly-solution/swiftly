#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysSlideConstraint::GCPhysSlideConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysSlideConstraint::GCPhysSlideConstraint(void *ptr) {
    m_ptr = ptr;
}
Vector GCPhysSlideConstraint::GetAxisEnd() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysSlideConstraint", "m_axisEnd");
}
void GCPhysSlideConstraint::SetAxisEnd(Vector value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_axisEnd", false, value);
}
float GCPhysSlideConstraint::GetSlideFriction() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_slideFriction");
}
void GCPhysSlideConstraint::SetSlideFriction(float value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_slideFriction", false, value);
}
float GCPhysSlideConstraint::GetSystemLoadScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_systemLoadScale");
}
void GCPhysSlideConstraint::SetSystemLoadScale(float value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_systemLoadScale", false, value);
}
float GCPhysSlideConstraint::GetInitialOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_initialOffset");
}
void GCPhysSlideConstraint::SetInitialOffset(float value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_initialOffset", false, value);
}
bool GCPhysSlideConstraint::GetEnableLinearConstraint() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysSlideConstraint", "m_bEnableLinearConstraint");
}
void GCPhysSlideConstraint::SetEnableLinearConstraint(bool value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_bEnableLinearConstraint", false, value);
}
bool GCPhysSlideConstraint::GetEnableAngularConstraint() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysSlideConstraint", "m_bEnableAngularConstraint");
}
void GCPhysSlideConstraint::SetEnableAngularConstraint(bool value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_bEnableAngularConstraint", false, value);
}
float GCPhysSlideConstraint::GetMotorFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_flMotorFrequency");
}
void GCPhysSlideConstraint::SetMotorFrequency(float value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_flMotorFrequency", false, value);
}
float GCPhysSlideConstraint::GetMotorDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_flMotorDampingRatio");
}
void GCPhysSlideConstraint::SetMotorDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_flMotorDampingRatio", false, value);
}
bool GCPhysSlideConstraint::GetUseEntityPivot() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysSlideConstraint", "m_bUseEntityPivot");
}
void GCPhysSlideConstraint::SetUseEntityPivot(bool value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_bUseEntityPivot", false, value);
}
GConstraintSoundInfo GCPhysSlideConstraint::GetSoundInfo() const {
    GConstraintSoundInfo value(GetSchemaPtr(m_ptr, "CPhysSlideConstraint", "m_soundInfo"));
    return value;
}
void GCPhysSlideConstraint::SetSoundInfo(GConstraintSoundInfo value) {
    SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_soundInfo", false, value);
}
std::string GCPhysSlideConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysSlideConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCPhysSlideConstraint::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCPhysSlideConstraint::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysSlideConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSlideConstraint>("CPhysSlideConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AxisEnd", &GCPhysSlideConstraint::GetAxisEnd, &GCPhysSlideConstraint::SetAxisEnd)
        .addProperty("SlideFriction", &GCPhysSlideConstraint::GetSlideFriction, &GCPhysSlideConstraint::SetSlideFriction)
        .addProperty("SystemLoadScale", &GCPhysSlideConstraint::GetSystemLoadScale, &GCPhysSlideConstraint::SetSystemLoadScale)
        .addProperty("InitialOffset", &GCPhysSlideConstraint::GetInitialOffset, &GCPhysSlideConstraint::SetInitialOffset)
        .addProperty("EnableLinearConstraint", &GCPhysSlideConstraint::GetEnableLinearConstraint, &GCPhysSlideConstraint::SetEnableLinearConstraint)
        .addProperty("EnableAngularConstraint", &GCPhysSlideConstraint::GetEnableAngularConstraint, &GCPhysSlideConstraint::SetEnableAngularConstraint)
        .addProperty("MotorFrequency", &GCPhysSlideConstraint::GetMotorFrequency, &GCPhysSlideConstraint::SetMotorFrequency)
        .addProperty("MotorDampingRatio", &GCPhysSlideConstraint::GetMotorDampingRatio, &GCPhysSlideConstraint::SetMotorDampingRatio)
        .addProperty("UseEntityPivot", &GCPhysSlideConstraint::GetUseEntityPivot, &GCPhysSlideConstraint::SetUseEntityPivot)
        .addProperty("SoundInfo", &GCPhysSlideConstraint::GetSoundInfo, &GCPhysSlideConstraint::SetSoundInfo)
        .addProperty("Parent", &GCPhysSlideConstraint::GetParent, &GCPhysSlideConstraint::SetParent)
        .addFunction("ToPtr", &GCPhysSlideConstraint::ToPtr)
        .addFunction("IsValid", &GCPhysSlideConstraint::IsValid)
        .endClass();
}