class GCDamageRecord;

#ifndef _gccdamagerecord_h
#define _gccdamagerecord_h

#include "../../../scripting.h"

#include "../types/GEKillTypes_t.h"
#include "GCCSPlayerPawn.h"
#include "GCCSPlayerController.h"

class GCDamageRecord
{
private:
    void *m_ptr;

public:
    GCDamageRecord() {}
    GCDamageRecord(void *ptr) : m_ptr(ptr) {}

    GCCSPlayerPawn* GetPlayerDamager() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CDamageRecord", "m_PlayerDamager"); }
    void SetPlayerDamager(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerDamager' is not possible.\n"); }
    GCCSPlayerPawn* GetPlayerRecipient() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CDamageRecord", "m_PlayerRecipient"); }
    void SetPlayerRecipient(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerRecipient' is not possible.\n"); }
    GCCSPlayerController* GetPlayerControllerDamager() const { return GetSchemaValue<GCCSPlayerController*>(m_ptr, "CDamageRecord", "m_hPlayerControllerDamager"); }
    void SetPlayerControllerDamager(GCCSPlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerControllerDamager' is not possible.\n"); }
    GCCSPlayerController* GetPlayerControllerRecipient() const { return GetSchemaValue<GCCSPlayerController*>(m_ptr, "CDamageRecord", "m_hPlayerControllerRecipient"); }
    void SetPlayerControllerRecipient(GCCSPlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerControllerRecipient' is not possible.\n"); }
    CUtlString GetPlayerDamagerName() const { return GetSchemaValue<CUtlString>(m_ptr, "CDamageRecord", "m_szPlayerDamagerName"); }
    void SetPlayerDamagerName(CUtlString value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_szPlayerDamagerName", false, value); }
    CUtlString GetPlayerRecipientName() const { return GetSchemaValue<CUtlString>(m_ptr, "CDamageRecord", "m_szPlayerRecipientName"); }
    void SetPlayerRecipientName(CUtlString value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_szPlayerRecipientName", false, value); }
    uint64_t GetDamagerXuid() const { return GetSchemaValue<uint64_t>(m_ptr, "CDamageRecord", "m_DamagerXuid"); }
    void SetDamagerXuid(uint64_t value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_DamagerXuid", false, value); }
    uint64_t GetRecipientXuid() const { return GetSchemaValue<uint64_t>(m_ptr, "CDamageRecord", "m_RecipientXuid"); }
    void SetRecipientXuid(uint64_t value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_RecipientXuid", false, value); }
    int32_t GetDamage() const { return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iDamage"); }
    void SetDamage(int32_t value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_iDamage", false, value); }
    int32_t GetActualHealthRemoved() const { return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iActualHealthRemoved"); }
    void SetActualHealthRemoved(int32_t value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_iActualHealthRemoved", false, value); }
    int32_t GetNumHits() const { return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iNumHits"); }
    void SetNumHits(int32_t value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_iNumHits", false, value); }
    int32_t GetLastBulletUpdate() const { return GetSchemaValue<int32_t>(m_ptr, "CDamageRecord", "m_iLastBulletUpdate"); }
    void SetLastBulletUpdate(int32_t value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_iLastBulletUpdate", false, value); }
    bool GetIsOtherEnemy() const { return GetSchemaValue<bool>(m_ptr, "CDamageRecord", "m_bIsOtherEnemy"); }
    void SetIsOtherEnemy(bool value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_bIsOtherEnemy", false, value); }
    EKillTypes_t GetKillType() const { return GetSchemaValue<EKillTypes_t>(m_ptr, "CDamageRecord", "m_killType"); }
    void SetKillType(EKillTypes_t value) { SetSchemaValue(m_ptr, "CDamageRecord", "m_killType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif