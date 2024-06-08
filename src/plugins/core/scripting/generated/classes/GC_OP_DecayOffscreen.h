class GC_OP_DecayOffscreen;

#ifndef _gcc_op_decayoffscreen_h
#define _gcc_op_decayoffscreen_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_DecayOffscreen
{
private:
    void *m_ptr;

public:
    GC_OP_DecayOffscreen() {}
    GC_OP_DecayOffscreen(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetOffscreenTime() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_DecayOffscreen", "m_flOffscreenTime"); }
    void SetOffscreenTime(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_DecayOffscreen", "m_flOffscreenTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif