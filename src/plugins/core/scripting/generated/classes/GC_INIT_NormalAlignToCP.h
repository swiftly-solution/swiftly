class GC_INIT_NormalAlignToCP;

#ifndef _gcc_init_normalaligntocp_h
#define _gcc_init_normalaligntocp_h

#include "../../../scripting.h"

#include "../types/GParticleControlPointAxis_t.h"
#include "GCParticleTransformInput.h"

class GC_INIT_NormalAlignToCP
{
private:
    void *m_ptr;

public:
    GC_INIT_NormalAlignToCP() {}
    GC_INIT_NormalAlignToCP(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_NormalAlignToCP", "m_transformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_NormalAlignToCP", "m_transformInput", false, value); }
    ParticleControlPointAxis_t GetControlPointAxis() const { return GetSchemaValue<ParticleControlPointAxis_t>(m_ptr, "C_INIT_NormalAlignToCP", "m_nControlPointAxis"); }
    void SetControlPointAxis(ParticleControlPointAxis_t value) { SetSchemaValue(m_ptr, "C_INIT_NormalAlignToCP", "m_nControlPointAxis", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif