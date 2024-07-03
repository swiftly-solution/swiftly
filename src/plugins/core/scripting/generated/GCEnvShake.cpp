#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvShake::GCEnvShake(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvShake::GCEnvShake(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvShake::GetLimitToEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvShake", "m_limitToEntity").String();
}
void GCEnvShake::SetLimitToEntity(std::string value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_limitToEntity", false, CUtlSymbolLarge(value.c_str()));
}
float GCEnvShake::GetAmplitude() const {
    return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Amplitude");
}
void GCEnvShake::SetAmplitude(float value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_Amplitude", false, value);
}
float GCEnvShake::GetFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Frequency");
}
void GCEnvShake::SetFrequency(float value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_Frequency", false, value);
}
float GCEnvShake::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Duration");
}
void GCEnvShake::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_Duration", false, value);
}
float GCEnvShake::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Radius");
}
void GCEnvShake::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_Radius", false, value);
}
float GCEnvShake::GetStopTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_stopTime");
}
void GCEnvShake::SetStopTime(float value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_stopTime", false, value);
}
float GCEnvShake::GetNextShake() const {
    return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_nextShake");
}
void GCEnvShake::SetNextShake(float value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_nextShake", false, value);
}
float GCEnvShake::GetCurrentAmp() const {
    return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_currentAmp");
}
void GCEnvShake::SetCurrentAmp(float value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_currentAmp", false, value);
}
Vector GCEnvShake::GetMaxForce() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvShake", "m_maxForce");
}
void GCEnvShake::SetMaxForce(Vector value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_maxForce", false, value);
}
GCPhysicsShake GCEnvShake::GetShakeCallback() const {
    GCPhysicsShake value(GetSchemaPtr(m_ptr, "CEnvShake", "m_shakeCallback"));
    return value;
}
void GCEnvShake::SetShakeCallback(GCPhysicsShake value) {
    SetSchemaValue(m_ptr, "CEnvShake", "m_shakeCallback", false, value);
}
std::string GCEnvShake::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvShake::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvShake::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvShake::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvShake(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvShake>("CEnvShake")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LimitToEntity", &GCEnvShake::GetLimitToEntity, &GCEnvShake::SetLimitToEntity)
        .addProperty("Amplitude", &GCEnvShake::GetAmplitude, &GCEnvShake::SetAmplitude)
        .addProperty("Frequency", &GCEnvShake::GetFrequency, &GCEnvShake::SetFrequency)
        .addProperty("Duration", &GCEnvShake::GetDuration, &GCEnvShake::SetDuration)
        .addProperty("Radius", &GCEnvShake::GetRadius, &GCEnvShake::SetRadius)
        .addProperty("StopTime", &GCEnvShake::GetStopTime, &GCEnvShake::SetStopTime)
        .addProperty("NextShake", &GCEnvShake::GetNextShake, &GCEnvShake::SetNextShake)
        .addProperty("CurrentAmp", &GCEnvShake::GetCurrentAmp, &GCEnvShake::SetCurrentAmp)
        .addProperty("MaxForce", &GCEnvShake::GetMaxForce, &GCEnvShake::SetMaxForce)
        .addProperty("ShakeCallback", &GCEnvShake::GetShakeCallback, &GCEnvShake::SetShakeCallback)
        .addProperty("Parent", &GCEnvShake::GetParent, &GCEnvShake::SetParent)
        .addFunction("ToPtr", &GCEnvShake::ToPtr)
        .addFunction("IsValid", &GCEnvShake::IsValid)
        .endClass();
}