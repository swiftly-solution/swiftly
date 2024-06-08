class GCCopyRecipientFilter;

#ifndef _gcccopyrecipientfilter_h
#define _gcccopyrecipientfilter_h

#include "../../../scripting.h"




class GCCopyRecipientFilter
{
private:
    void *m_ptr;

public:
    GCCopyRecipientFilter() {}
    GCCopyRecipientFilter(void *ptr) : m_ptr(ptr) {}

    int32_t GetFlags() const { return GetSchemaValue<int32_t>(m_ptr, "CCopyRecipientFilter", "m_Flags"); }
    void SetFlags(int32_t value) { SetSchemaValue(m_ptr, "CCopyRecipientFilter", "m_Flags", false, value); }
    std::vector<int32_t> GetRecipients() const { CUtlVector<int32_t>* vec = GetSchemaValue<CUtlVector<int32_t>*>(m_ptr, "CCopyRecipientFilter", "m_Recipients"); std::vector<int32_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRecipients(std::vector<int32_t> value) { SetSchemaValueCUtlVector<int32_t>(m_ptr, "CCopyRecipientFilter", "m_Recipients", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif