#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointAngularVelocitySensor::GCPointAngularVelocitySensor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointAngularVelocitySensor::GCPointAngularVelocitySensor(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCPointAngularVelocitySensor::GetTargetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointAngularVelocitySensor", "m_hTargetEntity"));
    return value;
}
void GCPointAngularVelocitySensor::SetTargetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n");
}
float GCPointAngularVelocitySensor::GetThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CPointAngularVelocitySensor", "m_flThreshold");
}
void GCPointAngularVelocitySensor::SetThreshold(float value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_flThreshold", false, value);
}
int32_t GCPointAngularVelocitySensor::GetLastCompareResult() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPointAngularVelocitySensor", "m_nLastCompareResult");
}
void GCPointAngularVelocitySensor::SetLastCompareResult(int32_t value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_nLastCompareResult", false, value);
}
int32_t GCPointAngularVelocitySensor::GetLastFireResult() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPointAngularVelocitySensor", "m_nLastFireResult");
}
void GCPointAngularVelocitySensor::SetLastFireResult(int32_t value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_nLastFireResult", false, value);
}
float GCPointAngularVelocitySensor::GetFireTime() const {
    return GetSchemaValue<float>(m_ptr, "CPointAngularVelocitySensor", "m_flFireTime");
}
void GCPointAngularVelocitySensor::SetFireTime(float value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_flFireTime", false, value);
}
float GCPointAngularVelocitySensor::GetFireInterval() const {
    return GetSchemaValue<float>(m_ptr, "CPointAngularVelocitySensor", "m_flFireInterval");
}
void GCPointAngularVelocitySensor::SetFireInterval(float value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_flFireInterval", false, value);
}
float GCPointAngularVelocitySensor::GetLastAngVelocity() const {
    return GetSchemaValue<float>(m_ptr, "CPointAngularVelocitySensor", "m_flLastAngVelocity");
}
void GCPointAngularVelocitySensor::SetLastAngVelocity(float value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_flLastAngVelocity", false, value);
}
QAngle GCPointAngularVelocitySensor::GetLastOrientation() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPointAngularVelocitySensor", "m_lastOrientation");
}
void GCPointAngularVelocitySensor::SetLastOrientation(QAngle value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_lastOrientation", false, value);
}
Vector GCPointAngularVelocitySensor::GetAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CPointAngularVelocitySensor", "m_vecAxis");
}
void GCPointAngularVelocitySensor::SetAxis(Vector value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_vecAxis", false, value);
}
bool GCPointAngularVelocitySensor::GetUseHelper() const {
    return GetSchemaValue<bool>(m_ptr, "CPointAngularVelocitySensor", "m_bUseHelper");
}
void GCPointAngularVelocitySensor::SetUseHelper(bool value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_bUseHelper", false, value);
}
GCEntityIOOutput GCPointAngularVelocitySensor::GetOnLessThan() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThan"));
    return value;
}
void GCPointAngularVelocitySensor::SetOnLessThan(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThan", false, value);
}
GCEntityIOOutput GCPointAngularVelocitySensor::GetOnLessThanOrEqualTo() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThanOrEqualTo"));
    return value;
}
void GCPointAngularVelocitySensor::SetOnLessThanOrEqualTo(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThanOrEqualTo", false, value);
}
GCEntityIOOutput GCPointAngularVelocitySensor::GetOnGreaterThan() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThan"));
    return value;
}
void GCPointAngularVelocitySensor::SetOnGreaterThan(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThan", false, value);
}
GCEntityIOOutput GCPointAngularVelocitySensor::GetOnGreaterThanOrEqualTo() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThanOrEqualTo"));
    return value;
}
void GCPointAngularVelocitySensor::SetOnGreaterThanOrEqualTo(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThanOrEqualTo", false, value);
}
GCEntityIOOutput GCPointAngularVelocitySensor::GetOnEqualTo() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointAngularVelocitySensor", "m_OnEqualTo"));
    return value;
}
void GCPointAngularVelocitySensor::SetOnEqualTo(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnEqualTo", false, value);
}
std::string GCPointAngularVelocitySensor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointAngularVelocitySensor::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointAngularVelocitySensor::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointAngularVelocitySensor::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointAngularVelocitySensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointAngularVelocitySensor>("CPointAngularVelocitySensor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetEntity", &GCPointAngularVelocitySensor::GetTargetEntity, &GCPointAngularVelocitySensor::SetTargetEntity)
        .addProperty("Threshold", &GCPointAngularVelocitySensor::GetThreshold, &GCPointAngularVelocitySensor::SetThreshold)
        .addProperty("LastCompareResult", &GCPointAngularVelocitySensor::GetLastCompareResult, &GCPointAngularVelocitySensor::SetLastCompareResult)
        .addProperty("LastFireResult", &GCPointAngularVelocitySensor::GetLastFireResult, &GCPointAngularVelocitySensor::SetLastFireResult)
        .addProperty("FireTime", &GCPointAngularVelocitySensor::GetFireTime, &GCPointAngularVelocitySensor::SetFireTime)
        .addProperty("FireInterval", &GCPointAngularVelocitySensor::GetFireInterval, &GCPointAngularVelocitySensor::SetFireInterval)
        .addProperty("LastAngVelocity", &GCPointAngularVelocitySensor::GetLastAngVelocity, &GCPointAngularVelocitySensor::SetLastAngVelocity)
        .addProperty("LastOrientation", &GCPointAngularVelocitySensor::GetLastOrientation, &GCPointAngularVelocitySensor::SetLastOrientation)
        .addProperty("Axis", &GCPointAngularVelocitySensor::GetAxis, &GCPointAngularVelocitySensor::SetAxis)
        .addProperty("UseHelper", &GCPointAngularVelocitySensor::GetUseHelper, &GCPointAngularVelocitySensor::SetUseHelper)
        .addProperty("OnLessThan", &GCPointAngularVelocitySensor::GetOnLessThan, &GCPointAngularVelocitySensor::SetOnLessThan)
        .addProperty("OnLessThanOrEqualTo", &GCPointAngularVelocitySensor::GetOnLessThanOrEqualTo, &GCPointAngularVelocitySensor::SetOnLessThanOrEqualTo)
        .addProperty("OnGreaterThan", &GCPointAngularVelocitySensor::GetOnGreaterThan, &GCPointAngularVelocitySensor::SetOnGreaterThan)
        .addProperty("OnGreaterThanOrEqualTo", &GCPointAngularVelocitySensor::GetOnGreaterThanOrEqualTo, &GCPointAngularVelocitySensor::SetOnGreaterThanOrEqualTo)
        .addProperty("OnEqualTo", &GCPointAngularVelocitySensor::GetOnEqualTo, &GCPointAngularVelocitySensor::SetOnEqualTo)
        .addProperty("Parent", &GCPointAngularVelocitySensor::GetParent, &GCPointAngularVelocitySensor::SetParent)
        .addFunction("ToPtr", &GCPointAngularVelocitySensor::ToPtr)
        .addFunction("IsValid", &GCPointAngularVelocitySensor::IsValid)
        .endClass();
}