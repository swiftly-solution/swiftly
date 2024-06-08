class GCInferno;

#ifndef _gccinferno_h
#define _gccinferno_h

#include "../../../scripting.h"


#include "GExtent.h"
#include "GCountdownTimer.h"
#include "GIntervalTimer.h"

class GCInferno
{
private:
    void *m_ptr;

public:
    GCInferno() {}
    GCInferno(void *ptr) : m_ptr(ptr) {}

    std::vector<Vector> GetFirePositions() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_firePositions"); std::vector<Vector> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetFirePositions(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_firePositions"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_firePositions", false, outValue); }
    std::vector<Vector> GetFireParentPositions() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_fireParentPositions"); std::vector<Vector> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetFireParentPositions(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_fireParentPositions"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_fireParentPositions", false, outValue); }
    std::vector<bool> GetFireIsBurning() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CInferno", "m_bFireIsBurning"); std::vector<bool> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetFireIsBurning(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CInferno", "m_bFireIsBurning"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_bFireIsBurning", false, outValue); }
    std::vector<Vector> GetBurnNormal() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_BurnNormal"); std::vector<Vector> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetBurnNormal(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CInferno", "m_BurnNormal"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInferno", "m_BurnNormal", false, outValue); }
    int32_t GetFireCount() const { return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_fireCount"); }
    void SetFireCount(int32_t value) { SetSchemaValue(m_ptr, "CInferno", "m_fireCount", false, value); }
    int32_t GetInfernoType() const { return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nInfernoType"); }
    void SetInfernoType(int32_t value) { SetSchemaValue(m_ptr, "CInferno", "m_nInfernoType", false, value); }
    int32_t GetFireEffectTickBegin() const { return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nFireEffectTickBegin"); }
    void SetFireEffectTickBegin(int32_t value) { SetSchemaValue(m_ptr, "CInferno", "m_nFireEffectTickBegin", false, value); }
    float GetFireLifetime() const { return GetSchemaValue<float>(m_ptr, "CInferno", "m_nFireLifetime"); }
    void SetFireLifetime(float value) { SetSchemaValue(m_ptr, "CInferno", "m_nFireLifetime", false, value); }
    bool GetInPostEffectTime() const { return GetSchemaValue<bool>(m_ptr, "CInferno", "m_bInPostEffectTime"); }
    void SetInPostEffectTime(bool value) { SetSchemaValue(m_ptr, "CInferno", "m_bInPostEffectTime", false, value); }
    int32_t GetFiresExtinguishCount() const { return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nFiresExtinguishCount"); }
    void SetFiresExtinguishCount(int32_t value) { SetSchemaValue(m_ptr, "CInferno", "m_nFiresExtinguishCount", false, value); }
    bool GetWasCreatedInSmoke() const { return GetSchemaValue<bool>(m_ptr, "CInferno", "m_bWasCreatedInSmoke"); }
    void SetWasCreatedInSmoke(bool value) { SetSchemaValue(m_ptr, "CInferno", "m_bWasCreatedInSmoke", false, value); }
    GExtent GetExtent() const { return GetSchemaValue<GExtent>(m_ptr, "CInferno", "m_extent"); }
    void SetExtent(GExtent value) { SetSchemaValue(m_ptr, "CInferno", "m_extent", false, value); }
    GCountdownTimer GetDamageTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CInferno", "m_damageTimer"); }
    void SetDamageTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CInferno", "m_damageTimer", false, value); }
    GCountdownTimer GetDamageRampTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CInferno", "m_damageRampTimer"); }
    void SetDamageRampTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CInferno", "m_damageRampTimer", false, value); }
    Vector GetSplashVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_splashVelocity"); }
    void SetSplashVelocity(Vector value) { SetSchemaValue(m_ptr, "CInferno", "m_splashVelocity", false, value); }
    Vector GetInitialSplashVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_InitialSplashVelocity"); }
    void SetInitialSplashVelocity(Vector value) { SetSchemaValue(m_ptr, "CInferno", "m_InitialSplashVelocity", false, value); }
    Vector GetStartPos() const { return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_startPos"); }
    void SetStartPos(Vector value) { SetSchemaValue(m_ptr, "CInferno", "m_startPos", false, value); }
    Vector GetOriginalSpawnLocation() const { return GetSchemaValue<Vector>(m_ptr, "CInferno", "m_vecOriginalSpawnLocation"); }
    void SetOriginalSpawnLocation(Vector value) { SetSchemaValue(m_ptr, "CInferno", "m_vecOriginalSpawnLocation", false, value); }
    GIntervalTimer GetActiveTimer() const { return GetSchemaValue<GIntervalTimer>(m_ptr, "CInferno", "m_activeTimer"); }
    void SetActiveTimer(GIntervalTimer value) { SetSchemaValue(m_ptr, "CInferno", "m_activeTimer", false, value); }
    int32_t GetFireSpawnOffset() const { return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_fireSpawnOffset"); }
    void SetFireSpawnOffset(int32_t value) { SetSchemaValue(m_ptr, "CInferno", "m_fireSpawnOffset", false, value); }
    int32_t GetMaxFlames() const { return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nMaxFlames"); }
    void SetMaxFlames(int32_t value) { SetSchemaValue(m_ptr, "CInferno", "m_nMaxFlames", false, value); }
    int32_t GetSpreadCount() const { return GetSchemaValue<int32_t>(m_ptr, "CInferno", "m_nSpreadCount"); }
    void SetSpreadCount(int32_t value) { SetSchemaValue(m_ptr, "CInferno", "m_nSpreadCount", false, value); }
    GCountdownTimer GetBookkeepingTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CInferno", "m_BookkeepingTimer"); }
    void SetBookkeepingTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CInferno", "m_BookkeepingTimer", false, value); }
    GCountdownTimer GetNextSpreadTimer() const { return GetSchemaValue<GCountdownTimer>(m_ptr, "CInferno", "m_NextSpreadTimer"); }
    void SetNextSpreadTimer(GCountdownTimer value) { SetSchemaValue(m_ptr, "CInferno", "m_NextSpreadTimer", false, value); }
    uint16_t GetSourceItemDefIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CInferno", "m_nSourceItemDefIndex"); }
    void SetSourceItemDefIndex(uint16_t value) { SetSchemaValue(m_ptr, "CInferno", "m_nSourceItemDefIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif