class GCWeaponShield;

#ifndef _gccweaponshield_h
#define _gccweaponshield_h

#include "../../../scripting.h"




class GCWeaponShield
{
private:
    void *m_ptr;

public:
    GCWeaponShield() {}
    GCWeaponShield(void *ptr) : m_ptr(ptr) {}

    float GetBulletDamageAbsorbed() const { return GetSchemaValue<float>(m_ptr, "CWeaponShield", "m_flBulletDamageAbsorbed"); }
    void SetBulletDamageAbsorbed(float value) { SetSchemaValue(m_ptr, "CWeaponShield", "m_flBulletDamageAbsorbed", false, value); }
    float GetDisplayHealth() const { return GetSchemaValue<float>(m_ptr, "CWeaponShield", "m_flDisplayHealth"); }
    void SetDisplayHealth(float value) { SetSchemaValue(m_ptr, "CWeaponShield", "m_flDisplayHealth", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif