class GCLogicGameEventListener;

#ifndef _gcclogicgameeventlistener_h
#define _gcclogicgameeventlistener_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicGameEventListener
{
private:
    void *m_ptr;

public:
    GCLogicGameEventListener() {}
    GCLogicGameEventListener(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnEventFired() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicGameEventListener", "m_OnEventFired"); }
    void SetOnEventFired(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_OnEventFired", false, value); }
    CUtlSymbolLarge GetGameEventName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicGameEventListener", "m_iszGameEventName"); }
    void SetGameEventName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_iszGameEventName", false, value); }
    CUtlSymbolLarge GetGameEventItem() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicGameEventListener", "m_iszGameEventItem"); }
    void SetGameEventItem(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_iszGameEventItem", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CLogicGameEventListener", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_bEnabled", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CLogicGameEventListener", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CLogicGameEventListener", "m_bStartDisabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif