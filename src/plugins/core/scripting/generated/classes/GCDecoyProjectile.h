class GCDecoyProjectile;

#ifndef _gccdecoyprojectile_h
#define _gccdecoyprojectile_h

#include "../../../scripting.h"




class GCDecoyProjectile
{
private:
    void *m_ptr;

public:
    GCDecoyProjectile() {}
    GCDecoyProjectile(void *ptr) : m_ptr(ptr) {}

    int32_t GetDecoyShotTick() const { return GetSchemaValue<int32_t>(m_ptr, "CDecoyProjectile", "m_nDecoyShotTick"); }
    void SetDecoyShotTick(int32_t value) { SetSchemaValue(m_ptr, "CDecoyProjectile", "m_nDecoyShotTick", false, value); }
    int32_t GetShotsRemaining() const { return GetSchemaValue<int32_t>(m_ptr, "CDecoyProjectile", "m_shotsRemaining"); }
    void SetShotsRemaining(int32_t value) { SetSchemaValue(m_ptr, "CDecoyProjectile", "m_shotsRemaining", false, value); }
    uint16_t GetDecoyWeaponDefIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CDecoyProjectile", "m_decoyWeaponDefIndex"); }
    void SetDecoyWeaponDefIndex(uint16_t value) { SetSchemaValue(m_ptr, "CDecoyProjectile", "m_decoyWeaponDefIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif