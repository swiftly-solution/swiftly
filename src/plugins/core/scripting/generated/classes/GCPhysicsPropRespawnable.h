class GCPhysicsPropRespawnable;

#ifndef _gccphysicsproprespawnable_h
#define _gccphysicsproprespawnable_h

#include "../../../scripting.h"




class GCPhysicsPropRespawnable
{
private:
    void *m_ptr;

public:
    GCPhysicsPropRespawnable() {}
    GCPhysicsPropRespawnable(void *ptr) : m_ptr(ptr) {}

    Vector GetOriginalSpawnOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnOrigin"); }
    void SetOriginalSpawnOrigin(Vector value) { SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnOrigin", false, value); }
    QAngle GetOriginalSpawnAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnAngles"); }
    void SetOriginalSpawnAngles(QAngle value) { SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnAngles", false, value); }
    Vector GetOriginalMins() const { return GetSchemaValue<Vector>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMins"); }
    void SetOriginalMins(Vector value) { SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMins", false, value); }
    Vector GetOriginalMaxs() const { return GetSchemaValue<Vector>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMaxs"); }
    void SetOriginalMaxs(Vector value) { SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMaxs", false, value); }
    float GetRespawnDuration() const { return GetSchemaValue<float>(m_ptr, "CPhysicsPropRespawnable", "m_flRespawnDuration"); }
    void SetRespawnDuration(float value) { SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_flRespawnDuration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif