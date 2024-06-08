class GCLogicGameEvent;

#ifndef _gcclogicgameevent_h
#define _gcclogicgameevent_h

#include "../../../scripting.h"




class GCLogicGameEvent
{
private:
    void *m_ptr;

public:
    GCLogicGameEvent() {}
    GCLogicGameEvent(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetEventName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicGameEvent", "m_iszEventName"); }
    void SetEventName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicGameEvent", "m_iszEventName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif