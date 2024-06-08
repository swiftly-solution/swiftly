class GCPointVelocitySensor;

#ifndef _gccpointvelocitysensor_h
#define _gccpointvelocitysensor_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCPointVelocitySensor
{
private:
    void *m_ptr;

public:
    GCPointVelocitySensor() {}
    GCPointVelocitySensor(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetTargetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointVelocitySensor", "m_hTargetEntity"); }
    void SetTargetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n"); }
    Vector GetAxis() const { return GetSchemaValue<Vector>(m_ptr, "CPointVelocitySensor", "m_vecAxis"); }
    void SetAxis(Vector value) { SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_vecAxis", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CPointVelocitySensor", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_bEnabled", false, value); }
    float GetPrevVelocity() const { return GetSchemaValue<float>(m_ptr, "CPointVelocitySensor", "m_fPrevVelocity"); }
    void SetPrevVelocity(float value) { SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_fPrevVelocity", false, value); }
    float GetAvgInterval() const { return GetSchemaValue<float>(m_ptr, "CPointVelocitySensor", "m_flAvgInterval"); }
    void SetAvgInterval(float value) { SetSchemaValue(m_ptr, "CPointVelocitySensor", "m_flAvgInterval", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif