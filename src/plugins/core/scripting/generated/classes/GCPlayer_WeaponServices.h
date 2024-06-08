class GCPlayer_WeaponServices;

#ifndef _gccplayer_weaponservices_h
#define _gccplayer_weaponservices_h

#include "../../../scripting.h"


#include "GCBasePlayerWeapon.h"

class GCPlayer_WeaponServices
{
private:
    void *m_ptr;

public:
    GCPlayer_WeaponServices() {}
    GCPlayer_WeaponServices(void *ptr) : m_ptr(ptr) {}

    GCBasePlayerWeapon* GetMyWeapons() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CPlayer_WeaponServices", "m_hMyWeapons"); }
    void SetMyWeapons(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'MyWeapons' is not possible.\n"); }
    GCBasePlayerWeapon* GetActiveWeapon() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CPlayer_WeaponServices", "m_hActiveWeapon"); }
    void SetActiveWeapon(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ActiveWeapon' is not possible.\n"); }
    GCBasePlayerWeapon* GetLastWeapon() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CPlayer_WeaponServices", "m_hLastWeapon"); }
    void SetLastWeapon(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastWeapon' is not possible.\n"); }
    std::vector<uint16_t> GetAmmo() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CPlayer_WeaponServices", "m_iAmmo"); std::vector<uint16_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetAmmo(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "CPlayer_WeaponServices", "m_iAmmo"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayer_WeaponServices", "m_iAmmo", false, outValue); }
    bool GetPreventWeaponPickup() const { return GetSchemaValue<bool>(m_ptr, "CPlayer_WeaponServices", "m_bPreventWeaponPickup"); }
    void SetPreventWeaponPickup(bool value) { SetSchemaValue(m_ptr, "CPlayer_WeaponServices", "m_bPreventWeaponPickup", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif