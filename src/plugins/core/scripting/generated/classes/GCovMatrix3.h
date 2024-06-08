class GCovMatrix3;

#ifndef _gccovmatrix3_h
#define _gccovmatrix3_h

#include "../../../scripting.h"




class GCovMatrix3
{
private:
    void *m_ptr;

public:
    GCovMatrix3() {}
    GCovMatrix3(void *ptr) : m_ptr(ptr) {}

    Vector GetDiag() const { return GetSchemaValue<Vector>(m_ptr, "CovMatrix3", "m_vDiag"); }
    void SetDiag(Vector value) { SetSchemaValue(m_ptr, "CovMatrix3", "m_vDiag", false, value); }
    float GetXY() const { return GetSchemaValue<float>(m_ptr, "CovMatrix3", "m_flXY"); }
    void SetXY(float value) { SetSchemaValue(m_ptr, "CovMatrix3", "m_flXY", false, value); }
    float GetXZ() const { return GetSchemaValue<float>(m_ptr, "CovMatrix3", "m_flXZ"); }
    void SetXZ(float value) { SetSchemaValue(m_ptr, "CovMatrix3", "m_flXZ", false, value); }
    float GetYZ() const { return GetSchemaValue<float>(m_ptr, "CovMatrix3", "m_flYZ"); }
    void SetYZ(float value) { SetSchemaValue(m_ptr, "CovMatrix3", "m_flYZ", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif