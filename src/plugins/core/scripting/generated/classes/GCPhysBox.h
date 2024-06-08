class GCPhysBox;

#ifndef _gccphysbox_h
#define _gccphysbox_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCBasePlayerPawn.h"

class GCPhysBox
{
private:
    void *m_ptr;

public:
    GCPhysBox() {}
    GCPhysBox(void *ptr) : m_ptr(ptr) {}

    int32_t GetDamageType() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysBox", "m_damageType"); }
    void SetDamageType(int32_t value) { SetSchemaValue(m_ptr, "CPhysBox", "m_damageType", false, value); }
    float GetMassScale() const { return GetSchemaValue<float>(m_ptr, "CPhysBox", "m_massScale"); }
    void SetMassScale(float value) { SetSchemaValue(m_ptr, "CPhysBox", "m_massScale", false, value); }
    int32_t GetDamageToEnableMotion() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysBox", "m_damageToEnableMotion"); }
    void SetDamageToEnableMotion(int32_t value) { SetSchemaValue(m_ptr, "CPhysBox", "m_damageToEnableMotion", false, value); }
    float GetForceToEnableMotion() const { return GetSchemaValue<float>(m_ptr, "CPhysBox", "m_flForceToEnableMotion"); }
    void SetForceToEnableMotion(float value) { SetSchemaValue(m_ptr, "CPhysBox", "m_flForceToEnableMotion", false, value); }
    QAngle GetPreferredCarryAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CPhysBox", "m_angPreferredCarryAngles"); }
    void SetPreferredCarryAngles(QAngle value) { SetSchemaValue(m_ptr, "CPhysBox", "m_angPreferredCarryAngles", false, value); }
    bool GetNotSolidToWorld() const { return GetSchemaValue<bool>(m_ptr, "CPhysBox", "m_bNotSolidToWorld"); }
    void SetNotSolidToWorld(bool value) { SetSchemaValue(m_ptr, "CPhysBox", "m_bNotSolidToWorld", false, value); }
    bool GetEnableUseOutput() const { return GetSchemaValue<bool>(m_ptr, "CPhysBox", "m_bEnableUseOutput"); }
    void SetEnableUseOutput(bool value) { SetSchemaValue(m_ptr, "CPhysBox", "m_bEnableUseOutput", false, value); }
    int32_t GetExploitableByPlayer() const { return GetSchemaValue<int32_t>(m_ptr, "CPhysBox", "m_iExploitableByPlayer"); }
    void SetExploitableByPlayer(int32_t value) { SetSchemaValue(m_ptr, "CPhysBox", "m_iExploitableByPlayer", false, value); }
    float GetTouchOutputPerEntityDelay() const { return GetSchemaValue<float>(m_ptr, "CPhysBox", "m_flTouchOutputPerEntityDelay"); }
    void SetTouchOutputPerEntityDelay(float value) { SetSchemaValue(m_ptr, "CPhysBox", "m_flTouchOutputPerEntityDelay", false, value); }
    GCEntityIOOutput GetOnDamaged() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysBox", "m_OnDamaged"); }
    void SetOnDamaged(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysBox", "m_OnDamaged", false, value); }
    GCEntityIOOutput GetOnAwakened() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysBox", "m_OnAwakened"); }
    void SetOnAwakened(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysBox", "m_OnAwakened", false, value); }
    GCEntityIOOutput GetOnMotionEnabled() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysBox", "m_OnMotionEnabled"); }
    void SetOnMotionEnabled(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysBox", "m_OnMotionEnabled", false, value); }
    GCEntityIOOutput GetOnPlayerUse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysBox", "m_OnPlayerUse"); }
    void SetOnPlayerUse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysBox", "m_OnPlayerUse", false, value); }
    GCEntityIOOutput GetOnStartTouch() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysBox", "m_OnStartTouch"); }
    void SetOnStartTouch(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysBox", "m_OnStartTouch", false, value); }
    GCBasePlayerPawn* GetCarryingPlayer() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CPhysBox", "m_hCarryingPlayer"); }
    void SetCarryingPlayer(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CarryingPlayer' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif