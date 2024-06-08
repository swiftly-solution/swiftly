class GCPropDoorRotating;

#ifndef _gccpropdoorrotating_h
#define _gccpropdoorrotating_h

#include "../../../scripting.h"

#include "../types/GPropDoorRotatingSpawnPos_t.h"
#include "../types/GPropDoorRotatingOpenDirection_e.h"
#include "GCEntityBlocker.h"

class GCPropDoorRotating
{
private:
    void *m_ptr;

public:
    GCPropDoorRotating() {}
    GCPropDoorRotating(void *ptr) : m_ptr(ptr) {}

    Vector GetAxis() const { return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecAxis"); }
    void SetAxis(Vector value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecAxis", false, value); }
    float GetDistance() const { return GetSchemaValue<float>(m_ptr, "CPropDoorRotating", "m_flDistance"); }
    void SetDistance(float value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_flDistance", false, value); }
    PropDoorRotatingSpawnPos_t GetSpawnPosition() const { return GetSchemaValue<PropDoorRotatingSpawnPos_t>(m_ptr, "CPropDoorRotating", "m_eSpawnPosition"); }
    void SetSpawnPosition(PropDoorRotatingSpawnPos_t value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_eSpawnPosition", false, value); }
    PropDoorRotatingOpenDirection_e GetOpenDirection() const { return GetSchemaValue<PropDoorRotatingOpenDirection_e>(m_ptr, "CPropDoorRotating", "m_eOpenDirection"); }
    void SetOpenDirection(PropDoorRotatingOpenDirection_e value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_eOpenDirection", false, value); }
    PropDoorRotatingOpenDirection_e GetCurrentOpenDirection() const { return GetSchemaValue<PropDoorRotatingOpenDirection_e>(m_ptr, "CPropDoorRotating", "m_eCurrentOpenDirection"); }
    void SetCurrentOpenDirection(PropDoorRotatingOpenDirection_e value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_eCurrentOpenDirection", false, value); }
    float GetAjarAngle() const { return GetSchemaValue<float>(m_ptr, "CPropDoorRotating", "m_flAjarAngle"); }
    void SetAjarAngle(float value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_flAjarAngle", false, value); }
    QAngle GetRotationAjarDeprecated() const { return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationAjarDeprecated"); }
    void SetRotationAjarDeprecated(QAngle value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationAjarDeprecated", false, value); }
    QAngle GetRotationClosed() const { return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationClosed"); }
    void SetRotationClosed(QAngle value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationClosed", false, value); }
    QAngle GetRotationOpenForward() const { return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationOpenForward"); }
    void SetRotationOpenForward(QAngle value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationOpenForward", false, value); }
    QAngle GetRotationOpenBack() const { return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationOpenBack"); }
    void SetRotationOpenBack(QAngle value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationOpenBack", false, value); }
    QAngle GetGoal() const { return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angGoal"); }
    void SetGoal(QAngle value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angGoal", false, value); }
    Vector GetForwardBoundsMin() const { return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMin"); }
    void SetForwardBoundsMin(Vector value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMin", false, value); }
    Vector GetForwardBoundsMax() const { return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMax"); }
    void SetForwardBoundsMax(Vector value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMax", false, value); }
    Vector GetBackBoundsMin() const { return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMin"); }
    void SetBackBoundsMin(Vector value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMin", false, value); }
    Vector GetBackBoundsMax() const { return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMax"); }
    void SetBackBoundsMax(Vector value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMax", false, value); }
    bool GetAjarDoorShouldntAlwaysOpen() const { return GetSchemaValue<bool>(m_ptr, "CPropDoorRotating", "m_bAjarDoorShouldntAlwaysOpen"); }
    void SetAjarDoorShouldntAlwaysOpen(bool value) { SetSchemaValue(m_ptr, "CPropDoorRotating", "m_bAjarDoorShouldntAlwaysOpen", false, value); }
    GCEntityBlocker* GetEntityBlocker() const { return GetSchemaValue<GCEntityBlocker*>(m_ptr, "CPropDoorRotating", "m_hEntityBlocker"); }
    void SetEntityBlocker(GCEntityBlocker* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityBlocker' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif