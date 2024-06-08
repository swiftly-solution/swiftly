class GFourQuaternions;

#ifndef _gcfourquaternions_h
#define _gcfourquaternions_h

#include "../../../scripting.h"




class GFourQuaternions
{
private:
    void *m_ptr;

public:
    GFourQuaternions() {}
    GFourQuaternions(void *ptr) : m_ptr(ptr) {}

    float GetX() const { return GetSchemaValue<float>(m_ptr, "FourQuaternions", "x"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "FourQuaternions", "x", false, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "FourQuaternions", "y"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "FourQuaternions", "y", false, value); }
    float GetZ() const { return GetSchemaValue<float>(m_ptr, "FourQuaternions", "z"); }
    void SetZ(float value) { SetSchemaValue(m_ptr, "FourQuaternions", "z", false, value); }
    float GetW() const { return GetSchemaValue<float>(m_ptr, "FourQuaternions", "w"); }
    void SetW(float value) { SetSchemaValue(m_ptr, "FourQuaternions", "w", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif