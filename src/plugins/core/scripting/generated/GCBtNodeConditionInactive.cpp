#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtNodeConditionInactive::GCBtNodeConditionInactive(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtNodeConditionInactive::GCBtNodeConditionInactive(void *ptr) {
    m_ptr = ptr;
}
float GCBtNodeConditionInactive::GetRoundStartThresholdSeconds() const {
    return GetSchemaValue<float>(m_ptr, "CBtNodeConditionInactive", "m_flRoundStartThresholdSeconds");
}
void GCBtNodeConditionInactive::SetRoundStartThresholdSeconds(float value) {
    SetSchemaValue(m_ptr, "CBtNodeConditionInactive", "m_flRoundStartThresholdSeconds", false, value);
}
float GCBtNodeConditionInactive::GetSensorInactivityThresholdSeconds() const {
    return GetSchemaValue<float>(m_ptr, "CBtNodeConditionInactive", "m_flSensorInactivityThresholdSeconds");
}
void GCBtNodeConditionInactive::SetSensorInactivityThresholdSeconds(float value) {
    SetSchemaValue(m_ptr, "CBtNodeConditionInactive", "m_flSensorInactivityThresholdSeconds", false, value);
}
GCountdownTimer GCBtNodeConditionInactive::GetSensorInactivityTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtNodeConditionInactive", "m_SensorInactivityTimer"));
    return value;
}
void GCBtNodeConditionInactive::SetSensorInactivityTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtNodeConditionInactive", "m_SensorInactivityTimer", false, value);
}
std::string GCBtNodeConditionInactive::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtNodeConditionInactive::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNodeCondition GCBtNodeConditionInactive::GetParent() const {
    GCBtNodeCondition value(m_ptr);
    return value;
}
void GCBtNodeConditionInactive::SetParent(GCBtNodeCondition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtNodeConditionInactive(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeConditionInactive>("CBtNodeConditionInactive")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RoundStartThresholdSeconds", &GCBtNodeConditionInactive::GetRoundStartThresholdSeconds, &GCBtNodeConditionInactive::SetRoundStartThresholdSeconds)
        .addProperty("SensorInactivityThresholdSeconds", &GCBtNodeConditionInactive::GetSensorInactivityThresholdSeconds, &GCBtNodeConditionInactive::SetSensorInactivityThresholdSeconds)
        .addProperty("SensorInactivityTimer", &GCBtNodeConditionInactive::GetSensorInactivityTimer, &GCBtNodeConditionInactive::SetSensorInactivityTimer)
        .addProperty("Parent", &GCBtNodeConditionInactive::GetParent, &GCBtNodeConditionInactive::SetParent)
        .addFunction("ToPtr", &GCBtNodeConditionInactive::ToPtr)
        .addFunction("IsValid", &GCBtNodeConditionInactive::IsValid)
        .endClass();
}