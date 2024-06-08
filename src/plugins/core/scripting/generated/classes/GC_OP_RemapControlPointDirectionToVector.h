class GC_OP_RemapControlPointDirectionToVector;

#ifndef _gcc_op_remapcontrolpointdirectiontovector_h
#define _gcc_op_remapcontrolpointdirectiontovector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapControlPointDirectionToVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapControlPointDirectionToVector() {}
    GC_OP_RemapControlPointDirectionToVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapControlPointDirectionToVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapControlPointDirectionToVector", "m_nFieldOutput", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapControlPointDirectionToVector", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_RemapControlPointDirectionToVector", "m_flScale", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapControlPointDirectionToVector", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapControlPointDirectionToVector", "m_nControlPointNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif