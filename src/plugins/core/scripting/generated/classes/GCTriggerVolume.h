class GCTriggerVolume;

#ifndef _gcctriggervolume_h
#define _gcctriggervolume_h

#include "../../../scripting.h"


#include "GCBaseFilter.h"

class GCTriggerVolume
{
private:
    void *m_ptr;

public:
    GCTriggerVolume() {}
    GCTriggerVolume(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetFilterName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerVolume", "m_iFilterName"); }
    void SetFilterName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTriggerVolume", "m_iFilterName", false, value); }
    GCBaseFilter* GetFilter() const { return GetSchemaValue<GCBaseFilter*>(m_ptr, "CTriggerVolume", "m_hFilter"); }
    void SetFilter(GCBaseFilter* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif