class GC_OP_RemapTransformToVelocity;

#ifndef _gcc_op_remaptransformtovelocity_h
#define _gcc_op_remaptransformtovelocity_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"

class GC_OP_RemapTransformToVelocity
{
private:
    void *m_ptr;

public:
    GC_OP_RemapTransformToVelocity() {}
    GC_OP_RemapTransformToVelocity(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_RemapTransformToVelocity", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformToVelocity", "m_TransformInput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif