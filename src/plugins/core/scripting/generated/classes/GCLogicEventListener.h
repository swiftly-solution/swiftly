class GCLogicEventListener;

#ifndef _gcclogiceventlistener_h
#define _gcclogiceventlistener_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicEventListener
{
private:
    void *m_ptr;

public:
    GCLogicEventListener() {}
    GCLogicEventListener(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrEventName() const { return GetSchemaValue<CUtlString>(m_ptr, "CLogicEventListener", "m_strEventName"); }
    void SetStrEventName(CUtlString value) { SetSchemaValue(m_ptr, "CLogicEventListener", "m_strEventName", false, value); }
    bool GetIsEnabled() const { return GetSchemaValue<bool>(m_ptr, "CLogicEventListener", "m_bIsEnabled"); }
    void SetIsEnabled(bool value) { SetSchemaValue(m_ptr, "CLogicEventListener", "m_bIsEnabled", false, value); }
    int32_t GetTeam() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicEventListener", "m_nTeam"); }
    void SetTeam(int32_t value) { SetSchemaValue(m_ptr, "CLogicEventListener", "m_nTeam", false, value); }
    GCEntityIOOutput GetOnEventFired() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicEventListener", "m_OnEventFired"); }
    void SetOnEventFired(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicEventListener", "m_OnEventFired", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif