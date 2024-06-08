class GFeEffectDesc_t;

#ifndef _gcfeeffectdesc_t_h
#define _gcfeeffectdesc_t_h

#include "../../../scripting.h"




class GFeEffectDesc_t
{
private:
    void *m_ptr;

public:
    GFeEffectDesc_t() {}
    GFeEffectDesc_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "FeEffectDesc_t", "sName"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "FeEffectDesc_t", "sName", true, value); }
    uint32_t GetNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "FeEffectDesc_t", "nNameHash"); }
    void SetNameHash(uint32_t value) { SetSchemaValue(m_ptr, "FeEffectDesc_t", "nNameHash", true, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "FeEffectDesc_t", "nType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "FeEffectDesc_t", "nType", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif