class GExtent;

#ifndef _gcextent_h
#define _gcextent_h

#include "../../../scripting.h"




class GExtent
{
private:
    void *m_ptr;

public:
    GExtent() {}
    GExtent(void *ptr) : m_ptr(ptr) {}

    Vector GetLo() const { return GetSchemaValue<Vector>(m_ptr, "Extent", "lo"); }
    void SetLo(Vector value) { SetSchemaValue(m_ptr, "Extent", "lo", false, value); }
    Vector GetHi() const { return GetSchemaValue<Vector>(m_ptr, "Extent", "hi"); }
    void SetHi(Vector value) { SetSchemaValue(m_ptr, "Extent", "hi", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif