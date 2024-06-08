class GCMotionMetricEvaluator;

#ifndef _gccmotionmetricevaluator_h
#define _gccmotionmetricevaluator_h

#include "../../../scripting.h"




class GCMotionMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCMotionMetricEvaluator() {}
    GCMotionMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    std::vector<float32> GetMeans() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMotionMetricEvaluator", "m_means"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMeans(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CMotionMetricEvaluator", "m_means", false, value); }
    std::vector<float32> GetStandardDeviations() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMotionMetricEvaluator", "m_standardDeviations"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetStandardDeviations(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CMotionMetricEvaluator", "m_standardDeviations", false, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "CMotionMetricEvaluator", "m_flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "CMotionMetricEvaluator", "m_flWeight", false, value); }
    int32_t GetDimensionStartIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionMetricEvaluator", "m_nDimensionStartIndex"); }
    void SetDimensionStartIndex(int32_t value) { SetSchemaValue(m_ptr, "CMotionMetricEvaluator", "m_nDimensionStartIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif