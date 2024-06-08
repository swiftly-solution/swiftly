class GCScriptNavBlocker;

#ifndef _gccscriptnavblocker_h
#define _gccscriptnavblocker_h

#include "../../../scripting.h"




class GCScriptNavBlocker
{
private:
    void *m_ptr;

public:
    GCScriptNavBlocker() {}
    GCScriptNavBlocker(void *ptr) : m_ptr(ptr) {}

    Vector GetExtent() const { return GetSchemaValue<Vector>(m_ptr, "CScriptNavBlocker", "m_vExtent"); }
    void SetExtent(Vector value) { SetSchemaValue(m_ptr, "CScriptNavBlocker", "m_vExtent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif