class GCTriggerPhysics;

#ifndef _gcctriggerphysics_h
#define _gcctriggerphysics_h

#include "../../../scripting.h"




class GCTriggerPhysics
{
private:
    void *m_ptr;

public:
    GCTriggerPhysics() {}
    GCTriggerPhysics(void *ptr) : m_ptr(ptr) {}

    float GetGravityScale() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_gravityScale"); }
    void SetGravityScale(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_gravityScale", false, value); }
    float GetLinearLimit() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_linearLimit"); }
    void SetLinearLimit(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_linearLimit", false, value); }
    float GetLinearDamping() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_linearDamping"); }
    void SetLinearDamping(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_linearDamping", false, value); }
    float GetAngularLimit() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_angularLimit"); }
    void SetAngularLimit(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_angularLimit", false, value); }
    float GetAngularDamping() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_angularDamping"); }
    void SetAngularDamping(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_angularDamping", false, value); }
    float GetLinearForce() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_linearForce"); }
    void SetLinearForce(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_linearForce", false, value); }
    float GetFrequency() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_flFrequency"); }
    void SetFrequency(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_flFrequency", false, value); }
    float GetDampingRatio() const { return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_flDampingRatio"); }
    void SetDampingRatio(float value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_flDampingRatio", false, value); }
    Vector GetLinearForcePointAt() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAt"); }
    void SetLinearForcePointAt(Vector value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAt", false, value); }
    bool GetCollapseToForcePoint() const { return GetSchemaValue<bool>(m_ptr, "CTriggerPhysics", "m_bCollapseToForcePoint"); }
    void SetCollapseToForcePoint(bool value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_bCollapseToForcePoint", false, value); }
    Vector GetLinearForcePointAtWorld() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAtWorld"); }
    void SetLinearForcePointAtWorld(Vector value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAtWorld", false, value); }
    Vector GetLinearForceDirection() const { return GetSchemaValue<Vector>(m_ptr, "CTriggerPhysics", "m_vecLinearForceDirection"); }
    void SetLinearForceDirection(Vector value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_vecLinearForceDirection", false, value); }
    bool GetConvertToDebrisWhenPossible() const { return GetSchemaValue<bool>(m_ptr, "CTriggerPhysics", "m_bConvertToDebrisWhenPossible"); }
    void SetConvertToDebrisWhenPossible(bool value) { SetSchemaValue(m_ptr, "CTriggerPhysics", "m_bConvertToDebrisWhenPossible", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif