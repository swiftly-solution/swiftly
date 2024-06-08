class GC_OP_RemapCPVelocityToVector;

#ifndef _gcc_op_remapcpvelocitytovector_h
#define _gcc_op_remapcpvelocitytovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapCPVelocityToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapCPVelocityToVector() {}
    GC_OP_RemapCPVelocityToVector(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPVelocityToVector", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPVelocityToVector", "m_nControlPoint", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapCPVelocityToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPVelocityToVector", "m_nFieldOutput", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPVelocityToVector", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPVelocityToVector", "m_flScale", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapCPVelocityToVector", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapCPVelocityToVector", "m_bNormalize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif