#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtActionAim::GCBtActionAim(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtActionAim::GCBtActionAim(void *ptr) {
    m_ptr = ptr;
}
std::string GCBtActionAim::GetSensorInputKey() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBtActionAim", "m_szSensorInputKey").Get();
}
void GCBtActionAim::SetSensorInputKey(std::string value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_szSensorInputKey", false, CUtlString(value.c_str()));
}
std::string GCBtActionAim::GetAimReadyKey() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBtActionAim", "m_szAimReadyKey").Get();
}
void GCBtActionAim::SetAimReadyKey(std::string value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_szAimReadyKey", false, CUtlString(value.c_str()));
}
float GCBtActionAim::GetZoomCooldownTimestamp() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flZoomCooldownTimestamp");
}
void GCBtActionAim::SetZoomCooldownTimestamp(float value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_flZoomCooldownTimestamp", false, value);
}
bool GCBtActionAim::GetDoneAiming() const {
    return GetSchemaValue<bool>(m_ptr, "CBtActionAim", "m_bDoneAiming");
}
void GCBtActionAim::SetDoneAiming(bool value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_bDoneAiming", false, value);
}
float GCBtActionAim::GetLerpStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flLerpStartTime");
}
void GCBtActionAim::SetLerpStartTime(float value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_flLerpStartTime", false, value);
}
float GCBtActionAim::GetNextLookTargetLerpTime() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flNextLookTargetLerpTime");
}
void GCBtActionAim::SetNextLookTargetLerpTime(float value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_flNextLookTargetLerpTime", false, value);
}
float GCBtActionAim::GetPenaltyReductionRatio() const {
    return GetSchemaValue<float>(m_ptr, "CBtActionAim", "m_flPenaltyReductionRatio");
}
void GCBtActionAim::SetPenaltyReductionRatio(float value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_flPenaltyReductionRatio", false, value);
}
QAngle GCBtActionAim::GetNextLookTarget() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBtActionAim", "m_NextLookTarget");
}
void GCBtActionAim::SetNextLookTarget(QAngle value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_NextLookTarget", false, value);
}
GCountdownTimer GCBtActionAim::GetAimTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionAim", "m_AimTimer"));
    return value;
}
void GCBtActionAim::SetAimTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_AimTimer", false, value);
}
GCountdownTimer GCBtActionAim::GetSniperHoldTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionAim", "m_SniperHoldTimer"));
    return value;
}
void GCBtActionAim::SetSniperHoldTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_SniperHoldTimer", false, value);
}
GCountdownTimer GCBtActionAim::GetFocusIntervalTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionAim", "m_FocusIntervalTimer"));
    return value;
}
void GCBtActionAim::SetFocusIntervalTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_FocusIntervalTimer", false, value);
}
bool GCBtActionAim::GetAcquired() const {
    return GetSchemaValue<bool>(m_ptr, "CBtActionAim", "m_bAcquired");
}
void GCBtActionAim::SetAcquired(bool value) {
    SetSchemaValue(m_ptr, "CBtActionAim", "m_bAcquired", false, value);
}
std::string GCBtActionAim::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtActionAim::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNode GCBtActionAim::GetParent() const {
    GCBtNode value(m_ptr);
    return value;
}
void GCBtActionAim::SetParent(GCBtNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtActionAim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionAim>("CBtActionAim")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SensorInputKey", &GCBtActionAim::GetSensorInputKey, &GCBtActionAim::SetSensorInputKey)
        .addProperty("AimReadyKey", &GCBtActionAim::GetAimReadyKey, &GCBtActionAim::SetAimReadyKey)
        .addProperty("ZoomCooldownTimestamp", &GCBtActionAim::GetZoomCooldownTimestamp, &GCBtActionAim::SetZoomCooldownTimestamp)
        .addProperty("DoneAiming", &GCBtActionAim::GetDoneAiming, &GCBtActionAim::SetDoneAiming)
        .addProperty("LerpStartTime", &GCBtActionAim::GetLerpStartTime, &GCBtActionAim::SetLerpStartTime)
        .addProperty("NextLookTargetLerpTime", &GCBtActionAim::GetNextLookTargetLerpTime, &GCBtActionAim::SetNextLookTargetLerpTime)
        .addProperty("PenaltyReductionRatio", &GCBtActionAim::GetPenaltyReductionRatio, &GCBtActionAim::SetPenaltyReductionRatio)
        .addProperty("NextLookTarget", &GCBtActionAim::GetNextLookTarget, &GCBtActionAim::SetNextLookTarget)
        .addProperty("AimTimer", &GCBtActionAim::GetAimTimer, &GCBtActionAim::SetAimTimer)
        .addProperty("SniperHoldTimer", &GCBtActionAim::GetSniperHoldTimer, &GCBtActionAim::SetSniperHoldTimer)
        .addProperty("FocusIntervalTimer", &GCBtActionAim::GetFocusIntervalTimer, &GCBtActionAim::SetFocusIntervalTimer)
        .addProperty("Acquired", &GCBtActionAim::GetAcquired, &GCBtActionAim::SetAcquired)
        .addProperty("Parent", &GCBtActionAim::GetParent, &GCBtActionAim::SetParent)
        .addFunction("ToPtr", &GCBtActionAim::ToPtr)
        .addFunction("IsValid", &GCBtActionAim::IsValid)
        .endClass();
}