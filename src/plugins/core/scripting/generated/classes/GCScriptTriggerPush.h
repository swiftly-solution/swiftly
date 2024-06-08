class GCScriptTriggerPush;

#ifndef _gccscripttriggerpush_h
#define _gccscripttriggerpush_h

#include "../../../scripting.h"




class GCScriptTriggerPush
{
private:
    void *m_ptr;

public:
    GCScriptTriggerPush() {}
    GCScriptTriggerPush(void *ptr) : m_ptr(ptr) {}

    Vector GetExtent() const { return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerPush", "m_vExtent"); }
    void SetExtent(Vector value) { SetSchemaValue(m_ptr, "CScriptTriggerPush", "m_vExtent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif