class GCAnimGraphNetworkSettings;

#ifndef _gccanimgraphnetworksettings_h
#define _gccanimgraphnetworksettings_h

#include "../../../scripting.h"




class GCAnimGraphNetworkSettings
{
private:
    void *m_ptr;

public:
    GCAnimGraphNetworkSettings() {}
    GCAnimGraphNetworkSettings(void *ptr) : m_ptr(ptr) {}

    bool GetNetworkingEnabled() const { return GetSchemaValue<bool>(m_ptr, "CAnimGraphNetworkSettings", "m_bNetworkingEnabled"); }
    void SetNetworkingEnabled(bool value) { SetSchemaValue(m_ptr, "CAnimGraphNetworkSettings", "m_bNetworkingEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif