class GCStateActionUpdater;

#ifndef _gccstateactionupdater_h
#define _gccstateactionupdater_h

#include "../../../scripting.h"

#include "../types/GStateActionBehavior.h"


class GCStateActionUpdater
{
private:
    void *m_ptr;

public:
    GCStateActionUpdater() {}
    GCStateActionUpdater(void *ptr) : m_ptr(ptr) {}

    StateActionBehavior GetBehavior() const { return GetSchemaValue<StateActionBehavior>(m_ptr, "CStateActionUpdater", "m_eBehavior"); }
    void SetBehavior(StateActionBehavior value) { SetSchemaValue(m_ptr, "CStateActionUpdater", "m_eBehavior", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif