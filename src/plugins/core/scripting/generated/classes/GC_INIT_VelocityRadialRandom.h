class GC_INIT_VelocityRadialRandom;

#ifndef _gcc_init_velocityradialrandom_h
#define _gcc_init_velocityradialrandom_h

#include "../../../scripting.h"




class GC_INIT_VelocityRadialRandom
{
private:
    void *m_ptr;

public:
    GC_INIT_VelocityRadialRandom() {}
    GC_INIT_VelocityRadialRandom(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_VelocityRadialRandom", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRadialRandom", "m_nControlPointNumber", false, value); }
    float GetSpeedMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_VelocityRadialRandom", "m_fSpeedMin"); }
    void SetSpeedMin(float value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRadialRandom", "m_fSpeedMin", false, value); }
    float GetSpeedMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_VelocityRadialRandom", "m_fSpeedMax"); }
    void SetSpeedMax(float value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRadialRandom", "m_fSpeedMax", false, value); }
    Vector GetLocalCoordinateSystemSpeedScale() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_VelocityRadialRandom", "m_vecLocalCoordinateSystemSpeedScale"); }
    void SetLocalCoordinateSystemSpeedScale(Vector value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRadialRandom", "m_vecLocalCoordinateSystemSpeedScale", false, value); }
    bool GetIgnoreDelta() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_VelocityRadialRandom", "m_bIgnoreDelta"); }
    void SetIgnoreDelta(bool value) { SetSchemaValue(m_ptr, "C_INIT_VelocityRadialRandom", "m_bIgnoreDelta", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif