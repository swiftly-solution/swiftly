class GFuseFunctionIndex_t;

#ifndef _gcfusefunctionindex_t_h
#define _gcfusefunctionindex_t_h

#include "../../../scripting.h"




class GFuseFunctionIndex_t
{
private:
    void *m_ptr;

public:
    GFuseFunctionIndex_t() {}
    GFuseFunctionIndex_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetValue() const { return GetSchemaValue<uint16_t>(m_ptr, "FuseFunctionIndex_t", "m_Value"); }
    void SetValue(uint16_t value) { SetSchemaValue(m_ptr, "FuseFunctionIndex_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif