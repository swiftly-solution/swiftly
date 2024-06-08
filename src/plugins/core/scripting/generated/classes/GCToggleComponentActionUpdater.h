class GCToggleComponentActionUpdater;

#ifndef _gcctogglecomponentactionupdater_h
#define _gcctogglecomponentactionupdater_h

#include "../../../scripting.h"


#include "GAnimComponentID.h"

class GCToggleComponentActionUpdater
{
private:
    void *m_ptr;

public:
    GCToggleComponentActionUpdater() {}
    GCToggleComponentActionUpdater(void *ptr) : m_ptr(ptr) {}

    GAnimComponentID GetComponentID() const { return GetSchemaValue<GAnimComponentID>(m_ptr, "CToggleComponentActionUpdater", "m_componentID"); }
    void SetComponentID(GAnimComponentID value) { SetSchemaValue(m_ptr, "CToggleComponentActionUpdater", "m_componentID", false, value); }
    bool GetSetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CToggleComponentActionUpdater", "m_bSetEnabled"); }
    void SetSetEnabled(bool value) { SetSchemaValue(m_ptr, "CToggleComponentActionUpdater", "m_bSetEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif