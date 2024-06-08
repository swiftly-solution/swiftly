class GCNmStateNode__TimedEvent_t;

#ifndef _gccnmstatenode__timedevent_t_h
#define _gccnmstatenode__timedevent_t_h

#include "../../../scripting.h"




class GCNmStateNode__TimedEvent_t
{
private:
    void *m_ptr;

public:
    GCNmStateNode__TimedEvent_t() {}
    GCNmStateNode__TimedEvent_t(void *ptr) : m_ptr(ptr) {}

    float GetTimeValue() const { return GetSchemaValue<float>(m_ptr, "CNmStateNode__TimedEvent_t", "m_timeValue"); }
    void SetTimeValue(float value) { SetSchemaValue(m_ptr, "CNmStateNode__TimedEvent_t", "m_timeValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif