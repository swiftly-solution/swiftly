class GCDemoSettingsComponentUpdater;

#ifndef _gccdemosettingscomponentupdater_h
#define _gccdemosettingscomponentupdater_h

#include "../../../scripting.h"


#include "GCAnimDemoCaptureSettings.h"

class GCDemoSettingsComponentUpdater
{
private:
    void *m_ptr;

public:
    GCDemoSettingsComponentUpdater() {}
    GCDemoSettingsComponentUpdater(void *ptr) : m_ptr(ptr) {}

    GCAnimDemoCaptureSettings GetSettings() const { return GetSchemaValue<GCAnimDemoCaptureSettings>(m_ptr, "CDemoSettingsComponentUpdater", "m_settings"); }
    void SetSettings(GCAnimDemoCaptureSettings value) { SetSchemaValue(m_ptr, "CDemoSettingsComponentUpdater", "m_settings", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif