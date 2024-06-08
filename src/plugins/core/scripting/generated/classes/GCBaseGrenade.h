class GCBaseGrenade;

#ifndef _gccbasegrenade_h
#define _gccbasegrenade_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GCCSPlayerPawn.h"

class GCBaseGrenade
{
private:
    void *m_ptr;

public:
    GCBaseGrenade() {}
    GCBaseGrenade(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnPlayerPickup() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseGrenade", "m_OnPlayerPickup"); }
    void SetOnPlayerPickup(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_OnPlayerPickup", false, value); }
    GCEntityIOOutput GetOnExplode() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBaseGrenade", "m_OnExplode"); }
    void SetOnExplode(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_OnExplode", false, value); }
    bool GetHasWarnedAI() const { return GetSchemaValue<bool>(m_ptr, "CBaseGrenade", "m_bHasWarnedAI"); }
    void SetHasWarnedAI(bool value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_bHasWarnedAI", false, value); }
    bool GetIsSmokeGrenade() const { return GetSchemaValue<bool>(m_ptr, "CBaseGrenade", "m_bIsSmokeGrenade"); }
    void SetIsSmokeGrenade(bool value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_bIsSmokeGrenade", false, value); }
    bool GetIsLive() const { return GetSchemaValue<bool>(m_ptr, "CBaseGrenade", "m_bIsLive"); }
    void SetIsLive(bool value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_bIsLive", false, value); }
    float GetDmgRadius() const { return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_DmgRadius"); }
    void SetDmgRadius(float value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_DmgRadius", false, value); }
    float GetWarnAITime() const { return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_flWarnAITime"); }
    void SetWarnAITime(float value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_flWarnAITime", false, value); }
    float GetDamage() const { return GetSchemaValue<float>(m_ptr, "CBaseGrenade", "m_flDamage"); }
    void SetDamage(float value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_flDamage", false, value); }
    CUtlSymbolLarge GetBounceSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseGrenade", "m_iszBounceSound"); }
    void SetBounceSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_iszBounceSound", false, value); }
    CUtlString GetExplosionSound() const { return GetSchemaValue<CUtlString>(m_ptr, "CBaseGrenade", "m_ExplosionSound"); }
    void SetExplosionSound(CUtlString value) { SetSchemaValue(m_ptr, "CBaseGrenade", "m_ExplosionSound", false, value); }
    GCCSPlayerPawn* GetThrower() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CBaseGrenade", "m_hThrower"); }
    void SetThrower(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Thrower' is not possible.\n"); }
    GCCSPlayerPawn* GetOriginalThrower() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CBaseGrenade", "m_hOriginalThrower"); }
    void SetOriginalThrower(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginalThrower' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif