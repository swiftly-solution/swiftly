class GCLightEntity;

#ifndef _gcclightentity_h
#define _gcclightentity_h

#include "../../../scripting.h"


#include "GCLightComponent.h"

class GCLightEntity
{
private:
    void *m_ptr;

public:
    GCLightEntity() {}
    GCLightEntity(void *ptr) : m_ptr(ptr) {}

    GCLightComponent* GetCLightComponent() const { return GetSchemaValue<GCLightComponent*>(m_ptr, "CLightEntity", "m_CLightComponent"); }
    void SetCLightComponent(GCLightComponent* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'CLightComponent' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif