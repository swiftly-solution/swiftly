class GSolveIKChainPoseOpFixedSettings_t;

#ifndef _gcsolveikchainposeopfixedsettings_t_h
#define _gcsolveikchainposeopfixedsettings_t_h

#include "../../../scripting.h"


#include "GChainToSolveData_t.h"

class GSolveIKChainPoseOpFixedSettings_t
{
private:
    void *m_ptr;

public:
    GSolveIKChainPoseOpFixedSettings_t() {}
    GSolveIKChainPoseOpFixedSettings_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GChainToSolveData_t> GetChainsToSolveData() const { CUtlVector<GChainToSolveData_t>* vec = GetSchemaValue<CUtlVector<GChainToSolveData_t>*>(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_ChainsToSolveData"); std::vector<GChainToSolveData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChainsToSolveData(std::vector<GChainToSolveData_t> value) { SetSchemaValueCUtlVector<GChainToSolveData_t>(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_ChainsToSolveData", true, value); }
    bool GetMatchTargetOrientation() const { return GetSchemaValue<bool>(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_bMatchTargetOrientation"); }
    void SetMatchTargetOrientation(bool value) { SetSchemaValue(m_ptr, "SolveIKChainPoseOpFixedSettings_t", "m_bMatchTargetOrientation", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif