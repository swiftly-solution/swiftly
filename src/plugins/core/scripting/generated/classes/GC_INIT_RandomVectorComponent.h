class GC_INIT_RandomVectorComponent;

#ifndef _gcc_init_randomvectorcomponent_h
#define _gcc_init_randomvectorcomponent_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_RandomVectorComponent
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomVectorComponent() {}
    GC_INIT_RandomVectorComponent(void *ptr) : m_ptr(ptr) {}

    float GetMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomVectorComponent", "m_flMin"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomVectorComponent", "m_flMin", false, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomVectorComponent", "m_flMax"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomVectorComponent", "m_flMax", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RandomVectorComponent", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomVectorComponent", "m_nFieldOutput", false, value); }
    int32_t GetComponent() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomVectorComponent", "m_nComponent"); }
    void SetComponent(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomVectorComponent", "m_nComponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif