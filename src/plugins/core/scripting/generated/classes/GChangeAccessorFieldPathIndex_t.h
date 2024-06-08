class GChangeAccessorFieldPathIndex_t;

#ifndef _gcchangeaccessorfieldpathindex_t_h
#define _gcchangeaccessorfieldpathindex_t_h

#include "../../../scripting.h"




class GChangeAccessorFieldPathIndex_t
{
private:
    void *m_ptr;

public:
    GChangeAccessorFieldPathIndex_t() {}
    GChangeAccessorFieldPathIndex_t(void *ptr) : m_ptr(ptr) {}

    int16_t GetValue() const { return GetSchemaValue<int16_t>(m_ptr, "ChangeAccessorFieldPathIndex_t", "m_Value"); }
    void SetValue(int16_t value) { SetSchemaValue(m_ptr, "ChangeAccessorFieldPathIndex_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif