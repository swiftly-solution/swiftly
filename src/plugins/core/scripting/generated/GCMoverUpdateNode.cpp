#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMoverUpdateNode::GCMoverUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMoverUpdateNode::GCMoverUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimInputDamping GCMoverUpdateNode::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CMoverUpdateNode", "m_damping"));
    return value;
}
void GCMoverUpdateNode::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_damping", false, value);
}
uint64_t GCMoverUpdateNode::GetFacingTarget() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CMoverUpdateNode", "m_facingTarget");
}
void GCMoverUpdateNode::SetFacingTarget(uint64_t value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_facingTarget", false, value);
}
GCAnimParamHandle GCMoverUpdateNode::GetMoveVecParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CMoverUpdateNode", "m_hMoveVecParam"));
    return value;
}
void GCMoverUpdateNode::SetMoveVecParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_hMoveVecParam", false, value);
}
GCAnimParamHandle GCMoverUpdateNode::GetMoveHeadingParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CMoverUpdateNode", "m_hMoveHeadingParam"));
    return value;
}
void GCMoverUpdateNode::SetMoveHeadingParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_hMoveHeadingParam", false, value);
}
GCAnimParamHandle GCMoverUpdateNode::GetTurnToFaceParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CMoverUpdateNode", "m_hTurnToFaceParam"));
    return value;
}
void GCMoverUpdateNode::SetTurnToFaceParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_hTurnToFaceParam", false, value);
}
float GCMoverUpdateNode::GetTurnToFaceOffset() const {
    return GetSchemaValue<float>(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceOffset");
}
void GCMoverUpdateNode::SetTurnToFaceOffset(float value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceOffset", false, value);
}
float GCMoverUpdateNode::GetTurnToFaceLimit() const {
    return GetSchemaValue<float>(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceLimit");
}
void GCMoverUpdateNode::SetTurnToFaceLimit(float value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_flTurnToFaceLimit", false, value);
}
bool GCMoverUpdateNode::GetAdditive() const {
    return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bAdditive");
}
void GCMoverUpdateNode::SetAdditive(bool value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bAdditive", false, value);
}
bool GCMoverUpdateNode::GetApplyMovement() const {
    return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bApplyMovement");
}
void GCMoverUpdateNode::SetApplyMovement(bool value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bApplyMovement", false, value);
}
bool GCMoverUpdateNode::GetOrientMovement() const {
    return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bOrientMovement");
}
void GCMoverUpdateNode::SetOrientMovement(bool value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bOrientMovement", false, value);
}
bool GCMoverUpdateNode::GetApplyRotation() const {
    return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bApplyRotation");
}
void GCMoverUpdateNode::SetApplyRotation(bool value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bApplyRotation", false, value);
}
bool GCMoverUpdateNode::GetLimitOnly() const {
    return GetSchemaValue<bool>(m_ptr, "CMoverUpdateNode", "m_bLimitOnly");
}
void GCMoverUpdateNode::SetLimitOnly(bool value) {
    SetSchemaValue(m_ptr, "CMoverUpdateNode", "m_bLimitOnly", false, value);
}
std::string GCMoverUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMoverUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCMoverUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCMoverUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMoverUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMoverUpdateNode>("CMoverUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Damping", &GCMoverUpdateNode::GetDamping, &GCMoverUpdateNode::SetDamping)
        .addProperty("FacingTarget", &GCMoverUpdateNode::GetFacingTarget, &GCMoverUpdateNode::SetFacingTarget)
        .addProperty("MoveVecParam", &GCMoverUpdateNode::GetMoveVecParam, &GCMoverUpdateNode::SetMoveVecParam)
        .addProperty("MoveHeadingParam", &GCMoverUpdateNode::GetMoveHeadingParam, &GCMoverUpdateNode::SetMoveHeadingParam)
        .addProperty("TurnToFaceParam", &GCMoverUpdateNode::GetTurnToFaceParam, &GCMoverUpdateNode::SetTurnToFaceParam)
        .addProperty("TurnToFaceOffset", &GCMoverUpdateNode::GetTurnToFaceOffset, &GCMoverUpdateNode::SetTurnToFaceOffset)
        .addProperty("TurnToFaceLimit", &GCMoverUpdateNode::GetTurnToFaceLimit, &GCMoverUpdateNode::SetTurnToFaceLimit)
        .addProperty("Additive", &GCMoverUpdateNode::GetAdditive, &GCMoverUpdateNode::SetAdditive)
        .addProperty("ApplyMovement", &GCMoverUpdateNode::GetApplyMovement, &GCMoverUpdateNode::SetApplyMovement)
        .addProperty("OrientMovement", &GCMoverUpdateNode::GetOrientMovement, &GCMoverUpdateNode::SetOrientMovement)
        .addProperty("ApplyRotation", &GCMoverUpdateNode::GetApplyRotation, &GCMoverUpdateNode::SetApplyRotation)
        .addProperty("LimitOnly", &GCMoverUpdateNode::GetLimitOnly, &GCMoverUpdateNode::SetLimitOnly)
        .addProperty("Parent", &GCMoverUpdateNode::GetParent, &GCMoverUpdateNode::SetParent)
        .addFunction("ToPtr", &GCMoverUpdateNode::ToPtr)
        .addFunction("IsValid", &GCMoverUpdateNode::IsValid)
        .endClass();
}