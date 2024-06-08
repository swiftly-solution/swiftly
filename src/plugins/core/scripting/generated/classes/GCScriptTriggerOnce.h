class GCScriptTriggerOnce;

#ifndef _gccscripttriggeronce_h
#define _gccscripttriggeronce_h

#include "../../../scripting.h"




class GCScriptTriggerOnce
{
private:
    void *m_ptr;

public:
    GCScriptTriggerOnce() {}
    GCScriptTriggerOnce(void *ptr) : m_ptr(ptr) {}

    Vector GetExtent() const { return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerOnce", "m_vExtent"); }
    void SetExtent(Vector value) { SetSchemaValue(m_ptr, "CScriptTriggerOnce", "m_vExtent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif