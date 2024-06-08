class GMaterialParamFloat_t;

#ifndef _gcmaterialparamfloat_t_h
#define _gcmaterialparamfloat_t_h

#include "../../../scripting.h"




class GMaterialParamFloat_t
{
private:
    void *m_ptr;

public:
    GMaterialParamFloat_t() {}
    GMaterialParamFloat_t(void *ptr) : m_ptr(ptr) {}

    float GetValue() const { return GetSchemaValue<float>(m_ptr, "MaterialParamFloat_t", "m_flValue"); }
    void SetValue(float value) { SetSchemaValue(m_ptr, "MaterialParamFloat_t", "m_flValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif