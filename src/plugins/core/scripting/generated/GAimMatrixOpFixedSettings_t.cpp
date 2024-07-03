#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAimMatrixOpFixedSettings_t::GAimMatrixOpFixedSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAimMatrixOpFixedSettings_t::GAimMatrixOpFixedSettings_t(void *ptr) {
    m_ptr = ptr;
}
GCAnimAttachment GAimMatrixOpFixedSettings_t::GetAttachment() const {
    GCAnimAttachment value(GetSchemaPtr(m_ptr, "AimMatrixOpFixedSettings_t", "m_attachment"));
    return value;
}
void GAimMatrixOpFixedSettings_t::SetAttachment(GCAnimAttachment value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_attachment", true, value);
}
GCAnimInputDamping GAimMatrixOpFixedSettings_t::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "AimMatrixOpFixedSettings_t", "m_damping"));
    return value;
}
void GAimMatrixOpFixedSettings_t::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_damping", true, value);
}
std::vector<GCPoseHandle> GAimMatrixOpFixedSettings_t::GetPoseCacheHandles() const {
    GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "AimMatrixOpFixedSettings_t", "m_poseCacheHandles"); std::vector<GCPoseHandle> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GAimMatrixOpFixedSettings_t::SetPoseCacheHandles(std::vector<GCPoseHandle> value) {
    GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "AimMatrixOpFixedSettings_t", "m_poseCacheHandles"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_poseCacheHandles", true, outValue);
}
uint64_t GAimMatrixOpFixedSettings_t::GetBlendMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "AimMatrixOpFixedSettings_t", "m_eBlendMode");
}
void GAimMatrixOpFixedSettings_t::SetBlendMode(uint64_t value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_eBlendMode", true, value);
}
float GAimMatrixOpFixedSettings_t::GetMaxYawAngle() const {
    return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxYawAngle");
}
void GAimMatrixOpFixedSettings_t::SetMaxYawAngle(float value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxYawAngle", true, value);
}
float GAimMatrixOpFixedSettings_t::GetMaxPitchAngle() const {
    return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxPitchAngle");
}
void GAimMatrixOpFixedSettings_t::SetMaxPitchAngle(float value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxPitchAngle", true, value);
}
int32_t GAimMatrixOpFixedSettings_t::GetSequenceMaxFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimMatrixOpFixedSettings_t", "m_nSequenceMaxFrame");
}
void GAimMatrixOpFixedSettings_t::SetSequenceMaxFrame(int32_t value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_nSequenceMaxFrame", true, value);
}
int32_t GAimMatrixOpFixedSettings_t::GetBoneMaskIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimMatrixOpFixedSettings_t", "m_nBoneMaskIndex");
}
void GAimMatrixOpFixedSettings_t::SetBoneMaskIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_nBoneMaskIndex", true, value);
}
bool GAimMatrixOpFixedSettings_t::GetTargetIsPosition() const {
    return GetSchemaValue<bool>(m_ptr, "AimMatrixOpFixedSettings_t", "m_bTargetIsPosition");
}
void GAimMatrixOpFixedSettings_t::SetTargetIsPosition(bool value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_bTargetIsPosition", true, value);
}
bool GAimMatrixOpFixedSettings_t::GetUseBiasAndClamp() const {
    return GetSchemaValue<bool>(m_ptr, "AimMatrixOpFixedSettings_t", "m_bUseBiasAndClamp");
}
void GAimMatrixOpFixedSettings_t::SetUseBiasAndClamp(bool value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_bUseBiasAndClamp", true, value);
}
float GAimMatrixOpFixedSettings_t::GetBiasAndClampYawOffset() const {
    return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampYawOffset");
}
void GAimMatrixOpFixedSettings_t::SetBiasAndClampYawOffset(float value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampYawOffset", true, value);
}
float GAimMatrixOpFixedSettings_t::GetBiasAndClampPitchOffset() const {
    return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampPitchOffset");
}
void GAimMatrixOpFixedSettings_t::SetBiasAndClampPitchOffset(float value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampPitchOffset", true, value);
}
GCBlendCurve GAimMatrixOpFixedSettings_t::GetBiasAndClampBlendCurve() const {
    GCBlendCurve value(GetSchemaPtr(m_ptr, "AimMatrixOpFixedSettings_t", "m_biasAndClampBlendCurve"));
    return value;
}
void GAimMatrixOpFixedSettings_t::SetBiasAndClampBlendCurve(GCBlendCurve value) {
    SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_biasAndClampBlendCurve", true, value);
}
std::string GAimMatrixOpFixedSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAimMatrixOpFixedSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAimMatrixOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAimMatrixOpFixedSettings_t>("AimMatrixOpFixedSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Attachment", &GAimMatrixOpFixedSettings_t::GetAttachment, &GAimMatrixOpFixedSettings_t::SetAttachment)
        .addProperty("Damping", &GAimMatrixOpFixedSettings_t::GetDamping, &GAimMatrixOpFixedSettings_t::SetDamping)
        .addProperty("PoseCacheHandles", &GAimMatrixOpFixedSettings_t::GetPoseCacheHandles, &GAimMatrixOpFixedSettings_t::SetPoseCacheHandles)
        .addProperty("BlendMode", &GAimMatrixOpFixedSettings_t::GetBlendMode, &GAimMatrixOpFixedSettings_t::SetBlendMode)
        .addProperty("MaxYawAngle", &GAimMatrixOpFixedSettings_t::GetMaxYawAngle, &GAimMatrixOpFixedSettings_t::SetMaxYawAngle)
        .addProperty("MaxPitchAngle", &GAimMatrixOpFixedSettings_t::GetMaxPitchAngle, &GAimMatrixOpFixedSettings_t::SetMaxPitchAngle)
        .addProperty("SequenceMaxFrame", &GAimMatrixOpFixedSettings_t::GetSequenceMaxFrame, &GAimMatrixOpFixedSettings_t::SetSequenceMaxFrame)
        .addProperty("BoneMaskIndex", &GAimMatrixOpFixedSettings_t::GetBoneMaskIndex, &GAimMatrixOpFixedSettings_t::SetBoneMaskIndex)
        .addProperty("TargetIsPosition", &GAimMatrixOpFixedSettings_t::GetTargetIsPosition, &GAimMatrixOpFixedSettings_t::SetTargetIsPosition)
        .addProperty("UseBiasAndClamp", &GAimMatrixOpFixedSettings_t::GetUseBiasAndClamp, &GAimMatrixOpFixedSettings_t::SetUseBiasAndClamp)
        .addProperty("BiasAndClampYawOffset", &GAimMatrixOpFixedSettings_t::GetBiasAndClampYawOffset, &GAimMatrixOpFixedSettings_t::SetBiasAndClampYawOffset)
        .addProperty("BiasAndClampPitchOffset", &GAimMatrixOpFixedSettings_t::GetBiasAndClampPitchOffset, &GAimMatrixOpFixedSettings_t::SetBiasAndClampPitchOffset)
        .addProperty("BiasAndClampBlendCurve", &GAimMatrixOpFixedSettings_t::GetBiasAndClampBlendCurve, &GAimMatrixOpFixedSettings_t::SetBiasAndClampBlendCurve)
        .addFunction("ToPtr", &GAimMatrixOpFixedSettings_t::ToPtr)
        .addFunction("IsValid", &GAimMatrixOpFixedSettings_t::IsValid)
        .endClass();
}