class GC_INIT_RandomAlpha;

#ifndef _gcc_init_randomalpha_h
#define _gcc_init_randomalpha_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_RandomAlpha
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomAlpha() {}
    GC_INIT_RandomAlpha(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RandomAlpha", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomAlpha", "m_nFieldOutput", false, value); }
    int32_t GetAlphaMin() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomAlpha", "m_nAlphaMin"); }
    void SetAlphaMin(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomAlpha", "m_nAlphaMin", false, value); }
    int32_t GetAlphaMax() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomAlpha", "m_nAlphaMax"); }
    void SetAlphaMax(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomAlpha", "m_nAlphaMax", false, value); }
    float GetAlphaRandExponent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomAlpha", "m_flAlphaRandExponent"); }
    void SetAlphaRandExponent(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomAlpha", "m_flAlphaRandExponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif