class GC_OP_RemapControlPointOrientationToRotation;

#ifndef _gcc_op_remapcontrolpointorientationtorotation_h
#define _gcc_op_remapcontrolpointorientationtorotation_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapControlPointOrientationToRotation
{
private:
    void *m_ptr;

public:
    GC_OP_RemapControlPointOrientationToRotation() {}
    GC_OP_RemapControlPointOrientationToRotation(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_nCP", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_nFieldOutput", false, value); }
    float GetOffsetRot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_flOffsetRot"); }
    void SetOffsetRot(float value) { SetSchemaValue(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_flOffsetRot", false, value); }
    int32_t GetComponent() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_nComponent"); }
    void SetComponent(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapControlPointOrientationToRotation", "m_nComponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif