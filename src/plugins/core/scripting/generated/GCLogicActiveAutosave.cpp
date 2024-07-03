#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicActiveAutosave::GCLogicActiveAutosave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicActiveAutosave::GCLogicActiveAutosave(void *ptr) {
    m_ptr = ptr;
}
int32_t GCLogicActiveAutosave::GetTriggerHitPoints() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicActiveAutosave", "m_TriggerHitPoints");
}
void GCLogicActiveAutosave::SetTriggerHitPoints(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicActiveAutosave", "m_TriggerHitPoints", false, value);
}
float GCLogicActiveAutosave::GetTimeToTrigger() const {
    return GetSchemaValue<float>(m_ptr, "CLogicActiveAutosave", "m_flTimeToTrigger");
}
void GCLogicActiveAutosave::SetTimeToTrigger(float value) {
    SetSchemaValue(m_ptr, "CLogicActiveAutosave", "m_flTimeToTrigger", false, value);
}
float GCLogicActiveAutosave::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CLogicActiveAutosave", "m_flStartTime");
}
void GCLogicActiveAutosave::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CLogicActiveAutosave", "m_flStartTime", false, value);
}
float GCLogicActiveAutosave::GetDangerousTime() const {
    return GetSchemaValue<float>(m_ptr, "CLogicActiveAutosave", "m_flDangerousTime");
}
void GCLogicActiveAutosave::SetDangerousTime(float value) {
    SetSchemaValue(m_ptr, "CLogicActiveAutosave", "m_flDangerousTime", false, value);
}
std::string GCLogicActiveAutosave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicActiveAutosave::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicAutosave GCLogicActiveAutosave::GetParent() const {
    GCLogicAutosave value(m_ptr);
    return value;
}
void GCLogicActiveAutosave::SetParent(GCLogicAutosave value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicActiveAutosave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicActiveAutosave>("CLogicActiveAutosave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TriggerHitPoints", &GCLogicActiveAutosave::GetTriggerHitPoints, &GCLogicActiveAutosave::SetTriggerHitPoints)
        .addProperty("TimeToTrigger", &GCLogicActiveAutosave::GetTimeToTrigger, &GCLogicActiveAutosave::SetTimeToTrigger)
        .addProperty("StartTime", &GCLogicActiveAutosave::GetStartTime, &GCLogicActiveAutosave::SetStartTime)
        .addProperty("DangerousTime", &GCLogicActiveAutosave::GetDangerousTime, &GCLogicActiveAutosave::SetDangerousTime)
        .addProperty("Parent", &GCLogicActiveAutosave::GetParent, &GCLogicActiveAutosave::SetParent)
        .addFunction("ToPtr", &GCLogicActiveAutosave::ToPtr)
        .addFunction("IsValid", &GCLogicActiveAutosave::IsValid)
        .endClass();
}