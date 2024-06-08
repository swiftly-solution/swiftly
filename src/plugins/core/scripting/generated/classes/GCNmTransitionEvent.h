class GCNmTransitionEvent;

#ifndef _gccnmtransitionevent_h
#define _gccnmtransitionevent_h

#include "../../../scripting.h"

#include "../types/GNmTransitionRule_t.h"


class GCNmTransitionEvent
{
private:
    void *m_ptr;

public:
    GCNmTransitionEvent() {}
    GCNmTransitionEvent(void *ptr) : m_ptr(ptr) {}

    NmTransitionRule_t GetRule() const { return GetSchemaValue<NmTransitionRule_t>(m_ptr, "CNmTransitionEvent", "m_rule"); }
    void SetRule(NmTransitionRule_t value) { SetSchemaValue(m_ptr, "CNmTransitionEvent", "m_rule", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif