class GC_OP_CPVelocityForce;

#ifndef _gcc_op_cpvelocityforce_h
#define _gcc_op_cpvelocityforce_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_OP_CPVelocityForce
{
private:
    void *m_ptr;

public:
    GC_OP_CPVelocityForce() {}
    GC_OP_CPVelocityForce(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CPVelocityForce", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CPVelocityForce", "m_nControlPointNumber", false, value); }
    GCPerParticleFloatInput GetScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CPVelocityForce", "m_flScale"); }
    void SetScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CPVelocityForce", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif