class GFeSimdAnimStrayRadius_t;

#ifndef _gcfesimdanimstrayradius_t_h
#define _gcfesimdanimstrayradius_t_h

#include "../../../scripting.h"




class GFeSimdAnimStrayRadius_t
{
private:
    void *m_ptr;

public:
    GFeSimdAnimStrayRadius_t() {}
    GFeSimdAnimStrayRadius_t(void *ptr) : m_ptr(ptr) {}

    float GetMaxDist() const { return GetSchemaValue<float>(m_ptr, "FeSimdAnimStrayRadius_t", "flMaxDist"); }
    void SetMaxDist(float value) { SetSchemaValue(m_ptr, "FeSimdAnimStrayRadius_t", "flMaxDist", true, value); }
    float GetRelaxationFactor() const { return GetSchemaValue<float>(m_ptr, "FeSimdAnimStrayRadius_t", "flRelaxationFactor"); }
    void SetRelaxationFactor(float value) { SetSchemaValue(m_ptr, "FeSimdAnimStrayRadius_t", "flRelaxationFactor", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif