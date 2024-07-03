#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFootPinningPoseOpFixedData_t::GFootPinningPoseOpFixedData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFootPinningPoseOpFixedData_t::GFootPinningPoseOpFixedData_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GFootFixedData_t> GFootPinningPoseOpFixedData_t::GetFootInfo() const {
    CUtlVector<GFootFixedData_t>* vec = GetSchemaValue<CUtlVector<GFootFixedData_t>*>(m_ptr, "FootPinningPoseOpFixedData_t", "m_footInfo"); std::vector<GFootFixedData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFootPinningPoseOpFixedData_t::SetFootInfo(std::vector<GFootFixedData_t> value) {
    SetSchemaValueCUtlVector<GFootFixedData_t>(m_ptr, "FootPinningPoseOpFixedData_t", "m_footInfo", true, value);
}
float GFootPinningPoseOpFixedData_t::GetBlendTime() const {
    return GetSchemaValue<float>(m_ptr, "FootPinningPoseOpFixedData_t", "m_flBlendTime");
}
void GFootPinningPoseOpFixedData_t::SetBlendTime(float value) {
    SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_flBlendTime", true, value);
}
float GFootPinningPoseOpFixedData_t::GetLockBreakDistance() const {
    return GetSchemaValue<float>(m_ptr, "FootPinningPoseOpFixedData_t", "m_flLockBreakDistance");
}
void GFootPinningPoseOpFixedData_t::SetLockBreakDistance(float value) {
    SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_flLockBreakDistance", true, value);
}
float GFootPinningPoseOpFixedData_t::GetMaxLegTwist() const {
    return GetSchemaValue<float>(m_ptr, "FootPinningPoseOpFixedData_t", "m_flMaxLegTwist");
}
void GFootPinningPoseOpFixedData_t::SetMaxLegTwist(float value) {
    SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_flMaxLegTwist", true, value);
}
int32_t GFootPinningPoseOpFixedData_t::GetHipBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootPinningPoseOpFixedData_t", "m_nHipBoneIndex");
}
void GFootPinningPoseOpFixedData_t::SetHipBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_nHipBoneIndex", true, value);
}
bool GFootPinningPoseOpFixedData_t::GetApplyLegTwistLimits() const {
    return GetSchemaValue<bool>(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyLegTwistLimits");
}
void GFootPinningPoseOpFixedData_t::SetApplyLegTwistLimits(bool value) {
    SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyLegTwistLimits", true, value);
}
bool GFootPinningPoseOpFixedData_t::GetApplyFootRotationLimits() const {
    return GetSchemaValue<bool>(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyFootRotationLimits");
}
void GFootPinningPoseOpFixedData_t::SetApplyFootRotationLimits(bool value) {
    SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyFootRotationLimits", true, value);
}
std::string GFootPinningPoseOpFixedData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFootPinningPoseOpFixedData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFootPinningPoseOpFixedData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootPinningPoseOpFixedData_t>("FootPinningPoseOpFixedData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootInfo", &GFootPinningPoseOpFixedData_t::GetFootInfo, &GFootPinningPoseOpFixedData_t::SetFootInfo)
        .addProperty("BlendTime", &GFootPinningPoseOpFixedData_t::GetBlendTime, &GFootPinningPoseOpFixedData_t::SetBlendTime)
        .addProperty("LockBreakDistance", &GFootPinningPoseOpFixedData_t::GetLockBreakDistance, &GFootPinningPoseOpFixedData_t::SetLockBreakDistance)
        .addProperty("MaxLegTwist", &GFootPinningPoseOpFixedData_t::GetMaxLegTwist, &GFootPinningPoseOpFixedData_t::SetMaxLegTwist)
        .addProperty("HipBoneIndex", &GFootPinningPoseOpFixedData_t::GetHipBoneIndex, &GFootPinningPoseOpFixedData_t::SetHipBoneIndex)
        .addProperty("ApplyLegTwistLimits", &GFootPinningPoseOpFixedData_t::GetApplyLegTwistLimits, &GFootPinningPoseOpFixedData_t::SetApplyLegTwistLimits)
        .addProperty("ApplyFootRotationLimits", &GFootPinningPoseOpFixedData_t::GetApplyFootRotationLimits, &GFootPinningPoseOpFixedData_t::SetApplyFootRotationLimits)
        .addFunction("ToPtr", &GFootPinningPoseOpFixedData_t::ToPtr)
        .addFunction("IsValid", &GFootPinningPoseOpFixedData_t::IsValid)
        .endClass();
}