class GC_INIT_CreateSpiralSphere;

#ifndef _gcc_init_createspiralsphere_h
#define _gcc_init_createspiralsphere_h

#include "../../../scripting.h"




class GC_INIT_CreateSpiralSphere
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateSpiralSphere() {}
    GC_INIT_CreateSpiralSphere(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateSpiralSphere", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateSpiralSphere", "m_nControlPointNumber", false, value); }
    int32_t GetOverrideCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateSpiralSphere", "m_nOverrideCP"); }
    void SetOverrideCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateSpiralSphere", "m_nOverrideCP", false, value); }
    int32_t GetDensity() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateSpiralSphere", "m_nDensity"); }
    void SetDensity(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateSpiralSphere", "m_nDensity", false, value); }
    float GetInitialRadius() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateSpiralSphere", "m_flInitialRadius"); }
    void SetInitialRadius(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateSpiralSphere", "m_flInitialRadius", false, value); }
    float GetInitialSpeedMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateSpiralSphere", "m_flInitialSpeedMin"); }
    void SetInitialSpeedMin(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateSpiralSphere", "m_flInitialSpeedMin", false, value); }
    float GetInitialSpeedMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateSpiralSphere", "m_flInitialSpeedMax"); }
    void SetInitialSpeedMax(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateSpiralSphere", "m_flInitialSpeedMax", false, value); }
    bool GetUseParticleCount() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateSpiralSphere", "m_bUseParticleCount"); }
    void SetUseParticleCount(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateSpiralSphere", "m_bUseParticleCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif