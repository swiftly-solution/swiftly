class GEngineCountdownTimer;

#ifndef _gcenginecountdowntimer_h
#define _gcenginecountdowntimer_h

#include "../../../scripting.h"




class GEngineCountdownTimer
{
private:
    void *m_ptr;

public:
    GEngineCountdownTimer() {}
    GEngineCountdownTimer(void *ptr) : m_ptr(ptr) {}

    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "EngineCountdownTimer", "m_duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "EngineCountdownTimer", "m_duration", false, value); }
    float GetTimestamp() const { return GetSchemaValue<float>(m_ptr, "EngineCountdownTimer", "m_timestamp"); }
    void SetTimestamp(float value) { SetSchemaValue(m_ptr, "EngineCountdownTimer", "m_timestamp", false, value); }
    float GetTimescale() const { return GetSchemaValue<float>(m_ptr, "EngineCountdownTimer", "m_timescale"); }
    void SetTimescale(float value) { SetSchemaValue(m_ptr, "EngineCountdownTimer", "m_timescale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif