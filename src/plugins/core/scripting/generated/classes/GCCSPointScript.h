class GCCSPointScript;

#ifndef _gcccspointscript_h
#define _gcccspointscript_h

#include "../../../scripting.h"


#include "GCCSPointScriptEntity.h"
#include "GCCSPointScript.h"

class GCCSPointScript
{
private:
    void *m_ptr;

public:
    GCCSPointScript() {}
    GCCSPointScript(void *ptr) : m_ptr(ptr) {}

    GCCSPointScriptEntity* GetParent() const { return GetSchemaValue<GCCSPointScriptEntity*>(m_ptr, "CCSPointScript", "m_pParent"); }
    void SetParent(GCCSPointScriptEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif