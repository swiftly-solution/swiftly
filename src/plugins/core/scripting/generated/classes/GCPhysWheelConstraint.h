class GCPhysWheelConstraint;

#ifndef _gccphyswheelconstraint_h
#define _gccphyswheelconstraint_h

#include "../../../scripting.h"




class GCPhysWheelConstraint
{
private:
    void *m_ptr;

public:
    GCPhysWheelConstraint() {}
    GCPhysWheelConstraint(void *ptr) : m_ptr(ptr) {}

    float GetSuspensionFrequency() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSuspensionFrequency"); }
    void SetSuspensionFrequency(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSuspensionFrequency", false, value); }
    float GetSuspensionDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSuspensionDampingRatio"); }
    void SetSuspensionDampingRatio(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSuspensionDampingRatio", false, value); }
    float GetSuspensionHeightOffset() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSuspensionHeightOffset"); }
    void SetSuspensionHeightOffset(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSuspensionHeightOffset", false, value); }
    bool GetEnableSuspensionLimit() const { return GetSchemaValue<bool>(m_ptr, "CPhysWheelConstraint", "m_bEnableSuspensionLimit"); }
    void SetEnableSuspensionLimit(bool value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_bEnableSuspensionLimit", false, value); }
    float GetMinSuspensionOffset() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMinSuspensionOffset"); }
    void SetMinSuspensionOffset(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMinSuspensionOffset", false, value); }
    float GetMaxSuspensionOffset() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMaxSuspensionOffset"); }
    void SetMaxSuspensionOffset(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMaxSuspensionOffset", false, value); }
    bool GetEnableSteeringLimit() const { return GetSchemaValue<bool>(m_ptr, "CPhysWheelConstraint", "m_bEnableSteeringLimit"); }
    void SetEnableSteeringLimit(bool value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_bEnableSteeringLimit", false, value); }
    float GetMinSteeringAngle() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMinSteeringAngle"); }
    void SetMinSteeringAngle(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMinSteeringAngle", false, value); }
    float GetMaxSteeringAngle() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flMaxSteeringAngle"); }
    void SetMaxSteeringAngle(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flMaxSteeringAngle", false, value); }
    float GetSteeringAxisFriction() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSteeringAxisFriction"); }
    void SetSteeringAxisFriction(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSteeringAxisFriction", false, value); }
    float GetSpinAxisFriction() const { return GetSchemaValue<float>(m_ptr, "CPhysWheelConstraint", "m_flSpinAxisFriction"); }
    void SetSpinAxisFriction(float value) { SetSchemaValue(m_ptr, "CPhysWheelConstraint", "m_flSpinAxisFriction", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif