class GNmPercent_t;

#ifndef _gcnmpercent_t_h
#define _gcnmpercent_t_h

#include "../../../scripting.h"




class GNmPercent_t
{
private:
    void *m_ptr;

public:
    GNmPercent_t() {}
    GNmPercent_t(void *ptr) : m_ptr(ptr) {}

    float GetValue() const { return GetSchemaValue<float>(m_ptr, "NmPercent_t", "m_flValue"); }
    void SetValue(float value) { SetSchemaValue(m_ptr, "NmPercent_t", "m_flValue", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif