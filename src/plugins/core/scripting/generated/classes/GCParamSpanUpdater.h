class GCParamSpanUpdater;

#ifndef _gccparamspanupdater_h
#define _gccparamspanupdater_h

#include "../../../scripting.h"


#include "GParamSpan_t.h"

class GCParamSpanUpdater
{
private:
    void *m_ptr;

public:
    GCParamSpanUpdater() {}
    GCParamSpanUpdater(void *ptr) : m_ptr(ptr) {}

    std::vector<GParamSpan_t> GetSpans() const { CUtlVector<GParamSpan_t>* vec = GetSchemaValue<CUtlVector<GParamSpan_t>*>(m_ptr, "CParamSpanUpdater", "m_spans"); std::vector<GParamSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSpans(std::vector<GParamSpan_t> value) { SetSchemaValueCUtlVector<GParamSpan_t>(m_ptr, "CParamSpanUpdater", "m_spans", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif