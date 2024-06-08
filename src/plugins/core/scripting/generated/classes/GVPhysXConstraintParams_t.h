class GVPhysXConstraintParams_t;

#ifndef _gcvphysxconstraintparams_t_h
#define _gcvphysxconstraintparams_t_h

#include "../../../scripting.h"




class GVPhysXConstraintParams_t
{
private:
    void *m_ptr;

public:
    GVPhysXConstraintParams_t() {}
    GVPhysXConstraintParams_t(void *ptr) : m_ptr(ptr) {}

    int8_t GetType() const { return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nType"); }
    void SetType(int8_t value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nType", true, value); }
    int8_t GetTranslateMotion() const { return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nTranslateMotion"); }
    void SetTranslateMotion(int8_t value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nTranslateMotion", true, value); }
    int8_t GetRotateMotion() const { return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nRotateMotion"); }
    void SetRotateMotion(int8_t value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nRotateMotion", true, value); }
    int8_t GetFlags() const { return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nFlags"); }
    void SetFlags(int8_t value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nFlags", true, value); }
    std::vector<Vector> GetAnchor() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "VPhysXConstraintParams_t", "m_anchor"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetAnchor(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "VPhysXConstraintParams_t", "m_anchor"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_anchor", true, outValue); }
    float GetMaxForce() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_maxForce"); }
    void SetMaxForce(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_maxForce", true, value); }
    float GetMaxTorque() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_maxTorque"); }
    void SetMaxTorque(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_maxTorque", true, value); }
    float GetLinearLimitValue() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitValue"); }
    void SetLinearLimitValue(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitValue", true, value); }
    float GetLinearLimitRestitution() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitRestitution"); }
    void SetLinearLimitRestitution(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitRestitution", true, value); }
    float GetLinearLimitSpring() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitSpring"); }
    void SetLinearLimitSpring(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitSpring", true, value); }
    float GetLinearLimitDamping() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitDamping"); }
    void SetLinearLimitDamping(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitDamping", true, value); }
    float GetTwistLowLimitValue() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitValue"); }
    void SetTwistLowLimitValue(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitValue", true, value); }
    float GetTwistLowLimitRestitution() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitRestitution"); }
    void SetTwistLowLimitRestitution(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitRestitution", true, value); }
    float GetTwistLowLimitSpring() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitSpring"); }
    void SetTwistLowLimitSpring(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitSpring", true, value); }
    float GetTwistLowLimitDamping() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitDamping"); }
    void SetTwistLowLimitDamping(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitDamping", true, value); }
    float GetTwistHighLimitValue() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitValue"); }
    void SetTwistHighLimitValue(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitValue", true, value); }
    float GetTwistHighLimitRestitution() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitRestitution"); }
    void SetTwistHighLimitRestitution(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitRestitution", true, value); }
    float GetTwistHighLimitSpring() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitSpring"); }
    void SetTwistHighLimitSpring(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitSpring", true, value); }
    float GetTwistHighLimitDamping() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitDamping"); }
    void SetTwistHighLimitDamping(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitDamping", true, value); }
    float GetSwing1LimitValue() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitValue"); }
    void SetSwing1LimitValue(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitValue", true, value); }
    float GetSwing1LimitRestitution() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitRestitution"); }
    void SetSwing1LimitRestitution(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitRestitution", true, value); }
    float GetSwing1LimitSpring() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitSpring"); }
    void SetSwing1LimitSpring(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitSpring", true, value); }
    float GetSwing1LimitDamping() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitDamping"); }
    void SetSwing1LimitDamping(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitDamping", true, value); }
    float GetSwing2LimitValue() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitValue"); }
    void SetSwing2LimitValue(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitValue", true, value); }
    float GetSwing2LimitRestitution() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitRestitution"); }
    void SetSwing2LimitRestitution(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitRestitution", true, value); }
    float GetSwing2LimitSpring() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitSpring"); }
    void SetSwing2LimitSpring(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitSpring", true, value); }
    float GetSwing2LimitDamping() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitDamping"); }
    void SetSwing2LimitDamping(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitDamping", true, value); }
    Vector GetGoalPosition() const { return GetSchemaValue<Vector>(m_ptr, "VPhysXConstraintParams_t", "m_goalPosition"); }
    void SetGoalPosition(Vector value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_goalPosition", true, value); }
    Vector GetGoalAngularVelocity() const { return GetSchemaValue<Vector>(m_ptr, "VPhysXConstraintParams_t", "m_goalAngularVelocity"); }
    void SetGoalAngularVelocity(Vector value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_goalAngularVelocity", true, value); }
    float GetDriveSpringX() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringX"); }
    void SetDriveSpringX(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringX", true, value); }
    float GetDriveSpringY() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringY"); }
    void SetDriveSpringY(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringY", true, value); }
    float GetDriveSpringZ() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringZ"); }
    void SetDriveSpringZ(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringZ", true, value); }
    float GetDriveDampingX() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingX"); }
    void SetDriveDampingX(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingX", true, value); }
    float GetDriveDampingY() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingY"); }
    void SetDriveDampingY(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingY", true, value); }
    float GetDriveDampingZ() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingZ"); }
    void SetDriveDampingZ(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingZ", true, value); }
    float GetDriveSpringTwist() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringTwist"); }
    void SetDriveSpringTwist(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringTwist", true, value); }
    float GetDriveSpringSwing() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSwing"); }
    void SetDriveSpringSwing(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSwing", true, value); }
    float GetDriveSpringSlerp() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSlerp"); }
    void SetDriveSpringSlerp(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSlerp", true, value); }
    float GetDriveDampingTwist() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingTwist"); }
    void SetDriveDampingTwist(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingTwist", true, value); }
    float GetDriveDampingSwing() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSwing"); }
    void SetDriveDampingSwing(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSwing", true, value); }
    float GetDriveDampingSlerp() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSlerp"); }
    void SetDriveDampingSlerp(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSlerp", true, value); }
    int32_t GetSolverIterationCount() const { return GetSchemaValue<int32_t>(m_ptr, "VPhysXConstraintParams_t", "m_solverIterationCount"); }
    void SetSolverIterationCount(int32_t value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_solverIterationCount", true, value); }
    float GetProjectionLinearTolerance() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_projectionLinearTolerance"); }
    void SetProjectionLinearTolerance(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_projectionLinearTolerance", true, value); }
    float GetProjectionAngularTolerance() const { return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_projectionAngularTolerance"); }
    void SetProjectionAngularTolerance(float value) { SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_projectionAngularTolerance", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif