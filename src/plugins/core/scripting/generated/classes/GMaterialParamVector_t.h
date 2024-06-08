class GMaterialParamVector_t;

#ifndef _gcmaterialparamvector_t_h
#define _gcmaterialparamvector_t_h

#include "../../../scripting.h"




class GMaterialParamVector_t
{
private:
    void *m_ptr;

public:
    GMaterialParamVector_t() {}
    GMaterialParamVector_t(void *ptr) : m_ptr(ptr) {}

    Vector4D GetValue() const { return GetSchemaValue<Vector4D>(m_ptr, "MaterialParamVector_t", "m_value"); }
    void SetValue(Vector4D value) { SetSchemaValue(m_ptr, "MaterialParamVector_t", "m_value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif