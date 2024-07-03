#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCScriptedSequence::GCScriptedSequence(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCScriptedSequence::GCScriptedSequence(void *ptr) {
    m_ptr = ptr;
}
std::string GCScriptedSequence::GetEntry() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszEntry").String();
}
void GCScriptedSequence::SetEntry(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszEntry", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptedSequence::GetPreIdle() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszPreIdle").String();
}
void GCScriptedSequence::SetPreIdle(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszPreIdle", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptedSequence::GetPlay() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszPlay").String();
}
void GCScriptedSequence::SetPlay(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszPlay", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptedSequence::GetPostIdle() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszPostIdle").String();
}
void GCScriptedSequence::SetPostIdle(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszPostIdle", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptedSequence::GetModifierToAddOnPlay() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszModifierToAddOnPlay").String();
}
void GCScriptedSequence::SetModifierToAddOnPlay(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszModifierToAddOnPlay", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptedSequence::GetNextScript() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszNextScript").String();
}
void GCScriptedSequence::SetNextScript(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszNextScript", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptedSequence::GetEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszEntity").String();
}
void GCScriptedSequence::SetEntity(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszEntity", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCScriptedSequence::GetSyncGroup() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CScriptedSequence", "m_iszSyncGroup").String();
}
void GCScriptedSequence::SetSyncGroup(std::string value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iszSyncGroup", false, CUtlSymbolLarge(value.c_str()));
}
uint64_t GCScriptedSequence::GetMoveTo() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CScriptedSequence", "m_nMoveTo");
}
void GCScriptedSequence::SetMoveTo(uint64_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_nMoveTo", false, value);
}
uint64_t GCScriptedSequence::GetMoveToGait() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CScriptedSequence", "m_nMoveToGait");
}
void GCScriptedSequence::SetMoveToGait(uint64_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_nMoveToGait", false, value);
}
bool GCScriptedSequence::GetIsPlayingPreIdle() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingPreIdle");
}
void GCScriptedSequence::SetIsPlayingPreIdle(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingPreIdle", false, value);
}
bool GCScriptedSequence::GetIsPlayingEntry() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingEntry");
}
void GCScriptedSequence::SetIsPlayingEntry(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingEntry", false, value);
}
bool GCScriptedSequence::GetIsPlayingAction() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingAction");
}
void GCScriptedSequence::SetIsPlayingAction(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingAction", false, value);
}
bool GCScriptedSequence::GetIsPlayingPostIdle() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsPlayingPostIdle");
}
void GCScriptedSequence::SetIsPlayingPostIdle(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsPlayingPostIdle", false, value);
}
bool GCScriptedSequence::GetDontRotateOther() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontRotateOther");
}
void GCScriptedSequence::SetDontRotateOther(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontRotateOther", false, value);
}
bool GCScriptedSequence::GetIsRepeatable() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsRepeatable");
}
void GCScriptedSequence::SetIsRepeatable(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsRepeatable", false, value);
}
bool GCScriptedSequence::GetShouldLeaveCorpse() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bShouldLeaveCorpse");
}
void GCScriptedSequence::SetShouldLeaveCorpse(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bShouldLeaveCorpse", false, value);
}
bool GCScriptedSequence::GetStartOnSpawn() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bStartOnSpawn");
}
void GCScriptedSequence::SetStartOnSpawn(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bStartOnSpawn", false, value);
}
bool GCScriptedSequence::GetDisallowInterrupts() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDisallowInterrupts");
}
void GCScriptedSequence::SetDisallowInterrupts(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDisallowInterrupts", false, value);
}
bool GCScriptedSequence::GetCanOverrideNPCState() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bCanOverrideNPCState");
}
void GCScriptedSequence::SetCanOverrideNPCState(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bCanOverrideNPCState", false, value);
}
bool GCScriptedSequence::GetDontTeleportAtEnd() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontTeleportAtEnd");
}
void GCScriptedSequence::SetDontTeleportAtEnd(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontTeleportAtEnd", false, value);
}
bool GCScriptedSequence::GetHighPriority() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bHighPriority");
}
void GCScriptedSequence::SetHighPriority(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bHighPriority", false, value);
}
bool GCScriptedSequence::GetHideDebugComplaints() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bHideDebugComplaints");
}
void GCScriptedSequence::SetHideDebugComplaints(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bHideDebugComplaints", false, value);
}
bool GCScriptedSequence::GetContinueOnDeath() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bContinueOnDeath");
}
void GCScriptedSequence::SetContinueOnDeath(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bContinueOnDeath", false, value);
}
bool GCScriptedSequence::GetLoopPreIdleSequence() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bLoopPreIdleSequence");
}
void GCScriptedSequence::SetLoopPreIdleSequence(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bLoopPreIdleSequence", false, value);
}
bool GCScriptedSequence::GetLoopActionSequence() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bLoopActionSequence");
}
void GCScriptedSequence::SetLoopActionSequence(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bLoopActionSequence", false, value);
}
bool GCScriptedSequence::GetLoopPostIdleSequence() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bLoopPostIdleSequence");
}
void GCScriptedSequence::SetLoopPostIdleSequence(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bLoopPostIdleSequence", false, value);
}
bool GCScriptedSequence::GetSynchPostIdles() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bSynchPostIdles");
}
void GCScriptedSequence::SetSynchPostIdles(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bSynchPostIdles", false, value);
}
bool GCScriptedSequence::GetIgnoreLookAt() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIgnoreLookAt");
}
void GCScriptedSequence::SetIgnoreLookAt(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIgnoreLookAt", false, value);
}
bool GCScriptedSequence::GetIgnoreGravity() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIgnoreGravity");
}
void GCScriptedSequence::SetIgnoreGravity(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIgnoreGravity", false, value);
}
bool GCScriptedSequence::GetDisableNPCCollisions() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDisableNPCCollisions");
}
void GCScriptedSequence::SetDisableNPCCollisions(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDisableNPCCollisions", false, value);
}
bool GCScriptedSequence::GetKeepAnimgraphLockedPost() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bKeepAnimgraphLockedPost");
}
void GCScriptedSequence::SetKeepAnimgraphLockedPost(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bKeepAnimgraphLockedPost", false, value);
}
bool GCScriptedSequence::GetDontAddModifiers() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontAddModifiers");
}
void GCScriptedSequence::SetDontAddModifiers(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontAddModifiers", false, value);
}
float GCScriptedSequence::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flRadius");
}
void GCScriptedSequence::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_flRadius", false, value);
}
float GCScriptedSequence::GetRepeat() const {
    return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flRepeat");
}
void GCScriptedSequence::SetRepeat(float value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_flRepeat", false, value);
}
float GCScriptedSequence::GetPlayAnimFadeInTime() const {
    return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flPlayAnimFadeInTime");
}
void GCScriptedSequence::SetPlayAnimFadeInTime(float value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_flPlayAnimFadeInTime", false, value);
}
float GCScriptedSequence::GetMoveInterpTime() const {
    return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flMoveInterpTime");
}
void GCScriptedSequence::SetMoveInterpTime(float value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_flMoveInterpTime", false, value);
}
float GCScriptedSequence::GetAngRate() const {
    return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_flAngRate");
}
void GCScriptedSequence::SetAngRate(float value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_flAngRate", false, value);
}
int32_t GCScriptedSequence::GetNotReadySequenceCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_nNotReadySequenceCount");
}
void GCScriptedSequence::SetNotReadySequenceCount(int32_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_nNotReadySequenceCount", false, value);
}
float GCScriptedSequence::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CScriptedSequence", "m_startTime");
}
void GCScriptedSequence::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_startTime", false, value);
}
bool GCScriptedSequence::GetWaitForBeginSequence() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bWaitForBeginSequence");
}
void GCScriptedSequence::SetWaitForBeginSequence(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bWaitForBeginSequence", false, value);
}
int32_t GCScriptedSequence::GetSaved_effects() const {
    return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_saved_effects");
}
void GCScriptedSequence::SetSaved_effects(int32_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_saved_effects", false, value);
}
int32_t GCScriptedSequence::GetSavedFlags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_savedFlags");
}
void GCScriptedSequence::SetSavedFlags(int32_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_savedFlags", false, value);
}
int32_t GCScriptedSequence::GetSavedCollisionGroup() const {
    return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_savedCollisionGroup");
}
void GCScriptedSequence::SetSavedCollisionGroup(int32_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_savedCollisionGroup", false, value);
}
bool GCScriptedSequence::GetInterruptable() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bInterruptable");
}
void GCScriptedSequence::SetInterruptable(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bInterruptable", false, value);
}
bool GCScriptedSequence::GetSequenceStarted() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_sequenceStarted");
}
void GCScriptedSequence::SetSequenceStarted(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_sequenceStarted", false, value);
}
bool GCScriptedSequence::GetPositionRelativeToOtherEntity() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bPositionRelativeToOtherEntity");
}
void GCScriptedSequence::SetPositionRelativeToOtherEntity(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bPositionRelativeToOtherEntity", false, value);
}
GCBaseEntity GCScriptedSequence::GetTargetEnt() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CScriptedSequence", "m_hTargetEnt"));
    return value;
}
void GCScriptedSequence::SetTargetEnt(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEnt' is not possible.\n");
}
GCScriptedSequence GCScriptedSequence::GetNextCine() const {
    GCScriptedSequence value(*GetSchemaValuePtr<void*>(m_ptr, "CScriptedSequence", "m_hNextCine"));
    return value;
}
void GCScriptedSequence::SetNextCine(GCScriptedSequence* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextCine' is not possible.\n");
}
bool GCScriptedSequence::GetThinking() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bThinking");
}
void GCScriptedSequence::SetThinking(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bThinking", false, value);
}
bool GCScriptedSequence::GetInitiatedSelfDelete() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bInitiatedSelfDelete");
}
void GCScriptedSequence::SetInitiatedSelfDelete(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bInitiatedSelfDelete", false, value);
}
bool GCScriptedSequence::GetIsTeleportingDueToMoveTo() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bIsTeleportingDueToMoveTo");
}
void GCScriptedSequence::SetIsTeleportingDueToMoveTo(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bIsTeleportingDueToMoveTo", false, value);
}
bool GCScriptedSequence::GetAllowCustomInterruptConditions() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bAllowCustomInterruptConditions");
}
void GCScriptedSequence::SetAllowCustomInterruptConditions(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bAllowCustomInterruptConditions", false, value);
}
GCBaseAnimGraph GCScriptedSequence::GetForcedTarget() const {
    GCBaseAnimGraph value(*GetSchemaValuePtr<void*>(m_ptr, "CScriptedSequence", "m_hForcedTarget"));
    return value;
}
void GCScriptedSequence::SetForcedTarget(GCBaseAnimGraph* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ForcedTarget' is not possible.\n");
}
bool GCScriptedSequence::GetDontCancelOtherSequences() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bDontCancelOtherSequences");
}
void GCScriptedSequence::SetDontCancelOtherSequences(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bDontCancelOtherSequences", false, value);
}
bool GCScriptedSequence::GetForceSynch() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bForceSynch");
}
void GCScriptedSequence::SetForceSynch(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bForceSynch", false, value);
}
bool GCScriptedSequence::GetPreventUpdateYawOnFinish() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bPreventUpdateYawOnFinish");
}
void GCScriptedSequence::SetPreventUpdateYawOnFinish(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bPreventUpdateYawOnFinish", false, value);
}
bool GCScriptedSequence::GetEnsureOnNavmeshOnFinish() const {
    return GetSchemaValue<bool>(m_ptr, "CScriptedSequence", "m_bEnsureOnNavmeshOnFinish");
}
void GCScriptedSequence::SetEnsureOnNavmeshOnFinish(bool value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_bEnsureOnNavmeshOnFinish", false, value);
}
uint64_t GCScriptedSequence::GetOnDeathBehavior() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CScriptedSequence", "m_onDeathBehavior");
}
void GCScriptedSequence::SetOnDeathBehavior(uint64_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_onDeathBehavior", false, value);
}
uint64_t GCScriptedSequence::GetConflictResponse() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CScriptedSequence", "m_ConflictResponse");
}
void GCScriptedSequence::SetConflictResponse(uint64_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_ConflictResponse", false, value);
}
GCEntityIOOutput GCScriptedSequence::GetOnBeginSequence() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CScriptedSequence", "m_OnBeginSequence"));
    return value;
}
void GCScriptedSequence::SetOnBeginSequence(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnBeginSequence", false, value);
}
GCEntityIOOutput GCScriptedSequence::GetOnActionStartOrLoop() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CScriptedSequence", "m_OnActionStartOrLoop"));
    return value;
}
void GCScriptedSequence::SetOnActionStartOrLoop(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnActionStartOrLoop", false, value);
}
GCEntityIOOutput GCScriptedSequence::GetOnEndSequence() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CScriptedSequence", "m_OnEndSequence"));
    return value;
}
void GCScriptedSequence::SetOnEndSequence(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnEndSequence", false, value);
}
GCEntityIOOutput GCScriptedSequence::GetOnPostIdleEndSequence() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CScriptedSequence", "m_OnPostIdleEndSequence"));
    return value;
}
void GCScriptedSequence::SetOnPostIdleEndSequence(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnPostIdleEndSequence", false, value);
}
GCEntityIOOutput GCScriptedSequence::GetOnCancelSequence() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CScriptedSequence", "m_OnCancelSequence"));
    return value;
}
void GCScriptedSequence::SetOnCancelSequence(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnCancelSequence", false, value);
}
GCEntityIOOutput GCScriptedSequence::GetOnCancelFailedSequence() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CScriptedSequence", "m_OnCancelFailedSequence"));
    return value;
}
void GCScriptedSequence::SetOnCancelFailedSequence(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnCancelFailedSequence", false, value);
}
std::vector<GCEntityIOOutput> GCScriptedSequence::GetOnScriptEvent() const {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CScriptedSequence", "m_OnScriptEvent"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCScriptedSequence::SetOnScriptEvent(std::vector<GCEntityIOOutput> value) {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CScriptedSequence", "m_OnScriptEvent"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CScriptedSequence", "m_OnScriptEvent", false, outValue);
}
GCBaseEntity GCScriptedSequence::GetInteractionMainEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CScriptedSequence", "m_hInteractionMainEntity"));
    return value;
}
void GCScriptedSequence::SetInteractionMainEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'InteractionMainEntity' is not possible.\n");
}
int32_t GCScriptedSequence::GetPlayerDeathBehavior() const {
    return GetSchemaValue<int32_t>(m_ptr, "CScriptedSequence", "m_iPlayerDeathBehavior");
}
void GCScriptedSequence::SetPlayerDeathBehavior(int32_t value) {
    SetSchemaValue(m_ptr, "CScriptedSequence", "m_iPlayerDeathBehavior", false, value);
}
std::string GCScriptedSequence::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCScriptedSequence::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCScriptedSequence::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCScriptedSequence::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCScriptedSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptedSequence>("CScriptedSequence")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entry", &GCScriptedSequence::GetEntry, &GCScriptedSequence::SetEntry)
        .addProperty("PreIdle", &GCScriptedSequence::GetPreIdle, &GCScriptedSequence::SetPreIdle)
        .addProperty("Play", &GCScriptedSequence::GetPlay, &GCScriptedSequence::SetPlay)
        .addProperty("PostIdle", &GCScriptedSequence::GetPostIdle, &GCScriptedSequence::SetPostIdle)
        .addProperty("ModifierToAddOnPlay", &GCScriptedSequence::GetModifierToAddOnPlay, &GCScriptedSequence::SetModifierToAddOnPlay)
        .addProperty("NextScript", &GCScriptedSequence::GetNextScript, &GCScriptedSequence::SetNextScript)
        .addProperty("Entity", &GCScriptedSequence::GetEntity, &GCScriptedSequence::SetEntity)
        .addProperty("SyncGroup", &GCScriptedSequence::GetSyncGroup, &GCScriptedSequence::SetSyncGroup)
        .addProperty("MoveTo", &GCScriptedSequence::GetMoveTo, &GCScriptedSequence::SetMoveTo)
        .addProperty("MoveToGait", &GCScriptedSequence::GetMoveToGait, &GCScriptedSequence::SetMoveToGait)
        .addProperty("IsPlayingPreIdle", &GCScriptedSequence::GetIsPlayingPreIdle, &GCScriptedSequence::SetIsPlayingPreIdle)
        .addProperty("IsPlayingEntry", &GCScriptedSequence::GetIsPlayingEntry, &GCScriptedSequence::SetIsPlayingEntry)
        .addProperty("IsPlayingAction", &GCScriptedSequence::GetIsPlayingAction, &GCScriptedSequence::SetIsPlayingAction)
        .addProperty("IsPlayingPostIdle", &GCScriptedSequence::GetIsPlayingPostIdle, &GCScriptedSequence::SetIsPlayingPostIdle)
        .addProperty("DontRotateOther", &GCScriptedSequence::GetDontRotateOther, &GCScriptedSequence::SetDontRotateOther)
        .addProperty("IsRepeatable", &GCScriptedSequence::GetIsRepeatable, &GCScriptedSequence::SetIsRepeatable)
        .addProperty("ShouldLeaveCorpse", &GCScriptedSequence::GetShouldLeaveCorpse, &GCScriptedSequence::SetShouldLeaveCorpse)
        .addProperty("StartOnSpawn", &GCScriptedSequence::GetStartOnSpawn, &GCScriptedSequence::SetStartOnSpawn)
        .addProperty("DisallowInterrupts", &GCScriptedSequence::GetDisallowInterrupts, &GCScriptedSequence::SetDisallowInterrupts)
        .addProperty("CanOverrideNPCState", &GCScriptedSequence::GetCanOverrideNPCState, &GCScriptedSequence::SetCanOverrideNPCState)
        .addProperty("DontTeleportAtEnd", &GCScriptedSequence::GetDontTeleportAtEnd, &GCScriptedSequence::SetDontTeleportAtEnd)
        .addProperty("HighPriority", &GCScriptedSequence::GetHighPriority, &GCScriptedSequence::SetHighPriority)
        .addProperty("HideDebugComplaints", &GCScriptedSequence::GetHideDebugComplaints, &GCScriptedSequence::SetHideDebugComplaints)
        .addProperty("ContinueOnDeath", &GCScriptedSequence::GetContinueOnDeath, &GCScriptedSequence::SetContinueOnDeath)
        .addProperty("LoopPreIdleSequence", &GCScriptedSequence::GetLoopPreIdleSequence, &GCScriptedSequence::SetLoopPreIdleSequence)
        .addProperty("LoopActionSequence", &GCScriptedSequence::GetLoopActionSequence, &GCScriptedSequence::SetLoopActionSequence)
        .addProperty("LoopPostIdleSequence", &GCScriptedSequence::GetLoopPostIdleSequence, &GCScriptedSequence::SetLoopPostIdleSequence)
        .addProperty("SynchPostIdles", &GCScriptedSequence::GetSynchPostIdles, &GCScriptedSequence::SetSynchPostIdles)
        .addProperty("IgnoreLookAt", &GCScriptedSequence::GetIgnoreLookAt, &GCScriptedSequence::SetIgnoreLookAt)
        .addProperty("IgnoreGravity", &GCScriptedSequence::GetIgnoreGravity, &GCScriptedSequence::SetIgnoreGravity)
        .addProperty("DisableNPCCollisions", &GCScriptedSequence::GetDisableNPCCollisions, &GCScriptedSequence::SetDisableNPCCollisions)
        .addProperty("KeepAnimgraphLockedPost", &GCScriptedSequence::GetKeepAnimgraphLockedPost, &GCScriptedSequence::SetKeepAnimgraphLockedPost)
        .addProperty("DontAddModifiers", &GCScriptedSequence::GetDontAddModifiers, &GCScriptedSequence::SetDontAddModifiers)
        .addProperty("Radius", &GCScriptedSequence::GetRadius, &GCScriptedSequence::SetRadius)
        .addProperty("Repeat", &GCScriptedSequence::GetRepeat, &GCScriptedSequence::SetRepeat)
        .addProperty("PlayAnimFadeInTime", &GCScriptedSequence::GetPlayAnimFadeInTime, &GCScriptedSequence::SetPlayAnimFadeInTime)
        .addProperty("MoveInterpTime", &GCScriptedSequence::GetMoveInterpTime, &GCScriptedSequence::SetMoveInterpTime)
        .addProperty("AngRate", &GCScriptedSequence::GetAngRate, &GCScriptedSequence::SetAngRate)
        .addProperty("NotReadySequenceCount", &GCScriptedSequence::GetNotReadySequenceCount, &GCScriptedSequence::SetNotReadySequenceCount)
        .addProperty("StartTime", &GCScriptedSequence::GetStartTime, &GCScriptedSequence::SetStartTime)
        .addProperty("WaitForBeginSequence", &GCScriptedSequence::GetWaitForBeginSequence, &GCScriptedSequence::SetWaitForBeginSequence)
        .addProperty("Saved_effects", &GCScriptedSequence::GetSaved_effects, &GCScriptedSequence::SetSaved_effects)
        .addProperty("SavedFlags", &GCScriptedSequence::GetSavedFlags, &GCScriptedSequence::SetSavedFlags)
        .addProperty("SavedCollisionGroup", &GCScriptedSequence::GetSavedCollisionGroup, &GCScriptedSequence::SetSavedCollisionGroup)
        .addProperty("Interruptable", &GCScriptedSequence::GetInterruptable, &GCScriptedSequence::SetInterruptable)
        .addProperty("SequenceStarted", &GCScriptedSequence::GetSequenceStarted, &GCScriptedSequence::SetSequenceStarted)
        .addProperty("PositionRelativeToOtherEntity", &GCScriptedSequence::GetPositionRelativeToOtherEntity, &GCScriptedSequence::SetPositionRelativeToOtherEntity)
        .addProperty("TargetEnt", &GCScriptedSequence::GetTargetEnt, &GCScriptedSequence::SetTargetEnt)
        .addProperty("NextCine", &GCScriptedSequence::GetNextCine, &GCScriptedSequence::SetNextCine)
        .addProperty("Thinking", &GCScriptedSequence::GetThinking, &GCScriptedSequence::SetThinking)
        .addProperty("InitiatedSelfDelete", &GCScriptedSequence::GetInitiatedSelfDelete, &GCScriptedSequence::SetInitiatedSelfDelete)
        .addProperty("IsTeleportingDueToMoveTo", &GCScriptedSequence::GetIsTeleportingDueToMoveTo, &GCScriptedSequence::SetIsTeleportingDueToMoveTo)
        .addProperty("AllowCustomInterruptConditions", &GCScriptedSequence::GetAllowCustomInterruptConditions, &GCScriptedSequence::SetAllowCustomInterruptConditions)
        .addProperty("ForcedTarget", &GCScriptedSequence::GetForcedTarget, &GCScriptedSequence::SetForcedTarget)
        .addProperty("DontCancelOtherSequences", &GCScriptedSequence::GetDontCancelOtherSequences, &GCScriptedSequence::SetDontCancelOtherSequences)
        .addProperty("ForceSynch", &GCScriptedSequence::GetForceSynch, &GCScriptedSequence::SetForceSynch)
        .addProperty("PreventUpdateYawOnFinish", &GCScriptedSequence::GetPreventUpdateYawOnFinish, &GCScriptedSequence::SetPreventUpdateYawOnFinish)
        .addProperty("EnsureOnNavmeshOnFinish", &GCScriptedSequence::GetEnsureOnNavmeshOnFinish, &GCScriptedSequence::SetEnsureOnNavmeshOnFinish)
        .addProperty("OnDeathBehavior", &GCScriptedSequence::GetOnDeathBehavior, &GCScriptedSequence::SetOnDeathBehavior)
        .addProperty("ConflictResponse", &GCScriptedSequence::GetConflictResponse, &GCScriptedSequence::SetConflictResponse)
        .addProperty("OnBeginSequence", &GCScriptedSequence::GetOnBeginSequence, &GCScriptedSequence::SetOnBeginSequence)
        .addProperty("OnActionStartOrLoop", &GCScriptedSequence::GetOnActionStartOrLoop, &GCScriptedSequence::SetOnActionStartOrLoop)
        .addProperty("OnEndSequence", &GCScriptedSequence::GetOnEndSequence, &GCScriptedSequence::SetOnEndSequence)
        .addProperty("OnPostIdleEndSequence", &GCScriptedSequence::GetOnPostIdleEndSequence, &GCScriptedSequence::SetOnPostIdleEndSequence)
        .addProperty("OnCancelSequence", &GCScriptedSequence::GetOnCancelSequence, &GCScriptedSequence::SetOnCancelSequence)
        .addProperty("OnCancelFailedSequence", &GCScriptedSequence::GetOnCancelFailedSequence, &GCScriptedSequence::SetOnCancelFailedSequence)
        .addProperty("OnScriptEvent", &GCScriptedSequence::GetOnScriptEvent, &GCScriptedSequence::SetOnScriptEvent)
        .addProperty("InteractionMainEntity", &GCScriptedSequence::GetInteractionMainEntity, &GCScriptedSequence::SetInteractionMainEntity)
        .addProperty("PlayerDeathBehavior", &GCScriptedSequence::GetPlayerDeathBehavior, &GCScriptedSequence::SetPlayerDeathBehavior)
        .addProperty("Parent", &GCScriptedSequence::GetParent, &GCScriptedSequence::SetParent)
        .addFunction("ToPtr", &GCScriptedSequence::ToPtr)
        .addFunction("IsValid", &GCScriptedSequence::IsValid)
        .endClass();
}