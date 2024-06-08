class GCDirectPlaybackTagData;

#ifndef _gccdirectplaybacktagdata_h
#define _gccdirectplaybacktagdata_h

#include "../../../scripting.h"


#include "GTagSpan_t.h"

class GCDirectPlaybackTagData
{
private:
    void *m_ptr;

public:
    GCDirectPlaybackTagData() {}
    GCDirectPlaybackTagData(void *ptr) : m_ptr(ptr) {}

    CUtlString GetSequenceName() const { return GetSchemaValue<CUtlString>(m_ptr, "CDirectPlaybackTagData", "m_sequenceName"); }
    void SetSequenceName(CUtlString value) { SetSchemaValue(m_ptr, "CDirectPlaybackTagData", "m_sequenceName", false, value); }
    std::vector<GTagSpan_t> GetTags() const { CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CDirectPlaybackTagData", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<GTagSpan_t> value) { SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CDirectPlaybackTagData", "m_tags", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif