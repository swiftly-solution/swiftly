class GServerAuthoritativeWeaponSlot_t;

#ifndef _gcserverauthoritativeweaponslot_t_h
#define _gcserverauthoritativeweaponslot_t_h

#include "../../../scripting.h"




class GServerAuthoritativeWeaponSlot_t
{
private:
    void *m_ptr;

public:
    GServerAuthoritativeWeaponSlot_t() {}
    GServerAuthoritativeWeaponSlot_t(void *ptr) : m_ptr(ptr) {}

    uint16_t GetClass() const { return GetSchemaValue<uint16_t>(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unClass"); }
    void SetClass(uint16_t value) { SetSchemaValue(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unClass", true, value); }
    uint16_t GetSlot() const { return GetSchemaValue<uint16_t>(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unSlot"); }
    void SetSlot(uint16_t value) { SetSchemaValue(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unSlot", true, value); }
    uint16_t GetItemDefIdx() const { return GetSchemaValue<uint16_t>(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unItemDefIdx"); }
    void SetItemDefIdx(uint16_t value) { SetSchemaValue(m_ptr, "ServerAuthoritativeWeaponSlot_t", "unItemDefIdx", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif