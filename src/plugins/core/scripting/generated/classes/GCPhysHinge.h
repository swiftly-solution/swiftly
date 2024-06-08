class GCPhysHinge;

#ifndef _gccphyshinge_h
#define _gccphyshinge_h

#include "../../../scripting.h"


#include "GConstraintSoundInfo.h"
#include "GCEntityIOOutput.h"
#include "Gconstraint_hingeparams_t.h"

class GCPhysHinge
{
private:
    void *m_ptr;

public:
    GCPhysHinge() {}
    GCPhysHinge(void *ptr) : m_ptr(ptr) {}

    GConstraintSoundInfo GetSoundInfo() const { return GetSchemaValue<GConstraintSoundInfo>(m_ptr, "CPhysHinge", "m_soundInfo"); }
    void SetSoundInfo(GConstraintSoundInfo value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_soundInfo", false, value); }
    GCEntityIOOutput GetNotifyMinLimitReached() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysHinge", "m_NotifyMinLimitReached"); }
    void SetNotifyMinLimitReached(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_NotifyMinLimitReached", false, value); }
    GCEntityIOOutput GetNotifyMaxLimitReached() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysHinge", "m_NotifyMaxLimitReached"); }
    void SetNotifyMaxLimitReached(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_NotifyMaxLimitReached", false, value); }
    bool GetAtMinLimit() const { return GetSchemaValue<bool>(m_ptr, "CPhysHinge", "m_bAtMinLimit"); }
    void SetAtMinLimit(bool value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_bAtMinLimit", false, value); }
    bool GetAtMaxLimit() const { return GetSchemaValue<bool>(m_ptr, "CPhysHinge", "m_bAtMaxLimit"); }
    void SetAtMaxLimit(bool value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_bAtMaxLimit", false, value); }
    Gconstraint_hingeparams_t GetHinge() const { return GetSchemaValue<Gconstraint_hingeparams_t>(m_ptr, "CPhysHinge", "m_hinge"); }
    void SetHinge(Gconstraint_hingeparams_t value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_hinge", false, value); }
    float GetHingeFriction() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_hingeFriction"); }
    void SetHingeFriction(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_hingeFriction", false, value); }
    float GetSystemLoadScale() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_systemLoadScale"); }
    void SetSystemLoadScale(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_systemLoadScale", false, value); }
    bool GetIsAxisLocal() const { return GetSchemaValue<bool>(m_ptr, "CPhysHinge", "m_bIsAxisLocal"); }
    void SetIsAxisLocal(bool value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_bIsAxisLocal", false, value); }
    float GetMinRotation() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMinRotation"); }
    void SetMinRotation(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_flMinRotation", false, value); }
    float GetMaxRotation() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMaxRotation"); }
    void SetMaxRotation(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_flMaxRotation", false, value); }
    float GetInitialRotation() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flInitialRotation"); }
    void SetInitialRotation(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_flInitialRotation", false, value); }
    float GetMotorFrequency() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMotorFrequency"); }
    void SetMotorFrequency(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_flMotorFrequency", false, value); }
    float GetMotorDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flMotorDampingRatio"); }
    void SetMotorDampingRatio(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_flMotorDampingRatio", false, value); }
    float GetAngleSpeed() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flAngleSpeed"); }
    void SetAngleSpeed(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_flAngleSpeed", false, value); }
    float GetAngleSpeedThreshold() const { return GetSchemaValue<float>(m_ptr, "CPhysHinge", "m_flAngleSpeedThreshold"); }
    void SetAngleSpeedThreshold(float value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_flAngleSpeedThreshold", false, value); }
    GCEntityIOOutput GetOnStartMoving() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysHinge", "m_OnStartMoving"); }
    void SetOnStartMoving(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_OnStartMoving", false, value); }
    GCEntityIOOutput GetOnStopMoving() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPhysHinge", "m_OnStopMoving"); }
    void SetOnStopMoving(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPhysHinge", "m_OnStopMoving", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif