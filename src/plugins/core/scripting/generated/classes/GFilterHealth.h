class GFilterHealth;

#ifndef _gcfilterhealth_h
#define _gcfilterhealth_h

#include "../../../scripting.h"




class GFilterHealth
{
private:
    void *m_ptr;

public:
    GFilterHealth() {}
    GFilterHealth(void *ptr) : m_ptr(ptr) {}

    bool GetAdrenalineActive() const { return GetSchemaValue<bool>(m_ptr, "FilterHealth", "m_bAdrenalineActive"); }
    void SetAdrenalineActive(bool value) { SetSchemaValue(m_ptr, "FilterHealth", "m_bAdrenalineActive", false, value); }
    int32_t GetHealthMin() const { return GetSchemaValue<int32_t>(m_ptr, "FilterHealth", "m_iHealthMin"); }
    void SetHealthMin(int32_t value) { SetSchemaValue(m_ptr, "FilterHealth", "m_iHealthMin", false, value); }
    int32_t GetHealthMax() const { return GetSchemaValue<int32_t>(m_ptr, "FilterHealth", "m_iHealthMax"); }
    void SetHealthMax(int32_t value) { SetSchemaValue(m_ptr, "FilterHealth", "m_iHealthMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif