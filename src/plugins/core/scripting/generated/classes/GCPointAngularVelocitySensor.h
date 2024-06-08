class GCPointAngularVelocitySensor;

#ifndef _gccpointangularvelocitysensor_h
#define _gccpointangularvelocitysensor_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCPointAngularVelocitySensor
{
private:
    void *m_ptr;

public:
    GCPointAngularVelocitySensor() {}
    GCPointAngularVelocitySensor(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetTargetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointAngularVelocitySensor", "m_hTargetEntity"); }
    void SetTargetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n"); }
    float GetThreshold() const { return GetSchemaValue<float>(m_ptr, "CPointAngularVelocitySensor", "m_flThreshold"); }
    void SetThreshold(float value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_flThreshold", false, value); }
    int32_t GetLastCompareResult() const { return GetSchemaValue<int32_t>(m_ptr, "CPointAngularVelocitySensor", "m_nLastCompareResult"); }
    void SetLastCompareResult(int32_t value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_nLastCompareResult", false, value); }
    int32_t GetLastFireResult() const { return GetSchemaValue<int32_t>(m_ptr, "CPointAngularVelocitySensor", "m_nLastFireResult"); }
    void SetLastFireResult(int32_t value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_nLastFireResult", false, value); }
    float GetFireInterval() const { return GetSchemaValue<float>(m_ptr, "CPointAngularVelocitySensor", "m_flFireInterval"); }
    void SetFireInterval(float value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_flFireInterval", false, value); }
    float GetLastAngVelocity() const { return GetSchemaValue<float>(m_ptr, "CPointAngularVelocitySensor", "m_flLastAngVelocity"); }
    void SetLastAngVelocity(float value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_flLastAngVelocity", false, value); }
    QAngle GetLastOrientation() const { return GetSchemaValue<QAngle>(m_ptr, "CPointAngularVelocitySensor", "m_lastOrientation"); }
    void SetLastOrientation(QAngle value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_lastOrientation", false, value); }
    Vector GetAxis() const { return GetSchemaValue<Vector>(m_ptr, "CPointAngularVelocitySensor", "m_vecAxis"); }
    void SetAxis(Vector value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_vecAxis", false, value); }
    bool GetUseHelper() const { return GetSchemaValue<bool>(m_ptr, "CPointAngularVelocitySensor", "m_bUseHelper"); }
    void SetUseHelper(bool value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_bUseHelper", false, value); }
    GCEntityIOOutput GetOnLessThan() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThan"); }
    void SetOnLessThan(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThan", false, value); }
    GCEntityIOOutput GetOnLessThanOrEqualTo() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThanOrEqualTo"); }
    void SetOnLessThanOrEqualTo(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnLessThanOrEqualTo", false, value); }
    GCEntityIOOutput GetOnGreaterThan() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThan"); }
    void SetOnGreaterThan(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThan", false, value); }
    GCEntityIOOutput GetOnGreaterThanOrEqualTo() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThanOrEqualTo"); }
    void SetOnGreaterThanOrEqualTo(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnGreaterThanOrEqualTo", false, value); }
    GCEntityIOOutput GetOnEqualTo() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointAngularVelocitySensor", "m_OnEqualTo"); }
    void SetOnEqualTo(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointAngularVelocitySensor", "m_OnEqualTo", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif