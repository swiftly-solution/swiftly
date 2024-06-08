class GMaterialParamInt_t;

#ifndef _gcmaterialparamint_t_h
#define _gcmaterialparamint_t_h

#include "../../../scripting.h"




class GMaterialParamInt_t
{
private:
    void *m_ptr;

public:
    GMaterialParamInt_t() {}
    GMaterialParamInt_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetValue() const { return GetSchemaValue<int32_t>(m_ptr, "MaterialParamInt_t", "m_nValue"); }
    void SetValue(int32_t value) { SetSchemaValue(m_ptr, "MaterialParamInt_t", "m_nValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif