class GC_INIT_RemapQAnglesToRotation;

#ifndef _gcc_init_remapqanglestorotation_h
#define _gcc_init_remapqanglestorotation_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"

class GC_INIT_RemapQAnglesToRotation
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapQAnglesToRotation() {}
    GC_INIT_RemapQAnglesToRotation(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_RemapQAnglesToRotation", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_RemapQAnglesToRotation", "m_TransformInput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif