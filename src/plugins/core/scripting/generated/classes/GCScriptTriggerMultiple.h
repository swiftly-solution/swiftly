class GCScriptTriggerMultiple;

#ifndef _gccscripttriggermultiple_h
#define _gccscripttriggermultiple_h

#include "../../../scripting.h"




class GCScriptTriggerMultiple
{
private:
    void *m_ptr;

public:
    GCScriptTriggerMultiple() {}
    GCScriptTriggerMultiple(void *ptr) : m_ptr(ptr) {}

    Vector GetExtent() const { return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerMultiple", "m_vExtent"); }
    void SetExtent(Vector value) { SetSchemaValue(m_ptr, "CScriptTriggerMultiple", "m_vExtent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif