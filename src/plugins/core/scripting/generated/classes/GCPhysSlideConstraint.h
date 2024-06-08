class GCPhysSlideConstraint;

#ifndef _gccphysslideconstraint_h
#define _gccphysslideconstraint_h

#include "../../../scripting.h"


#include "GConstraintSoundInfo.h"

class GCPhysSlideConstraint
{
private:
    void *m_ptr;

public:
    GCPhysSlideConstraint() {}
    GCPhysSlideConstraint(void *ptr) : m_ptr(ptr) {}

    Vector GetAxisEnd() const { return GetSchemaValue<Vector>(m_ptr, "CPhysSlideConstraint", "m_axisEnd"); }
    void SetAxisEnd(Vector value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_axisEnd", false, value); }
    float GetSlideFriction() const { return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_slideFriction"); }
    void SetSlideFriction(float value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_slideFriction", false, value); }
    float GetSystemLoadScale() const { return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_systemLoadScale"); }
    void SetSystemLoadScale(float value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_systemLoadScale", false, value); }
    float GetInitialOffset() const { return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_initialOffset"); }
    void SetInitialOffset(float value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_initialOffset", false, value); }
    bool GetEnableLinearConstraint() const { return GetSchemaValue<bool>(m_ptr, "CPhysSlideConstraint", "m_bEnableLinearConstraint"); }
    void SetEnableLinearConstraint(bool value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_bEnableLinearConstraint", false, value); }
    bool GetEnableAngularConstraint() const { return GetSchemaValue<bool>(m_ptr, "CPhysSlideConstraint", "m_bEnableAngularConstraint"); }
    void SetEnableAngularConstraint(bool value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_bEnableAngularConstraint", false, value); }
    float GetMotorFrequency() const { return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_flMotorFrequency"); }
    void SetMotorFrequency(float value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_flMotorFrequency", false, value); }
    float GetMotorDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CPhysSlideConstraint", "m_flMotorDampingRatio"); }
    void SetMotorDampingRatio(float value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_flMotorDampingRatio", false, value); }
    bool GetUseEntityPivot() const { return GetSchemaValue<bool>(m_ptr, "CPhysSlideConstraint", "m_bUseEntityPivot"); }
    void SetUseEntityPivot(bool value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_bUseEntityPivot", false, value); }
    GConstraintSoundInfo GetSoundInfo() const { return GetSchemaValue<GConstraintSoundInfo>(m_ptr, "CPhysSlideConstraint", "m_soundInfo"); }
    void SetSoundInfo(GConstraintSoundInfo value) { SetSchemaValue(m_ptr, "CPhysSlideConstraint", "m_soundInfo", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif