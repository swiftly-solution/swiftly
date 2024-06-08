class GCFootPositionMetricEvaluator;

#ifndef _gccfootpositionmetricevaluator_h
#define _gccfootpositionmetricevaluator_h

#include "../../../scripting.h"




class GCFootPositionMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCFootPositionMetricEvaluator() {}
    GCFootPositionMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    std::vector<int32> GetFootIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CFootPositionMetricEvaluator", "m_footIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFootIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CFootPositionMetricEvaluator", "m_footIndices", false, value); }
    bool GetIgnoreSlope() const { return GetSchemaValue<bool>(m_ptr, "CFootPositionMetricEvaluator", "m_bIgnoreSlope"); }
    void SetIgnoreSlope(bool value) { SetSchemaValue(m_ptr, "CFootPositionMetricEvaluator", "m_bIgnoreSlope", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif