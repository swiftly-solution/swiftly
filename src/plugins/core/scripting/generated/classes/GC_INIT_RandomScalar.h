class GC_INIT_RandomScalar;

#ifndef _gcc_init_randomscalar_h
#define _gcc_init_randomscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_RandomScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomScalar() {}
    GC_INIT_RandomScalar(void *ptr) : m_ptr(ptr) {}

    float GetMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomScalar", "m_flMin"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomScalar", "m_flMin", false, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomScalar", "m_flMax"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomScalar", "m_flMax", false, value); }
    float GetExponent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomScalar", "m_flExponent"); }
    void SetExponent(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomScalar", "m_flExponent", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RandomScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomScalar", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif