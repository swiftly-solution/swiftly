class GCPointProximitySensor;

#ifndef _gccpointproximitysensor_h
#define _gccpointproximitysensor_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCPointProximitySensor
{
private:
    void *m_ptr;

public:
    GCPointProximitySensor() {}
    GCPointProximitySensor(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CPointProximitySensor", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CPointProximitySensor", "m_bDisabled", false, value); }
    GCBaseEntity* GetTargetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointProximitySensor", "m_hTargetEntity"); }
    void SetTargetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif