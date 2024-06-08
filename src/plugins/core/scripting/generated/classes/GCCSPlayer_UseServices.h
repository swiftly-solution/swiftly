class GCCSPlayer_UseServices;

#ifndef _gcccsplayer_useservices_h
#define _gcccsplayer_useservices_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCCSPlayer_UseServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_UseServices() {}
    GCCSPlayer_UseServices(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetLastKnownUseEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CCSPlayer_UseServices", "m_hLastKnownUseEntity"); }
    void SetLastKnownUseEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastKnownUseEntity' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif