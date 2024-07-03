#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseCSGrenade::GCBaseCSGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseCSGrenade::GCBaseCSGrenade(void *ptr) {
    m_ptr = ptr;
}
bool GCBaseCSGrenade::GetRedraw() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bRedraw");
}
void GCBaseCSGrenade::SetRedraw(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bRedraw", false, value);
}
bool GCBaseCSGrenade::GetIsHeldByPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bIsHeldByPlayer");
}
void GCBaseCSGrenade::SetIsHeldByPlayer(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bIsHeldByPlayer", false, value);
}
bool GCBaseCSGrenade::GetPinPulled() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bPinPulled");
}
void GCBaseCSGrenade::SetPinPulled(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bPinPulled", false, value);
}
bool GCBaseCSGrenade::GetJumpThrow() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bJumpThrow");
}
void GCBaseCSGrenade::SetJumpThrow(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bJumpThrow", false, value);
}
bool GCBaseCSGrenade::GetThrowAnimating() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bThrowAnimating");
}
void GCBaseCSGrenade::SetThrowAnimating(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bThrowAnimating", false, value);
}
float GCBaseCSGrenade::GetThrowTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_fThrowTime");
}
void GCBaseCSGrenade::SetThrowTime(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_fThrowTime", false, value);
}
float GCBaseCSGrenade::GetThrowStrength() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_flThrowStrength");
}
void GCBaseCSGrenade::SetThrowStrength(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_flThrowStrength", false, value);
}
float GCBaseCSGrenade::GetThrowStrengthApproach() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_flThrowStrengthApproach");
}
void GCBaseCSGrenade::SetThrowStrengthApproach(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_flThrowStrengthApproach", false, value);
}
float GCBaseCSGrenade::GetDropTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_fDropTime");
}
void GCBaseCSGrenade::SetDropTime(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_fDropTime", false, value);
}
float GCBaseCSGrenade::GetPinPullTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_fPinPullTime");
}
void GCBaseCSGrenade::SetPinPullTime(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_fPinPullTime", false, value);
}
bool GCBaseCSGrenade::GetJustPulledPin() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bJustPulledPin");
}
void GCBaseCSGrenade::SetJustPulledPin(bool value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bJustPulledPin", false, value);
}
int32 GCBaseCSGrenade::GetNextHoldTick() const {
    return GetSchemaValue<int32>(m_ptr, "CBaseCSGrenade", "m_nNextHoldTick");
}
void GCBaseCSGrenade::SetNextHoldTick(int32 value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_nNextHoldTick", false, value);
}
float GCBaseCSGrenade::GetNextHoldFrac() const {
    return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_flNextHoldFrac");
}
void GCBaseCSGrenade::SetNextHoldFrac(float value) {
    SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_flNextHoldFrac", false, value);
}
GCCSWeaponBase GCBaseCSGrenade::GetSwitchToWeaponAfterThrow() const {
    GCCSWeaponBase value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseCSGrenade", "m_hSwitchToWeaponAfterThrow"));
    return value;
}
void GCBaseCSGrenade::SetSwitchToWeaponAfterThrow(GCCSWeaponBase* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'SwitchToWeaponAfterThrow' is not possible.\n");
}
std::string GCBaseCSGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseCSGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCBaseCSGrenade::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCBaseCSGrenade::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseCSGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseCSGrenade>("CBaseCSGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Redraw", &GCBaseCSGrenade::GetRedraw, &GCBaseCSGrenade::SetRedraw)
        .addProperty("IsHeldByPlayer", &GCBaseCSGrenade::GetIsHeldByPlayer, &GCBaseCSGrenade::SetIsHeldByPlayer)
        .addProperty("PinPulled", &GCBaseCSGrenade::GetPinPulled, &GCBaseCSGrenade::SetPinPulled)
        .addProperty("JumpThrow", &GCBaseCSGrenade::GetJumpThrow, &GCBaseCSGrenade::SetJumpThrow)
        .addProperty("ThrowAnimating", &GCBaseCSGrenade::GetThrowAnimating, &GCBaseCSGrenade::SetThrowAnimating)
        .addProperty("ThrowTime", &GCBaseCSGrenade::GetThrowTime, &GCBaseCSGrenade::SetThrowTime)
        .addProperty("ThrowStrength", &GCBaseCSGrenade::GetThrowStrength, &GCBaseCSGrenade::SetThrowStrength)
        .addProperty("ThrowStrengthApproach", &GCBaseCSGrenade::GetThrowStrengthApproach, &GCBaseCSGrenade::SetThrowStrengthApproach)
        .addProperty("DropTime", &GCBaseCSGrenade::GetDropTime, &GCBaseCSGrenade::SetDropTime)
        .addProperty("PinPullTime", &GCBaseCSGrenade::GetPinPullTime, &GCBaseCSGrenade::SetPinPullTime)
        .addProperty("JustPulledPin", &GCBaseCSGrenade::GetJustPulledPin, &GCBaseCSGrenade::SetJustPulledPin)
        .addProperty("NextHoldTick", &GCBaseCSGrenade::GetNextHoldTick, &GCBaseCSGrenade::SetNextHoldTick)
        .addProperty("NextHoldFrac", &GCBaseCSGrenade::GetNextHoldFrac, &GCBaseCSGrenade::SetNextHoldFrac)
        .addProperty("SwitchToWeaponAfterThrow", &GCBaseCSGrenade::GetSwitchToWeaponAfterThrow, &GCBaseCSGrenade::SetSwitchToWeaponAfterThrow)
        .addProperty("Parent", &GCBaseCSGrenade::GetParent, &GCBaseCSGrenade::SetParent)
        .addFunction("ToPtr", &GCBaseCSGrenade::ToPtr)
        .addFunction("IsValid", &GCBaseCSGrenade::IsValid)
        .endClass();
}