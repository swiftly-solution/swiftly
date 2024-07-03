#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerFan::GCTriggerFan(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerFan::GCTriggerFan(void *ptr) {
    m_ptr = ptr;
}
Vector GCTriggerFan::GetFanOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerFan", "m_vFanOrigin");
}
void GCTriggerFan::SetFanOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_vFanOrigin", false, value);
}
Vector GCTriggerFan::GetFanEnd() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerFan", "m_vFanEnd");
}
void GCTriggerFan::SetFanEnd(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_vFanEnd", false, value);
}
Vector GCTriggerFan::GetNoise() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerFan", "m_vNoise");
}
void GCTriggerFan::SetNoise(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_vNoise", false, value);
}
float GCTriggerFan::GetForce() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flForce");
}
void GCTriggerFan::SetForce(float value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_flForce", false, value);
}
float GCTriggerFan::GetRopeForceScale() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flRopeForceScale");
}
void GCTriggerFan::SetRopeForceScale(float value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_flRopeForceScale", false, value);
}
float GCTriggerFan::GetPlayerForce() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flPlayerForce");
}
void GCTriggerFan::SetPlayerForce(float value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_flPlayerForce", false, value);
}
float GCTriggerFan::GetRampTime() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerFan", "m_flRampTime");
}
void GCTriggerFan::SetRampTime(float value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_flRampTime", false, value);
}
bool GCTriggerFan::GetFalloff() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bFalloff");
}
void GCTriggerFan::SetFalloff(bool value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_bFalloff", false, value);
}
bool GCTriggerFan::GetPushPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bPushPlayer");
}
void GCTriggerFan::SetPushPlayer(bool value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_bPushPlayer", false, value);
}
bool GCTriggerFan::GetRampDown() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bRampDown");
}
void GCTriggerFan::SetRampDown(bool value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_bRampDown", false, value);
}
bool GCTriggerFan::GetAddNoise() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerFan", "m_bAddNoise");
}
void GCTriggerFan::SetAddNoise(bool value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_bAddNoise", false, value);
}
GCountdownTimer GCTriggerFan::GetRampTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CTriggerFan", "m_RampTimer"));
    return value;
}
void GCTriggerFan::SetRampTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CTriggerFan", "m_RampTimer", false, value);
}
std::string GCTriggerFan::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerFan::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerFan::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerFan::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerFan(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerFan>("CTriggerFan")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FanOrigin", &GCTriggerFan::GetFanOrigin, &GCTriggerFan::SetFanOrigin)
        .addProperty("FanEnd", &GCTriggerFan::GetFanEnd, &GCTriggerFan::SetFanEnd)
        .addProperty("Noise", &GCTriggerFan::GetNoise, &GCTriggerFan::SetNoise)
        .addProperty("Force", &GCTriggerFan::GetForce, &GCTriggerFan::SetForce)
        .addProperty("RopeForceScale", &GCTriggerFan::GetRopeForceScale, &GCTriggerFan::SetRopeForceScale)
        .addProperty("PlayerForce", &GCTriggerFan::GetPlayerForce, &GCTriggerFan::SetPlayerForce)
        .addProperty("RampTime", &GCTriggerFan::GetRampTime, &GCTriggerFan::SetRampTime)
        .addProperty("Falloff", &GCTriggerFan::GetFalloff, &GCTriggerFan::SetFalloff)
        .addProperty("PushPlayer", &GCTriggerFan::GetPushPlayer, &GCTriggerFan::SetPushPlayer)
        .addProperty("RampDown", &GCTriggerFan::GetRampDown, &GCTriggerFan::SetRampDown)
        .addProperty("AddNoise", &GCTriggerFan::GetAddNoise, &GCTriggerFan::SetAddNoise)
        .addProperty("RampTimer", &GCTriggerFan::GetRampTimer, &GCTriggerFan::SetRampTimer)
        .addProperty("Parent", &GCTriggerFan::GetParent, &GCTriggerFan::SetParent)
        .addFunction("ToPtr", &GCTriggerFan::ToPtr)
        .addFunction("IsValid", &GCTriggerFan::IsValid)
        .endClass();
}