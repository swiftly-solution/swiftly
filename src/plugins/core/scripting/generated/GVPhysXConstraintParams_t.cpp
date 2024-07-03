#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysXConstraintParams_t::GVPhysXConstraintParams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysXConstraintParams_t::GVPhysXConstraintParams_t(void *ptr) {
    m_ptr = ptr;
}
int8_t GVPhysXConstraintParams_t::GetType() const {
    return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nType");
}
void GVPhysXConstraintParams_t::SetType(int8_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nType", true, value);
}
int8_t GVPhysXConstraintParams_t::GetTranslateMotion() const {
    return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nTranslateMotion");
}
void GVPhysXConstraintParams_t::SetTranslateMotion(int8_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nTranslateMotion", true, value);
}
int8_t GVPhysXConstraintParams_t::GetRotateMotion() const {
    return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nRotateMotion");
}
void GVPhysXConstraintParams_t::SetRotateMotion(int8_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nRotateMotion", true, value);
}
int8_t GVPhysXConstraintParams_t::GetFlags() const {
    return GetSchemaValue<int8_t>(m_ptr, "VPhysXConstraintParams_t", "m_nFlags");
}
void GVPhysXConstraintParams_t::SetFlags(int8_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_nFlags", true, value);
}
std::vector<Vector> GVPhysXConstraintParams_t::GetAnchor() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "VPhysXConstraintParams_t", "m_anchor"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GVPhysXConstraintParams_t::SetAnchor(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "VPhysXConstraintParams_t", "m_anchor"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_anchor", true, outValue);
}
float GVPhysXConstraintParams_t::GetMaxForce() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_maxForce");
}
void GVPhysXConstraintParams_t::SetMaxForce(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_maxForce", true, value);
}
float GVPhysXConstraintParams_t::GetMaxTorque() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_maxTorque");
}
void GVPhysXConstraintParams_t::SetMaxTorque(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_maxTorque", true, value);
}
float GVPhysXConstraintParams_t::GetLinearLimitValue() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitValue");
}
void GVPhysXConstraintParams_t::SetLinearLimitValue(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitValue", true, value);
}
float GVPhysXConstraintParams_t::GetLinearLimitRestitution() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitRestitution");
}
void GVPhysXConstraintParams_t::SetLinearLimitRestitution(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitRestitution", true, value);
}
float GVPhysXConstraintParams_t::GetLinearLimitSpring() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitSpring");
}
void GVPhysXConstraintParams_t::SetLinearLimitSpring(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitSpring", true, value);
}
float GVPhysXConstraintParams_t::GetLinearLimitDamping() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitDamping");
}
void GVPhysXConstraintParams_t::SetLinearLimitDamping(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_linearLimitDamping", true, value);
}
float GVPhysXConstraintParams_t::GetTwistLowLimitValue() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitValue");
}
void GVPhysXConstraintParams_t::SetTwistLowLimitValue(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitValue", true, value);
}
float GVPhysXConstraintParams_t::GetTwistLowLimitRestitution() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitRestitution");
}
void GVPhysXConstraintParams_t::SetTwistLowLimitRestitution(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitRestitution", true, value);
}
float GVPhysXConstraintParams_t::GetTwistLowLimitSpring() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitSpring");
}
void GVPhysXConstraintParams_t::SetTwistLowLimitSpring(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitSpring", true, value);
}
float GVPhysXConstraintParams_t::GetTwistLowLimitDamping() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitDamping");
}
void GVPhysXConstraintParams_t::SetTwistLowLimitDamping(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistLowLimitDamping", true, value);
}
float GVPhysXConstraintParams_t::GetTwistHighLimitValue() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitValue");
}
void GVPhysXConstraintParams_t::SetTwistHighLimitValue(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitValue", true, value);
}
float GVPhysXConstraintParams_t::GetTwistHighLimitRestitution() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitRestitution");
}
void GVPhysXConstraintParams_t::SetTwistHighLimitRestitution(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitRestitution", true, value);
}
float GVPhysXConstraintParams_t::GetTwistHighLimitSpring() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitSpring");
}
void GVPhysXConstraintParams_t::SetTwistHighLimitSpring(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitSpring", true, value);
}
float GVPhysXConstraintParams_t::GetTwistHighLimitDamping() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitDamping");
}
void GVPhysXConstraintParams_t::SetTwistHighLimitDamping(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_twistHighLimitDamping", true, value);
}
float GVPhysXConstraintParams_t::GetSwing1LimitValue() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitValue");
}
void GVPhysXConstraintParams_t::SetSwing1LimitValue(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitValue", true, value);
}
float GVPhysXConstraintParams_t::GetSwing1LimitRestitution() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitRestitution");
}
void GVPhysXConstraintParams_t::SetSwing1LimitRestitution(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitRestitution", true, value);
}
float GVPhysXConstraintParams_t::GetSwing1LimitSpring() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitSpring");
}
void GVPhysXConstraintParams_t::SetSwing1LimitSpring(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitSpring", true, value);
}
float GVPhysXConstraintParams_t::GetSwing1LimitDamping() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitDamping");
}
void GVPhysXConstraintParams_t::SetSwing1LimitDamping(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing1LimitDamping", true, value);
}
float GVPhysXConstraintParams_t::GetSwing2LimitValue() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitValue");
}
void GVPhysXConstraintParams_t::SetSwing2LimitValue(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitValue", true, value);
}
float GVPhysXConstraintParams_t::GetSwing2LimitRestitution() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitRestitution");
}
void GVPhysXConstraintParams_t::SetSwing2LimitRestitution(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitRestitution", true, value);
}
float GVPhysXConstraintParams_t::GetSwing2LimitSpring() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitSpring");
}
void GVPhysXConstraintParams_t::SetSwing2LimitSpring(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitSpring", true, value);
}
float GVPhysXConstraintParams_t::GetSwing2LimitDamping() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitDamping");
}
void GVPhysXConstraintParams_t::SetSwing2LimitDamping(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_swing2LimitDamping", true, value);
}
Vector GVPhysXConstraintParams_t::GetGoalPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "VPhysXConstraintParams_t", "m_goalPosition");
}
void GVPhysXConstraintParams_t::SetGoalPosition(Vector value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_goalPosition", true, value);
}
Vector GVPhysXConstraintParams_t::GetGoalAngularVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "VPhysXConstraintParams_t", "m_goalAngularVelocity");
}
void GVPhysXConstraintParams_t::SetGoalAngularVelocity(Vector value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_goalAngularVelocity", true, value);
}
float GVPhysXConstraintParams_t::GetDriveSpringX() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringX");
}
void GVPhysXConstraintParams_t::SetDriveSpringX(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringX", true, value);
}
float GVPhysXConstraintParams_t::GetDriveSpringY() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringY");
}
void GVPhysXConstraintParams_t::SetDriveSpringY(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringY", true, value);
}
float GVPhysXConstraintParams_t::GetDriveSpringZ() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringZ");
}
void GVPhysXConstraintParams_t::SetDriveSpringZ(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringZ", true, value);
}
float GVPhysXConstraintParams_t::GetDriveDampingX() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingX");
}
void GVPhysXConstraintParams_t::SetDriveDampingX(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingX", true, value);
}
float GVPhysXConstraintParams_t::GetDriveDampingY() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingY");
}
void GVPhysXConstraintParams_t::SetDriveDampingY(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingY", true, value);
}
float GVPhysXConstraintParams_t::GetDriveDampingZ() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingZ");
}
void GVPhysXConstraintParams_t::SetDriveDampingZ(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingZ", true, value);
}
float GVPhysXConstraintParams_t::GetDriveSpringTwist() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringTwist");
}
void GVPhysXConstraintParams_t::SetDriveSpringTwist(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringTwist", true, value);
}
float GVPhysXConstraintParams_t::GetDriveSpringSwing() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSwing");
}
void GVPhysXConstraintParams_t::SetDriveSpringSwing(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSwing", true, value);
}
float GVPhysXConstraintParams_t::GetDriveSpringSlerp() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSlerp");
}
void GVPhysXConstraintParams_t::SetDriveSpringSlerp(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveSpringSlerp", true, value);
}
float GVPhysXConstraintParams_t::GetDriveDampingTwist() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingTwist");
}
void GVPhysXConstraintParams_t::SetDriveDampingTwist(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingTwist", true, value);
}
float GVPhysXConstraintParams_t::GetDriveDampingSwing() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSwing");
}
void GVPhysXConstraintParams_t::SetDriveDampingSwing(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSwing", true, value);
}
float GVPhysXConstraintParams_t::GetDriveDampingSlerp() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSlerp");
}
void GVPhysXConstraintParams_t::SetDriveDampingSlerp(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_driveDampingSlerp", true, value);
}
int32_t GVPhysXConstraintParams_t::GetSolverIterationCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "VPhysXConstraintParams_t", "m_solverIterationCount");
}
void GVPhysXConstraintParams_t::SetSolverIterationCount(int32_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_solverIterationCount", true, value);
}
float GVPhysXConstraintParams_t::GetProjectionLinearTolerance() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_projectionLinearTolerance");
}
void GVPhysXConstraintParams_t::SetProjectionLinearTolerance(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_projectionLinearTolerance", true, value);
}
float GVPhysXConstraintParams_t::GetProjectionAngularTolerance() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXConstraintParams_t", "m_projectionAngularTolerance");
}
void GVPhysXConstraintParams_t::SetProjectionAngularTolerance(float value) {
    SetSchemaValue(m_ptr, "VPhysXConstraintParams_t", "m_projectionAngularTolerance", true, value);
}
std::string GVPhysXConstraintParams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysXConstraintParams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysXConstraintParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXConstraintParams_t>("VPhysXConstraintParams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GVPhysXConstraintParams_t::GetType, &GVPhysXConstraintParams_t::SetType)
        .addProperty("TranslateMotion", &GVPhysXConstraintParams_t::GetTranslateMotion, &GVPhysXConstraintParams_t::SetTranslateMotion)
        .addProperty("RotateMotion", &GVPhysXConstraintParams_t::GetRotateMotion, &GVPhysXConstraintParams_t::SetRotateMotion)
        .addProperty("Flags", &GVPhysXConstraintParams_t::GetFlags, &GVPhysXConstraintParams_t::SetFlags)
        .addProperty("Anchor", &GVPhysXConstraintParams_t::GetAnchor, &GVPhysXConstraintParams_t::SetAnchor)
        .addProperty("MaxForce", &GVPhysXConstraintParams_t::GetMaxForce, &GVPhysXConstraintParams_t::SetMaxForce)
        .addProperty("MaxTorque", &GVPhysXConstraintParams_t::GetMaxTorque, &GVPhysXConstraintParams_t::SetMaxTorque)
        .addProperty("LinearLimitValue", &GVPhysXConstraintParams_t::GetLinearLimitValue, &GVPhysXConstraintParams_t::SetLinearLimitValue)
        .addProperty("LinearLimitRestitution", &GVPhysXConstraintParams_t::GetLinearLimitRestitution, &GVPhysXConstraintParams_t::SetLinearLimitRestitution)
        .addProperty("LinearLimitSpring", &GVPhysXConstraintParams_t::GetLinearLimitSpring, &GVPhysXConstraintParams_t::SetLinearLimitSpring)
        .addProperty("LinearLimitDamping", &GVPhysXConstraintParams_t::GetLinearLimitDamping, &GVPhysXConstraintParams_t::SetLinearLimitDamping)
        .addProperty("TwistLowLimitValue", &GVPhysXConstraintParams_t::GetTwistLowLimitValue, &GVPhysXConstraintParams_t::SetTwistLowLimitValue)
        .addProperty("TwistLowLimitRestitution", &GVPhysXConstraintParams_t::GetTwistLowLimitRestitution, &GVPhysXConstraintParams_t::SetTwistLowLimitRestitution)
        .addProperty("TwistLowLimitSpring", &GVPhysXConstraintParams_t::GetTwistLowLimitSpring, &GVPhysXConstraintParams_t::SetTwistLowLimitSpring)
        .addProperty("TwistLowLimitDamping", &GVPhysXConstraintParams_t::GetTwistLowLimitDamping, &GVPhysXConstraintParams_t::SetTwistLowLimitDamping)
        .addProperty("TwistHighLimitValue", &GVPhysXConstraintParams_t::GetTwistHighLimitValue, &GVPhysXConstraintParams_t::SetTwistHighLimitValue)
        .addProperty("TwistHighLimitRestitution", &GVPhysXConstraintParams_t::GetTwistHighLimitRestitution, &GVPhysXConstraintParams_t::SetTwistHighLimitRestitution)
        .addProperty("TwistHighLimitSpring", &GVPhysXConstraintParams_t::GetTwistHighLimitSpring, &GVPhysXConstraintParams_t::SetTwistHighLimitSpring)
        .addProperty("TwistHighLimitDamping", &GVPhysXConstraintParams_t::GetTwistHighLimitDamping, &GVPhysXConstraintParams_t::SetTwistHighLimitDamping)
        .addProperty("Swing1LimitValue", &GVPhysXConstraintParams_t::GetSwing1LimitValue, &GVPhysXConstraintParams_t::SetSwing1LimitValue)
        .addProperty("Swing1LimitRestitution", &GVPhysXConstraintParams_t::GetSwing1LimitRestitution, &GVPhysXConstraintParams_t::SetSwing1LimitRestitution)
        .addProperty("Swing1LimitSpring", &GVPhysXConstraintParams_t::GetSwing1LimitSpring, &GVPhysXConstraintParams_t::SetSwing1LimitSpring)
        .addProperty("Swing1LimitDamping", &GVPhysXConstraintParams_t::GetSwing1LimitDamping, &GVPhysXConstraintParams_t::SetSwing1LimitDamping)
        .addProperty("Swing2LimitValue", &GVPhysXConstraintParams_t::GetSwing2LimitValue, &GVPhysXConstraintParams_t::SetSwing2LimitValue)
        .addProperty("Swing2LimitRestitution", &GVPhysXConstraintParams_t::GetSwing2LimitRestitution, &GVPhysXConstraintParams_t::SetSwing2LimitRestitution)
        .addProperty("Swing2LimitSpring", &GVPhysXConstraintParams_t::GetSwing2LimitSpring, &GVPhysXConstraintParams_t::SetSwing2LimitSpring)
        .addProperty("Swing2LimitDamping", &GVPhysXConstraintParams_t::GetSwing2LimitDamping, &GVPhysXConstraintParams_t::SetSwing2LimitDamping)
        .addProperty("GoalPosition", &GVPhysXConstraintParams_t::GetGoalPosition, &GVPhysXConstraintParams_t::SetGoalPosition)
        .addProperty("GoalAngularVelocity", &GVPhysXConstraintParams_t::GetGoalAngularVelocity, &GVPhysXConstraintParams_t::SetGoalAngularVelocity)
        .addProperty("DriveSpringX", &GVPhysXConstraintParams_t::GetDriveSpringX, &GVPhysXConstraintParams_t::SetDriveSpringX)
        .addProperty("DriveSpringY", &GVPhysXConstraintParams_t::GetDriveSpringY, &GVPhysXConstraintParams_t::SetDriveSpringY)
        .addProperty("DriveSpringZ", &GVPhysXConstraintParams_t::GetDriveSpringZ, &GVPhysXConstraintParams_t::SetDriveSpringZ)
        .addProperty("DriveDampingX", &GVPhysXConstraintParams_t::GetDriveDampingX, &GVPhysXConstraintParams_t::SetDriveDampingX)
        .addProperty("DriveDampingY", &GVPhysXConstraintParams_t::GetDriveDampingY, &GVPhysXConstraintParams_t::SetDriveDampingY)
        .addProperty("DriveDampingZ", &GVPhysXConstraintParams_t::GetDriveDampingZ, &GVPhysXConstraintParams_t::SetDriveDampingZ)
        .addProperty("DriveSpringTwist", &GVPhysXConstraintParams_t::GetDriveSpringTwist, &GVPhysXConstraintParams_t::SetDriveSpringTwist)
        .addProperty("DriveSpringSwing", &GVPhysXConstraintParams_t::GetDriveSpringSwing, &GVPhysXConstraintParams_t::SetDriveSpringSwing)
        .addProperty("DriveSpringSlerp", &GVPhysXConstraintParams_t::GetDriveSpringSlerp, &GVPhysXConstraintParams_t::SetDriveSpringSlerp)
        .addProperty("DriveDampingTwist", &GVPhysXConstraintParams_t::GetDriveDampingTwist, &GVPhysXConstraintParams_t::SetDriveDampingTwist)
        .addProperty("DriveDampingSwing", &GVPhysXConstraintParams_t::GetDriveDampingSwing, &GVPhysXConstraintParams_t::SetDriveDampingSwing)
        .addProperty("DriveDampingSlerp", &GVPhysXConstraintParams_t::GetDriveDampingSlerp, &GVPhysXConstraintParams_t::SetDriveDampingSlerp)
        .addProperty("SolverIterationCount", &GVPhysXConstraintParams_t::GetSolverIterationCount, &GVPhysXConstraintParams_t::SetSolverIterationCount)
        .addProperty("ProjectionLinearTolerance", &GVPhysXConstraintParams_t::GetProjectionLinearTolerance, &GVPhysXConstraintParams_t::SetProjectionLinearTolerance)
        .addProperty("ProjectionAngularTolerance", &GVPhysXConstraintParams_t::GetProjectionAngularTolerance, &GVPhysXConstraintParams_t::SetProjectionAngularTolerance)
        .addFunction("ToPtr", &GVPhysXConstraintParams_t::ToPtr)
        .addFunction("IsValid", &GVPhysXConstraintParams_t::IsValid)
        .endClass();
}