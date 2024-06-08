class GC_OP_Decay;

#ifndef _gcc_op_decay_h
#define _gcc_op_decay_h

#include "../../../scripting.h"




class GC_OP_Decay
{
private:
    void *m_ptr;

public:
    GC_OP_Decay() {}
    GC_OP_Decay(void *ptr) : m_ptr(ptr) {}

    bool GetRopeDecay() const { return GetSchemaValue<bool>(m_ptr, "C_OP_Decay", "m_bRopeDecay"); }
    void SetRopeDecay(bool value) { SetSchemaValue(m_ptr, "C_OP_Decay", "m_bRopeDecay", false, value); }
    bool GetForcePreserveParticleOrder() const { return GetSchemaValue<bool>(m_ptr, "C_OP_Decay", "m_bForcePreserveParticleOrder"); }
    void SetForcePreserveParticleOrder(bool value) { SetSchemaValue(m_ptr, "C_OP_Decay", "m_bForcePreserveParticleOrder", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif