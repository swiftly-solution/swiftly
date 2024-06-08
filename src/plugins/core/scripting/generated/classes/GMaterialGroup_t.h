class GMaterialGroup_t;

#ifndef _gcmaterialgroup_t_h
#define _gcmaterialgroup_t_h

#include "../../../scripting.h"




class GMaterialGroup_t
{
private:
    void *m_ptr;

public:
    GMaterialGroup_t() {}
    GMaterialGroup_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "MaterialGroup_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "MaterialGroup_t", "m_name", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif