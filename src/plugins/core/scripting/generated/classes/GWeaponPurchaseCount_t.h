class GWeaponPurchaseCount_t;

#ifndef _gcweaponpurchasecount_t_h
#define _gcweaponpurchasecount_t_h

#include "../../../scripting.h"




class GWeaponPurchaseCount_t
{
private:
    void *m_ptr;

public:
    GWeaponPurchaseCount_t() {}
    GWeaponPurchaseCount_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetItemDefIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "WeaponPurchaseCount_t", "m_nItemDefIndex"); }
    void SetItemDefIndex(uint16_t value) { SetSchemaValue(m_ptr, "WeaponPurchaseCount_t", "m_nItemDefIndex", true, value); }
    uint16_t GetCount() const { return GetSchemaValue<uint16_t>(m_ptr, "WeaponPurchaseCount_t", "m_nCount"); }
    void SetCount(uint16_t value) { SetSchemaValue(m_ptr, "WeaponPurchaseCount_t", "m_nCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif