class GC_OP_LerpEndCapVector;

#ifndef _gcc_op_lerpendcapvector_h
#define _gcc_op_lerpendcapvector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_LerpEndCapVector
{
private:
    void *m_ptr;

public:
    GC_OP_LerpEndCapVector() {}
    GC_OP_LerpEndCapVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpEndCapVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpEndCapVector", "m_nFieldOutput", false, value); }
    Vector GetOutput() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_LerpEndCapVector", "m_vecOutput"); }
    void SetOutput(Vector value) { SetSchemaValue(m_ptr, "C_OP_LerpEndCapVector", "m_vecOutput", false, value); }
    float GetLerpTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_LerpEndCapVector", "m_flLerpTime"); }
    void SetLerpTime(float value) { SetSchemaValue(m_ptr, "C_OP_LerpEndCapVector", "m_flLerpTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif