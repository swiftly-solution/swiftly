class GC_INIT_CreateFromCPs;

#ifndef _gcc_init_createfromcps_h
#define _gcc_init_createfromcps_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"

class GC_INIT_CreateFromCPs
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateFromCPs() {}
    GC_INIT_CreateFromCPs(void *ptr) : m_ptr(ptr) {}

    int32_t GetIncrement() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateFromCPs", "m_nIncrement"); }
    void SetIncrement(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromCPs", "m_nIncrement", false, value); }
    int32_t GetMinCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateFromCPs", "m_nMinCP"); }
    void SetMinCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromCPs", "m_nMinCP", false, value); }
    int32_t GetMaxCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateFromCPs", "m_nMaxCP"); }
    void SetMaxCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromCPs", "m_nMaxCP", false, value); }
    GCParticleCollectionFloatInput GetDynamicCPCount() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateFromCPs", "m_nDynamicCPCount"); }
    void SetDynamicCPCount(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateFromCPs", "m_nDynamicCPCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif