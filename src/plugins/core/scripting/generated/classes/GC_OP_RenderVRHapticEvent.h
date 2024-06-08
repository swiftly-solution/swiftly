class GC_OP_RenderVRHapticEvent;

#ifndef _gcc_op_rendervrhapticevent_h
#define _gcc_op_rendervrhapticevent_h

#include "../../../scripting.h"

#include "../types/GParticleVRHandChoiceList_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_RenderVRHapticEvent
{
private:
    void *m_ptr;

public:
    GC_OP_RenderVRHapticEvent() {}
    GC_OP_RenderVRHapticEvent(void *ptr) : m_ptr(ptr) {}

    ParticleVRHandChoiceList_t GetHand() const { return GetSchemaValue<ParticleVRHandChoiceList_t>(m_ptr, "C_OP_RenderVRHapticEvent", "m_nHand"); }
    void SetHand(ParticleVRHandChoiceList_t value) { SetSchemaValue(m_ptr, "C_OP_RenderVRHapticEvent", "m_nHand", false, value); }
    int32_t GetOutputHandCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderVRHapticEvent", "m_nOutputHandCP"); }
    void SetOutputHandCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderVRHapticEvent", "m_nOutputHandCP", false, value); }
    int32_t GetOutputField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderVRHapticEvent", "m_nOutputField"); }
    void SetOutputField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderVRHapticEvent", "m_nOutputField", false, value); }
    GCPerParticleFloatInput GetAmplitude() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderVRHapticEvent", "m_flAmplitude"); }
    void SetAmplitude(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderVRHapticEvent", "m_flAmplitude", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif