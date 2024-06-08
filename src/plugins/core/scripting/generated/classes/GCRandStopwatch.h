class GCRandStopwatch;

#ifndef _gccrandstopwatch_h
#define _gccrandstopwatch_h

#include "../../../scripting.h"




class GCRandStopwatch
{
private:
    void *m_ptr;

public:
    GCRandStopwatch() {}
    GCRandStopwatch(void *ptr) : m_ptr(ptr) {}

    float GetMinInterval() const { return GetSchemaValue<float>(m_ptr, "CRandStopwatch", "m_minInterval"); }
    void SetMinInterval(float value) { SetSchemaValue(m_ptr, "CRandStopwatch", "m_minInterval", false, value); }
    float GetMaxInterval() const { return GetSchemaValue<float>(m_ptr, "CRandStopwatch", "m_maxInterval"); }
    void SetMaxInterval(float value) { SetSchemaValue(m_ptr, "CRandStopwatch", "m_maxInterval", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif