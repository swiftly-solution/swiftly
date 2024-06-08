class GC_OP_RemapSDFGradientToVectorAttribute;

#ifndef _gcc_op_remapsdfgradienttovectorattribute_h
#define _gcc_op_remapsdfgradienttovectorattribute_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapSDFGradientToVectorAttribute
{
private:
    void *m_ptr;

public:
    GC_OP_RemapSDFGradientToVectorAttribute() {}
    GC_OP_RemapSDFGradientToVectorAttribute(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapSDFGradientToVectorAttribute", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFGradientToVectorAttribute", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif