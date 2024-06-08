class GCSoundAreaEntitySphere;

#ifndef _gccsoundareaentitysphere_h
#define _gccsoundareaentitysphere_h

#include "../../../scripting.h"




class GCSoundAreaEntitySphere
{
private:
    void *m_ptr;

public:
    GCSoundAreaEntitySphere() {}
    GCSoundAreaEntitySphere(void *ptr) : m_ptr(ptr) {}

    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CSoundAreaEntitySphere", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CSoundAreaEntitySphere", "m_flRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif