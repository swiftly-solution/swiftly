class GFourCovMatrices3;

#ifndef _gcfourcovmatrices3_h
#define _gcfourcovmatrices3_h

#include "../../../scripting.h"




class GFourCovMatrices3
{
private:
    void *m_ptr;

public:
    GFourCovMatrices3() {}
    GFourCovMatrices3(void *ptr) : m_ptr(ptr) {}

    float GetXY() const { return GetSchemaValue<float>(m_ptr, "FourCovMatrices3", "m_flXY"); }
    void SetXY(float value) { SetSchemaValue(m_ptr, "FourCovMatrices3", "m_flXY", false, value); }
    float GetXZ() const { return GetSchemaValue<float>(m_ptr, "FourCovMatrices3", "m_flXZ"); }
    void SetXZ(float value) { SetSchemaValue(m_ptr, "FourCovMatrices3", "m_flXZ", false, value); }
    float GetYZ() const { return GetSchemaValue<float>(m_ptr, "FourCovMatrices3", "m_flYZ"); }
    void SetYZ(float value) { SetSchemaValue(m_ptr, "FourCovMatrices3", "m_flYZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif