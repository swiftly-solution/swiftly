class GCDspPresetModifierList;

#ifndef _gccdsppresetmodifierlist_h
#define _gccdsppresetmodifierlist_h

#include "../../../scripting.h"


#include "GCDSPMixgroupModifier.h"

class GCDspPresetModifierList
{
private:
    void *m_ptr;

public:
    GCDspPresetModifierList() {}
    GCDspPresetModifierList(void *ptr) : m_ptr(ptr) {}

    CUtlString GetDspName() const { return GetSchemaValue<CUtlString>(m_ptr, "CDspPresetModifierList", "m_dspName"); }
    void SetDspName(CUtlString value) { SetSchemaValue(m_ptr, "CDspPresetModifierList", "m_dspName", false, value); }
    std::vector<GCDSPMixgroupModifier> GetModifiers() const { CUtlVector<GCDSPMixgroupModifier>* vec = GetSchemaValue<CUtlVector<GCDSPMixgroupModifier>*>(m_ptr, "CDspPresetModifierList", "m_modifiers"); std::vector<GCDSPMixgroupModifier> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetModifiers(std::vector<GCDSPMixgroupModifier> value) { SetSchemaValueCUtlVector<GCDSPMixgroupModifier>(m_ptr, "CDspPresetModifierList", "m_modifiers", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif