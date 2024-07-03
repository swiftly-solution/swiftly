#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvTilt::GCEnvTilt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvTilt::GCEnvTilt(void *ptr) {
    m_ptr = ptr;
}
float GCEnvTilt::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CEnvTilt", "m_Duration");
}
void GCEnvTilt::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CEnvTilt", "m_Duration", false, value);
}
float GCEnvTilt::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvTilt", "m_Radius");
}
void GCEnvTilt::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvTilt", "m_Radius", false, value);
}
float GCEnvTilt::GetTiltTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvTilt", "m_TiltTime");
}
void GCEnvTilt::SetTiltTime(float value) {
    SetSchemaValue(m_ptr, "CEnvTilt", "m_TiltTime", false, value);
}
float GCEnvTilt::GetStopTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvTilt", "m_stopTime");
}
void GCEnvTilt::SetStopTime(float value) {
    SetSchemaValue(m_ptr, "CEnvTilt", "m_stopTime", false, value);
}
std::string GCEnvTilt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvTilt::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvTilt::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvTilt::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvTilt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvTilt>("CEnvTilt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Duration", &GCEnvTilt::GetDuration, &GCEnvTilt::SetDuration)
        .addProperty("Radius", &GCEnvTilt::GetRadius, &GCEnvTilt::SetRadius)
        .addProperty("TiltTime", &GCEnvTilt::GetTiltTime, &GCEnvTilt::SetTiltTime)
        .addProperty("StopTime", &GCEnvTilt::GetStopTime, &GCEnvTilt::SetStopTime)
        .addProperty("Parent", &GCEnvTilt::GetParent, &GCEnvTilt::SetParent)
        .addFunction("ToPtr", &GCEnvTilt::ToPtr)
        .addFunction("IsValid", &GCEnvTilt::IsValid)
        .endClass();
}