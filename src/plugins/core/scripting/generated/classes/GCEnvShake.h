class GCEnvShake;

#ifndef _gccenvshake_h
#define _gccenvshake_h

#include "../../../scripting.h"


#include "GCPhysicsShake.h"

class GCEnvShake
{
private:
    void *m_ptr;

public:
    GCEnvShake() {}
    GCEnvShake(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetLimitToEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvShake", "m_limitToEntity"); }
    void SetLimitToEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvShake", "m_limitToEntity", false, value); }
    float GetAmplitude() const { return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Amplitude"); }
    void SetAmplitude(float value) { SetSchemaValue(m_ptr, "CEnvShake", "m_Amplitude", false, value); }
    float GetFrequency() const { return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Frequency"); }
    void SetFrequency(float value) { SetSchemaValue(m_ptr, "CEnvShake", "m_Frequency", false, value); }
    float GetDuration() const { return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Duration"); }
    void SetDuration(float value) { SetSchemaValue(m_ptr, "CEnvShake", "m_Duration", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_Radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CEnvShake", "m_Radius", false, value); }
    float GetCurrentAmp() const { return GetSchemaValue<float>(m_ptr, "CEnvShake", "m_currentAmp"); }
    void SetCurrentAmp(float value) { SetSchemaValue(m_ptr, "CEnvShake", "m_currentAmp", false, value); }
    Vector GetMaxForce() const { return GetSchemaValue<Vector>(m_ptr, "CEnvShake", "m_maxForce"); }
    void SetMaxForce(Vector value) { SetSchemaValue(m_ptr, "CEnvShake", "m_maxForce", false, value); }
    GCPhysicsShake GetShakeCallback() const { return GetSchemaValue<GCPhysicsShake>(m_ptr, "CEnvShake", "m_shakeCallback"); }
    void SetShakeCallback(GCPhysicsShake value) { SetSchemaValue(m_ptr, "CEnvShake", "m_shakeCallback", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif