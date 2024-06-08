class GC_OP_DecayClampCount;

#ifndef _gcc_op_decayclampcount_h
#define _gcc_op_decayclampcount_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_DecayClampCount
{
private:
    void *m_ptr;

public:
    GC_OP_DecayClampCount() {}
    GC_OP_DecayClampCount(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetCount() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_DecayClampCount", "m_nCount"); }
    void SetCount(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DecayClampCount", "m_nCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif