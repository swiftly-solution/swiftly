class GCBaseToggle;

#ifndef _gccbasetoggle_h
#define _gccbasetoggle_h

#include "../../../scripting.h"

#include "../types/GTOGGLE_STATE.h"
#include "GCBaseEntity.h"

class GCBaseToggle
{
private:
    void *m_ptr;

public:
    GCBaseToggle() {}
    GCBaseToggle(void *ptr) : m_ptr(ptr) {}

    TOGGLE_STATE GetToggle_state() const { return GetSchemaValue<TOGGLE_STATE>(m_ptr, "CBaseToggle", "m_toggle_state"); }
    void SetToggle_state(TOGGLE_STATE value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_toggle_state", false, value); }
    float GetMoveDistance() const { return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flMoveDistance"); }
    void SetMoveDistance(float value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_flMoveDistance", false, value); }
    float GetWait() const { return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flWait"); }
    void SetWait(float value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_flWait", false, value); }
    float GetLip() const { return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flLip"); }
    void SetLip(float value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_flLip", false, value); }
    bool GetAlwaysFireBlockedOutputs() const { return GetSchemaValue<bool>(m_ptr, "CBaseToggle", "m_bAlwaysFireBlockedOutputs"); }
    void SetAlwaysFireBlockedOutputs(bool value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_bAlwaysFireBlockedOutputs", false, value); }
    Vector GetPosition1() const { return GetSchemaValue<Vector>(m_ptr, "CBaseToggle", "m_vecPosition1"); }
    void SetPosition1(Vector value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_vecPosition1", false, value); }
    Vector GetPosition2() const { return GetSchemaValue<Vector>(m_ptr, "CBaseToggle", "m_vecPosition2"); }
    void SetPosition2(Vector value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_vecPosition2", false, value); }
    QAngle GetMoveAng() const { return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecMoveAng"); }
    void SetMoveAng(QAngle value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_vecMoveAng", false, value); }
    QAngle GetAngle1() const { return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecAngle1"); }
    void SetAngle1(QAngle value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_vecAngle1", false, value); }
    QAngle GetAngle2() const { return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecAngle2"); }
    void SetAngle2(QAngle value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_vecAngle2", false, value); }
    float GetHeight() const { return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flHeight"); }
    void SetHeight(float value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_flHeight", false, value); }
    GCBaseEntity* GetActivator() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBaseToggle", "m_hActivator"); }
    void SetActivator(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n"); }
    Vector GetFinalDest() const { return GetSchemaValue<Vector>(m_ptr, "CBaseToggle", "m_vecFinalDest"); }
    void SetFinalDest(Vector value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_vecFinalDest", false, value); }
    QAngle GetFinalAngle() const { return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecFinalAngle"); }
    void SetFinalAngle(QAngle value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_vecFinalAngle", false, value); }
    int32_t GetMovementType() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseToggle", "m_movementType"); }
    void SetMovementType(int32_t value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_movementType", false, value); }
    CUtlSymbolLarge GetMaster() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseToggle", "m_sMaster"); }
    void SetMaster(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseToggle", "m_sMaster", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif