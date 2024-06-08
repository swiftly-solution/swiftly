class GCPhysicsEntitySolver;

#ifndef _gccphysicsentitysolver_h
#define _gccphysicsentitysolver_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCPhysicsEntitySolver
{
private:
    void *m_ptr;

public:
    GCPhysicsEntitySolver() {}
    GCPhysicsEntitySolver(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetMovingEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPhysicsEntitySolver", "m_hMovingEntity"); }
    void SetMovingEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MovingEntity' is not possible.\n"); }
    GCBaseEntity* GetPhysicsBlocker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPhysicsEntitySolver", "m_hPhysicsBlocker"); }
    void SetPhysicsBlocker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsBlocker' is not possible.\n"); }
    float GetSeparationDuration() const { return GetSchemaValue<float>(m_ptr, "CPhysicsEntitySolver", "m_separationDuration"); }
    void SetSeparationDuration(float value) { SetSchemaValue(m_ptr, "CPhysicsEntitySolver", "m_separationDuration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif