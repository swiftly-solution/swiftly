class GCPointTeleport;

#ifndef _gccpointteleport_h
#define _gccpointteleport_h

#include "../../../scripting.h"




class GCPointTeleport
{
private:
    void *m_ptr;

public:
    GCPointTeleport() {}
    GCPointTeleport(void *ptr) : m_ptr(ptr) {}

    Vector GetSaveOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CPointTeleport", "m_vSaveOrigin"); }
    void SetSaveOrigin(Vector value) { SetSchemaValue(m_ptr, "CPointTeleport", "m_vSaveOrigin", false, value); }
    QAngle GetSaveAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CPointTeleport", "m_vSaveAngles"); }
    void SetSaveAngles(QAngle value) { SetSchemaValue(m_ptr, "CPointTeleport", "m_vSaveAngles", false, value); }
    bool GetTeleportParentedEntities() const { return GetSchemaValue<bool>(m_ptr, "CPointTeleport", "m_bTeleportParentedEntities"); }
    void SetTeleportParentedEntities(bool value) { SetSchemaValue(m_ptr, "CPointTeleport", "m_bTeleportParentedEntities", false, value); }
    bool GetTeleportUseCurrentAngle() const { return GetSchemaValue<bool>(m_ptr, "CPointTeleport", "m_bTeleportUseCurrentAngle"); }
    void SetTeleportUseCurrentAngle(bool value) { SetSchemaValue(m_ptr, "CPointTeleport", "m_bTeleportUseCurrentAngle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif