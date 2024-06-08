class GWeaponPurchaseTracker_t;

#ifndef _gcweaponpurchasetracker_t_h
#define _gcweaponpurchasetracker_t_h

#include "../../../scripting.h"


#include "GWeaponPurchaseCount_t.h"

class GWeaponPurchaseTracker_t
{
private:
    void *m_ptr;

public:
    GWeaponPurchaseTracker_t() {}
    GWeaponPurchaseTracker_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GWeaponPurchaseCount_t> GetWeaponPurchases() const { CUtlVector<GWeaponPurchaseCount_t>* vec = GetSchemaValue<CUtlVector<GWeaponPurchaseCount_t>*>(m_ptr, "WeaponPurchaseTracker_t", "m_weaponPurchases"); std::vector<GWeaponPurchaseCount_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeaponPurchases(std::vector<GWeaponPurchaseCount_t> value) { SetSchemaValueCUtlVector<GWeaponPurchaseCount_t>(m_ptr, "WeaponPurchaseTracker_t", "m_weaponPurchases", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif