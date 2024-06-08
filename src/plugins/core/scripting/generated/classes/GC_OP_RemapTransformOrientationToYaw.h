class GC_OP_RemapTransformOrientationToYaw;

#ifndef _gcc_op_remaptransformorientationtoyaw_h
#define _gcc_op_remaptransformorientationtoyaw_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapTransformOrientationToYaw
{
private:
    void *m_ptr;

public:
    GC_OP_RemapTransformOrientationToYaw() {}
    GC_OP_RemapTransformOrientationToYaw(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_TransformInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_nFieldOutput", false, value); }
    float GetRotOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_flRotOffset"); }
    void SetRotOffset(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_flRotOffset", false, value); }
    float GetSpinStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_flSpinStrength"); }
    void SetSpinStrength(float value) { SetSchemaValue(m_ptr, "C_OP_RemapTransformOrientationToYaw", "m_flSpinStrength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif