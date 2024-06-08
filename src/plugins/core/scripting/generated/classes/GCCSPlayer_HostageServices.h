class GCCSPlayer_HostageServices;

#ifndef _gcccsplayer_hostageservices_h
#define _gcccsplayer_hostageservices_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCCSPlayer_HostageServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_HostageServices() {}
    GCCSPlayer_HostageServices(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetCarriedHostage() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSPlayer_HostageServices", "m_hCarriedHostage"); }
    void SetCarriedHostage(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CarriedHostage' is not possible.\n"); }
    GCBaseEntity* GetCarriedHostageProp() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSPlayer_HostageServices", "m_hCarriedHostageProp"); }
    void SetCarriedHostageProp(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CarriedHostageProp' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif