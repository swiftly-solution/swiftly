class GCPlayerInputAnimMotorUpdater;

#ifndef _gccplayerinputanimmotorupdater_h
#define _gccplayerinputanimmotorupdater_h

#include "../../../scripting.h"


#include "GCAnimParamHandle.h"

class GCPlayerInputAnimMotorUpdater
{
private:
    void *m_ptr;

public:
    GCPlayerInputAnimMotorUpdater() {}
    GCPlayerInputAnimMotorUpdater(void *ptr) : m_ptr(ptr) {}

    std::vector<float32> GetSampleTimes() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_sampleTimes"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSampleTimes(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_sampleTimes", false, value); }
    float GetSpringConstant() const { return GetSchemaValue<float>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flSpringConstant"); }
    void SetSpringConstant(float value) { SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flSpringConstant", false, value); }
    float GetAnticipationDistance() const { return GetSchemaValue<float>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flAnticipationDistance"); }
    void SetAnticipationDistance(float value) { SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_flAnticipationDistance", false, value); }
    GCAnimParamHandle GetAnticipationPosParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationPosParam"); }
    void SetAnticipationPosParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationPosParam", false, value); }
    GCAnimParamHandle GetAnticipationHeadingParam() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationHeadingParam"); }
    void SetAnticipationHeadingParam(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_hAnticipationHeadingParam", false, value); }
    bool GetUseAcceleration() const { return GetSchemaValue<bool>(m_ptr, "CPlayerInputAnimMotorUpdater", "m_bUseAcceleration"); }
    void SetUseAcceleration(bool value) { SetSchemaValue(m_ptr, "CPlayerInputAnimMotorUpdater", "m_bUseAcceleration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif