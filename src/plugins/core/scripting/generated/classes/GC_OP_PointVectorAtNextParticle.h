class GC_OP_PointVectorAtNextParticle;

#ifndef _gcc_op_pointvectoratnextparticle_h
#define _gcc_op_pointvectoratnextparticle_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_PointVectorAtNextParticle
{
private:
    void *m_ptr;

public:
    GC_OP_PointVectorAtNextParticle() {}
    GC_OP_PointVectorAtNextParticle(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_PointVectorAtNextParticle", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_PointVectorAtNextParticle", "m_nFieldOutput", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_PointVectorAtNextParticle", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PointVectorAtNextParticle", "m_flInterpolation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif