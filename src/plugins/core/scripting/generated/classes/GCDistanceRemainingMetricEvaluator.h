class GCDistanceRemainingMetricEvaluator;

#ifndef _gccdistanceremainingmetricevaluator_h
#define _gccdistanceremainingmetricevaluator_h

#include "../../../scripting.h"




class GCDistanceRemainingMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCDistanceRemainingMetricEvaluator() {}
    GCDistanceRemainingMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    float GetMaxDistance() const { return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxDistance"); }
    void SetMaxDistance(float value) { SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxDistance", false, value); }
    float GetMinDistance() const { return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMinDistance"); }
    void SetMinDistance(float value) { SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMinDistance", false, value); }
    float GetStartGoalFilterDistance() const { return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flStartGoalFilterDistance"); }
    void SetStartGoalFilterDistance(float value) { SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flStartGoalFilterDistance", false, value); }
    float GetMaxGoalOvershootScale() const { return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxGoalOvershootScale"); }
    void SetMaxGoalOvershootScale(float value) { SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxGoalOvershootScale", false, value); }
    bool GetFilterFixedMinDistance() const { return GetSchemaValue<bool>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterFixedMinDistance"); }
    void SetFilterFixedMinDistance(bool value) { SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterFixedMinDistance", false, value); }
    bool GetFilterGoalDistance() const { return GetSchemaValue<bool>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalDistance"); }
    void SetFilterGoalDistance(bool value) { SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalDistance", false, value); }
    bool GetFilterGoalOvershoot() const { return GetSchemaValue<bool>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalOvershoot"); }
    void SetFilterGoalOvershoot(bool value) { SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalOvershoot", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif