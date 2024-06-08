class GCountdownTimer;

#ifndef _gccountdowntimer_h
#define _gccountdowntimer_h

#include "../../../scripting.h"




class GCountdownTimer
{
private:
    void *m_ptr;

public:
    GCountdownTimer() {}
    GCountdownTimer(void *ptr) : m_ptr(ptr) {}

    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CountdownTimer", "m_duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CountdownTimer", "m_duration", false, value); }
    float GetTimescale() const { return GetSchemaValue<float>(m_ptr, "CountdownTimer", "m_timescale"); }
    void SetTimescale(float value) { SetSchemaValue(m_ptr, "CountdownTimer", "m_timescale", false, value); }
    WorldGroupId_t GetWorldGroupId() const { return GetSchemaValue<WorldGroupId_t>(m_ptr, "CountdownTimer", "m_nWorldGroupId"); }
    void SetWorldGroupId(WorldGroupId_t value) { SetSchemaValue(m_ptr, "CountdownTimer", "m_nWorldGroupId", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif