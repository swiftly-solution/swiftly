class GCAnimScriptComponentUpdater;

#ifndef _gccanimscriptcomponentupdater_h
#define _gccanimscriptcomponentupdater_h

#include "../../../scripting.h"


#include "GAnimScriptHandle.h"

class GCAnimScriptComponentUpdater
{
private:
    void *m_ptr;

public:
    GCAnimScriptComponentUpdater() {}
    GCAnimScriptComponentUpdater(void *ptr) : m_ptr(ptr) {}

    GAnimScriptHandle GetScript() const { return GetSchemaValue<GAnimScriptHandle>(m_ptr, "CAnimScriptComponentUpdater", "m_hScript"); }
    void SetScript(GAnimScriptHandle value) { SetSchemaValue(m_ptr, "CAnimScriptComponentUpdater", "m_hScript", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif