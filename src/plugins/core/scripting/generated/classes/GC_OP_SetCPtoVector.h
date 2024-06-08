class GC_OP_SetCPtoVector;

#ifndef _gcc_op_setcptovector_h
#define _gcc_op_setcptovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_SetCPtoVector
{
private:
    void *m_ptr;

public:
    GC_OP_SetCPtoVector() {}
    GC_OP_SetCPtoVector(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPInput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetCPtoVector", "m_nCPInput"); }
    void SetCPInput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPtoVector", "m_nCPInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetCPtoVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPtoVector", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif