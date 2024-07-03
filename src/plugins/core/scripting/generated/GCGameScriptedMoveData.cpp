#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameScriptedMoveData::GCGameScriptedMoveData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameScriptedMoveData::GCGameScriptedMoveData(void *ptr) {
    m_ptr = ptr;
}
Vector GCGameScriptedMoveData::GetAccumulatedRootMotion() const {
    return GetSchemaValue<Vector>(m_ptr, "CGameScriptedMoveData", "m_vAccumulatedRootMotion");
}
void GCGameScriptedMoveData::SetAccumulatedRootMotion(Vector value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_vAccumulatedRootMotion", false, value);
}
Vector GCGameScriptedMoveData::GetDest() const {
    return GetSchemaValue<Vector>(m_ptr, "CGameScriptedMoveData", "m_vDest");
}
void GCGameScriptedMoveData::SetDest(Vector value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_vDest", false, value);
}
Vector GCGameScriptedMoveData::GetSrc() const {
    return GetSchemaValue<Vector>(m_ptr, "CGameScriptedMoveData", "m_vSrc");
}
void GCGameScriptedMoveData::SetSrc(Vector value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_vSrc", false, value);
}
QAngle GCGameScriptedMoveData::GetSrc1() const {
    return GetSchemaValue<QAngle>(m_ptr, "CGameScriptedMoveData", "m_angSrc");
}
void GCGameScriptedMoveData::SetSrc1(QAngle value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_angSrc", false, value);
}
QAngle GCGameScriptedMoveData::GetDst() const {
    return GetSchemaValue<QAngle>(m_ptr, "CGameScriptedMoveData", "m_angDst");
}
void GCGameScriptedMoveData::SetDst(QAngle value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_angDst", false, value);
}
QAngle GCGameScriptedMoveData::GetCurrent() const {
    return GetSchemaValue<QAngle>(m_ptr, "CGameScriptedMoveData", "m_angCurrent");
}
void GCGameScriptedMoveData::SetCurrent(QAngle value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_angCurrent", false, value);
}
float GCGameScriptedMoveData::GetAngRate() const {
    return GetSchemaValue<float>(m_ptr, "CGameScriptedMoveData", "m_flAngRate");
}
void GCGameScriptedMoveData::SetAngRate(float value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_flAngRate", false, value);
}
float GCGameScriptedMoveData::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CGameScriptedMoveData", "m_flDuration");
}
void GCGameScriptedMoveData::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_flDuration", false, value);
}
float GCGameScriptedMoveData::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CGameScriptedMoveData", "m_flStartTime");
}
void GCGameScriptedMoveData::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_flStartTime", false, value);
}
bool GCGameScriptedMoveData::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bActive");
}
void GCGameScriptedMoveData::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bActive", false, value);
}
bool GCGameScriptedMoveData::GetTeleportOnEnd() const {
    return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bTeleportOnEnd");
}
void GCGameScriptedMoveData::SetTeleportOnEnd(bool value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bTeleportOnEnd", false, value);
}
bool GCGameScriptedMoveData::GetIgnoreRotation() const {
    return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bIgnoreRotation");
}
void GCGameScriptedMoveData::SetIgnoreRotation(bool value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bIgnoreRotation", false, value);
}
uint64_t GCGameScriptedMoveData::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGameScriptedMoveData", "m_nType");
}
void GCGameScriptedMoveData::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_nType", false, value);
}
bool GCGameScriptedMoveData::GetSuccess() const {
    return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bSuccess");
}
void GCGameScriptedMoveData::SetSuccess(bool value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bSuccess", false, value);
}
uint64_t GCGameScriptedMoveData::GetForcedCrouchState() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGameScriptedMoveData", "m_nForcedCrouchState");
}
void GCGameScriptedMoveData::SetForcedCrouchState(uint64_t value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_nForcedCrouchState", false, value);
}
bool GCGameScriptedMoveData::GetIgnoreCollisions() const {
    return GetSchemaValue<bool>(m_ptr, "CGameScriptedMoveData", "m_bIgnoreCollisions");
}
void GCGameScriptedMoveData::SetIgnoreCollisions(bool value) {
    SetSchemaValue(m_ptr, "CGameScriptedMoveData", "m_bIgnoreCollisions", false, value);
}
std::string GCGameScriptedMoveData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameScriptedMoveData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCGameScriptedMoveData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameScriptedMoveData>("CGameScriptedMoveData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AccumulatedRootMotion", &GCGameScriptedMoveData::GetAccumulatedRootMotion, &GCGameScriptedMoveData::SetAccumulatedRootMotion)
        .addProperty("Dest", &GCGameScriptedMoveData::GetDest, &GCGameScriptedMoveData::SetDest)
        .addProperty("Src", &GCGameScriptedMoveData::GetSrc, &GCGameScriptedMoveData::SetSrc)
        .addProperty("Src1", &GCGameScriptedMoveData::GetSrc1, &GCGameScriptedMoveData::SetSrc1)
        .addProperty("Dst", &GCGameScriptedMoveData::GetDst, &GCGameScriptedMoveData::SetDst)
        .addProperty("Current", &GCGameScriptedMoveData::GetCurrent, &GCGameScriptedMoveData::SetCurrent)
        .addProperty("AngRate", &GCGameScriptedMoveData::GetAngRate, &GCGameScriptedMoveData::SetAngRate)
        .addProperty("Duration", &GCGameScriptedMoveData::GetDuration, &GCGameScriptedMoveData::SetDuration)
        .addProperty("StartTime", &GCGameScriptedMoveData::GetStartTime, &GCGameScriptedMoveData::SetStartTime)
        .addProperty("Active", &GCGameScriptedMoveData::GetActive, &GCGameScriptedMoveData::SetActive)
        .addProperty("TeleportOnEnd", &GCGameScriptedMoveData::GetTeleportOnEnd, &GCGameScriptedMoveData::SetTeleportOnEnd)
        .addProperty("IgnoreRotation", &GCGameScriptedMoveData::GetIgnoreRotation, &GCGameScriptedMoveData::SetIgnoreRotation)
        .addProperty("Type", &GCGameScriptedMoveData::GetType, &GCGameScriptedMoveData::SetType)
        .addProperty("Success", &GCGameScriptedMoveData::GetSuccess, &GCGameScriptedMoveData::SetSuccess)
        .addProperty("ForcedCrouchState", &GCGameScriptedMoveData::GetForcedCrouchState, &GCGameScriptedMoveData::SetForcedCrouchState)
        .addProperty("IgnoreCollisions", &GCGameScriptedMoveData::GetIgnoreCollisions, &GCGameScriptedMoveData::SetIgnoreCollisions)
        .addFunction("ToPtr", &GCGameScriptedMoveData::ToPtr)
        .addFunction("IsValid", &GCGameScriptedMoveData::IsValid)
        .endClass();
}