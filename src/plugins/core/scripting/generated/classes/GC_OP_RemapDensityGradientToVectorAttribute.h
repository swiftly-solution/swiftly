class GC_OP_RemapDensityGradientToVectorAttribute;

#ifndef _gcc_op_remapdensitygradienttovectorattribute_h
#define _gcc_op_remapdensitygradienttovectorattribute_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapDensityGradientToVectorAttribute
{
private:
    void *m_ptr;

public:
    GC_OP_RemapDensityGradientToVectorAttribute() {}
    GC_OP_RemapDensityGradientToVectorAttribute(void *ptr) : m_ptr(ptr) {}

    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapDensityGradientToVectorAttribute", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityGradientToVectorAttribute", "m_flRadiusScale", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapDensityGradientToVectorAttribute", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapDensityGradientToVectorAttribute", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif