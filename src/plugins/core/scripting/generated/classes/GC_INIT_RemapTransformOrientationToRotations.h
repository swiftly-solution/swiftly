class GC_INIT_RemapTransformOrientationToRotations;

#ifndef _gcc_init_remaptransformorientationtorotations_h
#define _gcc_init_remaptransformorientationtorotations_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"

class GC_INIT_RemapTransformOrientationToRotations
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapTransformOrientationToRotations() {}
    GC_INIT_RemapTransformOrientationToRotations(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_TransformInput", false, value); }
    Vector GetRotation() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_vecRotation"); }
    void SetRotation(Vector value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_vecRotation", false, value); }
    bool GetUseQuat() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_bUseQuat"); }
    void SetUseQuat(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_bUseQuat", false, value); }
    bool GetWriteNormal() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_bWriteNormal"); }
    void SetWriteNormal(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapTransformOrientationToRotations", "m_bWriteNormal", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif