class GCGunTarget;

#ifndef _gccguntarget_h
#define _gccguntarget_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCGunTarget
{
private:
    void *m_ptr;

public:
    GCGunTarget() {}
    GCGunTarget(void *ptr) : m_ptr(ptr) {}

    bool GetOn() const { return GetSchemaValue<bool>(m_ptr, "CGunTarget", "m_on"); }
    void SetOn(bool value) { SetSchemaValue(m_ptr, "CGunTarget", "m_on", false, value); }
    GCBaseEntity* GetTargetEnt() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CGunTarget", "m_hTargetEnt"); }
    void SetTargetEnt(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEnt' is not possible.\n"); }
    GCEntityIOOutput GetOnDeath() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CGunTarget", "m_OnDeath"); }
    void SetOnDeath(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CGunTarget", "m_OnDeath", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif