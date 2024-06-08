class GEventFrameBoundary_t;

#ifndef _gceventframeboundary_t_h
#define _gceventframeboundary_t_h

#include "../../../scripting.h"




class GEventFrameBoundary_t
{
private:
    void *m_ptr;

public:
    GEventFrameBoundary_t() {}
    GEventFrameBoundary_t(void *ptr) : m_ptr(ptr) {}

    float GetFrameTime() const { return GetSchemaValue<float>(m_ptr, "EventFrameBoundary_t", "m_flFrameTime"); }
    void SetFrameTime(float value) { SetSchemaValue(m_ptr, "EventFrameBoundary_t", "m_flFrameTime", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif