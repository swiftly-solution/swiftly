class GAimMatrixOpFixedSettings_t;

#ifndef _gcaimmatrixopfixedsettings_t_h
#define _gcaimmatrixopfixedsettings_t_h

#include "../../../scripting.h"

#include "../types/GAimMatrixBlendMode.h"
#include "GCAnimAttachment.h"
#include "GCAnimInputDamping.h"
#include "GCPoseHandle.h"
#include "GCBlendCurve.h"

class GAimMatrixOpFixedSettings_t
{
private:
    void *m_ptr;

public:
    GAimMatrixOpFixedSettings_t() {}
    GAimMatrixOpFixedSettings_t(void *ptr) : m_ptr(ptr) {}

    GCAnimAttachment GetAttachment() const { return GetSchemaValue<GCAnimAttachment>(m_ptr, "AimMatrixOpFixedSettings_t", "m_attachment"); }
    void SetAttachment(GCAnimAttachment value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_attachment", true, value); }
    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "AimMatrixOpFixedSettings_t", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_damping", true, value); }
    std::vector<GCPoseHandle> GetPoseCacheHandles() const { GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "AimMatrixOpFixedSettings_t", "m_poseCacheHandles"); std::vector<GCPoseHandle> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPoseCacheHandles(std::vector<GCPoseHandle> value) { GCPoseHandle* outValue = GetSchemaValue<GCPoseHandle*>(m_ptr, "AimMatrixOpFixedSettings_t", "m_poseCacheHandles"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_poseCacheHandles", true, outValue); }
    AimMatrixBlendMode GetBlendMode() const { return GetSchemaValue<AimMatrixBlendMode>(m_ptr, "AimMatrixOpFixedSettings_t", "m_eBlendMode"); }
    void SetBlendMode(AimMatrixBlendMode value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_eBlendMode", true, value); }
    float GetMaxYawAngle() const { return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxYawAngle"); }
    void SetMaxYawAngle(float value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxYawAngle", true, value); }
    float GetMaxPitchAngle() const { return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxPitchAngle"); }
    void SetMaxPitchAngle(float value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flMaxPitchAngle", true, value); }
    int32_t GetSequenceMaxFrame() const { return GetSchemaValue<int32_t>(m_ptr, "AimMatrixOpFixedSettings_t", "m_nSequenceMaxFrame"); }
    void SetSequenceMaxFrame(int32_t value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_nSequenceMaxFrame", true, value); }
    int32_t GetBoneMaskIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AimMatrixOpFixedSettings_t", "m_nBoneMaskIndex"); }
    void SetBoneMaskIndex(int32_t value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_nBoneMaskIndex", true, value); }
    bool GetTargetIsPosition() const { return GetSchemaValue<bool>(m_ptr, "AimMatrixOpFixedSettings_t", "m_bTargetIsPosition"); }
    void SetTargetIsPosition(bool value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_bTargetIsPosition", true, value); }
    bool GetUseBiasAndClamp() const { return GetSchemaValue<bool>(m_ptr, "AimMatrixOpFixedSettings_t", "m_bUseBiasAndClamp"); }
    void SetUseBiasAndClamp(bool value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_bUseBiasAndClamp", true, value); }
    float GetBiasAndClampYawOffset() const { return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampYawOffset"); }
    void SetBiasAndClampYawOffset(float value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampYawOffset", true, value); }
    float GetBiasAndClampPitchOffset() const { return GetSchemaValue<float>(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampPitchOffset"); }
    void SetBiasAndClampPitchOffset(float value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_flBiasAndClampPitchOffset", true, value); }
    GCBlendCurve GetBiasAndClampBlendCurve() const { return GetSchemaValue<GCBlendCurve>(m_ptr, "AimMatrixOpFixedSettings_t", "m_biasAndClampBlendCurve"); }
    void SetBiasAndClampBlendCurve(GCBlendCurve value) { SetSchemaValue(m_ptr, "AimMatrixOpFixedSettings_t", "m_biasAndClampBlendCurve", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif