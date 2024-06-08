class GCPlatTrigger;

#ifndef _gccplattrigger_h
#define _gccplattrigger_h

#include "../../../scripting.h"


#include "GCFuncPlat.h"

class GCPlatTrigger
{
private:
    void *m_ptr;

public:
    GCPlatTrigger() {}
    GCPlatTrigger(void *ptr) : m_ptr(ptr) {}

    GCFuncPlat* GetPlatform() const { return GetSchemaValue<GCFuncPlat*>(m_ptr, "CPlatTrigger", "m_pPlatform"); }
    void SetPlatform(GCFuncPlat* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Platform' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif