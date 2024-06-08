class GCNmFrameSnapEvent;

#ifndef _gccnmframesnapevent_h
#define _gccnmframesnapevent_h

#include "../../../scripting.h"

#include "../types/GNmFrameSnapEventMode_t.h"


class GCNmFrameSnapEvent
{
private:
    void *m_ptr;

public:
    GCNmFrameSnapEvent() {}
    GCNmFrameSnapEvent(void *ptr) : m_ptr(ptr) {}

    NmFrameSnapEventMode_t GetFrameSnapMode() const { return GetSchemaValue<NmFrameSnapEventMode_t>(m_ptr, "CNmFrameSnapEvent", "m_frameSnapMode"); }
    void SetFrameSnapMode(NmFrameSnapEventMode_t value) { SetSchemaValue(m_ptr, "CNmFrameSnapEvent", "m_frameSnapMode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif