class GCBaseCSGrenadeProjectile;

#ifndef _gccbasecsgrenadeprojectile_h
#define _gccbasecsgrenadeprojectile_h

#include "../../../scripting.h"




class GCBaseCSGrenadeProjectile
{
private:
    void *m_ptr;

public:
    GCBaseCSGrenadeProjectile() {}
    GCBaseCSGrenadeProjectile(void *ptr) : m_ptr(ptr) {}

    Vector GetInitialPosition() const { return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialPosition"); }
    void SetInitialPosition(Vector value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialPosition", false, value); }
    Vector GetInitialVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialVelocity"); }
    void SetInitialVelocity(Vector value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vInitialVelocity", false, value); }
    int32_t GetBounces() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nBounces"); }
    void SetBounces(int32_t value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nBounces", false, value); }
    int32_t GetExplodeEffectTickBegin() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nExplodeEffectTickBegin"); }
    void SetExplodeEffectTickBegin(int32_t value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nExplodeEffectTickBegin", false, value); }
    Vector GetExplodeEffectOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecExplodeEffectOrigin"); }
    void SetExplodeEffectOrigin(Vector value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecExplodeEffectOrigin", false, value); }
    uint8_t GetOGSExtraFlags() const { return GetSchemaValue<uint8_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_unOGSExtraFlags"); }
    void SetOGSExtraFlags(uint8_t value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_unOGSExtraFlags", false, value); }
    bool GetDetonationRecorded() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenadeProjectile", "m_bDetonationRecorded"); }
    void SetDetonationRecorded(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_bDetonationRecorded", false, value); }
    uint16_t GetItemIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nItemIndex"); }
    void SetItemIndex(uint16_t value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nItemIndex", false, value); }
    Vector GetOriginalSpawnLocation() const { return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecOriginalSpawnLocation"); }
    void SetOriginalSpawnLocation(Vector value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecOriginalSpawnLocation", false, value); }
    Vector GetGrenadeSpin() const { return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecGrenadeSpin"); }
    void SetGrenadeSpin(Vector value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecGrenadeSpin", false, value); }
    Vector GetLastHitSurfaceNormal() const { return GetSchemaValue<Vector>(m_ptr, "CBaseCSGrenadeProjectile", "m_vecLastHitSurfaceNormal"); }
    void SetLastHitSurfaceNormal(Vector value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_vecLastHitSurfaceNormal", false, value); }
    int32_t GetTicksAtZeroVelocity() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseCSGrenadeProjectile", "m_nTicksAtZeroVelocity"); }
    void SetTicksAtZeroVelocity(int32_t value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_nTicksAtZeroVelocity", false, value); }
    bool GetHasEverHitPlayer() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenadeProjectile", "m_bHasEverHitPlayer"); }
    void SetHasEverHitPlayer(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_bHasEverHitPlayer", false, value); }
    bool GetClearFromPlayers() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenadeProjectile", "m_bClearFromPlayers"); }
    void SetClearFromPlayers(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenadeProjectile", "m_bClearFromPlayers", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif