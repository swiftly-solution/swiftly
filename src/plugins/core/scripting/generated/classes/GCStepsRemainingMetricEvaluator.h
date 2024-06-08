class GCStepsRemainingMetricEvaluator;

#ifndef _gccstepsremainingmetricevaluator_h
#define _gccstepsremainingmetricevaluator_h

#include "../../../scripting.h"




class GCStepsRemainingMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCStepsRemainingMetricEvaluator() {}
    GCStepsRemainingMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    std::vector<int32> GetFootIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CStepsRemainingMetricEvaluator", "m_footIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CStepsRemainingMetricEvaluator", "m_footIndices", false, value); }
    float GetMinStepsRemaining() const { return GetSchemaValue<float>(m_ptr, "CStepsRemainingMetricEvaluator", "m_flMinStepsRemaining"); }
    void SetMinStepsRemaining(float value) { SetSchemaValue(m_ptr, "CStepsRemainingMetricEvaluator", "m_flMinStepsRemaining", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif