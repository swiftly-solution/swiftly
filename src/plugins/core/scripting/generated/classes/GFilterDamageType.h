class GFilterDamageType;

#ifndef _gcfilterdamagetype_h
#define _gcfilterdamagetype_h

#include "../../../scripting.h"




class GFilterDamageType
{
private:
    void *m_ptr;

public:
    GFilterDamageType() {}
    GFilterDamageType(void *ptr) : m_ptr(ptr) {}

    int32_t GetDamageType() const { return GetSchemaValue<int32_t>(m_ptr, "FilterDamageType", "m_iDamageType"); }
    void SetDamageType(int32_t value) { SetSchemaValue(m_ptr, "FilterDamageType", "m_iDamageType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif