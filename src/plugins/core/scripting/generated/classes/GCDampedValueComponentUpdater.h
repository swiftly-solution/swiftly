class GCDampedValueComponentUpdater;

#ifndef _gccdampedvaluecomponentupdater_h
#define _gccdampedvaluecomponentupdater_h

#include "../../../scripting.h"


#include "GCDampedValueUpdateItem.h"

class GCDampedValueComponentUpdater
{
private:
    void *m_ptr;

public:
    GCDampedValueComponentUpdater() {}
    GCDampedValueComponentUpdater(void *ptr) : m_ptr(ptr) {}

    std::vector<GCDampedValueUpdateItem> GetItems() const { CUtlVector<GCDampedValueUpdateItem>* vec = GetSchemaValue<CUtlVector<GCDampedValueUpdateItem>*>(m_ptr, "CDampedValueComponentUpdater", "m_items"); std::vector<GCDampedValueUpdateItem> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetItems(std::vector<GCDampedValueUpdateItem> value) { SetSchemaValueCUtlVector<GCDampedValueUpdateItem>(m_ptr, "CDampedValueComponentUpdater", "m_items", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif