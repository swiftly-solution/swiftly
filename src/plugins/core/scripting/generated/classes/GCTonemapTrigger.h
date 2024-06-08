class GCTonemapTrigger;

#ifndef _gcctonemaptrigger_h
#define _gcctonemaptrigger_h

#include "../../../scripting.h"


#include "GCEntityInstance.h"

class GCTonemapTrigger
{
private:
    void *m_ptr;

public:
    GCTonemapTrigger() {}
    GCTonemapTrigger(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetTonemapControllerName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTonemapTrigger", "m_tonemapControllerName"); }
    void SetTonemapControllerName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CTonemapTrigger", "m_tonemapControllerName", false, value); }
    GCEntityInstance* GetTonemapController() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CTonemapTrigger", "m_hTonemapController"); }
    void SetTonemapController(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TonemapController' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif