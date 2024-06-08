class GFeSoftParent_t;

#ifndef _gcfesoftparent_t_h
#define _gcfesoftparent_t_h

#include "../../../scripting.h"




class GFeSoftParent_t
{
private:
    void *m_ptr;

public:
    GFeSoftParent_t() {}
    GFeSoftParent_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetParent() const { return GetSchemaValue<int32_t>(m_ptr, "FeSoftParent_t", "nParent"); }
    void SetParent(int32_t value) { SetSchemaValue(m_ptr, "FeSoftParent_t", "nParent", true, value); }
    float GetAlpha() const { return GetSchemaValue<float>(m_ptr, "FeSoftParent_t", "flAlpha"); }
    void SetAlpha(float value) { SetSchemaValue(m_ptr, "FeSoftParent_t", "flAlpha", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif