class GCNmEvent;

#ifndef _gccnmevent_h
#define _gccnmevent_h

#include "../../../scripting.h"




class GCNmEvent
{
private:
    void *m_ptr;

public:
    GCNmEvent() {}
    GCNmEvent(void *ptr) : m_ptr(ptr) {}

    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "CNmEvent", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "CNmEvent", "m_flStartTime", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CNmEvent", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CNmEvent", "m_flDuration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif