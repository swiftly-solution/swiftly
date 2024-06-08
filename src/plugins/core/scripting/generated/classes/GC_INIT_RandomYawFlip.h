class GC_INIT_RandomYawFlip;

#ifndef _gcc_init_randomyawflip_h
#define _gcc_init_randomyawflip_h

#include "../../../scripting.h"




class GC_INIT_RandomYawFlip
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomYawFlip() {}
    GC_INIT_RandomYawFlip(void *ptr) : m_ptr(ptr) {}

    float GetPercent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomYawFlip", "m_flPercent"); }
    void SetPercent(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomYawFlip", "m_flPercent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif