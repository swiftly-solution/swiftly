class GMaterialParam_t;

#ifndef _gcmaterialparam_t_h
#define _gcmaterialparam_t_h

#include "../../../scripting.h"




class GMaterialParam_t
{
private:
    void *m_ptr;

public:
    GMaterialParam_t() {}
    GMaterialParam_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "MaterialParam_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "MaterialParam_t", "m_name", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif