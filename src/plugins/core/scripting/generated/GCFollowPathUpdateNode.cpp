#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFollowPathUpdateNode::GCFollowPathUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFollowPathUpdateNode::GCFollowPathUpdateNode(void *ptr) {
    m_ptr = ptr;
}
float GCFollowPathUpdateNode::GetBlendOutTime() const {
    return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flBlendOutTime");
}
void GCFollowPathUpdateNode::SetBlendOutTime(float value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flBlendOutTime", false, value);
}
bool GCFollowPathUpdateNode::GetBlockNonPathMovement() const {
    return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bBlockNonPathMovement");
}
void GCFollowPathUpdateNode::SetBlockNonPathMovement(bool value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bBlockNonPathMovement", false, value);
}
bool GCFollowPathUpdateNode::GetStopFeetAtGoal() const {
    return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bStopFeetAtGoal");
}
void GCFollowPathUpdateNode::SetStopFeetAtGoal(bool value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bStopFeetAtGoal", false, value);
}
bool GCFollowPathUpdateNode::GetScaleSpeed() const {
    return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bScaleSpeed");
}
void GCFollowPathUpdateNode::SetScaleSpeed(bool value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bScaleSpeed", false, value);
}
float GCFollowPathUpdateNode::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flScale");
}
void GCFollowPathUpdateNode::SetScale(float value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flScale", false, value);
}
float GCFollowPathUpdateNode::GetMinAngle() const {
    return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flMinAngle");
}
void GCFollowPathUpdateNode::SetMinAngle(float value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flMinAngle", false, value);
}
float GCFollowPathUpdateNode::GetMaxAngle() const {
    return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flMaxAngle");
}
void GCFollowPathUpdateNode::SetMaxAngle(float value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flMaxAngle", false, value);
}
float GCFollowPathUpdateNode::GetSpeedScaleBlending() const {
    return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flSpeedScaleBlending");
}
void GCFollowPathUpdateNode::SetSpeedScaleBlending(float value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flSpeedScaleBlending", false, value);
}
GCAnimInputDamping GCFollowPathUpdateNode::GetTurnDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CFollowPathUpdateNode", "m_turnDamping"));
    return value;
}
void GCFollowPathUpdateNode::SetTurnDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_turnDamping", false, value);
}
uint64_t GCFollowPathUpdateNode::GetFacingTarget() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFollowPathUpdateNode", "m_facingTarget");
}
void GCFollowPathUpdateNode::SetFacingTarget(uint64_t value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_facingTarget", false, value);
}
GCAnimParamHandle GCFollowPathUpdateNode::GetParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CFollowPathUpdateNode", "m_hParam"));
    return value;
}
void GCFollowPathUpdateNode::SetParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_hParam", false, value);
}
float GCFollowPathUpdateNode::GetTurnToFaceOffset() const {
    return GetSchemaValue<float>(m_ptr, "CFollowPathUpdateNode", "m_flTurnToFaceOffset");
}
void GCFollowPathUpdateNode::SetTurnToFaceOffset(float value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_flTurnToFaceOffset", false, value);
}
bool GCFollowPathUpdateNode::GetTurnToFace() const {
    return GetSchemaValue<bool>(m_ptr, "CFollowPathUpdateNode", "m_bTurnToFace");
}
void GCFollowPathUpdateNode::SetTurnToFace(bool value) {
    SetSchemaValue(m_ptr, "CFollowPathUpdateNode", "m_bTurnToFace", false, value);
}
std::string GCFollowPathUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFollowPathUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCFollowPathUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCFollowPathUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFollowPathUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFollowPathUpdateNode>("CFollowPathUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BlendOutTime", &GCFollowPathUpdateNode::GetBlendOutTime, &GCFollowPathUpdateNode::SetBlendOutTime)
        .addProperty("BlockNonPathMovement", &GCFollowPathUpdateNode::GetBlockNonPathMovement, &GCFollowPathUpdateNode::SetBlockNonPathMovement)
        .addProperty("StopFeetAtGoal", &GCFollowPathUpdateNode::GetStopFeetAtGoal, &GCFollowPathUpdateNode::SetStopFeetAtGoal)
        .addProperty("ScaleSpeed", &GCFollowPathUpdateNode::GetScaleSpeed, &GCFollowPathUpdateNode::SetScaleSpeed)
        .addProperty("Scale", &GCFollowPathUpdateNode::GetScale, &GCFollowPathUpdateNode::SetScale)
        .addProperty("MinAngle", &GCFollowPathUpdateNode::GetMinAngle, &GCFollowPathUpdateNode::SetMinAngle)
        .addProperty("MaxAngle", &GCFollowPathUpdateNode::GetMaxAngle, &GCFollowPathUpdateNode::SetMaxAngle)
        .addProperty("SpeedScaleBlending", &GCFollowPathUpdateNode::GetSpeedScaleBlending, &GCFollowPathUpdateNode::SetSpeedScaleBlending)
        .addProperty("TurnDamping", &GCFollowPathUpdateNode::GetTurnDamping, &GCFollowPathUpdateNode::SetTurnDamping)
        .addProperty("FacingTarget", &GCFollowPathUpdateNode::GetFacingTarget, &GCFollowPathUpdateNode::SetFacingTarget)
        .addProperty("Param", &GCFollowPathUpdateNode::GetParam, &GCFollowPathUpdateNode::SetParam)
        .addProperty("TurnToFaceOffset", &GCFollowPathUpdateNode::GetTurnToFaceOffset, &GCFollowPathUpdateNode::SetTurnToFaceOffset)
        .addProperty("TurnToFace", &GCFollowPathUpdateNode::GetTurnToFace, &GCFollowPathUpdateNode::SetTurnToFace)
        .addProperty("Parent", &GCFollowPathUpdateNode::GetParent, &GCFollowPathUpdateNode::SetParent)
        .addFunction("ToPtr", &GCFollowPathUpdateNode::ToPtr)
        .addFunction("IsValid", &GCFollowPathUpdateNode::IsValid)
        .endClass();
}