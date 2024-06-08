class GParticleIndex_t;

#ifndef _gcparticleindex_t_h
#define _gcparticleindex_t_h

#include "../../../scripting.h"




class GParticleIndex_t
{
private:
    void *m_ptr;

public:
    GParticleIndex_t() {}
    GParticleIndex_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetValue() const { return GetSchemaValue<int32_t>(m_ptr, "ParticleIndex_t", "m_Value"); }
    void SetValue(int32_t value) { SetSchemaValue(m_ptr, "ParticleIndex_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif