class GCTimeRemainingMetricEvaluator;

#ifndef _gcctimeremainingmetricevaluator_h
#define _gcctimeremainingmetricevaluator_h

#include "../../../scripting.h"




class GCTimeRemainingMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCTimeRemainingMetricEvaluator() {}
    GCTimeRemainingMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    bool GetMatchByTimeRemaining() const { return GetSchemaValue<bool>(m_ptr, "CTimeRemainingMetricEvaluator", "m_bMatchByTimeRemaining"); }
    void SetMatchByTimeRemaining(bool value) { SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_bMatchByTimeRemaining", false, value); }
    float GetMaxTimeRemaining() const { return GetSchemaValue<float>(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMaxTimeRemaining"); }
    void SetMaxTimeRemaining(float value) { SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMaxTimeRemaining", false, value); }
    bool GetFilterByTimeRemaining() const { return GetSchemaValue<bool>(m_ptr, "CTimeRemainingMetricEvaluator", "m_bFilterByTimeRemaining"); }
    void SetFilterByTimeRemaining(bool value) { SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_bFilterByTimeRemaining", false, value); }
    float GetMinTimeRemaining() const { return GetSchemaValue<float>(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMinTimeRemaining"); }
    void SetMinTimeRemaining(float value) { SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMinTimeRemaining", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif