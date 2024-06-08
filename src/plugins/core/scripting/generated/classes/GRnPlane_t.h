class GRnPlane_t;

#ifndef _gcrnplane_t_h
#define _gcrnplane_t_h

#include "../../../scripting.h"




class GRnPlane_t
{
private:
    void *m_ptr;

public:
    GRnPlane_t() {}
    GRnPlane_t(void *ptr) : m_ptr(ptr) {}

    Vector GetNormal() const { return GetSchemaValue<Vector>(m_ptr, "RnPlane_t", "m_vNormal"); }
    void SetNormal(Vector value) { SetSchemaValue(m_ptr, "RnPlane_t", "m_vNormal", true, value); }
    float GetOffset() const { return GetSchemaValue<float>(m_ptr, "RnPlane_t", "m_flOffset"); }
    void SetOffset(float value) { SetSchemaValue(m_ptr, "RnPlane_t", "m_flOffset", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif