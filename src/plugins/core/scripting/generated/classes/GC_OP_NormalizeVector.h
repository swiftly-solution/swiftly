class GC_OP_NormalizeVector;

#ifndef _gcc_op_normalizevector_h
#define _gcc_op_normalizevector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_NormalizeVector
{
private:
    void *m_ptr;

public:
    GC_OP_NormalizeVector() {}
    GC_OP_NormalizeVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_NormalizeVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_NormalizeVector", "m_nFieldOutput", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_NormalizeVector", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_NormalizeVector", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif