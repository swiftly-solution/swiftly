class GC_INIT_RandomLifeTime;

#ifndef _gcc_init_randomlifetime_h
#define _gcc_init_randomlifetime_h

#include "../../../scripting.h"




class GC_INIT_RandomLifeTime
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomLifeTime() {}
    GC_INIT_RandomLifeTime(void *ptr) : m_ptr(ptr) {}

    float GetLifetimeMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomLifeTime", "m_fLifetimeMin"); }
    void SetLifetimeMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomLifeTime", "m_fLifetimeMin", false, value); }
    float GetLifetimeMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomLifeTime", "m_fLifetimeMax"); }
    void SetLifetimeMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomLifeTime", "m_fLifetimeMax", false, value); }
    float GetLifetimeRandExponent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomLifeTime", "m_fLifetimeRandExponent"); }
    void SetLifetimeRandExponent(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomLifeTime", "m_fLifetimeRandExponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif