class GCBasePlayerWeapon;

#ifndef _gccbaseplayerweapon_h
#define _gccbaseplayerweapon_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCBasePlayerWeapon
{
private:
    void *m_ptr;

public:
    GCBasePlayerWeapon() {}
    GCBasePlayerWeapon(void *ptr) : m_ptr(ptr) {}

    float GetNextPrimaryAttackTickRatio() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerWeapon", "m_flNextPrimaryAttackTickRatio"); }
    void SetNextPrimaryAttackTickRatio(float value) { SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_flNextPrimaryAttackTickRatio", false, value); }
    float GetNextSecondaryAttackTickRatio() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerWeapon", "m_flNextSecondaryAttackTickRatio"); }
    void SetNextSecondaryAttackTickRatio(float value) { SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_flNextSecondaryAttackTickRatio", false, value); }
    int32_t GetClip1() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeapon", "m_iClip1"); }
    void SetClip1(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_iClip1", false, value); }
    int32_t GetClip2() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeapon", "m_iClip2"); }
    void SetClip2(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_iClip2", false, value); }
    std::vector<int32_t> GetReserveAmmo() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CBasePlayerWeapon", "m_pReserveAmmo"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetReserveAmmo(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CBasePlayerWeapon", "m_pReserveAmmo"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_pReserveAmmo", false, outValue); }
    GCEntityIOOutput GetOnPlayerUse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBasePlayerWeapon", "m_OnPlayerUse"); }
    void SetOnPlayerUse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBasePlayerWeapon", "m_OnPlayerUse", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif