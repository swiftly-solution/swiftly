class GCFootCycleMetricEvaluator;

#ifndef _gccfootcyclemetricevaluator_h
#define _gccfootcyclemetricevaluator_h

#include "../../../scripting.h"




class GCFootCycleMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCFootCycleMetricEvaluator() {}
    GCFootCycleMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    std::vector<int32> GetFootIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CFootCycleMetricEvaluator", "m_footIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CFootCycleMetricEvaluator", "m_footIndices", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif