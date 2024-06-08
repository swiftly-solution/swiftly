class GCTakeDamageSummaryScopeGuard;

#ifndef _gcctakedamagesummaryscopeguard_h
#define _gcctakedamagesummaryscopeguard_h

#include "../../../scripting.h"


#include "GSummaryTakeDamageInfo_t.h"

class GCTakeDamageSummaryScopeGuard
{
private:
    void *m_ptr;

public:
    GCTakeDamageSummaryScopeGuard() {}
    GCTakeDamageSummaryScopeGuard(void *ptr) : m_ptr(ptr) {}

    std::vector<GSummaryTakeDamageInfo_t*> GetSummaries() const { CUtlVector<GSummaryTakeDamageInfo_t*>* vec = GetSchemaValue<CUtlVector<GSummaryTakeDamageInfo_t*>*>(m_ptr, "CTakeDamageSummaryScopeGuard", "m_vecSummaries"); std::vector<GSummaryTakeDamageInfo_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSummaries(std::vector<GSummaryTakeDamageInfo_t*> value) { SetSchemaValueCUtlVector<GSummaryTakeDamageInfo_t*>(m_ptr, "CTakeDamageSummaryScopeGuard", "m_vecSummaries", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif