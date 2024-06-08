class GTraceSettings_t;

#ifndef _gctracesettings_t_h
#define _gctracesettings_t_h

#include "../../../scripting.h"




class GTraceSettings_t
{
private:
    void *m_ptr;

public:
    GTraceSettings_t() {}
    GTraceSettings_t(void *ptr) : m_ptr(ptr) {}

    float GetTraceHeight() const { return GetSchemaValue<float>(m_ptr, "TraceSettings_t", "m_flTraceHeight"); }
    void SetTraceHeight(float value) { SetSchemaValue(m_ptr, "TraceSettings_t", "m_flTraceHeight", true, value); }
    float GetTraceRadius() const { return GetSchemaValue<float>(m_ptr, "TraceSettings_t", "m_flTraceRadius"); }
    void SetTraceRadius(float value) { SetSchemaValue(m_ptr, "TraceSettings_t", "m_flTraceRadius", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif