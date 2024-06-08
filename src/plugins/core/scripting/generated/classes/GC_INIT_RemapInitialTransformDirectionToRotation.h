class GC_INIT_RemapInitialTransformDirectionToRotation;

#ifndef _gcc_init_remapinitialtransformdirectiontorotation_h
#define _gcc_init_remapinitialtransformdirectiontorotation_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapInitialTransformDirectionToRotation
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapInitialTransformDirectionToRotation() {}
    GC_INIT_RemapInitialTransformDirectionToRotation(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_TransformInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_nFieldOutput", false, value); }
    float GetOffsetRot() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_flOffsetRot"); }
    void SetOffsetRot(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_flOffsetRot", false, value); }
    int32_t GetComponent() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_nComponent"); }
    void SetComponent(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialTransformDirectionToRotation", "m_nComponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif