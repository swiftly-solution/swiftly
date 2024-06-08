class GCPathMetricEvaluator;

#ifndef _gccpathmetricevaluator_h
#define _gccpathmetricevaluator_h

#include "../../../scripting.h"




class GCPathMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCPathMetricEvaluator() {}
    GCPathMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    std::vector<float32> GetPathTimeSamples() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CPathMetricEvaluator", "m_pathTimeSamples"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPathTimeSamples(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CPathMetricEvaluator", "m_pathTimeSamples", false, value); }
    float GetDistance() const { return GetSchemaValue<float>(m_ptr, "CPathMetricEvaluator", "m_flDistance"); }
    void SetDistance(float value) { SetSchemaValue(m_ptr, "CPathMetricEvaluator", "m_flDistance", false, value); }
    bool GetExtrapolateMovement() const { return GetSchemaValue<bool>(m_ptr, "CPathMetricEvaluator", "m_bExtrapolateMovement"); }
    void SetExtrapolateMovement(bool value) { SetSchemaValue(m_ptr, "CPathMetricEvaluator", "m_bExtrapolateMovement", false, value); }
    float GetMinExtrapolationSpeed() const { return GetSchemaValue<float>(m_ptr, "CPathMetricEvaluator", "m_flMinExtrapolationSpeed"); }
    void SetMinExtrapolationSpeed(float value) { SetSchemaValue(m_ptr, "CPathMetricEvaluator", "m_flMinExtrapolationSpeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif