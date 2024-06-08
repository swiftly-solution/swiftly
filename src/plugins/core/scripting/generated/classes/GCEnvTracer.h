class GCEnvTracer;

#ifndef _gccenvtracer_h
#define _gccenvtracer_h

#include "../../../scripting.h"




class GCEnvTracer
{
private:
    void *m_ptr;

public:
    GCEnvTracer() {}
    GCEnvTracer(void *ptr) : m_ptr(ptr) {}

    Vector GetEnd() const { return GetSchemaValue<Vector>(m_ptr, "CEnvTracer", "m_vecEnd"); }
    void SetEnd(Vector value) { SetSchemaValue(m_ptr, "CEnvTracer", "m_vecEnd", false, value); }
    float GetDelay() const { return GetSchemaValue<float>(m_ptr, "CEnvTracer", "m_flDelay"); }
    void SetDelay(float value) { SetSchemaValue(m_ptr, "CEnvTracer", "m_flDelay", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif