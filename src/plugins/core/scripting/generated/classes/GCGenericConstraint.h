class GCGenericConstraint;

#ifndef _gccgenericconstraint_h
#define _gccgenericconstraint_h

#include "../../../scripting.h"

#include "../types/GJointMotion_t.h"
#include "GCEntityIOOutput.h"

class GCGenericConstraint
{
private:
    void *m_ptr;

public:
    GCGenericConstraint() {}
    GCGenericConstraint(void *ptr) : m_ptr(ptr) {}

    JointMotion_t GetLinearMotionX() const { return GetSchemaValue<JointMotion_t>(m_ptr, "CGenericConstraint", "m_nLinearMotionX"); }
    void SetLinearMotionX(JointMotion_t value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_nLinearMotionX", false, value); }
    JointMotion_t GetLinearMotionY() const { return GetSchemaValue<JointMotion_t>(m_ptr, "CGenericConstraint", "m_nLinearMotionY"); }
    void SetLinearMotionY(JointMotion_t value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_nLinearMotionY", false, value); }
    JointMotion_t GetLinearMotionZ() const { return GetSchemaValue<JointMotion_t>(m_ptr, "CGenericConstraint", "m_nLinearMotionZ"); }
    void SetLinearMotionZ(JointMotion_t value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_nLinearMotionZ", false, value); }
    float GetLinearFrequencyX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearFrequencyX"); }
    void SetLinearFrequencyX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearFrequencyX", false, value); }
    float GetLinearFrequencyY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearFrequencyY"); }
    void SetLinearFrequencyY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearFrequencyY", false, value); }
    float GetLinearFrequencyZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearFrequencyZ"); }
    void SetLinearFrequencyZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearFrequencyZ", false, value); }
    float GetLinearDampingRatioX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioX"); }
    void SetLinearDampingRatioX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioX", false, value); }
    float GetLinearDampingRatioY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioY"); }
    void SetLinearDampingRatioY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioY", false, value); }
    float GetLinearDampingRatioZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioZ"); }
    void SetLinearDampingRatioZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioZ", false, value); }
    float GetMaxLinearImpulseX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseX"); }
    void SetMaxLinearImpulseX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseX", false, value); }
    float GetMaxLinearImpulseY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseY"); }
    void SetMaxLinearImpulseY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseY", false, value); }
    float GetMaxLinearImpulseZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseZ"); }
    void SetMaxLinearImpulseZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseZ", false, value); }
    float GetBreakAfterTimeX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeX"); }
    void SetBreakAfterTimeX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeX", false, value); }
    float GetBreakAfterTimeY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeY"); }
    void SetBreakAfterTimeY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeY", false, value); }
    float GetBreakAfterTimeZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeZ"); }
    void SetBreakAfterTimeZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeZ", false, value); }
    float GetBreakAfterTimeThresholdX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdX"); }
    void SetBreakAfterTimeThresholdX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdX", false, value); }
    float GetBreakAfterTimeThresholdY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdY"); }
    void SetBreakAfterTimeThresholdY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdY", false, value); }
    float GetBreakAfterTimeThresholdZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdZ"); }
    void SetBreakAfterTimeThresholdZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdZ", false, value); }
    float GetNotifyForceX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceX"); }
    void SetNotifyForceX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceX", false, value); }
    float GetNotifyForceY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceY"); }
    void SetNotifyForceY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceY", false, value); }
    float GetNotifyForceZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceZ"); }
    void SetNotifyForceZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceZ", false, value); }
    float GetNotifyForceMinTimeX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeX"); }
    void SetNotifyForceMinTimeX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeX", false, value); }
    float GetNotifyForceMinTimeY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeY"); }
    void SetNotifyForceMinTimeY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeY", false, value); }
    float GetNotifyForceMinTimeZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeZ"); }
    void SetNotifyForceMinTimeZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeZ", false, value); }
    bool GetAxisNotifiedX() const { return GetSchemaValue<bool>(m_ptr, "CGenericConstraint", "m_bAxisNotifiedX"); }
    void SetAxisNotifiedX(bool value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_bAxisNotifiedX", false, value); }
    bool GetAxisNotifiedY() const { return GetSchemaValue<bool>(m_ptr, "CGenericConstraint", "m_bAxisNotifiedY"); }
    void SetAxisNotifiedY(bool value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_bAxisNotifiedY", false, value); }
    bool GetAxisNotifiedZ() const { return GetSchemaValue<bool>(m_ptr, "CGenericConstraint", "m_bAxisNotifiedZ"); }
    void SetAxisNotifiedZ(bool value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_bAxisNotifiedZ", false, value); }
    JointMotion_t GetAngularMotionX() const { return GetSchemaValue<JointMotion_t>(m_ptr, "CGenericConstraint", "m_nAngularMotionX"); }
    void SetAngularMotionX(JointMotion_t value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_nAngularMotionX", false, value); }
    JointMotion_t GetAngularMotionY() const { return GetSchemaValue<JointMotion_t>(m_ptr, "CGenericConstraint", "m_nAngularMotionY"); }
    void SetAngularMotionY(JointMotion_t value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_nAngularMotionY", false, value); }
    JointMotion_t GetAngularMotionZ() const { return GetSchemaValue<JointMotion_t>(m_ptr, "CGenericConstraint", "m_nAngularMotionZ"); }
    void SetAngularMotionZ(JointMotion_t value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_nAngularMotionZ", false, value); }
    float GetAngularFrequencyX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularFrequencyX"); }
    void SetAngularFrequencyX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularFrequencyX", false, value); }
    float GetAngularFrequencyY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularFrequencyY"); }
    void SetAngularFrequencyY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularFrequencyY", false, value); }
    float GetAngularFrequencyZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularFrequencyZ"); }
    void SetAngularFrequencyZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularFrequencyZ", false, value); }
    float GetAngularDampingRatioX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioX"); }
    void SetAngularDampingRatioX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioX", false, value); }
    float GetAngularDampingRatioY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioY"); }
    void SetAngularDampingRatioY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioY", false, value); }
    float GetAngularDampingRatioZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioZ"); }
    void SetAngularDampingRatioZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioZ", false, value); }
    float GetMaxAngularImpulseX() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseX"); }
    void SetMaxAngularImpulseX(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseX", false, value); }
    float GetMaxAngularImpulseY() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseY"); }
    void SetMaxAngularImpulseY(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseY", false, value); }
    float GetMaxAngularImpulseZ() const { return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseZ"); }
    void SetMaxAngularImpulseZ(float value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseZ", false, value); }
    GCEntityIOOutput GetNotifyForceReachedX() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGenericConstraint", "m_NotifyForceReachedX"); }
    void SetNotifyForceReachedX(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_NotifyForceReachedX", false, value); }
    GCEntityIOOutput GetNotifyForceReachedY() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGenericConstraint", "m_NotifyForceReachedY"); }
    void SetNotifyForceReachedY(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_NotifyForceReachedY", false, value); }
    GCEntityIOOutput GetNotifyForceReachedZ() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGenericConstraint", "m_NotifyForceReachedZ"); }
    void SetNotifyForceReachedZ(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGenericConstraint", "m_NotifyForceReachedZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif