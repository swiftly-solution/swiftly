class GFootPinningPoseOpFixedData_t;

#ifndef _gcfootpinningposeopfixeddata_t_h
#define _gcfootpinningposeopfixeddata_t_h

#include "../../../scripting.h"


#include "GFootFixedData_t.h"

class GFootPinningPoseOpFixedData_t
{
private:
    void *m_ptr;

public:
    GFootPinningPoseOpFixedData_t() {}
    GFootPinningPoseOpFixedData_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GFootFixedData_t> GetFootInfo() const { CUtlVector<GFootFixedData_t>* vec = GetSchemaValue<CUtlVector<GFootFixedData_t>*>(m_ptr, "FootPinningPoseOpFixedData_t", "m_footInfo"); std::vector<GFootFixedData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootInfo(std::vector<GFootFixedData_t> value) { SetSchemaValueCUtlVector<GFootFixedData_t>(m_ptr, "FootPinningPoseOpFixedData_t", "m_footInfo", true, value); }
    float GetBlendTime() const { return GetSchemaValue<float>(m_ptr, "FootPinningPoseOpFixedData_t", "m_flBlendTime"); }
    void SetBlendTime(float value) { SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_flBlendTime", true, value); }
    float GetLockBreakDistance() const { return GetSchemaValue<float>(m_ptr, "FootPinningPoseOpFixedData_t", "m_flLockBreakDistance"); }
    void SetLockBreakDistance(float value) { SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_flLockBreakDistance", true, value); }
    float GetMaxLegTwist() const { return GetSchemaValue<float>(m_ptr, "FootPinningPoseOpFixedData_t", "m_flMaxLegTwist"); }
    void SetMaxLegTwist(float value) { SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_flMaxLegTwist", true, value); }
    int32_t GetHipBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootPinningPoseOpFixedData_t", "m_nHipBoneIndex"); }
    void SetHipBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_nHipBoneIndex", true, value); }
    bool GetApplyLegTwistLimits() const { return GetSchemaValue<bool>(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyLegTwistLimits"); }
    void SetApplyLegTwistLimits(bool value) { SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyLegTwistLimits", true, value); }
    bool GetApplyFootRotationLimits() const { return GetSchemaValue<bool>(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyFootRotationLimits"); }
    void SetApplyFootRotationLimits(bool value) { SetSchemaValue(m_ptr, "FootPinningPoseOpFixedData_t", "m_bApplyFootRotationLimits", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif