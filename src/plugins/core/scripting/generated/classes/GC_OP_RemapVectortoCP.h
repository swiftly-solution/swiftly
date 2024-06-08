class GC_OP_RemapVectortoCP;

#ifndef _gcc_op_remapvectortocp_h
#define _gcc_op_remapvectortocp_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapVectortoCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapVectortoCP() {}
    GC_OP_RemapVectortoCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetOutControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapVectortoCP", "m_nOutControlPointNumber"); }
    void SetOutControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapVectortoCP", "m_nOutControlPointNumber", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapVectortoCP", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapVectortoCP", "m_nFieldInput", false, value); }
    int32_t GetParticleNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapVectortoCP", "m_nParticleNumber"); }
    void SetParticleNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapVectortoCP", "m_nParticleNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif