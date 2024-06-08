class GCompositeMaterialMatchFilter_t;

#ifndef _gccompositematerialmatchfilter_t_h
#define _gccompositematerialmatchfilter_t_h

#include "../../../scripting.h"

#include "../types/GCompositeMaterialMatchFilterType_t.h"


class GCompositeMaterialMatchFilter_t
{
private:
    void *m_ptr;

public:
    GCompositeMaterialMatchFilter_t() {}
    GCompositeMaterialMatchFilter_t(void *ptr) : m_ptr(ptr) {}

    CompositeMaterialMatchFilterType_t GetCompositeMaterialMatchFilterType() const { return GetSchemaValue<CompositeMaterialMatchFilterType_t>(m_ptr, "CompositeMaterialMatchFilter_t", "m_nCompositeMaterialMatchFilterType"); }
    void SetCompositeMaterialMatchFilterType(CompositeMaterialMatchFilterType_t value) { SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_nCompositeMaterialMatchFilterType", true, value); }
    CUtlString GetStrMatchFilter() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchFilter"); }
    void SetStrMatchFilter(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchFilter", true, value); }
    CUtlString GetStrMatchValue() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchValue"); }
    void SetStrMatchValue(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchValue", true, value); }
    bool GetPassWhenTrue() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialMatchFilter_t", "m_bPassWhenTrue"); }
    void SetPassWhenTrue(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_bPassWhenTrue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif