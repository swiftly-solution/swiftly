class GCPhysForce;

#ifndef _gccphysforce_h
#define _gccphysforce_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCConstantForceController.h"

class GCPhysForce
{
private:
    void *m_ptr;

public:
    GCPhysForce() {}
    GCPhysForce(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetNameAttach() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysForce", "m_nameAttach"); }
    void SetNameAttach(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPhysForce", "m_nameAttach", false, value); }
    float GetForce() const { return GetSchemaValue<float>(m_ptr, "CPhysForce", "m_force"); }
    void SetForce(float value) { SetSchemaValue(m_ptr, "CPhysForce", "m_force", false, value); }
    float GetForceTime() const { return GetSchemaValue<float>(m_ptr, "CPhysForce", "m_forceTime"); }
    void SetForceTime(float value) { SetSchemaValue(m_ptr, "CPhysForce", "m_forceTime", false, value); }
    GCBaseEntity* GetAttachedObject() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPhysForce", "m_attachedObject"); }
    void SetAttachedObject(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedObject' is not possible.\n"); }
    bool GetWasRestored() const { return GetSchemaValue<bool>(m_ptr, "CPhysForce", "m_wasRestored"); }
    void SetWasRestored(bool value) { SetSchemaValue(m_ptr, "CPhysForce", "m_wasRestored", false, value); }
    GCConstantForceController GetIntegrator() const { return GetSchemaValue<GCConstantForceController>(m_ptr, "CPhysForce", "m_integrator"); }
    void SetIntegrator(GCConstantForceController value) { SetSchemaValue(m_ptr, "CPhysForce", "m_integrator", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif