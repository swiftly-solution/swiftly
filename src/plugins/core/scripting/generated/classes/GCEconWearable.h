class GCEconWearable;

#ifndef _gcceconwearable_h
#define _gcceconwearable_h

#include "../../../scripting.h"




class GCEconWearable
{
private:
    void *m_ptr;

public:
    GCEconWearable() {}
    GCEconWearable(void *ptr) : m_ptr(ptr) {}

    int32_t GetForceSkin() const { return GetSchemaValue<int32_t>(m_ptr, "CEconWearable", "m_nForceSkin"); }
    void SetForceSkin(int32_t value) { SetSchemaValue(m_ptr, "CEconWearable", "m_nForceSkin", false, value); }
    bool GetAlwaysAllow() const { return GetSchemaValue<bool>(m_ptr, "CEconWearable", "m_bAlwaysAllow"); }
    void SetAlwaysAllow(bool value) { SetSchemaValue(m_ptr, "CEconWearable", "m_bAlwaysAllow", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif