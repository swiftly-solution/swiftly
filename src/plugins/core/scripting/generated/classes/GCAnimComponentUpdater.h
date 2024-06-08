class GCAnimComponentUpdater;

#ifndef _gccanimcomponentupdater_h
#define _gccanimcomponentupdater_h

#include "../../../scripting.h"

#include "../types/GAnimNodeNetworkMode.h"
#include "GAnimComponentID.h"

class GCAnimComponentUpdater
{
private:
    void *m_ptr;

public:
    GCAnimComponentUpdater() {}
    GCAnimComponentUpdater(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimComponentUpdater", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_name", false, value); }
    GAnimComponentID GetId() const { return GetSchemaValue<GAnimComponentID>(m_ptr, "CAnimComponentUpdater", "m_id"); }
    void SetId(GAnimComponentID value) { SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_id", false, value); }
    AnimNodeNetworkMode GetNetworkMode() const { return GetSchemaValue<AnimNodeNetworkMode>(m_ptr, "CAnimComponentUpdater", "m_networkMode"); }
    void SetNetworkMode(AnimNodeNetworkMode value) { SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_networkMode", false, value); }
    bool GetStartEnabled() const { return GetSchemaValue<bool>(m_ptr, "CAnimComponentUpdater", "m_bStartEnabled"); }
    void SetStartEnabled(bool value) { SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_bStartEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif