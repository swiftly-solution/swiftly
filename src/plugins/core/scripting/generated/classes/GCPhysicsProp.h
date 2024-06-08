class GCPhysicsProp;

#ifndef _gccphysicsprop_h
#define _gccphysicsprop_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCPhysicsProp
{
private:
    void *m_ptr;

public:
    GCPhysicsProp() {}
    GCPhysicsProp(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetMotionEnabled() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysicsProp", "m_MotionEnabled"); }
    void SetMotionEnabled(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_MotionEnabled", false, value); }
    GCEntityIOOutput GetOnAwakened() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysicsProp", "m_OnAwakened"); }
    void SetOnAwakened(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnAwakened", false, value); }
    GCEntityIOOutput GetOnAwake() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysicsProp", "m_OnAwake"); }
    void SetOnAwake(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnAwake", false, value); }
    GCEntityIOOutput GetOnAsleep() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysicsProp", "m_OnAsleep"); }
    void SetOnAsleep(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnAsleep", false, value); }
    GCEntityIOOutput GetOnPlayerUse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysicsProp", "m_OnPlayerUse"); }
    void SetOnPlayerUse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnPlayerUse", false, value); }
    GCEntityIOOutput GetOnOutOfWorld() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysicsProp", "m_OnOutOfWorld"); }
    void SetOnOutOfWorld(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnOutOfWorld", false, value); }
    GCEntityIOOutput GetOnPlayerPickup() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysicsProp", "m_OnPlayerPickup"); }
    void SetOnPlayerPickup(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_OnPlayerPickup", false, value); }
    bool GetForceNavIgnore() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bForceNavIgnore"); }
    void SetForceNavIgnore(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bForceNavIgnore", false, value); }
    bool GetNoNavmeshBlocker() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bNoNavmeshBlocker"); }
    void SetNoNavmeshBlocker(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bNoNavmeshBlocker", false, value); }
    bool GetForceNpcExclude() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bForceNpcExclude"); }
    void SetForceNpcExclude(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bForceNpcExclude", false, value); }
    float GetMassScale() const { return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_massScale"); }
    void SetMassScale(float value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_massScale", false, value); }
    float GetInertiaScale() const { return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_inertiaScale"); }
    void SetInertiaScale(float value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_inertiaScale", false, value); }
    float GetBuoyancyScale() const { return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_buoyancyScale"); }
    void SetBuoyancyScale(float value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_buoyancyScale", false, value); }
    int32_t GetDamageType() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_damageType"); }
    void SetDamageType(int32_t value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_damageType", false, value); }
    int32_t GetDamageToEnableMotion() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_damageToEnableMotion"); }
    void SetDamageToEnableMotion(int32_t value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_damageToEnableMotion", false, value); }
    float GetForceToEnableMotion() const { return GetSchemaValue<float>(m_ptr, "CPhysicsProp", "m_flForceToEnableMotion"); }
    void SetForceToEnableMotion(float value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_flForceToEnableMotion", false, value); }
    bool GetThrownByPlayer() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bThrownByPlayer"); }
    void SetThrownByPlayer(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bThrownByPlayer", false, value); }
    bool GetDroppedByPlayer() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bDroppedByPlayer"); }
    void SetDroppedByPlayer(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bDroppedByPlayer", false, value); }
    bool GetTouchedByPlayer() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bTouchedByPlayer"); }
    void SetTouchedByPlayer(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bTouchedByPlayer", false, value); }
    bool GetFirstCollisionAfterLaunch() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bFirstCollisionAfterLaunch"); }
    void SetFirstCollisionAfterLaunch(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bFirstCollisionAfterLaunch", false, value); }
    int32_t GetExploitableByPlayer() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_iExploitableByPlayer"); }
    void SetExploitableByPlayer(int32_t value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_iExploitableByPlayer", false, value); }
    bool GetHasBeenAwakened() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bHasBeenAwakened"); }
    void SetHasBeenAwakened(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bHasBeenAwakened", false, value); }
    bool GetIsOverrideProp() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bIsOverrideProp"); }
    void SetIsOverrideProp(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bIsOverrideProp", false, value); }
    int32_t GetInitialGlowState() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_iInitialGlowState"); }
    void SetInitialGlowState(int32_t value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_iInitialGlowState", false, value); }
    int32_t GetGlowRange() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_nGlowRange"); }
    void SetGlowRange(int32_t value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_nGlowRange", false, value); }
    int32_t GetGlowRangeMin() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysicsProp", "m_nGlowRangeMin"); }
    void SetGlowRangeMin(int32_t value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_nGlowRangeMin", false, value); }
    Color GetGlowColor() const { return GetSchemaValue<Color>(m_ptr, "CPhysicsProp", "m_glowColor"); }
    void SetGlowColor(Color value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_glowColor", false, value); }
    bool GetShouldAutoConvertBackFromDebris() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bShouldAutoConvertBackFromDebris"); }
    void SetShouldAutoConvertBackFromDebris(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bShouldAutoConvertBackFromDebris", false, value); }
    bool GetMuteImpactEffects() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bMuteImpactEffects"); }
    void SetMuteImpactEffects(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bMuteImpactEffects", false, value); }
    bool GetAcceptDamageFromHeldObjects() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bAcceptDamageFromHeldObjects"); }
    void SetAcceptDamageFromHeldObjects(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bAcceptDamageFromHeldObjects", false, value); }
    bool GetEnableUseOutput() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bEnableUseOutput"); }
    void SetEnableUseOutput(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bEnableUseOutput", false, value); }
    bool GetAwake() const { return GetSchemaValue<bool>(m_ptr, "CPhysicsProp", "m_bAwake"); }
    void SetAwake(bool value) { SetSchemaValue(m_ptr, "CPhysicsProp", "m_bAwake", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif