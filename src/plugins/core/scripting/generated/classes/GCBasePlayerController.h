class GCBasePlayerController;

#ifndef _gccbaseplayercontroller_h
#define _gccbaseplayercontroller_h

#include "../../../scripting.h"

#include "../types/GPlayerConnectedState.h"
#include "../types/GChatIgnoreType_t.h"
#include "GCBasePlayerPawn.h"
#include "GCBasePlayerController.h"

class GCBasePlayerController
{
private:
    void *m_ptr;

public:
    GCBasePlayerController() {}
    GCBasePlayerController(void *ptr) : m_ptr(ptr) {}

    uint64_t GetInButtonsWhichAreToggles() const { return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerController", "m_nInButtonsWhichAreToggles"); }
    void SetInButtonsWhichAreToggles(uint64_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_nInButtonsWhichAreToggles", false, value); }
    uint32_t GetTickBase() const { return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerController", "m_nTickBase"); }
    void SetTickBase(uint32_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_nTickBase", false, value); }
    GCBasePlayerPawn* GetPawn() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CBasePlayerController", "m_hPawn"); }
    void SetPawn(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pawn' is not possible.\n"); }
    bool GetKnownTeamMismatch() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bKnownTeamMismatch"); }
    void SetKnownTeamMismatch(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bKnownTeamMismatch", false, value); }
    int32_t GetSplitScreenSlot() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nSplitScreenSlot"); }
    void SetSplitScreenSlot(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_nSplitScreenSlot", false, value); }
    GCBasePlayerController* GetSplitOwner() const { return GetSchemaValue<GCBasePlayerController*>(m_ptr, "CBasePlayerController", "m_hSplitOwner"); }
    void SetSplitOwner(GCBasePlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SplitOwner' is not possible.\n"); }
    bool GetIsHLTV() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bIsHLTV"); }
    void SetIsHLTV(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bIsHLTV", false, value); }
    PlayerConnectedState GetConnected() const { return GetSchemaValue<PlayerConnectedState>(m_ptr, "CBasePlayerController", "m_iConnected"); }
    void SetConnected(PlayerConnectedState value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_iConnected", false, value); }
    std::string GetPlayerName() const { return GetSchemaValue<char*>(m_ptr, "CBasePlayerController", "m_iszPlayerName"); }
    void SetPlayerName(std::string value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_iszPlayerName", false, value); }
    CUtlString GetNetworkIDString() const { return GetSchemaValue<CUtlString>(m_ptr, "CBasePlayerController", "m_szNetworkIDString"); }
    void SetNetworkIDString(CUtlString value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_szNetworkIDString", false, value); }
    float GetLerpTime() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerController", "m_fLerpTime"); }
    void SetLerpTime(float value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_fLerpTime", false, value); }
    bool GetLagCompensation() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bLagCompensation"); }
    void SetLagCompensation(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bLagCompensation", false, value); }
    bool GetPredict() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bPredict"); }
    void SetPredict(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bPredict", false, value); }
    bool GetAutoKickDisabled() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bAutoKickDisabled"); }
    void SetAutoKickDisabled(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bAutoKickDisabled", false, value); }
    bool GetIsLowViolence() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bIsLowViolence"); }
    void SetIsLowViolence(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bIsLowViolence", false, value); }
    bool GetGamePaused() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bGamePaused"); }
    void SetGamePaused(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bGamePaused", false, value); }
    int32_t GetLastRealCommandNumberExecuted() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nLastRealCommandNumberExecuted"); }
    void SetLastRealCommandNumberExecuted(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_nLastRealCommandNumberExecuted", false, value); }
    int32_t GetLastLateCommandExecuted() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nLastLateCommandExecuted"); }
    void SetLastLateCommandExecuted(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_nLastLateCommandExecuted", false, value); }
    ChatIgnoreType_t GetIgnoreGlobalChat() const { return GetSchemaValue<ChatIgnoreType_t>(m_ptr, "CBasePlayerController", "m_iIgnoreGlobalChat"); }
    void SetIgnoreGlobalChat(ChatIgnoreType_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_iIgnoreGlobalChat", false, value); }
    float GetLastPlayerTalkTime() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerController", "m_flLastPlayerTalkTime"); }
    void SetLastPlayerTalkTime(float value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_flLastPlayerTalkTime", false, value); }
    float GetLastEntitySteadyState() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerController", "m_flLastEntitySteadyState"); }
    void SetLastEntitySteadyState(float value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_flLastEntitySteadyState", false, value); }
    int32_t GetAvailableEntitySteadyState() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nAvailableEntitySteadyState"); }
    void SetAvailableEntitySteadyState(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_nAvailableEntitySteadyState", false, value); }
    bool GetHasAnySteadyStateEnts() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bHasAnySteadyStateEnts"); }
    void SetHasAnySteadyStateEnts(bool value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_bHasAnySteadyStateEnts", false, value); }
    uint64_t GetSteamID() const { return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerController", "m_steamID"); }
    void SetSteamID(uint64_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_steamID", false, value); }
    uint32_t GetDesiredFOV() const { return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerController", "m_iDesiredFOV"); }
    void SetDesiredFOV(uint32_t value) { SetSchemaValue(m_ptr, "CBasePlayerController", "m_iDesiredFOV", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif