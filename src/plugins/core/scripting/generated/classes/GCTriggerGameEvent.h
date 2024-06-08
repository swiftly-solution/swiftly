class GCTriggerGameEvent;

#ifndef _gcctriggergameevent_h
#define _gcctriggergameevent_h

#include "../../../scripting.h"




class GCTriggerGameEvent
{
private:
    void *m_ptr;

public:
    GCTriggerGameEvent() {}
    GCTriggerGameEvent(void *ptr) : m_ptr(ptr) {}

    CUtlString GetStrStartTouchEventName() const { return GetSchemaValue<CUtlString>(m_ptr, "CTriggerGameEvent", "m_strStartTouchEventName"); }
    void SetStrStartTouchEventName(CUtlString value) { SetSchemaValue(m_ptr, "CTriggerGameEvent", "m_strStartTouchEventName", false, value); }
    CUtlString GetStrEndTouchEventName() const { return GetSchemaValue<CUtlString>(m_ptr, "CTriggerGameEvent", "m_strEndTouchEventName"); }
    void SetStrEndTouchEventName(CUtlString value) { SetSchemaValue(m_ptr, "CTriggerGameEvent", "m_strEndTouchEventName", false, value); }
    CUtlString GetStrTriggerID() const { return GetSchemaValue<CUtlString>(m_ptr, "CTriggerGameEvent", "m_strTriggerID"); }
    void SetStrTriggerID(CUtlString value) { SetSchemaValue(m_ptr, "CTriggerGameEvent", "m_strTriggerID", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif