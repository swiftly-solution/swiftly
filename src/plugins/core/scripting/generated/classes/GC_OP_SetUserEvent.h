class GC_OP_SetUserEvent;

#ifndef _gcc_op_setuserevent_h
#define _gcc_op_setuserevent_h

#include "../../../scripting.h"

#include "../types/GEventTypeSelection_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_SetUserEvent
{
private:
    void *m_ptr;

public:
    GC_OP_SetUserEvent() {}
    GC_OP_SetUserEvent(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetInput() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SetUserEvent", "m_flInput"); }
    void SetInput(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetUserEvent", "m_flInput", false, value); }
    GCPerParticleFloatInput GetRisingEdge() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SetUserEvent", "m_flRisingEdge"); }
    void SetRisingEdge(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetUserEvent", "m_flRisingEdge", false, value); }
    EventTypeSelection_t GetRisingEventType() const { return GetSchemaValue<EventTypeSelection_t>(m_ptr, "C_OP_SetUserEvent", "m_nRisingEventType"); }
    void SetRisingEventType(EventTypeSelection_t value) { SetSchemaValue(m_ptr, "C_OP_SetUserEvent", "m_nRisingEventType", false, value); }
    GCPerParticleFloatInput GetFallingEdge() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_SetUserEvent", "m_flFallingEdge"); }
    void SetFallingEdge(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetUserEvent", "m_flFallingEdge", false, value); }
    EventTypeSelection_t GetFallingEventType() const { return GetSchemaValue<EventTypeSelection_t>(m_ptr, "C_OP_SetUserEvent", "m_nFallingEventType"); }
    void SetFallingEventType(EventTypeSelection_t value) { SetSchemaValue(m_ptr, "C_OP_SetUserEvent", "m_nFallingEventType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif