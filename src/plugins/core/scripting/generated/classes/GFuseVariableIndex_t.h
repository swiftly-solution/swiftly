class GFuseVariableIndex_t;

#ifndef _gcfusevariableindex_t_h
#define _gcfusevariableindex_t_h

#include "../../../scripting.h"




class GFuseVariableIndex_t
{
private:
    void *m_ptr;

public:
    GFuseVariableIndex_t() {}
    GFuseVariableIndex_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetValue() const { return GetSchemaValue<uint16_t>(m_ptr, "FuseVariableIndex_t", "m_Value"); }
    void SetValue(uint16_t value) { SetSchemaValue(m_ptr, "FuseVariableIndex_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif