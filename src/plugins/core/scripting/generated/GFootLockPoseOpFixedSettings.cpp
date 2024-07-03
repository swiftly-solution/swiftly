#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFootLockPoseOpFixedSettings::GFootLockPoseOpFixedSettings(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFootLockPoseOpFixedSettings::GFootLockPoseOpFixedSettings(void *ptr) {
    m_ptr = ptr;
}
std::vector<GFootFixedData_t> GFootLockPoseOpFixedSettings::GetFootInfo() const {
    CUtlVector<GFootFixedData_t>* vec = GetSchemaValue<CUtlVector<GFootFixedData_t>*>(m_ptr, "FootLockPoseOpFixedSettings", "m_footInfo"); std::vector<GFootFixedData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFootLockPoseOpFixedSettings::SetFootInfo(std::vector<GFootFixedData_t> value) {
    SetSchemaValueCUtlVector<GFootFixedData_t>(m_ptr, "FootLockPoseOpFixedSettings", "m_footInfo", false, value);
}
GCAnimInputDamping GFootLockPoseOpFixedSettings::GetHipDampingSettings() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "FootLockPoseOpFixedSettings", "m_hipDampingSettings"));
    return value;
}
void GFootLockPoseOpFixedSettings::SetHipDampingSettings(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_hipDampingSettings", false, value);
}
int32_t GFootLockPoseOpFixedSettings::GetHipBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootLockPoseOpFixedSettings", "m_nHipBoneIndex");
}
void GFootLockPoseOpFixedSettings::SetHipBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_nHipBoneIndex", false, value);
}
uint64_t GFootLockPoseOpFixedSettings::GetIkSolverType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "FootLockPoseOpFixedSettings", "m_ikSolverType");
}
void GFootLockPoseOpFixedSettings::SetIkSolverType(uint64_t value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_ikSolverType", false, value);
}
bool GFootLockPoseOpFixedSettings::GetApplyTilt() const {
    return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyTilt");
}
void GFootLockPoseOpFixedSettings::SetApplyTilt(bool value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyTilt", false, value);
}
bool GFootLockPoseOpFixedSettings::GetApplyHipDrop() const {
    return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyHipDrop");
}
void GFootLockPoseOpFixedSettings::SetApplyHipDrop(bool value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyHipDrop", false, value);
}
bool GFootLockPoseOpFixedSettings::GetAlwaysUseFallbackHinge() const {
    return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bAlwaysUseFallbackHinge");
}
void GFootLockPoseOpFixedSettings::SetAlwaysUseFallbackHinge(bool value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bAlwaysUseFallbackHinge", false, value);
}
bool GFootLockPoseOpFixedSettings::GetApplyFootRotationLimits() const {
    return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyFootRotationLimits");
}
void GFootLockPoseOpFixedSettings::SetApplyFootRotationLimits(bool value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyFootRotationLimits", false, value);
}
bool GFootLockPoseOpFixedSettings::GetApplyLegTwistLimits() const {
    return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyLegTwistLimits");
}
void GFootLockPoseOpFixedSettings::SetApplyLegTwistLimits(bool value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bApplyLegTwistLimits", false, value);
}
float GFootLockPoseOpFixedSettings::GetMaxFootHeight() const {
    return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxFootHeight");
}
void GFootLockPoseOpFixedSettings::SetMaxFootHeight(float value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxFootHeight", false, value);
}
float GFootLockPoseOpFixedSettings::GetExtensionScale() const {
    return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flExtensionScale");
}
void GFootLockPoseOpFixedSettings::SetExtensionScale(float value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flExtensionScale", false, value);
}
float GFootLockPoseOpFixedSettings::GetMaxLegTwist() const {
    return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxLegTwist");
}
void GFootLockPoseOpFixedSettings::SetMaxLegTwist(float value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxLegTwist", false, value);
}
bool GFootLockPoseOpFixedSettings::GetEnableLockBreaking() const {
    return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableLockBreaking");
}
void GFootLockPoseOpFixedSettings::SetEnableLockBreaking(bool value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableLockBreaking", false, value);
}
float GFootLockPoseOpFixedSettings::GetLockBreakTolerance() const {
    return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBreakTolerance");
}
void GFootLockPoseOpFixedSettings::SetLockBreakTolerance(float value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBreakTolerance", false, value);
}
float GFootLockPoseOpFixedSettings::GetLockBlendTime() const {
    return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBlendTime");
}
void GFootLockPoseOpFixedSettings::SetLockBlendTime(float value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flLockBlendTime", false, value);
}
bool GFootLockPoseOpFixedSettings::GetEnableStretching() const {
    return GetSchemaValue<bool>(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableStretching");
}
void GFootLockPoseOpFixedSettings::SetEnableStretching(bool value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_bEnableStretching", false, value);
}
float GFootLockPoseOpFixedSettings::GetMaxStretchAmount() const {
    return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxStretchAmount");
}
void GFootLockPoseOpFixedSettings::SetMaxStretchAmount(float value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flMaxStretchAmount", false, value);
}
float GFootLockPoseOpFixedSettings::GetStretchExtensionScale() const {
    return GetSchemaValue<float>(m_ptr, "FootLockPoseOpFixedSettings", "m_flStretchExtensionScale");
}
void GFootLockPoseOpFixedSettings::SetStretchExtensionScale(float value) {
    SetSchemaValue(m_ptr, "FootLockPoseOpFixedSettings", "m_flStretchExtensionScale", false, value);
}
std::string GFootLockPoseOpFixedSettings::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFootLockPoseOpFixedSettings::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFootLockPoseOpFixedSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootLockPoseOpFixedSettings>("FootLockPoseOpFixedSettings")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootInfo", &GFootLockPoseOpFixedSettings::GetFootInfo, &GFootLockPoseOpFixedSettings::SetFootInfo)
        .addProperty("HipDampingSettings", &GFootLockPoseOpFixedSettings::GetHipDampingSettings, &GFootLockPoseOpFixedSettings::SetHipDampingSettings)
        .addProperty("HipBoneIndex", &GFootLockPoseOpFixedSettings::GetHipBoneIndex, &GFootLockPoseOpFixedSettings::SetHipBoneIndex)
        .addProperty("IkSolverType", &GFootLockPoseOpFixedSettings::GetIkSolverType, &GFootLockPoseOpFixedSettings::SetIkSolverType)
        .addProperty("ApplyTilt", &GFootLockPoseOpFixedSettings::GetApplyTilt, &GFootLockPoseOpFixedSettings::SetApplyTilt)
        .addProperty("ApplyHipDrop", &GFootLockPoseOpFixedSettings::GetApplyHipDrop, &GFootLockPoseOpFixedSettings::SetApplyHipDrop)
        .addProperty("AlwaysUseFallbackHinge", &GFootLockPoseOpFixedSettings::GetAlwaysUseFallbackHinge, &GFootLockPoseOpFixedSettings::SetAlwaysUseFallbackHinge)
        .addProperty("ApplyFootRotationLimits", &GFootLockPoseOpFixedSettings::GetApplyFootRotationLimits, &GFootLockPoseOpFixedSettings::SetApplyFootRotationLimits)
        .addProperty("ApplyLegTwistLimits", &GFootLockPoseOpFixedSettings::GetApplyLegTwistLimits, &GFootLockPoseOpFixedSettings::SetApplyLegTwistLimits)
        .addProperty("MaxFootHeight", &GFootLockPoseOpFixedSettings::GetMaxFootHeight, &GFootLockPoseOpFixedSettings::SetMaxFootHeight)
        .addProperty("ExtensionScale", &GFootLockPoseOpFixedSettings::GetExtensionScale, &GFootLockPoseOpFixedSettings::SetExtensionScale)
        .addProperty("MaxLegTwist", &GFootLockPoseOpFixedSettings::GetMaxLegTwist, &GFootLockPoseOpFixedSettings::SetMaxLegTwist)
        .addProperty("EnableLockBreaking", &GFootLockPoseOpFixedSettings::GetEnableLockBreaking, &GFootLockPoseOpFixedSettings::SetEnableLockBreaking)
        .addProperty("LockBreakTolerance", &GFootLockPoseOpFixedSettings::GetLockBreakTolerance, &GFootLockPoseOpFixedSettings::SetLockBreakTolerance)
        .addProperty("LockBlendTime", &GFootLockPoseOpFixedSettings::GetLockBlendTime, &GFootLockPoseOpFixedSettings::SetLockBlendTime)
        .addProperty("EnableStretching", &GFootLockPoseOpFixedSettings::GetEnableStretching, &GFootLockPoseOpFixedSettings::SetEnableStretching)
        .addProperty("MaxStretchAmount", &GFootLockPoseOpFixedSettings::GetMaxStretchAmount, &GFootLockPoseOpFixedSettings::SetMaxStretchAmount)
        .addProperty("StretchExtensionScale", &GFootLockPoseOpFixedSettings::GetStretchExtensionScale, &GFootLockPoseOpFixedSettings::SetStretchExtensionScale)
        .addFunction("ToPtr", &GFootLockPoseOpFixedSettings::ToPtr)
        .addFunction("IsValid", &GFootLockPoseOpFixedSettings::IsValid)
        .endClass();
}