class GC_OP_ReadFromNeighboringParticle;

#ifndef _gcc_op_readfromneighboringparticle_h
#define _gcc_op_readfromneighboringparticle_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_ReadFromNeighboringParticle
{
private:
    void *m_ptr;

public:
    GC_OP_ReadFromNeighboringParticle() {}
    GC_OP_ReadFromNeighboringParticle(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_nFieldOutput", false, value); }
    int32_t GetIncrement() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_nIncrement"); }
    void SetIncrement(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_nIncrement", false, value); }
    GCPerParticleFloatInput GetDistanceCheck() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_DistanceCheck"); }
    void SetDistanceCheck(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_DistanceCheck", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ReadFromNeighboringParticle", "m_flInterpolation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif