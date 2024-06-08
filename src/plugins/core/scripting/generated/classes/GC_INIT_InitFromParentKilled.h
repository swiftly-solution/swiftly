class GC_INIT_InitFromParentKilled;

#ifndef _gcc_init_initfromparentkilled_h
#define _gcc_init_initfromparentkilled_h

#include "../../../scripting.h"

#include "../types/GEventTypeSelection_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_InitFromParentKilled
{
private:
    void *m_ptr;

public:
    GC_INIT_InitFromParentKilled() {}
    GC_INIT_InitFromParentKilled(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetAttributeToCopy() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitFromParentKilled", "m_nAttributeToCopy"); }
    void SetAttributeToCopy(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromParentKilled", "m_nAttributeToCopy", false, value); }
    EventTypeSelection_t GetEventType() const { return GetSchemaValue<EventTypeSelection_t>(m_ptr, "C_INIT_InitFromParentKilled", "m_nEventType"); }
    void SetEventType(EventTypeSelection_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFromParentKilled", "m_nEventType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif