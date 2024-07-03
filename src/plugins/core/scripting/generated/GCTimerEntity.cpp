#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTimerEntity::GCTimerEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTimerEntity::GCTimerEntity(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCTimerEntity::GetOnTimer() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTimerEntity", "m_OnTimer"));
    return value;
}
void GCTimerEntity::SetOnTimer(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_OnTimer", false, value);
}
GCEntityIOOutput GCTimerEntity::GetOnTimerHigh() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTimerEntity", "m_OnTimerHigh"));
    return value;
}
void GCTimerEntity::SetOnTimerHigh(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_OnTimerHigh", false, value);
}
GCEntityIOOutput GCTimerEntity::GetOnTimerLow() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTimerEntity", "m_OnTimerLow"));
    return value;
}
void GCTimerEntity::SetOnTimerLow(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_OnTimerLow", false, value);
}
int32_t GCTimerEntity::GetDisabled() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTimerEntity", "m_iDisabled");
}
void GCTimerEntity::SetDisabled(int32_t value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_iDisabled", false, value);
}
float GCTimerEntity::GetInitialDelay() const {
    return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flInitialDelay");
}
void GCTimerEntity::SetInitialDelay(float value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_flInitialDelay", false, value);
}
float GCTimerEntity::GetRefireTime() const {
    return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flRefireTime");
}
void GCTimerEntity::SetRefireTime(float value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_flRefireTime", false, value);
}
bool GCTimerEntity::GetUpDownState() const {
    return GetSchemaValue<bool>(m_ptr, "CTimerEntity", "m_bUpDownState");
}
void GCTimerEntity::SetUpDownState(bool value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_bUpDownState", false, value);
}
int32_t GCTimerEntity::GetUseRandomTime() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTimerEntity", "m_iUseRandomTime");
}
void GCTimerEntity::SetUseRandomTime(int32_t value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_iUseRandomTime", false, value);
}
bool GCTimerEntity::GetPauseAfterFiring() const {
    return GetSchemaValue<bool>(m_ptr, "CTimerEntity", "m_bPauseAfterFiring");
}
void GCTimerEntity::SetPauseAfterFiring(bool value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_bPauseAfterFiring", false, value);
}
float GCTimerEntity::GetLowerRandomBound() const {
    return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flLowerRandomBound");
}
void GCTimerEntity::SetLowerRandomBound(float value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_flLowerRandomBound", false, value);
}
float GCTimerEntity::GetUpperRandomBound() const {
    return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flUpperRandomBound");
}
void GCTimerEntity::SetUpperRandomBound(float value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_flUpperRandomBound", false, value);
}
float GCTimerEntity::GetRemainingTime() const {
    return GetSchemaValue<float>(m_ptr, "CTimerEntity", "m_flRemainingTime");
}
void GCTimerEntity::SetRemainingTime(float value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_flRemainingTime", false, value);
}
bool GCTimerEntity::GetPaused() const {
    return GetSchemaValue<bool>(m_ptr, "CTimerEntity", "m_bPaused");
}
void GCTimerEntity::SetPaused(bool value) {
    SetSchemaValue(m_ptr, "CTimerEntity", "m_bPaused", false, value);
}
std::string GCTimerEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTimerEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCTimerEntity::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCTimerEntity::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTimerEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTimerEntity>("CTimerEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnTimer", &GCTimerEntity::GetOnTimer, &GCTimerEntity::SetOnTimer)
        .addProperty("OnTimerHigh", &GCTimerEntity::GetOnTimerHigh, &GCTimerEntity::SetOnTimerHigh)
        .addProperty("OnTimerLow", &GCTimerEntity::GetOnTimerLow, &GCTimerEntity::SetOnTimerLow)
        .addProperty("Disabled", &GCTimerEntity::GetDisabled, &GCTimerEntity::SetDisabled)
        .addProperty("InitialDelay", &GCTimerEntity::GetInitialDelay, &GCTimerEntity::SetInitialDelay)
        .addProperty("RefireTime", &GCTimerEntity::GetRefireTime, &GCTimerEntity::SetRefireTime)
        .addProperty("UpDownState", &GCTimerEntity::GetUpDownState, &GCTimerEntity::SetUpDownState)
        .addProperty("UseRandomTime", &GCTimerEntity::GetUseRandomTime, &GCTimerEntity::SetUseRandomTime)
        .addProperty("PauseAfterFiring", &GCTimerEntity::GetPauseAfterFiring, &GCTimerEntity::SetPauseAfterFiring)
        .addProperty("LowerRandomBound", &GCTimerEntity::GetLowerRandomBound, &GCTimerEntity::SetLowerRandomBound)
        .addProperty("UpperRandomBound", &GCTimerEntity::GetUpperRandomBound, &GCTimerEntity::SetUpperRandomBound)
        .addProperty("RemainingTime", &GCTimerEntity::GetRemainingTime, &GCTimerEntity::SetRemainingTime)
        .addProperty("Paused", &GCTimerEntity::GetPaused, &GCTimerEntity::SetPaused)
        .addProperty("Parent", &GCTimerEntity::GetParent, &GCTimerEntity::SetParent)
        .addFunction("ToPtr", &GCTimerEntity::ToPtr)
        .addFunction("IsValid", &GCTimerEntity::IsValid)
        .endClass();
}