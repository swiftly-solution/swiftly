class GCBtNodeConditionInactive;

#ifndef _gccbtnodeconditioninactive_h
#define _gccbtnodeconditioninactive_h

#include "../../../scripting.h"


#include "GCountdownTimer.h"

class GCBtNodeConditionInactive
{
private:
    void *m_ptr;

public:
    GCBtNodeConditionInactive() {}
    GCBtNodeConditionInactive(void *ptr) : m_ptr(ptr) {}

    float GetRoundStartThresholdSeconds() const { return GetSchemaValue<float>(m_ptr, "CBtNodeConditionInactive", "m_flRoundStartThresholdSeconds"); }
    void SetRoundStartThresholdSeconds(float value) { SetSchemaValue(m_ptr, "CBtNodeConditionInactive", "m_flRoundStartThresholdSeconds", false, value); }
    float GetSensorInactivityThresholdSeconds() const { return GetSchemaValue<float>(m_ptr, "CBtNodeConditionInactive", "m_flSensorInactivityThresholdSeconds"); }
    void SetSensorInactivityThresholdSeconds(float value) { SetSchemaValue(m_ptr, "CBtNodeConditionInactive", "m_flSensorInactivityThresholdSeconds", false, value); }
    GCountdownTimer GetSensorInactivityTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CBtNodeConditionInactive", "m_SensorInactivityTimer"); }
    void SetSensorInactivityTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CBtNodeConditionInactive", "m_SensorInactivityTimer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif