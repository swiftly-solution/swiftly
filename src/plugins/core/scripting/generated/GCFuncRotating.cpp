#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncRotating::GCFuncRotating(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncRotating::GCFuncRotating(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCFuncRotating::GetOnStopped() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncRotating", "m_OnStopped"));
    return value;
}
void GCFuncRotating::SetOnStopped(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_OnStopped", false, value);
}
GCEntityIOOutput GCFuncRotating::GetOnStarted() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncRotating", "m_OnStarted"));
    return value;
}
void GCFuncRotating::SetOnStarted(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_OnStarted", false, value);
}
GCEntityIOOutput GCFuncRotating::GetOnReachedStart() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CFuncRotating", "m_OnReachedStart"));
    return value;
}
void GCFuncRotating::SetOnReachedStart(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_OnReachedStart", false, value);
}
Vector GCFuncRotating::GetLocalRotationVector() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncRotating", "m_localRotationVector");
}
void GCFuncRotating::SetLocalRotationVector(Vector value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_localRotationVector", false, value);
}
float GCFuncRotating::GetFanFriction() const {
    return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flFanFriction");
}
void GCFuncRotating::SetFanFriction(float value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_flFanFriction", false, value);
}
float GCFuncRotating::GetAttenuation() const {
    return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flAttenuation");
}
void GCFuncRotating::SetAttenuation(float value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_flAttenuation", false, value);
}
float GCFuncRotating::GetVolume() const {
    return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flVolume");
}
void GCFuncRotating::SetVolume(float value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_flVolume", false, value);
}
float GCFuncRotating::GetTargetSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flTargetSpeed");
}
void GCFuncRotating::SetTargetSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_flTargetSpeed", false, value);
}
float GCFuncRotating::GetMaxSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flMaxSpeed");
}
void GCFuncRotating::SetMaxSpeed(float value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_flMaxSpeed", false, value);
}
float GCFuncRotating::GetBlockDamage() const {
    return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flBlockDamage");
}
void GCFuncRotating::SetBlockDamage(float value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_flBlockDamage", false, value);
}
std::string GCFuncRotating::GetNoiseRunning() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncRotating", "m_NoiseRunning").String();
}
void GCFuncRotating::SetNoiseRunning(std::string value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_NoiseRunning", false, CUtlSymbolLarge(value.c_str()));
}
bool GCFuncRotating::GetReversed() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncRotating", "m_bReversed");
}
void GCFuncRotating::SetReversed(bool value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_bReversed", false, value);
}
bool GCFuncRotating::GetAccelDecel() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncRotating", "m_bAccelDecel");
}
void GCFuncRotating::SetAccelDecel(bool value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_bAccelDecel", false, value);
}
QAngle GCFuncRotating::GetPrevLocalAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncRotating", "m_prevLocalAngles");
}
void GCFuncRotating::SetPrevLocalAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_prevLocalAngles", false, value);
}
QAngle GCFuncRotating::GetStart() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncRotating", "m_angStart");
}
void GCFuncRotating::SetStart(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_angStart", false, value);
}
bool GCFuncRotating::GetStopAtStartPos() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncRotating", "m_bStopAtStartPos");
}
void GCFuncRotating::SetStopAtStartPos(bool value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_bStopAtStartPos", false, value);
}
Vector GCFuncRotating::GetClientOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CFuncRotating", "m_vecClientOrigin");
}
void GCFuncRotating::SetClientOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_vecClientOrigin", false, value);
}
QAngle GCFuncRotating::GetClientAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CFuncRotating", "m_vecClientAngles");
}
void GCFuncRotating::SetClientAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CFuncRotating", "m_vecClientAngles", false, value);
}
std::string GCFuncRotating::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncRotating::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncRotating::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncRotating::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncRotating(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncRotating>("CFuncRotating")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnStopped", &GCFuncRotating::GetOnStopped, &GCFuncRotating::SetOnStopped)
        .addProperty("OnStarted", &GCFuncRotating::GetOnStarted, &GCFuncRotating::SetOnStarted)
        .addProperty("OnReachedStart", &GCFuncRotating::GetOnReachedStart, &GCFuncRotating::SetOnReachedStart)
        .addProperty("LocalRotationVector", &GCFuncRotating::GetLocalRotationVector, &GCFuncRotating::SetLocalRotationVector)
        .addProperty("FanFriction", &GCFuncRotating::GetFanFriction, &GCFuncRotating::SetFanFriction)
        .addProperty("Attenuation", &GCFuncRotating::GetAttenuation, &GCFuncRotating::SetAttenuation)
        .addProperty("Volume", &GCFuncRotating::GetVolume, &GCFuncRotating::SetVolume)
        .addProperty("TargetSpeed", &GCFuncRotating::GetTargetSpeed, &GCFuncRotating::SetTargetSpeed)
        .addProperty("MaxSpeed", &GCFuncRotating::GetMaxSpeed, &GCFuncRotating::SetMaxSpeed)
        .addProperty("BlockDamage", &GCFuncRotating::GetBlockDamage, &GCFuncRotating::SetBlockDamage)
        .addProperty("NoiseRunning", &GCFuncRotating::GetNoiseRunning, &GCFuncRotating::SetNoiseRunning)
        .addProperty("Reversed", &GCFuncRotating::GetReversed, &GCFuncRotating::SetReversed)
        .addProperty("AccelDecel", &GCFuncRotating::GetAccelDecel, &GCFuncRotating::SetAccelDecel)
        .addProperty("PrevLocalAngles", &GCFuncRotating::GetPrevLocalAngles, &GCFuncRotating::SetPrevLocalAngles)
        .addProperty("Start", &GCFuncRotating::GetStart, &GCFuncRotating::SetStart)
        .addProperty("StopAtStartPos", &GCFuncRotating::GetStopAtStartPos, &GCFuncRotating::SetStopAtStartPos)
        .addProperty("ClientOrigin", &GCFuncRotating::GetClientOrigin, &GCFuncRotating::SetClientOrigin)
        .addProperty("ClientAngles", &GCFuncRotating::GetClientAngles, &GCFuncRotating::SetClientAngles)
        .addProperty("Parent", &GCFuncRotating::GetParent, &GCFuncRotating::SetParent)
        .addFunction("ToPtr", &GCFuncRotating::ToPtr)
        .addFunction("IsValid", &GCFuncRotating::IsValid)
        .endClass();
}