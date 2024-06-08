class GVPhysXJoint_t;

#ifndef _gcvphysxjoint_t_h
#define _gcvphysxjoint_t_h

#include "../../../scripting.h"


#include "GVPhysXRange_t.h"

class GVPhysXJoint_t
{
private:
    void *m_ptr;

public:
    GVPhysXJoint_t() {}
    GVPhysXJoint_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetType() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nType"); }
    void SetType(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nType", true, value); }
    uint16_t GetBody1() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nBody1"); }
    void SetBody1(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nBody1", true, value); }
    uint16_t GetBody2() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nBody2"); }
    void SetBody2(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nBody2", true, value); }
    uint16_t GetFlags() const { return GetSchemaValue<uint16_t>(m_ptr, "VPhysXJoint_t", "m_nFlags"); }
    void SetFlags(uint16_t value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_nFlags", true, value); }
    bool GetEnableCollision() const { return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableCollision"); }
    void SetEnableCollision(bool value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableCollision", true, value); }
    bool GetEnableLinearLimit() const { return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableLinearLimit"); }
    void SetEnableLinearLimit(bool value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableLinearLimit", true, value); }
    GVPhysXRange_t GetLinearLimit() const { return GetSchemaValue<GVPhysXRange_t>(m_ptr, "VPhysXJoint_t", "m_LinearLimit"); }
    void SetLinearLimit(GVPhysXRange_t value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_LinearLimit", true, value); }
    bool GetEnableLinearMotor() const { return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableLinearMotor"); }
    void SetEnableLinearMotor(bool value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableLinearMotor", true, value); }
    Vector GetLinearTargetVelocity() const { return GetSchemaValue<Vector>(m_ptr, "VPhysXJoint_t", "m_vLinearTargetVelocity"); }
    void SetLinearTargetVelocity(Vector value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_vLinearTargetVelocity", true, value); }
    float GetMaxForce() const { return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flMaxForce"); }
    void SetMaxForce(float value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flMaxForce", true, value); }
    bool GetEnableSwingLimit() const { return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableSwingLimit"); }
    void SetEnableSwingLimit(bool value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableSwingLimit", true, value); }
    GVPhysXRange_t GetSwingLimit() const { return GetSchemaValue<GVPhysXRange_t>(m_ptr, "VPhysXJoint_t", "m_SwingLimit"); }
    void SetSwingLimit(GVPhysXRange_t value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_SwingLimit", true, value); }
    bool GetEnableTwistLimit() const { return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableTwistLimit"); }
    void SetEnableTwistLimit(bool value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableTwistLimit", true, value); }
    GVPhysXRange_t GetTwistLimit() const { return GetSchemaValue<GVPhysXRange_t>(m_ptr, "VPhysXJoint_t", "m_TwistLimit"); }
    void SetTwistLimit(GVPhysXRange_t value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_TwistLimit", true, value); }
    bool GetEnableAngularMotor() const { return GetSchemaValue<bool>(m_ptr, "VPhysXJoint_t", "m_bEnableAngularMotor"); }
    void SetEnableAngularMotor(bool value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_bEnableAngularMotor", true, value); }
    Vector GetAngularTargetVelocity() const { return GetSchemaValue<Vector>(m_ptr, "VPhysXJoint_t", "m_vAngularTargetVelocity"); }
    void SetAngularTargetVelocity(Vector value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_vAngularTargetVelocity", true, value); }
    float GetMaxTorque() const { return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flMaxTorque"); }
    void SetMaxTorque(float value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flMaxTorque", true, value); }
    float GetLinearFrequency() const { return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flLinearFrequency"); }
    void SetLinearFrequency(float value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flLinearFrequency", true, value); }
    float GetLinearDampingRatio() const { return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flLinearDampingRatio"); }
    void SetLinearDampingRatio(float value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flLinearDampingRatio", true, value); }
    float GetAngularFrequency() const { return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flAngularFrequency"); }
    void SetAngularFrequency(float value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flAngularFrequency", true, value); }
    float GetAngularDampingRatio() const { return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flAngularDampingRatio"); }
    void SetAngularDampingRatio(float value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flAngularDampingRatio", true, value); }
    float GetFriction() const { return GetSchemaValue<float>(m_ptr, "VPhysXJoint_t", "m_flFriction"); }
    void SetFriction(float value) { SetSchemaValue(m_ptr, "VPhysXJoint_t", "m_flFriction", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif