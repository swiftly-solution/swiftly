class GC_OP_OrientTo2dDirection;

#ifndef _gcc_op_orientto2ddirection_h
#define _gcc_op_orientto2ddirection_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_OrientTo2dDirection
{
private:
    void *m_ptr;

public:
    GC_OP_OrientTo2dDirection() {}
    GC_OP_OrientTo2dDirection(void *ptr) : m_ptr(ptr) {}

    float GetRotOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_OrientTo2dDirection", "m_flRotOffset"); }
    void SetRotOffset(float value) { SetSchemaValue(m_ptr, "C_OP_OrientTo2dDirection", "m_flRotOffset", false, value); }
    float GetSpinStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_OrientTo2dDirection", "m_flSpinStrength"); }
    void SetSpinStrength(float value) { SetSchemaValue(m_ptr, "C_OP_OrientTo2dDirection", "m_flSpinStrength", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_OrientTo2dDirection", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_OrientTo2dDirection", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif