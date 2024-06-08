class GCDSPPresetMixgroupModifierTable;

#ifndef _gccdsppresetmixgroupmodifiertable_h
#define _gccdsppresetmixgroupmodifiertable_h

#include "../../../scripting.h"


#include "GCDspPresetModifierList.h"

class GCDSPPresetMixgroupModifierTable
{
private:
    void *m_ptr;

public:
    GCDSPPresetMixgroupModifierTable() {}
    GCDSPPresetMixgroupModifierTable(void *ptr) : m_ptr(ptr) {}

    std::vector<GCDspPresetModifierList> GetTable() const { CUtlVector<GCDspPresetModifierList>* vec = GetSchemaValue<CUtlVector<GCDspPresetModifierList>*>(m_ptr, "CDSPPresetMixgroupModifierTable", "m_table"); std::vector<GCDspPresetModifierList> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTable(std::vector<GCDspPresetModifierList> value) { SetSchemaValueCUtlVector<GCDspPresetModifierList>(m_ptr, "CDSPPresetMixgroupModifierTable", "m_table", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif