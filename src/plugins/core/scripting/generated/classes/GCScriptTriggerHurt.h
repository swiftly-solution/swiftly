class GCScriptTriggerHurt;

#ifndef _gccscripttriggerhurt_h
#define _gccscripttriggerhurt_h

#include "../../../scripting.h"




class GCScriptTriggerHurt
{
private:
    void *m_ptr;

public:
    GCScriptTriggerHurt() {}
    GCScriptTriggerHurt(void *ptr) : m_ptr(ptr) {}

    Vector GetExtent() const { return GetSchemaValue<Vector>(m_ptr, "CScriptTriggerHurt", "m_vExtent"); }
    void SetExtent(Vector value) { SetSchemaValue(m_ptr, "CScriptTriggerHurt", "m_vExtent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif