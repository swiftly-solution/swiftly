class GTestResource_t;

#ifndef _gctestresource_t_h
#define _gctestresource_t_h

#include "../../../scripting.h"




class GTestResource_t
{
private:
    void *m_ptr;

public:
    GTestResource_t() {}
    GTestResource_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "TestResource_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "TestResource_t", "m_name", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif