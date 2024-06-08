class GC_INIT_InitFloatCollection;

#ifndef _gcc_init_initfloatcollection_h
#define _gcc_init_initfloatcollection_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_InitFloatCollection
{
private:
    void *m_ptr;

public:
    GC_INIT_InitFloatCollection() {}
    GC_INIT_InitFloatCollection(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetInputValue() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_InitFloatCollection", "m_InputValue"); }
    void SetInputValue(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitFloatCollection", "m_InputValue", false, value); }
    GParticleAttributeIndex_t GetOutputField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitFloatCollection", "m_nOutputField"); }
    void SetOutputField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitFloatCollection", "m_nOutputField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif