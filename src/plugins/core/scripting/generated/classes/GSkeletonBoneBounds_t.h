class GSkeletonBoneBounds_t;

#ifndef _gcskeletonbonebounds_t_h
#define _gcskeletonbonebounds_t_h

#include "../../../scripting.h"




class GSkeletonBoneBounds_t
{
private:
    void *m_ptr;

public:
    GSkeletonBoneBounds_t() {}
    GSkeletonBoneBounds_t(void *ptr) : m_ptr(ptr) {}

    Vector GetCenter() const { return GetSchemaValue<Vector>(m_ptr, "SkeletonBoneBounds_t", "m_vecCenter"); }
    void SetCenter(Vector value) { SetSchemaValue(m_ptr, "SkeletonBoneBounds_t", "m_vecCenter", true, value); }
    Vector GetSize() const { return GetSchemaValue<Vector>(m_ptr, "SkeletonBoneBounds_t", "m_vecSize"); }
    void SetSize(Vector value) { SetSchemaValue(m_ptr, "SkeletonBoneBounds_t", "m_vecSize", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif