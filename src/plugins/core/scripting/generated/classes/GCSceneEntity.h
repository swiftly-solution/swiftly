class GCSceneEntity;

#ifndef _gccsceneentity_h
#define _gccsceneentity_h

#include "../../../scripting.h"

#include "../types/GSceneOnPlayerDeath_t.h"
#include "GCBaseEntity.h"
#include "GCBaseFlex.h"
#include "GCEntityIOOutput.h"
#include "GCSceneEntity.h"

class GCSceneEntity
{
private:
    void *m_ptr;

public:
    GCSceneEntity() {}
    GCSceneEntity(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetSceneFile() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszSceneFile"); }
    void SetSceneFile(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszSceneFile", false, value); }
    CUtlSymbolLarge GetResumeSceneFile() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszResumeSceneFile"); }
    void SetResumeSceneFile(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszResumeSceneFile", false, value); }
    CUtlSymbolLarge GetTarget1() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget1"); }
    void SetTarget1(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget1", false, value); }
    CUtlSymbolLarge GetTarget2() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget2"); }
    void SetTarget2(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget2", false, value); }
    CUtlSymbolLarge GetTarget3() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget3"); }
    void SetTarget3(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget3", false, value); }
    CUtlSymbolLarge GetTarget4() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget4"); }
    void SetTarget4(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget4", false, value); }
    CUtlSymbolLarge GetTarget5() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget5"); }
    void SetTarget5(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget5", false, value); }
    CUtlSymbolLarge GetTarget6() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget6"); }
    void SetTarget6(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget6", false, value); }
    CUtlSymbolLarge GetTarget7() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget7"); }
    void SetTarget7(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget7", false, value); }
    CUtlSymbolLarge GetTarget8() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget8"); }
    void SetTarget8(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget8", false, value); }
    GCBaseEntity* GetTarget11() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget1"); }
    void SetTarget11(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target11' is not possible.\n"); }
    GCBaseEntity* GetTarget21() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget2"); }
    void SetTarget21(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target21' is not possible.\n"); }
    GCBaseEntity* GetTarget31() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget3"); }
    void SetTarget31(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target31' is not possible.\n"); }
    GCBaseEntity* GetTarget41() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget4"); }
    void SetTarget41(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target41' is not possible.\n"); }
    GCBaseEntity* GetTarget51() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget5"); }
    void SetTarget51(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target51' is not possible.\n"); }
    GCBaseEntity* GetTarget61() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget6"); }
    void SetTarget61(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target61' is not possible.\n"); }
    GCBaseEntity* GetTarget71() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget7"); }
    void SetTarget71(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target71' is not possible.\n"); }
    GCBaseEntity* GetTarget81() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hTarget8"); }
    void SetTarget81(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target81' is not possible.\n"); }
    CUtlSymbolLarge GetTargetAttachment() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_sTargetAttachment"); }
    void SetTargetAttachment(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_sTargetAttachment", false, value); }
    bool GetIsPlayingBack() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bIsPlayingBack"); }
    void SetIsPlayingBack(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bIsPlayingBack", false, value); }
    bool GetPaused() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bPaused"); }
    void SetPaused(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bPaused", false, value); }
    bool GetMultiplayer() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bMultiplayer"); }
    void SetMultiplayer(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bMultiplayer", false, value); }
    bool GetAutogenerated() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bAutogenerated"); }
    void SetAutogenerated(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bAutogenerated", false, value); }
    float GetForceClientTime() const { return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flForceClientTime"); }
    void SetForceClientTime(float value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_flForceClientTime", false, value); }
    float GetCurrentTime() const { return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flCurrentTime"); }
    void SetCurrentTime(float value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_flCurrentTime", false, value); }
    float GetFrameTime() const { return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flFrameTime"); }
    void SetFrameTime(float value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_flFrameTime", false, value); }
    bool GetCancelAtNextInterrupt() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bCancelAtNextInterrupt"); }
    void SetCancelAtNextInterrupt(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bCancelAtNextInterrupt", false, value); }
    float GetPitch() const { return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_fPitch"); }
    void SetPitch(float value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_fPitch", false, value); }
    bool GetAutomated() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bAutomated"); }
    void SetAutomated(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bAutomated", false, value); }
    int32_t GetAutomatedAction() const { return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_nAutomatedAction"); }
    void SetAutomatedAction(int32_t value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_nAutomatedAction", false, value); }
    float GetAutomationDelay() const { return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flAutomationDelay"); }
    void SetAutomationDelay(float value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_flAutomationDelay", false, value); }
    float GetAutomationTime() const { return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flAutomationTime"); }
    void SetAutomationTime(float value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_flAutomationTime", false, value); }
    GCBaseEntity* GetWaitingForThisResumeScene() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hWaitingForThisResumeScene"); }
    void SetWaitingForThisResumeScene(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'WaitingForThisResumeScene' is not possible.\n"); }
    bool GetWaitingForResumeScene() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bWaitingForResumeScene"); }
    void SetWaitingForResumeScene(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bWaitingForResumeScene", false, value); }
    bool GetPausedViaInput() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bPausedViaInput"); }
    void SetPausedViaInput(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bPausedViaInput", false, value); }
    bool GetPauseAtNextInterrupt() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bPauseAtNextInterrupt"); }
    void SetPauseAtNextInterrupt(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bPauseAtNextInterrupt", false, value); }
    bool GetWaitingForActor() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bWaitingForActor"); }
    void SetWaitingForActor(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bWaitingForActor", false, value); }
    bool GetWaitingForInterrupt() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bWaitingForInterrupt"); }
    void SetWaitingForInterrupt(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bWaitingForInterrupt", false, value); }
    bool GetInterruptedActorsScenes() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bInterruptedActorsScenes"); }
    void SetInterruptedActorsScenes(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bInterruptedActorsScenes", false, value); }
    bool GetBreakOnNonIdle() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bBreakOnNonIdle"); }
    void SetBreakOnNonIdle(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bBreakOnNonIdle", false, value); }
    bool GetSceneFinished() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bSceneFinished"); }
    void SetSceneFinished(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bSceneFinished", false, value); }
    GCBaseFlex* GetActorList() const { return GetSchemaValue<GCBaseFlex*>(m_ptr, "CSceneEntity", "m_hActorList"); }
    void SetActorList(GCBaseFlex* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ActorList' is not possible.\n"); }
    int32_t GetSceneFlushCounter() const { return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_nSceneFlushCounter"); }
    void SetSceneFlushCounter(int32_t value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_nSceneFlushCounter", false, value); }
    uint16_t GetSceneStringIndex() const { return GetSchemaValue<uint16_t>(m_ptr, "CSceneEntity", "m_nSceneStringIndex"); }
    void SetSceneStringIndex(uint16_t value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_nSceneStringIndex", false, value); }
    GCEntityIOOutput GetOnStart() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSceneEntity", "m_OnStart"); }
    void SetOnStart(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_OnStart", false, value); }
    GCEntityIOOutput GetOnCompletion() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSceneEntity", "m_OnCompletion"); }
    void SetOnCompletion(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_OnCompletion", false, value); }
    GCEntityIOOutput GetOnCanceled() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSceneEntity", "m_OnCanceled"); }
    void SetOnCanceled(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_OnCanceled", false, value); }
    GCEntityIOOutput GetOnPaused() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSceneEntity", "m_OnPaused"); }
    void SetOnPaused(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_OnPaused", false, value); }
    GCEntityIOOutput GetOnResumed() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CSceneEntity", "m_OnResumed"); }
    void SetOnResumed(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_OnResumed", false, value); }
    std::vector<GCEntityIOOutput> GetOnTrigger() const { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CSceneEntity", "m_OnTrigger"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 16; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOnTrigger(std::vector<GCEntityIOOutput> value) { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CSceneEntity", "m_OnTrigger"); for(int i = 0; i < 16; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSceneEntity", "m_OnTrigger", false, outValue); }
    GCSceneEntity* GetInterruptScene() const { return GetSchemaValue<GCSceneEntity*>(m_ptr, "CSceneEntity", "m_hInterruptScene"); }
    void SetInterruptScene(GCSceneEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'InterruptScene' is not possible.\n"); }
    int32_t GetInterruptCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_nInterruptCount"); }
    void SetInterruptCount(int32_t value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_nInterruptCount", false, value); }
    bool GetSceneMissing() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bSceneMissing"); }
    void SetSceneMissing(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bSceneMissing", false, value); }
    bool GetInterrupted() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bInterrupted"); }
    void SetInterrupted(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bInterrupted", false, value); }
    bool GetCompletedEarly() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bCompletedEarly"); }
    void SetCompletedEarly(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bCompletedEarly", false, value); }
    bool GetInterruptSceneFinished() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bInterruptSceneFinished"); }
    void SetInterruptSceneFinished(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bInterruptSceneFinished", false, value); }
    bool GetRestoring() const { return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bRestoring"); }
    void SetRestoring(bool value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_bRestoring", false, value); }
    CUtlSymbolLarge GetSoundName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszSoundName"); }
    void SetSoundName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszSoundName", false, value); }
    CUtlSymbolLarge GetSequenceName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszSequenceName"); }
    void SetSequenceName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iszSequenceName", false, value); }
    GCBaseFlex* GetActor() const { return GetSchemaValue<GCBaseFlex*>(m_ptr, "CSceneEntity", "m_hActor"); }
    void SetActor(GCBaseFlex* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Actor' is not possible.\n"); }
    GCBaseEntity* GetActivator() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CSceneEntity", "m_hActivator"); }
    void SetActivator(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n"); }
    int32_t GetBusyActor() const { return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_BusyActor"); }
    void SetBusyActor(int32_t value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_BusyActor", false, value); }
    SceneOnPlayerDeath_t GetPlayerDeathBehavior() const { return GetSchemaValue<SceneOnPlayerDeath_t>(m_ptr, "CSceneEntity", "m_iPlayerDeathBehavior"); }
    void SetPlayerDeathBehavior(SceneOnPlayerDeath_t value) { SetSchemaValue(m_ptr, "CSceneEntity", "m_iPlayerDeathBehavior", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif