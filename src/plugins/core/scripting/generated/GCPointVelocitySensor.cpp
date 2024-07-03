#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointVelocitySensor::GCPointVelocitySensor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointVelocitySensor::GCPointVelocitySensor(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCPointVelocitySensor::GetTargetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointVelocitySensor", "m_hTargetEntity"));
    return value;
}
void GCPointVelocitySensor::SetTargetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n");
}
Vector GCPointVelocitySensor::GetAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CPointVelocitySensor", "m_vecAxis");
}
void GCPointVelocitySensor::SetAxis(Vector value) {
    SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_vecAxis", false, value);
}
bool GCPointVelocitySensor::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointVelocitySensor", "m_bEnabled");
}
void GCPointVelocitySensor::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_bEnabled", false, value);
}
float GCPointVelocitySensor::GetPrevVelocity() const {
    return GetSchemaValue<float>(m_ptr, "CPointVelocitySensor", "m_fPrevVelocity");
}
void GCPointVelocitySensor::SetPrevVelocity(float value) {
    SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_fPrevVelocity", false, value);
}
float GCPointVelocitySensor::GetAvgInterval() const {
    return GetSchemaValue<float>(m_ptr, "CPointVelocitySensor", "m_flAvgInterval");
}
void GCPointVelocitySensor::SetAvgInterval(float value) {
    SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_flAvgInterval", false, value);
}
std::string GCPointVelocitySensor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointVelocitySensor::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointVelocitySensor::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointVelocitySensor::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointVelocitySensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointVelocitySensor>("CPointVelocitySensor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetEntity", &GCPointVelocitySensor::GetTargetEntity, &GCPointVelocitySensor::SetTargetEntity)
        .addProperty("Axis", &GCPointVelocitySensor::GetAxis, &GCPointVelocitySensor::SetAxis)
        .addProperty("Enabled", &GCPointVelocitySensor::GetEnabled, &GCPointVelocitySensor::SetEnabled)
        .addProperty("PrevVelocity", &GCPointVelocitySensor::GetPrevVelocity, &GCPointVelocitySensor::SetPrevVelocity)
        .addProperty("AvgInterval", &GCPointVelocitySensor::GetAvgInterval, &GCPointVelocitySensor::SetAvgInterval)
        .addProperty("Parent", &GCPointVelocitySensor::GetParent, &GCPointVelocitySensor::SetParent)
        .addFunction("ToPtr", &GCPointVelocitySensor::ToPtr)
        .addFunction("IsValid", &GCPointVelocitySensor::IsValid)
        .endClass();
}