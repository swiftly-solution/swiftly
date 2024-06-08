class GSellbackPurchaseEntry_t;

#ifndef _gcsellbackpurchaseentry_t_h
#define _gcsellbackpurchaseentry_t_h

#include "../../../scripting.h"


#include "GCEntityInstance.h"

class GSellbackPurchaseEntry_t
{
private:
    void *m_ptr;

public:
    GSellbackPurchaseEntry_t() {}
    GSellbackPurchaseEntry_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetDefIdx() const { return GetSchemaValue<uint16_t>(m_ptr, "SellbackPurchaseEntry_t", "m_unDefIdx"); }
    void SetDefIdx(uint16_t value) { SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_unDefIdx", true, value); }
    int32_t GetCost() const { return GetSchemaValue<int32_t>(m_ptr, "SellbackPurchaseEntry_t", "m_nCost"); }
    void SetCost(int32_t value) { SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_nCost", true, value); }
    int32_t GetPrevArmor() const { return GetSchemaValue<int32_t>(m_ptr, "SellbackPurchaseEntry_t", "m_nPrevArmor"); }
    void SetPrevArmor(int32_t value) { SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_nPrevArmor", true, value); }
    bool GetPrevHelmet() const { return GetSchemaValue<bool>(m_ptr, "SellbackPurchaseEntry_t", "m_bPrevHelmet"); }
    void SetPrevHelmet(bool value) { SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_bPrevHelmet", true, value); }
    GCEntityInstance* GetItem() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "SellbackPurchaseEntry_t", "m_hItem"); }
    void SetItem(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Item' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif