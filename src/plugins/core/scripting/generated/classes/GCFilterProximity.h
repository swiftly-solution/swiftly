class GCFilterProximity;

#ifndef _gccfilterproximity_h
#define _gccfilterproximity_h

#include "../../../scripting.h"




class GCFilterProximity
{
private:
    void *m_ptr;

public:
    GCFilterProximity() {}
    GCFilterProximity(void *ptr) : m_ptr(ptr) {}

    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CFilterProximity", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CFilterProximity", "m_flRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif