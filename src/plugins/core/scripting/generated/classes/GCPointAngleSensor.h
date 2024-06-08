class GCPointAngleSensor;

#ifndef _gccpointanglesensor_h
#define _gccpointanglesensor_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCPointAngleSensor
{
private:
    void *m_ptr;

public:
    GCPointAngleSensor() {}
    GCPointAngleSensor(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CPointAngleSensor", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CPointAngleSensor", "m_bDisabled", false, value); }
    CUtlSymbolLarge GetLookAtName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointAngleSensor", "m_nLookAtName"); }
    void SetLookAtName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointAngleSensor", "m_nLookAtName", false, value); }
    GCBaseEntity* GetTargetEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointAngleSensor", "m_hTargetEntity"); }
    void SetTargetEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n"); }
    GCBaseEntity* GetLookAtEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointAngleSensor", "m_hLookAtEntity"); }
    void SetLookAtEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LookAtEntity' is not possible.\n"); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CPointAngleSensor", "m_flDuration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CPointAngleSensor", "m_flDuration", false, value); }
    float GetDotTolerance() const { return GetSchemaValue<float>(m_ptr, "CPointAngleSensor", "m_flDotTolerance"); }
    void SetDotTolerance(float value) { SetSchemaValue(m_ptr, "CPointAngleSensor", "m_flDotTolerance", false, value); }
    bool GetFired() const { return GetSchemaValue<bool>(m_ptr, "CPointAngleSensor", "m_bFired"); }
    void SetFired(bool value) { SetSchemaValue(m_ptr, "CPointAngleSensor", "m_bFired", false, value); }
    GCEntityIOOutput GetOnFacingLookat() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointAngleSensor", "m_OnFacingLookat"); }
    void SetOnFacingLookat(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointAngleSensor", "m_OnFacingLookat", false, value); }
    GCEntityIOOutput GetOnNotFacingLookat() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPointAngleSensor", "m_OnNotFacingLookat"); }
    void SetOnNotFacingLookat(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPointAngleSensor", "m_OnNotFacingLookat", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif