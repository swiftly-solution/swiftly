class GCFilterMultiple;

#ifndef _gccfiltermultiple_h
#define _gccfiltermultiple_h

#include "../../../scripting.h"

#include "../types/Gfilter_t.h"
#include "GCBaseEntity.h"

class GCFilterMultiple
{
private:
    void *m_ptr;

public:
    GCFilterMultiple() {}
    GCFilterMultiple(void *ptr) : m_ptr(ptr) {}

    filter_t GetFilterType() const { return GetSchemaValue<filter_t>(m_ptr, "CFilterMultiple", "m_nFilterType"); }
    void SetFilterType(filter_t value) { SetSchemaValue(m_ptr, "CFilterMultiple", "m_nFilterType", false, value); }
    std::vector<CUtlSymbolLarge> GetFilterName() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CFilterMultiple", "m_iFilterName"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetFilterName(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CFilterMultiple", "m_iFilterName"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFilterMultiple", "m_iFilterName", false, outValue); }
    GCBaseEntity* GetFilter() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CFilterMultiple", "m_hFilter"); }
    void SetFilter(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n"); }
    int32_t GetFilterCount() const { return GetSchemaValue<int32_t>(m_ptr, "CFilterMultiple", "m_nFilterCount"); }
    void SetFilterCount(int32_t value) { SetSchemaValue(m_ptr, "CFilterMultiple", "m_nFilterCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif