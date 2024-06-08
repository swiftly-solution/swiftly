class GC_OP_SetControlPointRotation;

#ifndef _gcc_op_setcontrolpointrotation_h
#define _gcc_op_setcontrolpointrotation_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_SetControlPointRotation
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointRotation() {}
    GC_OP_SetControlPointRotation(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetRotRate() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetControlPointRotation", "m_flRotRate"); }
    void SetRotRate(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointRotation", "m_flRotRate", false, value); }
    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointRotation", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointRotation", "m_nCP", false, value); }
    int32_t GetLocalCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointRotation", "m_nLocalCP"); }
    void SetLocalCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointRotation", "m_nLocalCP", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif