class GAimCameraOpFixedSettings_t;

#ifndef _gcaimcameraopfixedsettings_t_h
#define _gcaimcameraopfixedsettings_t_h

#include "../../../scripting.h"




class GAimCameraOpFixedSettings_t
{
private:
    void *m_ptr;

public:
    GAimCameraOpFixedSettings_t() {}
    GAimCameraOpFixedSettings_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetChainIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nChainIndex"); }
    void SetChainIndex(int32_t value) { SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nChainIndex", true, value); }
    int32_t GetCameraJointIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nCameraJointIndex"); }
    void SetCameraJointIndex(int32_t value) { SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nCameraJointIndex", true, value); }
    int32_t GetPelvisJointIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nPelvisJointIndex"); }
    void SetPelvisJointIndex(int32_t value) { SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nPelvisJointIndex", true, value); }
    int32_t GetClavicleLeftJointIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleLeftJointIndex"); }
    void SetClavicleLeftJointIndex(int32_t value) { SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleLeftJointIndex", true, value); }
    int32_t GetClavicleRightJointIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleRightJointIndex"); }
    void SetClavicleRightJointIndex(int32_t value) { SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleRightJointIndex", true, value); }
    int32_t GetDepenetrationJointIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nDepenetrationJointIndex"); }
    void SetDepenetrationJointIndex(int32_t value) { SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nDepenetrationJointIndex", true, value); }
    std::vector<int32> GetPropJoints() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "AimCameraOpFixedSettings_t", "m_propJoints"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPropJoints(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "AimCameraOpFixedSettings_t", "m_propJoints", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif