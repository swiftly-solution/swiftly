class GCResponseCriteriaSet;

#ifndef _gccresponsecriteriaset_h
#define _gccresponsecriteriaset_h

#include "../../../scripting.h"




class GCResponseCriteriaSet
{
private:
    void *m_ptr;

public:
    GCResponseCriteriaSet() {}
    GCResponseCriteriaSet(void *ptr) : m_ptr(ptr) {}

    int32_t GetNumPrefixedContexts() const { return GetSchemaValue<int32_t>(m_ptr, "CResponseCriteriaSet", "m_nNumPrefixedContexts"); }
    void SetNumPrefixedContexts(int32_t value) { SetSchemaValue(m_ptr, "CResponseCriteriaSet", "m_nNumPrefixedContexts", false, value); }
    bool GetOverrideOnAppend() const { return GetSchemaValue<bool>(m_ptr, "CResponseCriteriaSet", "m_bOverrideOnAppend"); }
    void SetOverrideOnAppend(bool value) { SetSchemaValue(m_ptr, "CResponseCriteriaSet", "m_bOverrideOnAppend", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif