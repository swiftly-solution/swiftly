class GFourVectors2D;

#ifndef _gcfourvectors2d_h
#define _gcfourvectors2d_h

#include "../../../scripting.h"




class GFourVectors2D
{
private:
    void *m_ptr;

public:
    GFourVectors2D() {}
    GFourVectors2D(void *ptr) : m_ptr(ptr) {}

    float GetX() const { return GetSchemaValue<float>(m_ptr, "FourVectors2D", "x"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "FourVectors2D", "x", false, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "FourVectors2D", "y"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "FourVectors2D", "y", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif