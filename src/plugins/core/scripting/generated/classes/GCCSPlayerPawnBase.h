class GCCSPlayerPawnBase;

#ifndef _gcccsplayerpawnbase_h
#define _gcccsplayerpawnbase_h

#include "../../../scripting.h"

#include "../types/GCSPlayerState.h"
#include "GCTouchExpansionComponent.h"
#include "GCCSPlayer_PingServices.h"
#include "GCPlayer_ViewModelServices.h"
#include "GCCSPlayerController.h"

class GCCSPlayerPawnBase
{
private:
    void *m_ptr;

public:
    GCCSPlayerPawnBase() {}
    GCCSPlayerPawnBase(void *ptr) : m_ptr(ptr) {}

    GCTouchExpansionComponent GetCTouchExpansionComponent() const { return GetSchemaValue<GCTouchExpansionComponent>(m_ptr, "CCSPlayerPawnBase", "m_CTouchExpansionComponent"); }
    void SetCTouchExpansionComponent(GCTouchExpansionComponent value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_CTouchExpansionComponent", false, value); }
    GCCSPlayer_PingServices* GetPingServices() const { return GetSchemaValue<GCCSPlayer_PingServices*>(m_ptr, "CCSPlayerPawnBase", "m_pPingServices"); }
    void SetPingServices(GCCSPlayer_PingServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PingServices' is not possible.\n"); }
    GCPlayer_ViewModelServices* GetViewModelServices() const { return GetSchemaValue<GCPlayer_ViewModelServices*>(m_ptr, "CCSPlayerPawnBase", "m_pViewModelServices"); }
    void SetViewModelServices(GCPlayer_ViewModelServices* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ViewModelServices' is not possible.\n"); }
    CSPlayerState GetPlayerState() const { return GetSchemaValue<CSPlayerState>(m_ptr, "CCSPlayerPawnBase", "m_iPlayerState"); }
    void SetPlayerState(CSPlayerState value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_iPlayerState", false, value); }
    bool GetRespawning() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bRespawning"); }
    void SetRespawning(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bRespawning", false, value); }
    bool GetGunGameImmunity() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bGunGameImmunity"); }
    void SetGunGameImmunity(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bGunGameImmunity", false, value); }
    float GetMolotovDamageTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_fMolotovDamageTime"); }
    void SetMolotovDamageTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_fMolotovDamageTime", false, value); }
    bool GetHasMovedSinceSpawn() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bHasMovedSinceSpawn"); }
    void SetHasMovedSinceSpawn(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bHasMovedSinceSpawn", false, value); }
    int32_t GetNumSpawns() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawnBase", "m_iNumSpawns"); }
    void SetNumSpawns(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_iNumSpawns", false, value); }
    float GetIdleTimeSinceLastAction() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flIdleTimeSinceLastAction"); }
    void SetIdleTimeSinceLastAction(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flIdleTimeSinceLastAction", false, value); }
    float GetNextRadarUpdateTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_fNextRadarUpdateTime"); }
    void SetNextRadarUpdateTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_fNextRadarUpdateTime", false, value); }
    float GetFlashDuration() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flFlashDuration"); }
    void SetFlashDuration(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flFlashDuration", false, value); }
    float GetFlashMaxAlpha() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flFlashMaxAlpha"); }
    void SetFlashMaxAlpha(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flFlashMaxAlpha", false, value); }
    float GetProgressBarStartTime() const { return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flProgressBarStartTime"); }
    void SetProgressBarStartTime(float value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flProgressBarStartTime", false, value); }
    int32_t GetProgressBarDuration() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawnBase", "m_iProgressBarDuration"); }
    void SetProgressBarDuration(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_iProgressBarDuration", false, value); }
    QAngle GetEyeAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawnBase", "m_angEyeAngles"); }
    void SetEyeAngles(QAngle value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_angEyeAngles", false, value); }
    int32_t GetNumEnemiesAtRoundStart() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawnBase", "m_NumEnemiesAtRoundStart"); }
    void SetNumEnemiesAtRoundStart(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_NumEnemiesAtRoundStart", false, value); }
    bool GetWasNotKilledNaturally() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_wasNotKilledNaturally"); }
    void SetWasNotKilledNaturally(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_wasNotKilledNaturally", false, value); }
    bool GetCommittingSuicideOnTeamChange() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bCommittingSuicideOnTeamChange"); }
    void SetCommittingSuicideOnTeamChange(bool value) { SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bCommittingSuicideOnTeamChange", false, value); }
    GCCSPlayerController* GetOriginalController() const { return GetSchemaValue<GCCSPlayerController*>(m_ptr, "CCSPlayerPawnBase", "m_hOriginalController"); }
    void SetOriginalController(GCCSPlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginalController' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif