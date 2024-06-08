class GCSimTimer;

#ifndef _gccsimtimer_h
#define _gccsimtimer_h

#include "../../../scripting.h"




class GCSimTimer
{
private:
    void *m_ptr;

public:
    GCSimTimer() {}
    GCSimTimer(void *ptr) : m_ptr(ptr) {}

    float GetInterval() const { return GetSchemaValue<float>(m_ptr, "CSimTimer", "m_interval"); }
    void SetInterval(float value) { SetSchemaValue(m_ptr, "CSimTimer", "m_interval", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif