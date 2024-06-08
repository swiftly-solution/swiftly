class GCFutureVelocityMetricEvaluator;

#ifndef _gccfuturevelocitymetricevaluator_h
#define _gccfuturevelocitymetricevaluator_h

#include "../../../scripting.h"

#include "../types/GVelocityMetricMode.h"


class GCFutureVelocityMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCFutureVelocityMetricEvaluator() {}
    GCFutureVelocityMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    float GetDistance() const { return GetSchemaValue<float>(m_ptr, "CFutureVelocityMetricEvaluator", "m_flDistance"); }
    void SetDistance(float value) { SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_flDistance", false, value); }
    float GetStoppingDistance() const { return GetSchemaValue<float>(m_ptr, "CFutureVelocityMetricEvaluator", "m_flStoppingDistance"); }
    void SetStoppingDistance(float value) { SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_flStoppingDistance", false, value); }
    float GetTargetSpeed() const { return GetSchemaValue<float>(m_ptr, "CFutureVelocityMetricEvaluator", "m_flTargetSpeed"); }
    void SetTargetSpeed(float value) { SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_flTargetSpeed", false, value); }
    VelocityMetricMode GetMode() const { return GetSchemaValue<VelocityMetricMode>(m_ptr, "CFutureVelocityMetricEvaluator", "m_eMode"); }
    void SetMode(VelocityMetricMode value) { SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_eMode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif