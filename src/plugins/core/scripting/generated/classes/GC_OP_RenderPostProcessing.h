class GC_OP_RenderPostProcessing;

#ifndef _gcc_op_renderpostprocessing_h
#define _gcc_op_renderpostprocessing_h

#include "../../../scripting.h"

#include "../types/GParticlePostProcessPriorityGroup_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_RenderPostProcessing
{
private:
    void *m_ptr;

public:
    GC_OP_RenderPostProcessing() {}
    GC_OP_RenderPostProcessing(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetPostProcessStrength() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderPostProcessing", "m_flPostProcessStrength"); }
    void SetPostProcessStrength(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderPostProcessing", "m_flPostProcessStrength", false, value); }
    ParticlePostProcessPriorityGroup_t GetPriority() const { return GetSchemaValue<ParticlePostProcessPriorityGroup_t>(m_ptr, "C_OP_RenderPostProcessing", "m_nPriority"); }
    void SetPriority(ParticlePostProcessPriorityGroup_t value) { SetSchemaValue(m_ptr, "C_OP_RenderPostProcessing", "m_nPriority", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif