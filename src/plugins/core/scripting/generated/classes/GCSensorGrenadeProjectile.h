class GCSensorGrenadeProjectile;

#ifndef _gccsensorgrenadeprojectile_h
#define _gccsensorgrenadeprojectile_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCSensorGrenadeProjectile
{
private:
    void *m_ptr;

public:
    GCSensorGrenadeProjectile() {}
    GCSensorGrenadeProjectile(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetDisplayGrenade() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSensorGrenadeProjectile", "m_hDisplayGrenade"); }
    void SetDisplayGrenade(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'DisplayGrenade' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif