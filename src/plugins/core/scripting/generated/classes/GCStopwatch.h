class GCStopwatch;

#ifndef _gccstopwatch_h
#define _gccstopwatch_h

#include "../../../scripting.h"




class GCStopwatch
{
private:
    void *m_ptr;

public:
    GCStopwatch() {}
    GCStopwatch(void *ptr) : m_ptr(ptr) {}

    float GetInterval() const { return GetSchemaValue<float>(m_ptr, "CStopwatch", "m_interval"); }
    void SetInterval(float value) { SetSchemaValue(m_ptr, "CStopwatch", "m_interval", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif