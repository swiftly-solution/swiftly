class GCPlantedC4;

#ifndef _gccplantedc4_h
#define _gccplantedc4_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"
#include "GEntitySpottedState_t.h"
#include "GCCSPlayerPawn.h"
#include "GCBaseEntity.h"

class GCPlantedC4
{
private:
    void *m_ptr;

public:
    GCPlantedC4() {}
    GCPlantedC4(void *ptr) : m_ptr(ptr) {}

    bool GetBombTicking() const { return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bBombTicking"); }
    void SetBombTicking(bool value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_bBombTicking", false, value); }
    int32_t GetBombSite() const { return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_nBombSite"); }
    void SetBombSite(int32_t value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_nBombSite", false, value); }
    int32_t GetSourceSoundscapeHash() const { return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_nSourceSoundscapeHash"); }
    void SetSourceSoundscapeHash(int32_t value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_nSourceSoundscapeHash", false, value); }
    GCEntityIOOutput GetOnBombDefused() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPlantedC4", "m_OnBombDefused"); }
    void SetOnBombDefused(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_OnBombDefused", false, value); }
    GCEntityIOOutput GetOnBombBeginDefuse() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPlantedC4", "m_OnBombBeginDefuse"); }
    void SetOnBombBeginDefuse(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_OnBombBeginDefuse", false, value); }
    GCEntityIOOutput GetOnBombDefuseAborted() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPlantedC4", "m_OnBombDefuseAborted"); }
    void SetOnBombDefuseAborted(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_OnBombDefuseAborted", false, value); }
    bool GetCannotBeDefused() const { return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bCannotBeDefused"); }
    void SetCannotBeDefused(bool value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_bCannotBeDefused", false, value); }
    GEntitySpottedState_t GetEntitySpottedState() const { return GetSchemaValue<GEntitySpottedState_t>(m_ptr, "CPlantedC4", "m_entitySpottedState"); }
    void SetEntitySpottedState(GEntitySpottedState_t value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_entitySpottedState", false, value); }
    int32_t GetSpotRules() const { return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_nSpotRules"); }
    void SetSpotRules(int32_t value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_nSpotRules", false, value); }
    bool GetTrainingPlacedByPlayer() const { return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bTrainingPlacedByPlayer"); }
    void SetTrainingPlacedByPlayer(bool value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_bTrainingPlacedByPlayer", false, value); }
    bool GetHasExploded() const { return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bHasExploded"); }
    void SetHasExploded(bool value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_bHasExploded", false, value); }
    float GetTimerLength() const { return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flTimerLength"); }
    void SetTimerLength(float value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_flTimerLength", false, value); }
    bool GetBeingDefused() const { return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bBeingDefused"); }
    void SetBeingDefused(bool value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_bBeingDefused", false, value); }
    float GetDefuseLength() const { return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flDefuseLength"); }
    void SetDefuseLength(float value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_flDefuseLength", false, value); }
    bool GetBombDefused() const { return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bBombDefused"); }
    void SetBombDefused(bool value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_bBombDefused", false, value); }
    GCCSPlayerPawn* GetBombDefuser() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CPlantedC4", "m_hBombDefuser"); }
    void SetBombDefuser(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'BombDefuser' is not possible.\n"); }
    GCBaseEntity* GetControlPanel() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPlantedC4", "m_hControlPanel"); }
    void SetControlPanel(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ControlPanel' is not possible.\n"); }
    int32_t GetProgressBarTime() const { return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_iProgressBarTime"); }
    void SetProgressBarTime(int32_t value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_iProgressBarTime", false, value); }
    bool GetVoiceAlertFired() const { return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bVoiceAlertFired"); }
    void SetVoiceAlertFired(bool value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_bVoiceAlertFired", false, value); }
    std::vector<bool> GetVoiceAlertPlayed() const { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CPlantedC4", "m_bVoiceAlertPlayed"); std::vector<bool> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetVoiceAlertPlayed(std::vector<bool> value) { bool* outValue = GetSchemaValue<bool*>(m_ptr, "CPlantedC4", "m_bVoiceAlertPlayed"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlantedC4", "m_bVoiceAlertPlayed", false, outValue); }
    QAngle GetCatchUpToPlayerEye() const { return GetSchemaValue<QAngle>(m_ptr, "CPlantedC4", "m_angCatchUpToPlayerEye"); }
    void SetCatchUpToPlayerEye(QAngle value) { SetSchemaValue(m_ptr, "CPlantedC4", "m_angCatchUpToPlayerEye", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif