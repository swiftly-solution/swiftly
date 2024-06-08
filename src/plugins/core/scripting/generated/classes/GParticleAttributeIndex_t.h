class GParticleAttributeIndex_t;

#ifndef _gcparticleattributeindex_t_h
#define _gcparticleattributeindex_t_h

#include "../../../scripting.h"




class GParticleAttributeIndex_t
{
private:
    void *m_ptr;

public:
    GParticleAttributeIndex_t() {}
    GParticleAttributeIndex_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetValue() const { return GetSchemaValue<int32_t>(m_ptr, "ParticleAttributeIndex_t", "m_Value"); }
    void SetValue(int32_t value) { SetSchemaValue(m_ptr, "ParticleAttributeIndex_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif