class GResourceId_t;

#ifndef _gcresourceid_t_h
#define _gcresourceid_t_h

#include "../../../scripting.h"




class GResourceId_t
{
private:
    void *m_ptr;

public:
    GResourceId_t() {}
    GResourceId_t(void *ptr) : m_ptr(ptr) {}

    uint64_t GetValue() const { return GetSchemaValue<uint64_t>(m_ptr, "ResourceId_t", "m_Value"); }
    void SetValue(uint64_t value) { SetSchemaValue(m_ptr, "ResourceId_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif