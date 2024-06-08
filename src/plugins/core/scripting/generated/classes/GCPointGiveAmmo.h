class GCPointGiveAmmo;

#ifndef _gccpointgiveammo_h
#define _gccpointgiveammo_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCPointGiveAmmo
{
private:
    void *m_ptr;

public:
    GCPointGiveAmmo() {}
    GCPointGiveAmmo(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetActivator() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointGiveAmmo", "m_pActivator"); }
    void SetActivator(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif