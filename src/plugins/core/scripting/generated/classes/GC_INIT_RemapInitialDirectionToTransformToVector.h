class GC_INIT_RemapInitialDirectionToTransformToVector;

#ifndef _gcc_init_remapinitialdirectiontotransformtovector_h
#define _gcc_init_remapinitialdirectiontotransformtovector_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapInitialDirectionToTransformToVector
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapInitialDirectionToTransformToVector() {}
    GC_INIT_RemapInitialDirectionToTransformToVector(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_TransformInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_nFieldOutput", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_flScale", false, value); }
    float GetOffsetRot() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_flOffsetRot"); }
    void SetOffsetRot(float value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_flOffsetRot", false, value); }
    Vector GetOffsetAxis() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_vecOffsetAxis"); }
    void SetOffsetAxis(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_vecOffsetAxis", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapInitialDirectionToTransformToVector", "m_bNormalize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif