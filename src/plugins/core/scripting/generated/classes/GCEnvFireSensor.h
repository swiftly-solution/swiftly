class GCEnvFireSensor;

#ifndef _gccenvfiresensor_h
#define _gccenvfiresensor_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCEnvFireSensor
{
private:
    void *m_ptr;

public:
    GCEnvFireSensor() {}
    GCEnvFireSensor(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvFireSensor", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_bEnabled", false, value); }
    bool GetHeatAtLevel() const { return GetSchemaValue<bool>(m_ptr, "CEnvFireSensor", "m_bHeatAtLevel"); }
    void SetHeatAtLevel(bool value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_bHeatAtLevel", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_radius", false, value); }
    float GetTargetLevel() const { return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_targetLevel"); }
    void SetTargetLevel(float value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_targetLevel", false, value); }
    float GetTargetTime() const { return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_targetTime"); }
    void SetTargetTime(float value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_targetTime", false, value); }
    float GetLevelTime() const { return GetSchemaValue<float>(m_ptr, "CEnvFireSensor", "m_levelTime"); }
    void SetLevelTime(float value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_levelTime", false, value); }
    GCEntityIOOutput GetOnHeatLevelStart() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvFireSensor", "m_OnHeatLevelStart"); }
    void SetOnHeatLevelStart(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_OnHeatLevelStart", false, value); }
    GCEntityIOOutput GetOnHeatLevelEnd() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvFireSensor", "m_OnHeatLevelEnd"); }
    void SetOnHeatLevelEnd(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvFireSensor", "m_OnHeatLevelEnd", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif