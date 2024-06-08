class GCRandSimTimer;

#ifndef _gccrandsimtimer_h
#define _gccrandsimtimer_h

#include "../../../scripting.h"




class GCRandSimTimer
{
private:
    void *m_ptr;

public:
    GCRandSimTimer() {}
    GCRandSimTimer(void *ptr) : m_ptr(ptr) {}

    float GetMinInterval() const { return GetSchemaValue<float>(m_ptr, "CRandSimTimer", "m_minInterval"); }
    void SetMinInterval(float value) { SetSchemaValue(m_ptr, "CRandSimTimer", "m_minInterval", false, value); }
    float GetMaxInterval() const { return GetSchemaValue<float>(m_ptr, "CRandSimTimer", "m_maxInterval"); }
    void SetMaxInterval(float value) { SetSchemaValue(m_ptr, "CRandSimTimer", "m_maxInterval", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif