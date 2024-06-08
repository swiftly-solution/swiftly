class GCAnimEnum;

#ifndef _gccanimenum_h
#define _gccanimenum_h

#include "../../../scripting.h"




class GCAnimEnum
{
private:
    void *m_ptr;

public:
    GCAnimEnum() {}
    GCAnimEnum(void *ptr) : m_ptr(ptr) {}

    uint8_t GetValue() const { return GetSchemaValue<uint8_t>(m_ptr, "CAnimEnum", "m_value"); }
    void SetValue(uint8_t value) { SetSchemaValue(m_ptr, "CAnimEnum", "m_value", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif