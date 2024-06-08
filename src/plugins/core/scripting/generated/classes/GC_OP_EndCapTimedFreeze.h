class GC_OP_EndCapTimedFreeze;

#ifndef _gcc_op_endcaptimedfreeze_h
#define _gcc_op_endcaptimedfreeze_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_EndCapTimedFreeze
{
private:
    void *m_ptr;

public:
    GC_OP_EndCapTimedFreeze() {}
    GC_OP_EndCapTimedFreeze(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetFreezeTime() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_EndCapTimedFreeze", "m_flFreezeTime"); }
    void SetFreezeTime(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_EndCapTimedFreeze", "m_flFreezeTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif