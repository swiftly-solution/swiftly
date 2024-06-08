class GCRuleEntity;

#ifndef _gccruleentity_h
#define _gccruleentity_h

#include "../../../scripting.h"




class GCRuleEntity
{
private:
    void *m_ptr;

public:
    GCRuleEntity() {}
    GCRuleEntity(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetMaster() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRuleEntity", "m_iszMaster"); }
    void SetMaster(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CRuleEntity", "m_iszMaster", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif