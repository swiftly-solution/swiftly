class GCLogicRelay;

#ifndef _gcclogicrelay_h
#define _gcclogicrelay_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicRelay
{
private:
    void *m_ptr;

public:
    GCLogicRelay() {}
    GCLogicRelay(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnTrigger() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicRelay", "m_OnTrigger"); }
    void SetOnTrigger(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicRelay", "m_OnTrigger", false, value); }
    GCEntityIOOutput GetOnSpawn() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CLogicRelay", "m_OnSpawn"); }
    void SetOnSpawn(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CLogicRelay", "m_OnSpawn", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CLogicRelay", "m_bDisabled", false, value); }
    bool GetWaitForRefire() const { return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bWaitForRefire"); }
    void SetWaitForRefire(bool value) { SetSchemaValue(m_ptr, "CLogicRelay", "m_bWaitForRefire", false, value); }
    bool GetTriggerOnce() const { return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bTriggerOnce"); }
    void SetTriggerOnce(bool value) { SetSchemaValue(m_ptr, "CLogicRelay", "m_bTriggerOnce", false, value); }
    bool GetFastRetrigger() const { return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bFastRetrigger"); }
    void SetFastRetrigger(bool value) { SetSchemaValue(m_ptr, "CLogicRelay", "m_bFastRetrigger", false, value); }
    bool GetPassthoughCaller() const { return GetSchemaValue<bool>(m_ptr, "CLogicRelay", "m_bPassthoughCaller"); }
    void SetPassthoughCaller(bool value) { SetSchemaValue(m_ptr, "CLogicRelay", "m_bPassthoughCaller", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif