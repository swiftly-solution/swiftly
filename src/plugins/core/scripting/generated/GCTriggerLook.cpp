#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerLook::GCTriggerLook(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerLook::GCTriggerLook(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCTriggerLook::GetLookTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTriggerLook", "m_hLookTarget"));
    return value;
}
void GCTriggerLook::SetLookTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LookTarget' is not possible.\n");
}
float GCTriggerLook::GetFieldOfView() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flFieldOfView");
}
void GCTriggerLook::SetFieldOfView(float value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_flFieldOfView", false, value);
}
float GCTriggerLook::GetLookTime() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flLookTime");
}
void GCTriggerLook::SetLookTime(float value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_flLookTime", false, value);
}
float GCTriggerLook::GetLookTimeTotal() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flLookTimeTotal");
}
void GCTriggerLook::SetLookTimeTotal(float value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_flLookTimeTotal", false, value);
}
float GCTriggerLook::GetLookTimeLast() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flLookTimeLast");
}
void GCTriggerLook::SetLookTimeLast(float value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_flLookTimeLast", false, value);
}
float GCTriggerLook::GetTimeoutDuration() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerLook", "m_flTimeoutDuration");
}
void GCTriggerLook::SetTimeoutDuration(float value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_flTimeoutDuration", false, value);
}
bool GCTriggerLook::GetTimeoutFired() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bTimeoutFired");
}
void GCTriggerLook::SetTimeoutFired(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_bTimeoutFired", false, value);
}
bool GCTriggerLook::GetIsLooking() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bIsLooking");
}
void GCTriggerLook::SetIsLooking(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_bIsLooking", false, value);
}
bool GCTriggerLook::Get2DFOV() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_b2DFOV");
}
void GCTriggerLook::Set2DFOV(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_b2DFOV", false, value);
}
bool GCTriggerLook::GetUseVelocity() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bUseVelocity");
}
void GCTriggerLook::SetUseVelocity(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_bUseVelocity", false, value);
}
bool GCTriggerLook::GetTestOcclusion() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLook", "m_bTestOcclusion");
}
void GCTriggerLook::SetTestOcclusion(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_bTestOcclusion", false, value);
}
GCEntityIOOutput GCTriggerLook::GetOnTimeout() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerLook", "m_OnTimeout"));
    return value;
}
void GCTriggerLook::SetOnTimeout(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_OnTimeout", false, value);
}
GCEntityIOOutput GCTriggerLook::GetOnStartLook() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerLook", "m_OnStartLook"));
    return value;
}
void GCTriggerLook::SetOnStartLook(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_OnStartLook", false, value);
}
GCEntityIOOutput GCTriggerLook::GetOnEndLook() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerLook", "m_OnEndLook"));
    return value;
}
void GCTriggerLook::SetOnEndLook(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerLook", "m_OnEndLook", false, value);
}
std::string GCTriggerLook::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerLook::IsValid() {
    return (m_ptr != nullptr);
}
GCTriggerOnce GCTriggerLook::GetParent() const {
    GCTriggerOnce value(m_ptr);
    return value;
}
void GCTriggerLook::SetParent(GCTriggerOnce value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerLook(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerLook>("CTriggerLook")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LookTarget", &GCTriggerLook::GetLookTarget, &GCTriggerLook::SetLookTarget)
        .addProperty("FieldOfView", &GCTriggerLook::GetFieldOfView, &GCTriggerLook::SetFieldOfView)
        .addProperty("LookTime", &GCTriggerLook::GetLookTime, &GCTriggerLook::SetLookTime)
        .addProperty("LookTimeTotal", &GCTriggerLook::GetLookTimeTotal, &GCTriggerLook::SetLookTimeTotal)
        .addProperty("LookTimeLast", &GCTriggerLook::GetLookTimeLast, &GCTriggerLook::SetLookTimeLast)
        .addProperty("TimeoutDuration", &GCTriggerLook::GetTimeoutDuration, &GCTriggerLook::SetTimeoutDuration)
        .addProperty("TimeoutFired", &GCTriggerLook::GetTimeoutFired, &GCTriggerLook::SetTimeoutFired)
        .addProperty("IsLooking", &GCTriggerLook::GetIsLooking, &GCTriggerLook::SetIsLooking)
        .addProperty("2DFOV", &GCTriggerLook::Get2DFOV, &GCTriggerLook::Set2DFOV)
        .addProperty("UseVelocity", &GCTriggerLook::GetUseVelocity, &GCTriggerLook::SetUseVelocity)
        .addProperty("TestOcclusion", &GCTriggerLook::GetTestOcclusion, &GCTriggerLook::SetTestOcclusion)
        .addProperty("OnTimeout", &GCTriggerLook::GetOnTimeout, &GCTriggerLook::SetOnTimeout)
        .addProperty("OnStartLook", &GCTriggerLook::GetOnStartLook, &GCTriggerLook::SetOnStartLook)
        .addProperty("OnEndLook", &GCTriggerLook::GetOnEndLook, &GCTriggerLook::SetOnEndLook)
        .addProperty("Parent", &GCTriggerLook::GetParent, &GCTriggerLook::SetParent)
        .addFunction("ToPtr", &GCTriggerLook::ToPtr)
        .addFunction("IsValid", &GCTriggerLook::IsValid)
        .endClass();
}