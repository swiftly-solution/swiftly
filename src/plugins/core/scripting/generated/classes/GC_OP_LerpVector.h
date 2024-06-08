class GC_OP_LerpVector;

#ifndef _gcc_op_lerpvector_h
#define _gcc_op_lerpvector_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_LerpVector
{
private:
    void *m_ptr;

public:
    GC_OP_LerpVector() {}
    GC_OP_LerpVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpVector", "m_nFieldOutput", false, value); }
    Vector GetOutput() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_LerpVector", "m_vecOutput"); }
    void SetOutput(Vector value) { SetSchemaValue(m_ptr, "C_OP_LerpVector", "m_vecOutput", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_LerpVector", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_LerpVector", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_LerpVector", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_LerpVector", "m_flEndTime", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_LerpVector", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_LerpVector", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif