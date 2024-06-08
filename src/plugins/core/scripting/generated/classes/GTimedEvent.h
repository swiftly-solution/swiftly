class GTimedEvent;

#ifndef _gctimedevent_h
#define _gctimedevent_h

#include "../../../scripting.h"




class GTimedEvent
{
private:
    void *m_ptr;

public:
    GTimedEvent() {}
    GTimedEvent(void *ptr) : m_ptr(ptr) {}

    float GetTimeBetweenEvents() const { return GetSchemaValue<float>(m_ptr, "TimedEvent", "m_TimeBetweenEvents"); }
    void SetTimeBetweenEvents(float value) { SetSchemaValue(m_ptr, "TimedEvent", "m_TimeBetweenEvents", false, value); }
    float GetNextEvent() const { return GetSchemaValue<float>(m_ptr, "TimedEvent", "m_fNextEvent"); }
    void SetNextEvent(float value) { SetSchemaValue(m_ptr, "TimedEvent", "m_fNextEvent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif