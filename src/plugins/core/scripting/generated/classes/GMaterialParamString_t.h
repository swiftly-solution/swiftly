class GMaterialParamString_t;

#ifndef _gcmaterialparamstring_t_h
#define _gcmaterialparamstring_t_h

#include "../../../scripting.h"




class GMaterialParamString_t
{
private:
    void *m_ptr;

public:
    GMaterialParamString_t() {}
    GMaterialParamString_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetValue() const { return GetSchemaValue<CUtlString>(m_ptr, "MaterialParamString_t", "m_value"); }
    void SetValue(CUtlString value) { SetSchemaValue(m_ptr, "MaterialParamString_t", "m_value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif