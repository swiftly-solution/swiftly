class GGameAmmoTypeInfo_t;

#ifndef _gcgameammotypeinfo_t_h
#define _gcgameammotypeinfo_t_h

#include "../../../scripting.h"




class GGameAmmoTypeInfo_t
{
private:
    void *m_ptr;

public:
    GGameAmmoTypeInfo_t() {}
    GGameAmmoTypeInfo_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetBuySize() const { return GetSchemaValue<int32_t>(m_ptr, "GameAmmoTypeInfo_t", "m_nBuySize"); }
    void SetBuySize(int32_t value) { SetSchemaValue(m_ptr, "GameAmmoTypeInfo_t", "m_nBuySize", true, value); }
    int32_t GetCost() const { return GetSchemaValue<int32_t>(m_ptr, "GameAmmoTypeInfo_t", "m_nCost"); }
    void SetCost(int32_t value) { SetSchemaValue(m_ptr, "GameAmmoTypeInfo_t", "m_nCost", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif