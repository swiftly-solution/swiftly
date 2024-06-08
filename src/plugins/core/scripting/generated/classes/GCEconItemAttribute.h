class GCEconItemAttribute;

#ifndef _gcceconitemattribute_h
#define _gcceconitemattribute_h

#include "../../../scripting.h"




class GCEconItemAttribute
{
private:
    void *m_ptr;

public:
    GCEconItemAttribute() {}
    GCEconItemAttribute(void *ptr) : m_ptr(ptr) {}

    uint16_t GetAttributeDefinitionIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CEconItemAttribute", "m_iAttributeDefinitionIndex"); }
    void SetAttributeDefinitionIndex(uint16_t value) { SetSchemaValue(m_ptr, "CEconItemAttribute", "m_iAttributeDefinitionIndex", false, value); }
    float GetValue() const { return GetSchemaValue<float>(m_ptr, "CEconItemAttribute", "m_flValue"); }
    void SetValue(float value) { SetSchemaValue(m_ptr, "CEconItemAttribute", "m_flValue", false, value); }
    float GetInitialValue() const { return GetSchemaValue<float>(m_ptr, "CEconItemAttribute", "m_flInitialValue"); }
    void SetInitialValue(float value) { SetSchemaValue(m_ptr, "CEconItemAttribute", "m_flInitialValue", false, value); }
    int32_t GetRefundableCurrency() const { return GetSchemaValue<int32_t>(m_ptr, "CEconItemAttribute", "m_nRefundableCurrency"); }
    void SetRefundableCurrency(int32_t value) { SetSchemaValue(m_ptr, "CEconItemAttribute", "m_nRefundableCurrency", false, value); }
    bool GetSetBonus() const { return GetSchemaValue<bool>(m_ptr, "CEconItemAttribute", "m_bSetBonus"); }
    void SetSetBonus(bool value) { SetSchemaValue(m_ptr, "CEconItemAttribute", "m_bSetBonus", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif