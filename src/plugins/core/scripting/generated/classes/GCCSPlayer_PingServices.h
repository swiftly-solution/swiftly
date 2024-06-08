class GCCSPlayer_PingServices;

#ifndef _gcccsplayer_pingservices_h
#define _gcccsplayer_pingservices_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCCSPlayer_PingServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_PingServices() {}
    GCCSPlayer_PingServices(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetPlayerPing() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSPlayer_PingServices", "m_hPlayerPing"); }
    void SetPlayerPing(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerPing' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif