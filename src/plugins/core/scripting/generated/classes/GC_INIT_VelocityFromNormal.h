class GC_INIT_VelocityFromNormal;

#ifndef _gcc_init_velocityfromnormal_h
#define _gcc_init_velocityfromnormal_h

#include "../../../scripting.h"




class GC_INIT_VelocityFromNormal
{
private:
    void *m_ptr;

public:
    GC_INIT_VelocityFromNormal() {}
    GC_INIT_VelocityFromNormal(void *ptr) : m_ptr(ptr) {}

    float GetSpeedMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_VelocityFromNormal", "m_fSpeedMin"); }
    void SetSpeedMin(float value) { SetSchemaValue(m_ptr, "C_INIT_VelocityFromNormal", "m_fSpeedMin", false, value); }
    float GetSpeedMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_VelocityFromNormal", "m_fSpeedMax"); }
    void SetSpeedMax(float value) { SetSchemaValue(m_ptr, "C_INIT_VelocityFromNormal", "m_fSpeedMax", false, value); }
    bool GetIgnoreDt() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_VelocityFromNormal", "m_bIgnoreDt"); }
    void SetIgnoreDt(bool value) { SetSchemaValue(m_ptr, "C_INIT_VelocityFromNormal", "m_bIgnoreDt", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif