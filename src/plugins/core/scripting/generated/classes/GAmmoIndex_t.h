class GAmmoIndex_t;

#ifndef _gcammoindex_t_h
#define _gcammoindex_t_h

#include "../../../scripting.h"




class GAmmoIndex_t
{
private:
    void *m_ptr;

public:
    GAmmoIndex_t() {}
    GAmmoIndex_t(void *ptr) : m_ptr(ptr) {}

    int8_t GetValue() const { return GetSchemaValue<int8_t>(m_ptr, "AmmoIndex_t", "m_Value"); }
    void SetValue(int8_t value) { SetSchemaValue(m_ptr, "AmmoIndex_t", "m_Value", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif