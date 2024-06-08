class GCNmFootEvent;

#ifndef _gccnmfootevent_h
#define _gccnmfootevent_h

#include "../../../scripting.h"

#include "../types/GNmFootPhase_t.h"


class GCNmFootEvent
{
private:
    void *m_ptr;

public:
    GCNmFootEvent() {}
    GCNmFootEvent(void *ptr) : m_ptr(ptr) {}

    NmFootPhase_t GetPhase() const { return GetSchemaValue<NmFootPhase_t>(m_ptr, "CNmFootEvent", "m_phase"); }
    void SetPhase(NmFootPhase_t value) { SetSchemaValue(m_ptr, "CNmFootEvent", "m_phase", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif