class GC_OP_LerpEndCapScalar;

#ifndef _gcc_op_lerpendcapscalar_h
#define _gcc_op_lerpendcapscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_LerpEndCapScalar
{
private:
    void *m_ptr;

public:
    GC_OP_LerpEndCapScalar() {}
    GC_OP_LerpEndCapScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpEndCapScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpEndCapScalar", "m_nFieldOutput", false, value); }
    float GetOutput() const { return GetSchemaValue<float>(m_ptr, "C_OP_LerpEndCapScalar", "m_flOutput"); }
    void SetOutput(float value) { SetSchemaValue(m_ptr, "C_OP_LerpEndCapScalar", "m_flOutput", false, value); }
    float GetLerpTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_LerpEndCapScalar", "m_flLerpTime"); }
    void SetLerpTime(float value) { SetSchemaValue(m_ptr, "C_OP_LerpEndCapScalar", "m_flLerpTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif