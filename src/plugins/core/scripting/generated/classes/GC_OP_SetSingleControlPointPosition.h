class GC_OP_SetSingleControlPointPosition;

#ifndef _gcc_op_setsinglecontrolpointposition_h
#define _gcc_op_setsinglecontrolpointposition_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"

class GC_OP_SetSingleControlPointPosition
{
private:
    void *m_ptr;

public:
    GC_OP_SetSingleControlPointPosition() {}
    GC_OP_SetSingleControlPointPosition(void *ptr) : m_ptr(ptr) {}

    bool GetSetOnce() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetSingleControlPointPosition", "m_bSetOnce"); }
    void SetSetOnce(bool value) { SetSchemaValue(m_ptr, "C_OP_SetSingleControlPointPosition", "m_bSetOnce", false, value); }
    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetSingleControlPointPosition", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetSingleControlPointPosition", "m_nCP1", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_SetSingleControlPointPosition", "m_transformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_SetSingleControlPointPosition", "m_transformInput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif