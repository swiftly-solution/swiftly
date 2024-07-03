#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysHinge::GCPhysHinge(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysHinge::GCPhysHinge(void *ptr) {
    m_ptr = ptr;
}
GConstraintSoundInfo GCPhysHinge::GetSoundInfo() const {
    GConstraintSoundInfo value(GetSchemaPtr(m_ptr, "CPhysHinge", "m_soundInfo"));
    return value;
}
void GCPhysHinge::SetSoundInfo(GConstraintSoundInfo value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_soundInfo", false, value);
}
GCEntityIOOutput GCPhysHinge::GetNotifyMinLimitReached() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysHinge", "m_NotifyMinLimitReached"));
    return value;
}
void GCPhysHinge::SetNotifyMinLimitReached(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_NotifyMinLimitReached", false, value);
}
GCEntityIOOutput GCPhysHinge::GetNotifyMaxLimitReached() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysHinge", "m_NotifyMaxLimitReached"));
    return value;
}
void GCPhysHinge::SetNotifyMaxLimitReached(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_NotifyMaxLimitReached", false, value);
}
bool GCPhysHinge::GetAtMinLimit() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysHinge", "m_bAtMinLimit");
}
void GCPhysHinge::SetAtMinLimit(bool value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_bAtMinLimit", false, value);
}
bool GCPhysHinge::GetAtMaxLimit() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysHinge", "m_bAtMaxLimit");
}
void GCPhysHinge::SetAtMaxLimit(bool value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_bAtMaxLimit", false, value);
}
Gconstraint_hingeparams_t GCPhysHinge::GetHinge() const {
    Gconstraint_hingeparams_t value(GetSchemaPtr(m_ptr, "CPhysHinge", "m_hinge"));
    return value;
}
void GCPhysHinge::SetHinge(Gconstraint_hingeparams_t value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_hinge", false, value);
}
float GCPhysHinge::GetHingeFriction() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_hingeFriction");
}
void GCPhysHinge::SetHingeFriction(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_hingeFriction", false, value);
}
float GCPhysHinge::GetSystemLoadScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_systemLoadScale");
}
void GCPhysHinge::SetSystemLoadScale(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_systemLoadScale", false, value);
}
bool GCPhysHinge::GetIsAxisLocal() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysHinge", "m_bIsAxisLocal");
}
void GCPhysHinge::SetIsAxisLocal(bool value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_bIsAxisLocal", false, value);
}
float GCPhysHinge::GetMinRotation() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMinRotation");
}
void GCPhysHinge::SetMinRotation(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_flMinRotation", false, value);
}
float GCPhysHinge::GetMaxRotation() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMaxRotation");
}
void GCPhysHinge::SetMaxRotation(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_flMaxRotation", false, value);
}
float GCPhysHinge::GetInitialRotation() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flInitialRotation");
}
void GCPhysHinge::SetInitialRotation(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_flInitialRotation", false, value);
}
float GCPhysHinge::GetMotorFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMotorFrequency");
}
void GCPhysHinge::SetMotorFrequency(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_flMotorFrequency", false, value);
}
float GCPhysHinge::GetMotorDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMotorDampingRatio");
}
void GCPhysHinge::SetMotorDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_flMotorDampingRatio", false, value);
}
float GCPhysHinge::GetAngleSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flAngleSpeed");
}
void GCPhysHinge::SetAngleSpeed(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_flAngleSpeed", false, value);
}
float GCPhysHinge::GetAngleSpeedThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flAngleSpeedThreshold");
}
void GCPhysHinge::SetAngleSpeedThreshold(float value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_flAngleSpeedThreshold", false, value);
}
GCEntityIOOutput GCPhysHinge::GetOnStartMoving() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysHinge", "m_OnStartMoving"));
    return value;
}
void GCPhysHinge::SetOnStartMoving(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_OnStartMoving", false, value);
}
GCEntityIOOutput GCPhysHinge::GetOnStopMoving() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysHinge", "m_OnStopMoving"));
    return value;
}
void GCPhysHinge::SetOnStopMoving(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysHinge", "m_OnStopMoving", false, value);
}
std::string GCPhysHinge::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysHinge::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCPhysHinge::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCPhysHinge::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysHinge(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysHinge>("CPhysHinge")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SoundInfo", &GCPhysHinge::GetSoundInfo, &GCPhysHinge::SetSoundInfo)
        .addProperty("NotifyMinLimitReached", &GCPhysHinge::GetNotifyMinLimitReached, &GCPhysHinge::SetNotifyMinLimitReached)
        .addProperty("NotifyMaxLimitReached", &GCPhysHinge::GetNotifyMaxLimitReached, &GCPhysHinge::SetNotifyMaxLimitReached)
        .addProperty("AtMinLimit", &GCPhysHinge::GetAtMinLimit, &GCPhysHinge::SetAtMinLimit)
        .addProperty("AtMaxLimit", &GCPhysHinge::GetAtMaxLimit, &GCPhysHinge::SetAtMaxLimit)
        .addProperty("Hinge", &GCPhysHinge::GetHinge, &GCPhysHinge::SetHinge)
        .addProperty("HingeFriction", &GCPhysHinge::GetHingeFriction, &GCPhysHinge::SetHingeFriction)
        .addProperty("SystemLoadScale", &GCPhysHinge::GetSystemLoadScale, &GCPhysHinge::SetSystemLoadScale)
        .addProperty("IsAxisLocal", &GCPhysHinge::GetIsAxisLocal, &GCPhysHinge::SetIsAxisLocal)
        .addProperty("MinRotation", &GCPhysHinge::GetMinRotation, &GCPhysHinge::SetMinRotation)
        .addProperty("MaxRotation", &GCPhysHinge::GetMaxRotation, &GCPhysHinge::SetMaxRotation)
        .addProperty("InitialRotation", &GCPhysHinge::GetInitialRotation, &GCPhysHinge::SetInitialRotation)
        .addProperty("MotorFrequency", &GCPhysHinge::GetMotorFrequency, &GCPhysHinge::SetMotorFrequency)
        .addProperty("MotorDampingRatio", &GCPhysHinge::GetMotorDampingRatio, &GCPhysHinge::SetMotorDampingRatio)
        .addProperty("AngleSpeed", &GCPhysHinge::GetAngleSpeed, &GCPhysHinge::SetAngleSpeed)
        .addProperty("AngleSpeedThreshold", &GCPhysHinge::GetAngleSpeedThreshold, &GCPhysHinge::SetAngleSpeedThreshold)
        .addProperty("OnStartMoving", &GCPhysHinge::GetOnStartMoving, &GCPhysHinge::SetOnStartMoving)
        .addProperty("OnStopMoving", &GCPhysHinge::GetOnStopMoving, &GCPhysHinge::SetOnStopMoving)
        .addProperty("Parent", &GCPhysHinge::GetParent, &GCPhysHinge::SetParent)
        .addFunction("ToPtr", &GCPhysHinge::ToPtr)
        .addFunction("IsValid", &GCPhysHinge::IsValid)
        .endClass();
}