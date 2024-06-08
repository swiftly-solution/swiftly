class GFeSimdTri_t;

#ifndef _gcfesimdtri_t_h
#define _gcfesimdtri_t_h

#include "../../../scripting.h"




class GFeSimdTri_t
{
private:
    void *m_ptr;

public:
    GFeSimdTri_t() {}
    GFeSimdTri_t(void *ptr) : m_ptr(ptr) {}

    float GetW1() const { return GetSchemaValue<float>(m_ptr, "FeSimdTri_t", "w1"); }
    void SetW1(float value) { SetSchemaValue(m_ptr, "FeSimdTri_t", "w1", true, value); }
    float GetW2() const { return GetSchemaValue<float>(m_ptr, "FeSimdTri_t", "w2"); }
    void SetW2(float value) { SetSchemaValue(m_ptr, "FeSimdTri_t", "w2", true, value); }
    float Get1x() const { return GetSchemaValue<float>(m_ptr, "FeSimdTri_t", "v1x"); }
    void Set1x(float value) { SetSchemaValue(m_ptr, "FeSimdTri_t", "v1x", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif