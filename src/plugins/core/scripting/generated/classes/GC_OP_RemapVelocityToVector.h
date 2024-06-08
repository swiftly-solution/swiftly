class GC_OP_RemapVelocityToVector;

#ifndef _gcc_op_remapvelocitytovector_h
#define _gcc_op_remapvelocitytovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapVelocityToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapVelocityToVector() {}
    GC_OP_RemapVelocityToVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapVelocityToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapVelocityToVector", "m_nFieldOutput", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapVelocityToVector", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_RemapVelocityToVector", "m_flScale", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapVelocityToVector", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapVelocityToVector", "m_bNormalize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif