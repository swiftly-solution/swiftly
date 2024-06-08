class GCNavVolumeSphere;

#ifndef _gccnavvolumesphere_h
#define _gccnavvolumesphere_h

#include "../../../scripting.h"




class GCNavVolumeSphere
{
private:
    void *m_ptr;

public:
    GCNavVolumeSphere() {}
    GCNavVolumeSphere(void *ptr) : m_ptr(ptr) {}

    Vector GetCenter() const { return GetSchemaValue<Vector>(m_ptr, "CNavVolumeSphere", "m_vCenter"); }
    void SetCenter(Vector value) { SetSchemaValue(m_ptr, "CNavVolumeSphere", "m_vCenter", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CNavVolumeSphere", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CNavVolumeSphere", "m_flRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif