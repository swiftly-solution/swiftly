class GC_OP_RemapVectorComponentToScalar;

#ifndef _gcc_op_remapvectorcomponenttoscalar_h
#define _gcc_op_remapvectorcomponenttoscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapVectorComponentToScalar
{
private:
    void *m_ptr;

public:
    GC_OP_RemapVectorComponentToScalar() {}
    GC_OP_RemapVectorComponentToScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapVectorComponentToScalar", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapVectorComponentToScalar", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapVectorComponentToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapVectorComponentToScalar", "m_nFieldOutput", false, value); }
    int32_t GetComponent() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapVectorComponentToScalar", "m_nComponent"); }
    void SetComponent(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapVectorComponentToScalar", "m_nComponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif