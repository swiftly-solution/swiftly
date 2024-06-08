class GAABB_t;

#ifndef _gcaabb_t_h
#define _gcaabb_t_h

#include "../../../scripting.h"




class GAABB_t
{
private:
    void *m_ptr;

public:
    GAABB_t() {}
    GAABB_t(void *ptr) : m_ptr(ptr) {}

    Vector GetMinBounds() const { return GetSchemaValue<Vector>(m_ptr, "AABB_t", "m_vMinBounds"); }
    void SetMinBounds(Vector value) { SetSchemaValue(m_ptr, "AABB_t", "m_vMinBounds", true, value); }
    Vector GetMaxBounds() const { return GetSchemaValue<Vector>(m_ptr, "AABB_t", "m_vMaxBounds"); }
    void SetMaxBounds(Vector value) { SetSchemaValue(m_ptr, "AABB_t", "m_vMaxBounds", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif