class GC_OP_RemapDirectionToCPToVector;

#ifndef _gcc_op_remapdirectiontocptovector_h
#define _gcc_op_remapdirectiontocptovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapDirectionToCPToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDirectionToCPToVector() {}
    GC_OP_RemapDirectionToCPToVector(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_nCP", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_nFieldOutput", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_flScale", false, value); }
    float GetOffsetRot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_flOffsetRot"); }
    void SetOffsetRot(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_flOffsetRot", false, value); }
    Vector GetOffsetAxis() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_vecOffsetAxis"); }
    void SetOffsetAxis(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_vecOffsetAxis", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_bNormalize", false, value); }
    GParticleAttributeIndex_t GetFieldStrength() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_nFieldStrength"); }
    void SetFieldStrength(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDirectionToCPToVector", "m_nFieldStrength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif