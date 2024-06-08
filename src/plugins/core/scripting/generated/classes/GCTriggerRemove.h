class GCTriggerRemove;

#ifndef _gcctriggerremove_h
#define _gcctriggerremove_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTriggerRemove
{
private:
    void *m_ptr;

public:
    GCTriggerRemove() {}
    GCTriggerRemove(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnRemove() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerRemove", "m_OnRemove"); }
    void SetOnRemove(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerRemove", "m_OnRemove", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif