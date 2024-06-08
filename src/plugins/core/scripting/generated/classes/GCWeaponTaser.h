class GCWeaponTaser;

#ifndef _gccweapontaser_h
#define _gccweapontaser_h

#include "../../../scripting.h"




class GCWeaponTaser
{
private:
    void *m_ptr;

public:
    GCWeaponTaser() {}
    GCWeaponTaser(void *ptr) : m_ptr(ptr) {}

    int32_t GetLastAttackTick() const { return GetSchemaValue<int32_t>(m_ptr, "CWeaponTaser", "m_nLastAttackTick"); }
    void SetLastAttackTick(int32_t value) { SetSchemaValue(m_ptr, "CWeaponTaser", "m_nLastAttackTick", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif