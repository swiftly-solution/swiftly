class GC_OP_StopAfterCPDuration;

#ifndef _gcc_op_stopaftercpduration_h
#define _gcc_op_stopaftercpduration_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_OP_StopAfterCPDuration
{
private:
    void *m_ptr;

public:
    GC_OP_StopAfterCPDuration() {}
    GC_OP_StopAfterCPDuration(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetDuration() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_StopAfterCPDuration", "m_flDuration"); }
    void SetDuration(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_StopAfterCPDuration", "m_flDuration", false, value); }
    bool GetDestroyImmediately() const { return GetSchemaValue<bool>(m_ptr, "C_OP_StopAfterCPDuration", "m_bDestroyImmediately"); }
    void SetDestroyImmediately(bool value) { SetSchemaValue(m_ptr, "C_OP_StopAfterCPDuration", "m_bDestroyImmediately", false, value); }
    bool GetPlayEndCap() const { return GetSchemaValue<bool>(m_ptr, "C_OP_StopAfterCPDuration", "m_bPlayEndCap"); }
    void SetPlayEndCap(bool value) { SetSchemaValue(m_ptr, "C_OP_StopAfterCPDuration", "m_bPlayEndCap", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif