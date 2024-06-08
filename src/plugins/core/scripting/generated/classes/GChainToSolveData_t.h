class GChainToSolveData_t;

#ifndef _gcchaintosolvedata_t_h
#define _gcchaintosolvedata_t_h

#include "../../../scripting.h"

#include "../types/GSolveIKChainAnimNodeDebugSetting.h"
#include "GIKSolverSettings_t.h"
#include "GIKTargetSettings_t.h"

class GChainToSolveData_t
{
private:
    void *m_ptr;

public:
    GChainToSolveData_t() {}
    GChainToSolveData_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetChainIndex() const { return GetSchemaValue<int32_t>(m_ptr, "ChainToSolveData_t", "m_nChainIndex"); }
    void SetChainIndex(int32_t value) { SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_nChainIndex", true, value); }
    GIKSolverSettings_t GetSolverSettings() const { return GetSchemaValue<GIKSolverSettings_t>(m_ptr, "ChainToSolveData_t", "m_SolverSettings"); }
    void SetSolverSettings(GIKSolverSettings_t value) { SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_SolverSettings", true, value); }
    GIKTargetSettings_t GetTargetSettings() const { return GetSchemaValue<GIKTargetSettings_t>(m_ptr, "ChainToSolveData_t", "m_TargetSettings"); }
    void SetTargetSettings(GIKTargetSettings_t value) { SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_TargetSettings", true, value); }
    SolveIKChainAnimNodeDebugSetting GetDebugSetting() const { return GetSchemaValue<SolveIKChainAnimNodeDebugSetting>(m_ptr, "ChainToSolveData_t", "m_DebugSetting"); }
    void SetDebugSetting(SolveIKChainAnimNodeDebugSetting value) { SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_DebugSetting", true, value); }
    float GetDebugNormalizedValue() const { return GetSchemaValue<float>(m_ptr, "ChainToSolveData_t", "m_flDebugNormalizedValue"); }
    void SetDebugNormalizedValue(float value) { SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_flDebugNormalizedValue", true, value); }
    Vector GetDebugOffset() const { return GetSchemaValue<Vector>(m_ptr, "ChainToSolveData_t", "m_vDebugOffset"); }
    void SetDebugOffset(Vector value) { SetSchemaValue(m_ptr, "ChainToSolveData_t", "m_vDebugOffset", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif