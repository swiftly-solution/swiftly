class GCScriptedSequence;

#ifndef _gccscriptedsequence_h
#define _gccscriptedsequence_h

#include "../../../scripting.h"

#include "../types/GScriptedMoveTo_t.h"
#include "../types/GMovementGait_t.h"
#include "../types/GScriptedOnDeath_t.h"
#include "../types/GScriptedConflictResponse_t.h"
#include "GCBaseEntity.h"
#include "GCScriptedSequence.h"
#include "GCBaseAnimGraph.h"
#include "GCEntityIOOutput.h"

class GCScriptedSequence
{
private:
    void *m_ptr;

public:
    GCScriptedSequence() {}
    GCScriptedSequence(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetEntry() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszEntry"); }
    void SetEntry(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszEntry", false, value); }
    CUtlSymbolLarge GetPreIdle() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszPreIdle"); }
    void SetPreIdle(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszPreIdle", false, value); }
    CUtlSymbolLarge GetPlay() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszPlay"); }
    void SetPlay(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszPlay", false, value); }
    CUtlSymbolLarge GetPostIdle() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszPostIdle"); }
    void SetPostIdle(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszPostIdle", false, value); }
    CUtlSymbolLarge GetModifierToAddOnPlay() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszModifierToAddOnPlay"); }
    void SetModifierToAddOnPlay(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszModifierToAddOnPlay", false, value); }
    CUtlSymbolLarge GetNextScript() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszNextScript"); }
    void SetNextScript(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszNextScript", false, value); }
    CUtlSymbolLarge GetEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszEntity"); }
    void SetEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszEntity", false, value); }
    CUtlSymbolLarge GetSyncGroup() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszSyncGroup"); }
    void SetSyncGroup(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszSyncGroup", false, value); }
    ScriptedMoveTo_t GetMoveTo() const { return GetSchemaValue<ScriptedMoveTo_t>(m_ptr, "CScriptedSequence", "m_nMoveTo"); }
    void SetMoveTo(ScriptedMoveTo_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_nMoveTo", false, value); }
    MovementGait_t GetMoveToGait() const { return GetSchemaValue<MovementGait_t>(m_ptr, "CScriptedSequence", "m_nMoveToGait"); }
    void SetMoveToGait(MovementGait_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_nMoveToGait", false, value); }
    bool GetIsPlayingPreIdle() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingPreIdle"); }
    void SetIsPlayingPreIdle(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingPreIdle", false, value); }
    bool GetIsPlayingEntry() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingEntry"); }
    void SetIsPlayingEntry(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingEntry", false, value); }
    bool GetIsPlayingAction() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingAction"); }
    void SetIsPlayingAction(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingAction", false, value); }
    bool GetIsPlayingPostIdle() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingPostIdle"); }
    void SetIsPlayingPostIdle(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingPostIdle", false, value); }
    bool GetDontRotateOther() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontRotateOther"); }
    void SetDontRotateOther(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontRotateOther", false, value); }
    bool GetIsRepeatable() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsRepeatable"); }
    void SetIsRepeatable(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsRepeatable", false, value); }
    bool GetShouldLeaveCorpse() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bShouldLeaveCorpse"); }
    void SetShouldLeaveCorpse(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bShouldLeaveCorpse", false, value); }
    bool GetStartOnSpawn() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bStartOnSpawn"); }
    void SetStartOnSpawn(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bStartOnSpawn", false, value); }
    bool GetDisallowInterrupts() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDisallowInterrupts"); }
    void SetDisallowInterrupts(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDisallowInterrupts", false, value); }
    bool GetCanOverrideNPCState() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bCanOverrideNPCState"); }
    void SetCanOverrideNPCState(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bCanOverrideNPCState", false, value); }
    bool GetDontTeleportAtEnd() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontTeleportAtEnd"); }
    void SetDontTeleportAtEnd(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontTeleportAtEnd", false, value); }
    bool GetHighPriority() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bHighPriority"); }
    void SetHighPriority(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bHighPriority", false, value); }
    bool GetHideDebugComplaints() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bHideDebugComplaints"); }
    void SetHideDebugComplaints(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bHideDebugComplaints", false, value); }
    bool GetContinueOnDeath() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bContinueOnDeath"); }
    void SetContinueOnDeath(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bContinueOnDeath", false, value); }
    bool GetLoopPreIdleSequence() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bLoopPreIdleSequence"); }
    void SetLoopPreIdleSequence(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bLoopPreIdleSequence", false, value); }
    bool GetLoopActionSequence() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bLoopActionSequence"); }
    void SetLoopActionSequence(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bLoopActionSequence", false, value); }
    bool GetLoopPostIdleSequence() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bLoopPostIdleSequence"); }
    void SetLoopPostIdleSequence(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bLoopPostIdleSequence", false, value); }
    bool GetSynchPostIdles() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bSynchPostIdles"); }
    void SetSynchPostIdles(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bSynchPostIdles", false, value); }
    bool GetIgnoreLookAt() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIgnoreLookAt"); }
    void SetIgnoreLookAt(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIgnoreLookAt", false, value); }
    bool GetIgnoreGravity() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIgnoreGravity"); }
    void SetIgnoreGravity(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIgnoreGravity", false, value); }
    bool GetDisableNPCCollisions() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDisableNPCCollisions"); }
    void SetDisableNPCCollisions(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDisableNPCCollisions", false, value); }
    bool GetKeepAnimgraphLockedPost() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bKeepAnimgraphLockedPost"); }
    void SetKeepAnimgraphLockedPost(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bKeepAnimgraphLockedPost", false, value); }
    bool GetDontAddModifiers() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontAddModifiers"); }
    void SetDontAddModifiers(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontAddModifiers", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_flRadius", false, value); }
    float GetRepeat() const { return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flRepeat"); }
    void SetRepeat(float value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_flRepeat", false, value); }
    float GetPlayAnimFadeInTime() const { return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flPlayAnimFadeInTime"); }
    void SetPlayAnimFadeInTime(float value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_flPlayAnimFadeInTime", false, value); }
    float GetMoveInterpTime() const { return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flMoveInterpTime"); }
    void SetMoveInterpTime(float value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_flMoveInterpTime", false, value); }
    float GetAngRate() const { return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flAngRate"); }
    void SetAngRate(float value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_flAngRate", false, value); }
    int32_t GetNotReadySequenceCount() const { return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_nNotReadySequenceCount"); }
    void SetNotReadySequenceCount(int32_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_nNotReadySequenceCount", false, value); }
    bool GetWaitForBeginSequence() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bWaitForBeginSequence"); }
    void SetWaitForBeginSequence(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bWaitForBeginSequence", false, value); }
    int32_t GetSaved_effects() const { return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_saved_effects"); }
    void SetSaved_effects(int32_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_saved_effects", false, value); }
    int32_t GetSavedFlags() const { return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_savedFlags"); }
    void SetSavedFlags(int32_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_savedFlags", false, value); }
    int32_t GetSavedCollisionGroup() const { return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_savedCollisionGroup"); }
    void SetSavedCollisionGroup(int32_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_savedCollisionGroup", false, value); }
    bool GetInterruptable() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bInterruptable"); }
    void SetInterruptable(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bInterruptable", false, value); }
    bool GetSequenceStarted() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_sequenceStarted"); }
    void SetSequenceStarted(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_sequenceStarted", false, value); }
    bool GetPositionRelativeToOtherEntity() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bPositionRelativeToOtherEntity"); }
    void SetPositionRelativeToOtherEntity(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bPositionRelativeToOtherEntity", false, value); }
    GCBaseEntity* GetTargetEnt() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CScriptedSequence", "m_hTargetEnt"); }
    void SetTargetEnt(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEnt' is not possible.\n"); }
    GCScriptedSequence* GetNextCine() const { return GetSchemaValue<GCScriptedSequence*>(m_ptr, "CScriptedSequence", "m_hNextCine"); }
    void SetNextCine(GCScriptedSequence* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextCine' is not possible.\n"); }
    bool GetThinking() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bThinking"); }
    void SetThinking(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bThinking", false, value); }
    bool GetInitiatedSelfDelete() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bInitiatedSelfDelete"); }
    void SetInitiatedSelfDelete(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bInitiatedSelfDelete", false, value); }
    bool GetIsTeleportingDueToMoveTo() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsTeleportingDueToMoveTo"); }
    void SetIsTeleportingDueToMoveTo(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsTeleportingDueToMoveTo", false, value); }
    bool GetAllowCustomInterruptConditions() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bAllowCustomInterruptConditions"); }
    void SetAllowCustomInterruptConditions(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bAllowCustomInterruptConditions", false, value); }
    GCBaseAnimGraph* GetForcedTarget() const { return GetSchemaValue<GCBaseAnimGraph*>(m_ptr, "CScriptedSequence", "m_hForcedTarget"); }
    void SetForcedTarget(GCBaseAnimGraph* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ForcedTarget' is not possible.\n"); }
    bool GetDontCancelOtherSequences() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontCancelOtherSequences"); }
    void SetDontCancelOtherSequences(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontCancelOtherSequences", false, value); }
    bool GetForceSynch() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bForceSynch"); }
    void SetForceSynch(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bForceSynch", false, value); }
    bool GetPreventUpdateYawOnFinish() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bPreventUpdateYawOnFinish"); }
    void SetPreventUpdateYawOnFinish(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bPreventUpdateYawOnFinish", false, value); }
    bool GetEnsureOnNavmeshOnFinish() const { return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bEnsureOnNavmeshOnFinish"); }
    void SetEnsureOnNavmeshOnFinish(bool value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_bEnsureOnNavmeshOnFinish", false, value); }
    ScriptedOnDeath_t GetOnDeathBehavior() const { return GetSchemaValue<ScriptedOnDeath_t>(m_ptr, "CScriptedSequence", "m_onDeathBehavior"); }
    void SetOnDeathBehavior(ScriptedOnDeath_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_onDeathBehavior", false, value); }
    ScriptedConflictResponse_t GetConflictResponse() const { return GetSchemaValue<ScriptedConflictResponse_t>(m_ptr, "CScriptedSequence", "m_ConflictResponse"); }
    void SetConflictResponse(ScriptedConflictResponse_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_ConflictResponse", false, value); }
    GCEntityIOOutput GetOnBeginSequence() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CScriptedSequence", "m_OnBeginSequence"); }
    void SetOnBeginSequence(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnBeginSequence", false, value); }
    GCEntityIOOutput GetOnActionStartOrLoop() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CScriptedSequence", "m_OnActionStartOrLoop"); }
    void SetOnActionStartOrLoop(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnActionStartOrLoop", false, value); }
    GCEntityIOOutput GetOnEndSequence() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CScriptedSequence", "m_OnEndSequence"); }
    void SetOnEndSequence(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnEndSequence", false, value); }
    GCEntityIOOutput GetOnPostIdleEndSequence() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CScriptedSequence", "m_OnPostIdleEndSequence"); }
    void SetOnPostIdleEndSequence(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnPostIdleEndSequence", false, value); }
    GCEntityIOOutput GetOnCancelSequence() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CScriptedSequence", "m_OnCancelSequence"); }
    void SetOnCancelSequence(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnCancelSequence", false, value); }
    GCEntityIOOutput GetOnCancelFailedSequence() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CScriptedSequence", "m_OnCancelFailedSequence"); }
    void SetOnCancelFailedSequence(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnCancelFailedSequence", false, value); }
    std::vector<GCEntityIOOutput> GetOnScriptEvent() const { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CScriptedSequence", "m_OnScriptEvent"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOnScriptEvent(std::vector<GCEntityIOOutput> value) { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CScriptedSequence", "m_OnScriptEvent"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnScriptEvent", false, outValue); }
    GCBaseEntity* GetInteractionMainEntity() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CScriptedSequence", "m_hInteractionMainEntity"); }
    void SetInteractionMainEntity(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'InteractionMainEntity' is not possible.\n"); }
    int32_t GetPlayerDeathBehavior() const { return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_iPlayerDeathBehavior"); }
    void SetPlayerDeathBehavior(int32_t value) { SetSchemaValue(m_ptr, "CScriptedSequence", "m_iPlayerDeathBehavior", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif