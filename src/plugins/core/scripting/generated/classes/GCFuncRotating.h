class GCFuncRotating;

#ifndef _gccfuncrotating_h
#define _gccfuncrotating_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCFuncRotating
{
private:
    void *m_ptr;

public:
    GCFuncRotating() {}
    GCFuncRotating(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnStopped() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncRotating", "m_OnStopped"); }
    void SetOnStopped(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_OnStopped", false, value); }
    GCEntityIOOutput GetOnStarted() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncRotating", "m_OnStarted"); }
    void SetOnStarted(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_OnStarted", false, value); }
    GCEntityIOOutput GetOnReachedStart() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncRotating", "m_OnReachedStart"); }
    void SetOnReachedStart(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_OnReachedStart", false, value); }
    Vector GetLocalRotationVector() const { return GetSchemaValue<Vector>(m_ptr, "CFuncRotating", "m_localRotationVector"); }
    void SetLocalRotationVector(Vector value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_localRotationVector", false, value); }
    float GetFanFriction() const { return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flFanFriction"); }
    void SetFanFriction(float value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_flFanFriction", false, value); }
    float GetAttenuation() const { return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flAttenuation"); }
    void SetAttenuation(float value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_flAttenuation", false, value); }
    float GetVolume() const { return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flVolume"); }
    void SetVolume(float value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_flVolume", false, value); }
    float GetTargetSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flTargetSpeed"); }
    void SetTargetSpeed(float value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_flTargetSpeed", false, value); }
    float GetMaxSpeed() const { return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flMaxSpeed"); }
    void SetMaxSpeed(float value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_flMaxSpeed", false, value); }
    float GetBlockDamage() const { return GetSchemaValue<float>(m_ptr, "CFuncRotating", "m_flBlockDamage"); }
    void SetBlockDamage(float value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_flBlockDamage", false, value); }
    CUtlSymbolLarge GetNoiseRunning() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncRotating", "m_NoiseRunning"); }
    void SetNoiseRunning(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_NoiseRunning", false, value); }
    bool GetReversed() const { return GetSchemaValue<bool>(m_ptr, "CFuncRotating", "m_bReversed"); }
    void SetReversed(bool value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_bReversed", false, value); }
    bool GetAccelDecel() const { return GetSchemaValue<bool>(m_ptr, "CFuncRotating", "m_bAccelDecel"); }
    void SetAccelDecel(bool value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_bAccelDecel", false, value); }
    QAngle GetPrevLocalAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncRotating", "m_prevLocalAngles"); }
    void SetPrevLocalAngles(QAngle value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_prevLocalAngles", false, value); }
    QAngle GetStart() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncRotating", "m_angStart"); }
    void SetStart(QAngle value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_angStart", false, value); }
    bool GetStopAtStartPos() const { return GetSchemaValue<bool>(m_ptr, "CFuncRotating", "m_bStopAtStartPos"); }
    void SetStopAtStartPos(bool value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_bStopAtStartPos", false, value); }
    Vector GetClientOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CFuncRotating", "m_vecClientOrigin"); }
    void SetClientOrigin(Vector value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_vecClientOrigin", false, value); }
    QAngle GetClientAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncRotating", "m_vecClientAngles"); }
    void SetClientAngles(QAngle value) { SetSchemaValue(m_ptr, "CFuncRotating", "m_vecClientAngles", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif