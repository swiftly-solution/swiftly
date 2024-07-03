#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsProp::GCPhysicsProp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsProp::GCPhysicsProp(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCPhysicsProp::GetMotionEnabled() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysicsProp", "m_MotionEnabled"));
    return value;
}
void GCPhysicsProp::SetMotionEnabled(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_MotionEnabled", false, value);
}
GCEntityIOOutput GCPhysicsProp::GetOnAwakened() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysicsProp", "m_OnAwakened"));
    return value;
}
void GCPhysicsProp::SetOnAwakened(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnAwakened", false, value);
}
GCEntityIOOutput GCPhysicsProp::GetOnAwake() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysicsProp", "m_OnAwake"));
    return value;
}
void GCPhysicsProp::SetOnAwake(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnAwake", false, value);
}
GCEntityIOOutput GCPhysicsProp::GetOnAsleep() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysicsProp", "m_OnAsleep"));
    return value;
}
void GCPhysicsProp::SetOnAsleep(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnAsleep", false, value);
}
GCEntityIOOutput GCPhysicsProp::GetOnPlayerUse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysicsProp", "m_OnPlayerUse"));
    return value;
}
void GCPhysicsProp::SetOnPlayerUse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnPlayerUse", false, value);
}
GCEntityIOOutput GCPhysicsProp::GetOnOutOfWorld() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysicsProp", "m_OnOutOfWorld"));
    return value;
}
void GCPhysicsProp::SetOnOutOfWorld(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnOutOfWorld", false, value);
}
GCEntityIOOutput GCPhysicsProp::GetOnPlayerPickup() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysicsProp", "m_OnPlayerPickup"));
    return value;
}
void GCPhysicsProp::SetOnPlayerPickup(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnPlayerPickup", false, value);
}
bool GCPhysicsProp::GetForceNavIgnore() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bForceNavIgnore");
}
void GCPhysicsProp::SetForceNavIgnore(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bForceNavIgnore", false, value);
}
bool GCPhysicsProp::GetNoNavmeshBlocker() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bNoNavmeshBlocker");
}
void GCPhysicsProp::SetNoNavmeshBlocker(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bNoNavmeshBlocker", false, value);
}
bool GCPhysicsProp::GetForceNpcExclude() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bForceNpcExclude");
}
void GCPhysicsProp::SetForceNpcExclude(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bForceNpcExclude", false, value);
}
float GCPhysicsProp::GetMassScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_massScale");
}
void GCPhysicsProp::SetMassScale(float value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_massScale", false, value);
}
float GCPhysicsProp::GetInertiaScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_inertiaScale");
}
void GCPhysicsProp::SetInertiaScale(float value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_inertiaScale", false, value);
}
float GCPhysicsProp::GetBuoyancyScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_buoyancyScale");
}
void GCPhysicsProp::SetBuoyancyScale(float value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_buoyancyScale", false, value);
}
int32_t GCPhysicsProp::GetDamageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_damageType");
}
void GCPhysicsProp::SetDamageType(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_damageType", false, value);
}
int32_t GCPhysicsProp::GetDamageToEnableMotion() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_damageToEnableMotion");
}
void GCPhysicsProp::SetDamageToEnableMotion(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_damageToEnableMotion", false, value);
}
float GCPhysicsProp::GetForceToEnableMotion() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_flForceToEnableMotion");
}
void GCPhysicsProp::SetForceToEnableMotion(float value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_flForceToEnableMotion", false, value);
}
bool GCPhysicsProp::GetThrownByPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bThrownByPlayer");
}
void GCPhysicsProp::SetThrownByPlayer(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bThrownByPlayer", false, value);
}
bool GCPhysicsProp::GetDroppedByPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bDroppedByPlayer");
}
void GCPhysicsProp::SetDroppedByPlayer(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bDroppedByPlayer", false, value);
}
bool GCPhysicsProp::GetTouchedByPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bTouchedByPlayer");
}
void GCPhysicsProp::SetTouchedByPlayer(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bTouchedByPlayer", false, value);
}
bool GCPhysicsProp::GetFirstCollisionAfterLaunch() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bFirstCollisionAfterLaunch");
}
void GCPhysicsProp::SetFirstCollisionAfterLaunch(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bFirstCollisionAfterLaunch", false, value);
}
int32_t GCPhysicsProp::GetExploitableByPlayer() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_iExploitableByPlayer");
}
void GCPhysicsProp::SetExploitableByPlayer(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_iExploitableByPlayer", false, value);
}
bool GCPhysicsProp::GetHasBeenAwakened() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bHasBeenAwakened");
}
void GCPhysicsProp::SetHasBeenAwakened(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bHasBeenAwakened", false, value);
}
bool GCPhysicsProp::GetIsOverrideProp() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bIsOverrideProp");
}
void GCPhysicsProp::SetIsOverrideProp(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bIsOverrideProp", false, value);
}
float GCPhysicsProp::GetNextCheckDisableMotionContactsTime() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_fNextCheckDisableMotionContactsTime");
}
void GCPhysicsProp::SetNextCheckDisableMotionContactsTime(float value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_fNextCheckDisableMotionContactsTime", false, value);
}
int32_t GCPhysicsProp::GetInitialGlowState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_iInitialGlowState");
}
void GCPhysicsProp::SetInitialGlowState(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_iInitialGlowState", false, value);
}
int32_t GCPhysicsProp::GetGlowRange() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_nGlowRange");
}
void GCPhysicsProp::SetGlowRange(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_nGlowRange", false, value);
}
int32_t GCPhysicsProp::GetGlowRangeMin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_nGlowRangeMin");
}
void GCPhysicsProp::SetGlowRangeMin(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_nGlowRangeMin", false, value);
}
Color GCPhysicsProp::GetGlowColor() const {
    return GetSchemaValue<Color>(m_ptr, "CPhysicsProp", "m_glowColor");
}
void GCPhysicsProp::SetGlowColor(Color value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_glowColor", false, value);
}
bool GCPhysicsProp::GetShouldAutoConvertBackFromDebris() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bShouldAutoConvertBackFromDebris");
}
void GCPhysicsProp::SetShouldAutoConvertBackFromDebris(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bShouldAutoConvertBackFromDebris", false, value);
}
bool GCPhysicsProp::GetMuteImpactEffects() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bMuteImpactEffects");
}
void GCPhysicsProp::SetMuteImpactEffects(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bMuteImpactEffects", false, value);
}
bool GCPhysicsProp::GetAcceptDamageFromHeldObjects() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bAcceptDamageFromHeldObjects");
}
void GCPhysicsProp::SetAcceptDamageFromHeldObjects(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bAcceptDamageFromHeldObjects", false, value);
}
bool GCPhysicsProp::GetEnableUseOutput() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bEnableUseOutput");
}
void GCPhysicsProp::SetEnableUseOutput(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bEnableUseOutput", false, value);
}
bool GCPhysicsProp::GetAwake() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bAwake");
}
void GCPhysicsProp::SetAwake(bool value) {
    SetSchemaValue(m_ptr, "CPhysicsProp", "m_bAwake", false, value);
}
std::string GCPhysicsProp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsProp::IsValid() {
    return (m_ptr != nullptr);
}
GCBreakableProp GCPhysicsProp::GetParent() const {
    GCBreakableProp value(m_ptr);
    return value;
}
void GCPhysicsProp::SetParent(GCBreakableProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicsProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsProp>("CPhysicsProp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MotionEnabled", &GCPhysicsProp::GetMotionEnabled, &GCPhysicsProp::SetMotionEnabled)
        .addProperty("OnAwakened", &GCPhysicsProp::GetOnAwakened, &GCPhysicsProp::SetOnAwakened)
        .addProperty("OnAwake", &GCPhysicsProp::GetOnAwake, &GCPhysicsProp::SetOnAwake)
        .addProperty("OnAsleep", &GCPhysicsProp::GetOnAsleep, &GCPhysicsProp::SetOnAsleep)
        .addProperty("OnPlayerUse", &GCPhysicsProp::GetOnPlayerUse, &GCPhysicsProp::SetOnPlayerUse)
        .addProperty("OnOutOfWorld", &GCPhysicsProp::GetOnOutOfWorld, &GCPhysicsProp::SetOnOutOfWorld)
        .addProperty("OnPlayerPickup", &GCPhysicsProp::GetOnPlayerPickup, &GCPhysicsProp::SetOnPlayerPickup)
        .addProperty("ForceNavIgnore", &GCPhysicsProp::GetForceNavIgnore, &GCPhysicsProp::SetForceNavIgnore)
        .addProperty("NoNavmeshBlocker", &GCPhysicsProp::GetNoNavmeshBlocker, &GCPhysicsProp::SetNoNavmeshBlocker)
        .addProperty("ForceNpcExclude", &GCPhysicsProp::GetForceNpcExclude, &GCPhysicsProp::SetForceNpcExclude)
        .addProperty("MassScale", &GCPhysicsProp::GetMassScale, &GCPhysicsProp::SetMassScale)
        .addProperty("InertiaScale", &GCPhysicsProp::GetInertiaScale, &GCPhysicsProp::SetInertiaScale)
        .addProperty("BuoyancyScale", &GCPhysicsProp::GetBuoyancyScale, &GCPhysicsProp::SetBuoyancyScale)
        .addProperty("DamageType", &GCPhysicsProp::GetDamageType, &GCPhysicsProp::SetDamageType)
        .addProperty("DamageToEnableMotion", &GCPhysicsProp::GetDamageToEnableMotion, &GCPhysicsProp::SetDamageToEnableMotion)
        .addProperty("ForceToEnableMotion", &GCPhysicsProp::GetForceToEnableMotion, &GCPhysicsProp::SetForceToEnableMotion)
        .addProperty("ThrownByPlayer", &GCPhysicsProp::GetThrownByPlayer, &GCPhysicsProp::SetThrownByPlayer)
        .addProperty("DroppedByPlayer", &GCPhysicsProp::GetDroppedByPlayer, &GCPhysicsProp::SetDroppedByPlayer)
        .addProperty("TouchedByPlayer", &GCPhysicsProp::GetTouchedByPlayer, &GCPhysicsProp::SetTouchedByPlayer)
        .addProperty("FirstCollisionAfterLaunch", &GCPhysicsProp::GetFirstCollisionAfterLaunch, &GCPhysicsProp::SetFirstCollisionAfterLaunch)
        .addProperty("ExploitableByPlayer", &GCPhysicsProp::GetExploitableByPlayer, &GCPhysicsProp::SetExploitableByPlayer)
        .addProperty("HasBeenAwakened", &GCPhysicsProp::GetHasBeenAwakened, &GCPhysicsProp::SetHasBeenAwakened)
        .addProperty("IsOverrideProp", &GCPhysicsProp::GetIsOverrideProp, &GCPhysicsProp::SetIsOverrideProp)
        .addProperty("NextCheckDisableMotionContactsTime", &GCPhysicsProp::GetNextCheckDisableMotionContactsTime, &GCPhysicsProp::SetNextCheckDisableMotionContactsTime)
        .addProperty("InitialGlowState", &GCPhysicsProp::GetInitialGlowState, &GCPhysicsProp::SetInitialGlowState)
        .addProperty("GlowRange", &GCPhysicsProp::GetGlowRange, &GCPhysicsProp::SetGlowRange)
        .addProperty("GlowRangeMin", &GCPhysicsProp::GetGlowRangeMin, &GCPhysicsProp::SetGlowRangeMin)
        .addProperty("GlowColor", &GCPhysicsProp::GetGlowColor, &GCPhysicsProp::SetGlowColor)
        .addProperty("ShouldAutoConvertBackFromDebris", &GCPhysicsProp::GetShouldAutoConvertBackFromDebris, &GCPhysicsProp::SetShouldAutoConvertBackFromDebris)
        .addProperty("MuteImpactEffects", &GCPhysicsProp::GetMuteImpactEffects, &GCPhysicsProp::SetMuteImpactEffects)
        .addProperty("AcceptDamageFromHeldObjects", &GCPhysicsProp::GetAcceptDamageFromHeldObjects, &GCPhysicsProp::SetAcceptDamageFromHeldObjects)
        .addProperty("EnableUseOutput", &GCPhysicsProp::GetEnableUseOutput, &GCPhysicsProp::SetEnableUseOutput)
        .addProperty("Awake", &GCPhysicsProp::GetAwake, &GCPhysicsProp::SetAwake)
        .addProperty("Parent", &GCPhysicsProp::GetParent, &GCPhysicsProp::SetParent)
        .addFunction("ToPtr", &GCPhysicsProp::ToPtr)
        .addFunction("IsValid", &GCPhysicsProp::IsValid)
        .endClass();
}