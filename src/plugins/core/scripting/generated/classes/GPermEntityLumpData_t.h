class GPermEntityLumpData_t;

#ifndef _gcpermentitylumpdata_t_h
#define _gcpermentitylumpdata_t_h

#include "../../../scripting.h"




class GPermEntityLumpData_t
{
private:
    void *m_ptr;

public:
    GPermEntityLumpData_t() {}
    GPermEntityLumpData_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "PermEntityLumpData_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "PermEntityLumpData_t", "m_name", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif