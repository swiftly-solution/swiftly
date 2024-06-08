class GCFutureFacingMetricEvaluator;

#ifndef _gccfuturefacingmetricevaluator_h
#define _gccfuturefacingmetricevaluator_h

#include "../../../scripting.h"




class GCFutureFacingMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCFutureFacingMetricEvaluator() {}
    GCFutureFacingMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    float GetDistance() const { return GetSchemaValue<float>(m_ptr, "CFutureFacingMetricEvaluator", "m_flDistance"); }
    void SetDistance(float value) { SetSchemaValue(m_ptr, "CFutureFacingMetricEvaluator", "m_flDistance", false, value); }
    float GetTime() const { return GetSchemaValue<float>(m_ptr, "CFutureFacingMetricEvaluator", "m_flTime"); }
    void SetTime(float value) { SetSchemaValue(m_ptr, "CFutureFacingMetricEvaluator", "m_flTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif