#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvFireSensor::GCEnvFireSensor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvFireSensor::GCEnvFireSensor(void *ptr) {
    m_ptr = ptr;
}
bool GCEnvFireSensor::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvFireSensor", "m_bEnabled");
}
void GCEnvFireSensor::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_bEnabled", false, value);
}
bool GCEnvFireSensor::GetHeatAtLevel() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvFireSensor", "m_bHeatAtLevel");
}
void GCEnvFireSensor::SetHeatAtLevel(bool value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_bHeatAtLevel", false, value);
}
float GCEnvFireSensor::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_radius");
}
void GCEnvFireSensor::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_radius", false, value);
}
float GCEnvFireSensor::GetTargetLevel() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_targetLevel");
}
void GCEnvFireSensor::SetTargetLevel(float value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_targetLevel", false, value);
}
float GCEnvFireSensor::GetTargetTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_targetTime");
}
void GCEnvFireSensor::SetTargetTime(float value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_targetTime", false, value);
}
float GCEnvFireSensor::GetLevelTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_levelTime");
}
void GCEnvFireSensor::SetLevelTime(float value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_levelTime", false, value);
}
GCEntityIOOutput GCEnvFireSensor::GetOnHeatLevelStart() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvFireSensor", "m_OnHeatLevelStart"));
    return value;
}
void GCEnvFireSensor::SetOnHeatLevelStart(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_OnHeatLevelStart", false, value);
}
GCEntityIOOutput GCEnvFireSensor::GetOnHeatLevelEnd() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvFireSensor", "m_OnHeatLevelEnd"));
    return value;
}
void GCEnvFireSensor::SetOnHeatLevelEnd(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvFireSensor", "m_OnHeatLevelEnd", false, value);
}
std::string GCEnvFireSensor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvFireSensor::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvFireSensor::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvFireSensor::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvFireSensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFireSensor>("CEnvFireSensor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCEnvFireSensor::GetEnabled, &GCEnvFireSensor::SetEnabled)
        .addProperty("HeatAtLevel", &GCEnvFireSensor::GetHeatAtLevel, &GCEnvFireSensor::SetHeatAtLevel)
        .addProperty("Radius", &GCEnvFireSensor::GetRadius, &GCEnvFireSensor::SetRadius)
        .addProperty("TargetLevel", &GCEnvFireSensor::GetTargetLevel, &GCEnvFireSensor::SetTargetLevel)
        .addProperty("TargetTime", &GCEnvFireSensor::GetTargetTime, &GCEnvFireSensor::SetTargetTime)
        .addProperty("LevelTime", &GCEnvFireSensor::GetLevelTime, &GCEnvFireSensor::SetLevelTime)
        .addProperty("OnHeatLevelStart", &GCEnvFireSensor::GetOnHeatLevelStart, &GCEnvFireSensor::SetOnHeatLevelStart)
        .addProperty("OnHeatLevelEnd", &GCEnvFireSensor::GetOnHeatLevelEnd, &GCEnvFireSensor::SetOnHeatLevelEnd)
        .addProperty("Parent", &GCEnvFireSensor::GetParent, &GCEnvFireSensor::SetParent)
        .addFunction("ToPtr", &GCEnvFireSensor::ToPtr)
        .addFunction("IsValid", &GCEnvFireSensor::IsValid)
        .endClass();
}