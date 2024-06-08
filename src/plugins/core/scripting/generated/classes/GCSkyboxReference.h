class GCSkyboxReference;

#ifndef _gccskyboxreference_h
#define _gccskyboxreference_h

#include "../../../scripting.h"


#include "GCSkyCamera.h"

class GCSkyboxReference
{
private:
    void *m_ptr;

public:
    GCSkyboxReference() {}
    GCSkyboxReference(void *ptr) : m_ptr(ptr) {}

    WorldGroupId_t GetWorldGroupId() const { return GetSchemaValue<WorldGroupId_t>(m_ptr, "CSkyboxReference", "m_worldGroupId"); }
    void SetWorldGroupId(WorldGroupId_t value) { SetSchemaValue(m_ptr, "CSkyboxReference", "m_worldGroupId", false, value); }
    GCSkyCamera* GetSkyCamera() const { return GetSchemaValue<GCSkyCamera*>(m_ptr, "CSkyboxReference", "m_hSkyCamera"); }
    void SetSkyCamera(GCSkyCamera* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SkyCamera' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif