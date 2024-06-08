class GC_OP_SetFloatCollection;

#ifndef _gcc_op_setfloatcollection_h
#define _gcc_op_setfloatcollection_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_SetFloatCollection
{
private:
    void *m_ptr;

public:
    GC_OP_SetFloatCollection() {}
    GC_OP_SetFloatCollection(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetInputValue() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetFloatCollection", "m_InputValue"); }
    void SetInputValue(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFloatCollection", "m_InputValue", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetFloatCollection", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetFloatCollection", "m_nOutputField", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_SetFloatCollection", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_SetFloatCollection", "m_nSetMethod", false, value); }
    GCParticleCollectionFloatInput GetLerp() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_SetFloatCollection", "m_Lerp"); }
    void SetLerp(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_SetFloatCollection", "m_Lerp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif