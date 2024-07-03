#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GTwoBoneIKSettings_t::GTwoBoneIKSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GTwoBoneIKSettings_t::GTwoBoneIKSettings_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GTwoBoneIKSettings_t::GetEndEffectorType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorType");
}
void GTwoBoneIKSettings_t::SetEndEffectorType(uint64_t value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorType", true, value);
}
GCAnimAttachment GTwoBoneIKSettings_t::GetEndEffectorAttachment() const {
    GCAnimAttachment value(GetSchemaPtr(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorAttachment"));
    return value;
}
void GTwoBoneIKSettings_t::SetEndEffectorAttachment(GCAnimAttachment value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_endEffectorAttachment", true, value);
}
uint64_t GTwoBoneIKSettings_t::GetTargetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TwoBoneIKSettings_t", "m_targetType");
}
void GTwoBoneIKSettings_t::SetTargetType(uint64_t value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_targetType", true, value);
}
GCAnimAttachment GTwoBoneIKSettings_t::GetTargetAttachment() const {
    GCAnimAttachment value(GetSchemaPtr(m_ptr, "TwoBoneIKSettings_t", "m_targetAttachment"));
    return value;
}
void GTwoBoneIKSettings_t::SetTargetAttachment(GCAnimAttachment value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_targetAttachment", true, value);
}
int32_t GTwoBoneIKSettings_t::GetTargetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_targetBoneIndex");
}
void GTwoBoneIKSettings_t::SetTargetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_targetBoneIndex", true, value);
}
GCAnimParamHandle GTwoBoneIKSettings_t::GetPositionParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "TwoBoneIKSettings_t", "m_hPositionParam"));
    return value;
}
void GTwoBoneIKSettings_t::SetPositionParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_hPositionParam", true, value);
}
GCAnimParamHandle GTwoBoneIKSettings_t::GetRotationParam() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "TwoBoneIKSettings_t", "m_hRotationParam"));
    return value;
}
void GTwoBoneIKSettings_t::SetRotationParam(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_hRotationParam", true, value);
}
bool GTwoBoneIKSettings_t::GetAlwaysUseFallbackHinge() const {
    return GetSchemaValue<bool>(m_ptr, "TwoBoneIKSettings_t", "m_bAlwaysUseFallbackHinge");
}
void GTwoBoneIKSettings_t::SetAlwaysUseFallbackHinge(bool value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_bAlwaysUseFallbackHinge", true, value);
}
Vector GTwoBoneIKSettings_t::GetLsFallbackHingeAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "TwoBoneIKSettings_t", "m_vLsFallbackHingeAxis");
}
void GTwoBoneIKSettings_t::SetLsFallbackHingeAxis(Vector value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_vLsFallbackHingeAxis", true, value);
}
int32_t GTwoBoneIKSettings_t::GetFixedBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_nFixedBoneIndex");
}
void GTwoBoneIKSettings_t::SetFixedBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_nFixedBoneIndex", true, value);
}
int32_t GTwoBoneIKSettings_t::GetMiddleBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_nMiddleBoneIndex");
}
void GTwoBoneIKSettings_t::SetMiddleBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_nMiddleBoneIndex", true, value);
}
int32_t GTwoBoneIKSettings_t::GetEndBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "TwoBoneIKSettings_t", "m_nEndBoneIndex");
}
void GTwoBoneIKSettings_t::SetEndBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_nEndBoneIndex", true, value);
}
bool GTwoBoneIKSettings_t::GetMatchTargetOrientation() const {
    return GetSchemaValue<bool>(m_ptr, "TwoBoneIKSettings_t", "m_bMatchTargetOrientation");
}
void GTwoBoneIKSettings_t::SetMatchTargetOrientation(bool value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_bMatchTargetOrientation", true, value);
}
bool GTwoBoneIKSettings_t::GetConstrainTwist() const {
    return GetSchemaValue<bool>(m_ptr, "TwoBoneIKSettings_t", "m_bConstrainTwist");
}
void GTwoBoneIKSettings_t::SetConstrainTwist(bool value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_bConstrainTwist", true, value);
}
float GTwoBoneIKSettings_t::GetMaxTwist() const {
    return GetSchemaValue<float>(m_ptr, "TwoBoneIKSettings_t", "m_flMaxTwist");
}
void GTwoBoneIKSettings_t::SetMaxTwist(float value) {
    SetSchemaValue(m_ptr, "TwoBoneIKSettings_t", "m_flMaxTwist", true, value);
}
std::string GTwoBoneIKSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GTwoBoneIKSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassTwoBoneIKSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTwoBoneIKSettings_t>("TwoBoneIKSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EndEffectorType", &GTwoBoneIKSettings_t::GetEndEffectorType, &GTwoBoneIKSettings_t::SetEndEffectorType)
        .addProperty("EndEffectorAttachment", &GTwoBoneIKSettings_t::GetEndEffectorAttachment, &GTwoBoneIKSettings_t::SetEndEffectorAttachment)
        .addProperty("TargetType", &GTwoBoneIKSettings_t::GetTargetType, &GTwoBoneIKSettings_t::SetTargetType)
        .addProperty("TargetAttachment", &GTwoBoneIKSettings_t::GetTargetAttachment, &GTwoBoneIKSettings_t::SetTargetAttachment)
        .addProperty("TargetBoneIndex", &GTwoBoneIKSettings_t::GetTargetBoneIndex, &GTwoBoneIKSettings_t::SetTargetBoneIndex)
        .addProperty("PositionParam", &GTwoBoneIKSettings_t::GetPositionParam, &GTwoBoneIKSettings_t::SetPositionParam)
        .addProperty("RotationParam", &GTwoBoneIKSettings_t::GetRotationParam, &GTwoBoneIKSettings_t::SetRotationParam)
        .addProperty("AlwaysUseFallbackHinge", &GTwoBoneIKSettings_t::GetAlwaysUseFallbackHinge, &GTwoBoneIKSettings_t::SetAlwaysUseFallbackHinge)
        .addProperty("LsFallbackHingeAxis", &GTwoBoneIKSettings_t::GetLsFallbackHingeAxis, &GTwoBoneIKSettings_t::SetLsFallbackHingeAxis)
        .addProperty("FixedBoneIndex", &GTwoBoneIKSettings_t::GetFixedBoneIndex, &GTwoBoneIKSettings_t::SetFixedBoneIndex)
        .addProperty("MiddleBoneIndex", &GTwoBoneIKSettings_t::GetMiddleBoneIndex, &GTwoBoneIKSettings_t::SetMiddleBoneIndex)
        .addProperty("EndBoneIndex", &GTwoBoneIKSettings_t::GetEndBoneIndex, &GTwoBoneIKSettings_t::SetEndBoneIndex)
        .addProperty("MatchTargetOrientation", &GTwoBoneIKSettings_t::GetMatchTargetOrientation, &GTwoBoneIKSettings_t::SetMatchTargetOrientation)
        .addProperty("ConstrainTwist", &GTwoBoneIKSettings_t::GetConstrainTwist, &GTwoBoneIKSettings_t::SetConstrainTwist)
        .addProperty("MaxTwist", &GTwoBoneIKSettings_t::GetMaxTwist, &GTwoBoneIKSettings_t::SetMaxTwist)
        .addFunction("ToPtr", &GTwoBoneIKSettings_t::ToPtr)
        .addFunction("IsValid", &GTwoBoneIKSettings_t::IsValid)
        .endClass();
}