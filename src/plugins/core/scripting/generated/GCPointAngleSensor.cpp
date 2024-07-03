#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointAngleSensor::GCPointAngleSensor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointAngleSensor::GCPointAngleSensor(void *ptr) {
    m_ptr = ptr;
}
bool GCPointAngleSensor::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointAngleSensor", "m_bDisabled");
}
void GCPointAngleSensor::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_bDisabled", false, value);
}
std::string GCPointAngleSensor::GetLookAtName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointAngleSensor", "m_nLookAtName").String();
}
void GCPointAngleSensor::SetLookAtName(std::string value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_nLookAtName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCPointAngleSensor::GetTargetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointAngleSensor", "m_hTargetEntity"));
    return value;
}
void GCPointAngleSensor::SetTargetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n");
}
GCBaseEntity GCPointAngleSensor::GetLookAtEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointAngleSensor", "m_hLookAtEntity"));
    return value;
}
void GCPointAngleSensor::SetLookAtEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LookAtEntity' is not possible.\n");
}
float GCPointAngleSensor::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CPointAngleSensor", "m_flDuration");
}
void GCPointAngleSensor::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_flDuration", false, value);
}
float GCPointAngleSensor::GetDotTolerance() const {
    return GetSchemaValue<float>(m_ptr, "CPointAngleSensor", "m_flDotTolerance");
}
void GCPointAngleSensor::SetDotTolerance(float value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_flDotTolerance", false, value);
}
float GCPointAngleSensor::GetFacingTime() const {
    return GetSchemaValue<float>(m_ptr, "CPointAngleSensor", "m_flFacingTime");
}
void GCPointAngleSensor::SetFacingTime(float value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_flFacingTime", false, value);
}
bool GCPointAngleSensor::GetFired() const {
    return GetSchemaValue<bool>(m_ptr, "CPointAngleSensor", "m_bFired");
}
void GCPointAngleSensor::SetFired(bool value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_bFired", false, value);
}
GCEntityIOOutput GCPointAngleSensor::GetOnFacingLookat() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointAngleSensor", "m_OnFacingLookat"));
    return value;
}
void GCPointAngleSensor::SetOnFacingLookat(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_OnFacingLookat", false, value);
}
GCEntityIOOutput GCPointAngleSensor::GetOnNotFacingLookat() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPointAngleSensor", "m_OnNotFacingLookat"));
    return value;
}
void GCPointAngleSensor::SetOnNotFacingLookat(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPointAngleSensor", "m_OnNotFacingLookat", false, value);
}
std::string GCPointAngleSensor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointAngleSensor::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointAngleSensor::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointAngleSensor::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointAngleSensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointAngleSensor>("CPointAngleSensor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCPointAngleSensor::GetDisabled, &GCPointAngleSensor::SetDisabled)
        .addProperty("LookAtName", &GCPointAngleSensor::GetLookAtName, &GCPointAngleSensor::SetLookAtName)
        .addProperty("TargetEntity", &GCPointAngleSensor::GetTargetEntity, &GCPointAngleSensor::SetTargetEntity)
        .addProperty("LookAtEntity", &GCPointAngleSensor::GetLookAtEntity, &GCPointAngleSensor::SetLookAtEntity)
        .addProperty("Duration", &GCPointAngleSensor::GetDuration, &GCPointAngleSensor::SetDuration)
        .addProperty("DotTolerance", &GCPointAngleSensor::GetDotTolerance, &GCPointAngleSensor::SetDotTolerance)
        .addProperty("FacingTime", &GCPointAngleSensor::GetFacingTime, &GCPointAngleSensor::SetFacingTime)
        .addProperty("Fired", &GCPointAngleSensor::GetFired, &GCPointAngleSensor::SetFired)
        .addProperty("OnFacingLookat", &GCPointAngleSensor::GetOnFacingLookat, &GCPointAngleSensor::SetOnFacingLookat)
        .addProperty("OnNotFacingLookat", &GCPointAngleSensor::GetOnNotFacingLookat, &GCPointAngleSensor::SetOnNotFacingLookat)
        .addProperty("Parent", &GCPointAngleSensor::GetParent, &GCPointAngleSensor::SetParent)
        .addFunction("ToPtr", &GCPointAngleSensor::ToPtr)
        .addFunction("IsValid", &GCPointAngleSensor::IsValid)
        .endClass();
}