class GCTriggerMultiple;

#ifndef _gcctriggermultiple_h
#define _gcctriggermultiple_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCTriggerMultiple
{
private:
    void *m_ptr;

public:
    GCTriggerMultiple() {}
    GCTriggerMultiple(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnTrigger() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CTriggerMultiple", "m_OnTrigger"); }
    void SetOnTrigger(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CTriggerMultiple", "m_OnTrigger", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif