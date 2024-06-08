class GCPlayer_ObserverServices;

#ifndef _gccplayer_observerservices_h
#define _gccplayer_observerservices_h

#include "../../../scripting.h"

#include "../types/GObserverMode_t.h"
#include "GCBaseEntity.h"

class GCPlayer_ObserverServices
{
private:
    void *m_ptr;

public:
    GCPlayer_ObserverServices() {}
    GCPlayer_ObserverServices(void *ptr) : m_ptr(ptr) {}

    uint8_t GetObserverMode() const { return GetSchemaValue<uint8_t>(m_ptr, "CPlayer_ObserverServices", "m_iObserverMode"); }
    void SetObserverMode(uint8_t value) { SetSchemaValue(m_ptr, "CPlayer_ObserverServices", "m_iObserverMode", false, value); }
    GCBaseEntity* GetObserverTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPlayer_ObserverServices", "m_hObserverTarget"); }
    void SetObserverTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ObserverTarget' is not possible.\n"); }
    ObserverMode_t GetObserverLastMode() const { return GetSchemaValue<ObserverMode_t>(m_ptr, "CPlayer_ObserverServices", "m_iObserverLastMode"); }
    void SetObserverLastMode(ObserverMode_t value) { SetSchemaValue(m_ptr, "CPlayer_ObserverServices", "m_iObserverLastMode", false, value); }
    bool GetForcedObserverMode() const { return GetSchemaValue<bool>(m_ptr, "CPlayer_ObserverServices", "m_bForcedObserverMode"); }
    void SetForcedObserverMode(bool value) { SetSchemaValue(m_ptr, "CPlayer_ObserverServices", "m_bForcedObserverMode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif