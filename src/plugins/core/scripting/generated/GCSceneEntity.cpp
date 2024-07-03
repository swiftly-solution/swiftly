#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSceneEntity::GCSceneEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSceneEntity::GCSceneEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCSceneEntity::GetSceneFile() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszSceneFile").String();
}
void GCSceneEntity::SetSceneFile(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszSceneFile", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetResumeSceneFile() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszResumeSceneFile").String();
}
void GCSceneEntity::SetResumeSceneFile(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszResumeSceneFile", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget1() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget1").String();
}
void GCSceneEntity::SetTarget1(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget1", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget2() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget2").String();
}
void GCSceneEntity::SetTarget2(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget2", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget3() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget3").String();
}
void GCSceneEntity::SetTarget3(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget3", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget4() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget4").String();
}
void GCSceneEntity::SetTarget4(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget4", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget5() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget5").String();
}
void GCSceneEntity::SetTarget5(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget5", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget6() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget6").String();
}
void GCSceneEntity::SetTarget6(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget6", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget7() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget7").String();
}
void GCSceneEntity::SetTarget7(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget7", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetTarget8() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszTarget8").String();
}
void GCSceneEntity::SetTarget8(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszTarget8", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCSceneEntity::GetTarget11() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget1"));
    return value;
}
void GCSceneEntity::SetTarget11(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target11' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetTarget21() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget2"));
    return value;
}
void GCSceneEntity::SetTarget21(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target21' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetTarget31() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget3"));
    return value;
}
void GCSceneEntity::SetTarget31(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target31' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetTarget41() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget4"));
    return value;
}
void GCSceneEntity::SetTarget41(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target41' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetTarget51() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget5"));
    return value;
}
void GCSceneEntity::SetTarget51(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target51' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetTarget61() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget6"));
    return value;
}
void GCSceneEntity::SetTarget61(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target61' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetTarget71() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget7"));
    return value;
}
void GCSceneEntity::SetTarget71(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target71' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetTarget81() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hTarget8"));
    return value;
}
void GCSceneEntity::SetTarget81(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target81' is not possible.\n");
}
std::string GCSceneEntity::GetTargetAttachment() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_sTargetAttachment").String();
}
void GCSceneEntity::SetTargetAttachment(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_sTargetAttachment", false, CUtlSymbolLarge(value.c_str()));
}
bool GCSceneEntity::GetIsPlayingBack() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bIsPlayingBack");
}
void GCSceneEntity::SetIsPlayingBack(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bIsPlayingBack", false, value);
}
bool GCSceneEntity::GetPaused() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bPaused");
}
void GCSceneEntity::SetPaused(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bPaused", false, value);
}
bool GCSceneEntity::GetMultiplayer() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bMultiplayer");
}
void GCSceneEntity::SetMultiplayer(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bMultiplayer", false, value);
}
bool GCSceneEntity::GetAutogenerated() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bAutogenerated");
}
void GCSceneEntity::SetAutogenerated(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bAutogenerated", false, value);
}
float GCSceneEntity::GetForceClientTime() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flForceClientTime");
}
void GCSceneEntity::SetForceClientTime(float value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_flForceClientTime", false, value);
}
float GCSceneEntity::GetCurrentTime() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flCurrentTime");
}
void GCSceneEntity::SetCurrentTime(float value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_flCurrentTime", false, value);
}
float GCSceneEntity::GetFrameTime() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flFrameTime");
}
void GCSceneEntity::SetFrameTime(float value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_flFrameTime", false, value);
}
bool GCSceneEntity::GetCancelAtNextInterrupt() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bCancelAtNextInterrupt");
}
void GCSceneEntity::SetCancelAtNextInterrupt(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bCancelAtNextInterrupt", false, value);
}
float GCSceneEntity::GetPitch() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_fPitch");
}
void GCSceneEntity::SetPitch(float value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_fPitch", false, value);
}
bool GCSceneEntity::GetAutomated() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bAutomated");
}
void GCSceneEntity::SetAutomated(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bAutomated", false, value);
}
int32_t GCSceneEntity::GetAutomatedAction() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_nAutomatedAction");
}
void GCSceneEntity::SetAutomatedAction(int32_t value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_nAutomatedAction", false, value);
}
float GCSceneEntity::GetAutomationDelay() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flAutomationDelay");
}
void GCSceneEntity::SetAutomationDelay(float value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_flAutomationDelay", false, value);
}
float GCSceneEntity::GetAutomationTime() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEntity", "m_flAutomationTime");
}
void GCSceneEntity::SetAutomationTime(float value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_flAutomationTime", false, value);
}
GCBaseEntity GCSceneEntity::GetWaitingForThisResumeScene() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hWaitingForThisResumeScene"));
    return value;
}
void GCSceneEntity::SetWaitingForThisResumeScene(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'WaitingForThisResumeScene' is not possible.\n");
}
bool GCSceneEntity::GetWaitingForResumeScene() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bWaitingForResumeScene");
}
void GCSceneEntity::SetWaitingForResumeScene(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bWaitingForResumeScene", false, value);
}
bool GCSceneEntity::GetPausedViaInput() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bPausedViaInput");
}
void GCSceneEntity::SetPausedViaInput(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bPausedViaInput", false, value);
}
bool GCSceneEntity::GetPauseAtNextInterrupt() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bPauseAtNextInterrupt");
}
void GCSceneEntity::SetPauseAtNextInterrupt(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bPauseAtNextInterrupt", false, value);
}
bool GCSceneEntity::GetWaitingForActor() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bWaitingForActor");
}
void GCSceneEntity::SetWaitingForActor(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bWaitingForActor", false, value);
}
bool GCSceneEntity::GetWaitingForInterrupt() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bWaitingForInterrupt");
}
void GCSceneEntity::SetWaitingForInterrupt(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bWaitingForInterrupt", false, value);
}
bool GCSceneEntity::GetInterruptedActorsScenes() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bInterruptedActorsScenes");
}
void GCSceneEntity::SetInterruptedActorsScenes(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bInterruptedActorsScenes", false, value);
}
bool GCSceneEntity::GetBreakOnNonIdle() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bBreakOnNonIdle");
}
void GCSceneEntity::SetBreakOnNonIdle(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bBreakOnNonIdle", false, value);
}
bool GCSceneEntity::GetSceneFinished() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bSceneFinished");
}
void GCSceneEntity::SetSceneFinished(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bSceneFinished", false, value);
}
std::vector<GCBaseFlex*> GCSceneEntity::GetActorList() const {
    CUtlVector<GCBaseFlex*>* vec = GetSchemaValue<CUtlVector<GCBaseFlex*>*>(m_ptr, "CSceneEntity", "m_hActorList"); std::vector<GCBaseFlex*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSceneEntity::SetActorList(std::vector<GCBaseFlex*> value) {
    SetSchemaValueCUtlVector<GCBaseFlex*>(m_ptr, "CSceneEntity", "m_hActorList", false, value);
}
int32_t GCSceneEntity::GetSceneFlushCounter() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_nSceneFlushCounter");
}
void GCSceneEntity::SetSceneFlushCounter(int32_t value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_nSceneFlushCounter", false, value);
}
uint16_t GCSceneEntity::GetSceneStringIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CSceneEntity", "m_nSceneStringIndex");
}
void GCSceneEntity::SetSceneStringIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_nSceneStringIndex", false, value);
}
GCEntityIOOutput GCSceneEntity::GetOnStart() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSceneEntity", "m_OnStart"));
    return value;
}
void GCSceneEntity::SetOnStart(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_OnStart", false, value);
}
GCEntityIOOutput GCSceneEntity::GetOnCompletion() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSceneEntity", "m_OnCompletion"));
    return value;
}
void GCSceneEntity::SetOnCompletion(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_OnCompletion", false, value);
}
GCEntityIOOutput GCSceneEntity::GetOnCanceled() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSceneEntity", "m_OnCanceled"));
    return value;
}
void GCSceneEntity::SetOnCanceled(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_OnCanceled", false, value);
}
GCEntityIOOutput GCSceneEntity::GetOnPaused() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSceneEntity", "m_OnPaused"));
    return value;
}
void GCSceneEntity::SetOnPaused(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_OnPaused", false, value);
}
GCEntityIOOutput GCSceneEntity::GetOnResumed() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CSceneEntity", "m_OnResumed"));
    return value;
}
void GCSceneEntity::SetOnResumed(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_OnResumed", false, value);
}
std::vector<GCEntityIOOutput> GCSceneEntity::GetOnTrigger() const {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CSceneEntity", "m_OnTrigger"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 16; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSceneEntity::SetOnTrigger(std::vector<GCEntityIOOutput> value) {
    GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CSceneEntity", "m_OnTrigger"); for(int i = 0; i < 16; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSceneEntity", "m_OnTrigger", false, outValue);
}
GCSceneEntity GCSceneEntity::GetInterruptScene() const {
    GCSceneEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hInterruptScene"));
    return value;
}
void GCSceneEntity::SetInterruptScene(GCSceneEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'InterruptScene' is not possible.\n");
}
int32_t GCSceneEntity::GetInterruptCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_nInterruptCount");
}
void GCSceneEntity::SetInterruptCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_nInterruptCount", false, value);
}
bool GCSceneEntity::GetSceneMissing() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bSceneMissing");
}
void GCSceneEntity::SetSceneMissing(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bSceneMissing", false, value);
}
bool GCSceneEntity::GetInterrupted() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bInterrupted");
}
void GCSceneEntity::SetInterrupted(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bInterrupted", false, value);
}
bool GCSceneEntity::GetCompletedEarly() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bCompletedEarly");
}
void GCSceneEntity::SetCompletedEarly(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bCompletedEarly", false, value);
}
bool GCSceneEntity::GetInterruptSceneFinished() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bInterruptSceneFinished");
}
void GCSceneEntity::SetInterruptSceneFinished(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bInterruptSceneFinished", false, value);
}
bool GCSceneEntity::GetRestoring() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEntity", "m_bRestoring");
}
void GCSceneEntity::SetRestoring(bool value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_bRestoring", false, value);
}
std::string GCSceneEntity::GetSoundName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszSoundName").String();
}
void GCSceneEntity::SetSoundName(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszSoundName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSceneEntity::GetSequenceName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSceneEntity", "m_iszSequenceName").String();
}
void GCSceneEntity::SetSequenceName(std::string value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iszSequenceName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFlex GCSceneEntity::GetActor() const {
    GCBaseFlex value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hActor"));
    return value;
}
void GCSceneEntity::SetActor(GCBaseFlex* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Actor' is not possible.\n");
}
GCBaseEntity GCSceneEntity::GetActivator() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEntity", "m_hActivator"));
    return value;
}
void GCSceneEntity::SetActivator(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n");
}
int32_t GCSceneEntity::GetBusyActor() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSceneEntity", "m_BusyActor");
}
void GCSceneEntity::SetBusyActor(int32_t value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_BusyActor", false, value);
}
uint64_t GCSceneEntity::GetPlayerDeathBehavior() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSceneEntity", "m_iPlayerDeathBehavior");
}
void GCSceneEntity::SetPlayerDeathBehavior(uint64_t value) {
    SetSchemaValue(m_ptr, "CSceneEntity", "m_iPlayerDeathBehavior", false, value);
}
std::string GCSceneEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSceneEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCSceneEntity::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCSceneEntity::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSceneEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneEntity>("CSceneEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SceneFile", &GCSceneEntity::GetSceneFile, &GCSceneEntity::SetSceneFile)
        .addProperty("ResumeSceneFile", &GCSceneEntity::GetResumeSceneFile, &GCSceneEntity::SetResumeSceneFile)
        .addProperty("Target1", &GCSceneEntity::GetTarget1, &GCSceneEntity::SetTarget1)
        .addProperty("Target2", &GCSceneEntity::GetTarget2, &GCSceneEntity::SetTarget2)
        .addProperty("Target3", &GCSceneEntity::GetTarget3, &GCSceneEntity::SetTarget3)
        .addProperty("Target4", &GCSceneEntity::GetTarget4, &GCSceneEntity::SetTarget4)
        .addProperty("Target5", &GCSceneEntity::GetTarget5, &GCSceneEntity::SetTarget5)
        .addProperty("Target6", &GCSceneEntity::GetTarget6, &GCSceneEntity::SetTarget6)
        .addProperty("Target7", &GCSceneEntity::GetTarget7, &GCSceneEntity::SetTarget7)
        .addProperty("Target8", &GCSceneEntity::GetTarget8, &GCSceneEntity::SetTarget8)
        .addProperty("Target11", &GCSceneEntity::GetTarget11, &GCSceneEntity::SetTarget11)
        .addProperty("Target21", &GCSceneEntity::GetTarget21, &GCSceneEntity::SetTarget21)
        .addProperty("Target31", &GCSceneEntity::GetTarget31, &GCSceneEntity::SetTarget31)
        .addProperty("Target41", &GCSceneEntity::GetTarget41, &GCSceneEntity::SetTarget41)
        .addProperty("Target51", &GCSceneEntity::GetTarget51, &GCSceneEntity::SetTarget51)
        .addProperty("Target61", &GCSceneEntity::GetTarget61, &GCSceneEntity::SetTarget61)
        .addProperty("Target71", &GCSceneEntity::GetTarget71, &GCSceneEntity::SetTarget71)
        .addProperty("Target81", &GCSceneEntity::GetTarget81, &GCSceneEntity::SetTarget81)
        .addProperty("TargetAttachment", &GCSceneEntity::GetTargetAttachment, &GCSceneEntity::SetTargetAttachment)
        .addProperty("IsPlayingBack", &GCSceneEntity::GetIsPlayingBack, &GCSceneEntity::SetIsPlayingBack)
        .addProperty("Paused", &GCSceneEntity::GetPaused, &GCSceneEntity::SetPaused)
        .addProperty("Multiplayer", &GCSceneEntity::GetMultiplayer, &GCSceneEntity::SetMultiplayer)
        .addProperty("Autogenerated", &GCSceneEntity::GetAutogenerated, &GCSceneEntity::SetAutogenerated)
        .addProperty("ForceClientTime", &GCSceneEntity::GetForceClientTime, &GCSceneEntity::SetForceClientTime)
        .addProperty("CurrentTime", &GCSceneEntity::GetCurrentTime, &GCSceneEntity::SetCurrentTime)
        .addProperty("FrameTime", &GCSceneEntity::GetFrameTime, &GCSceneEntity::SetFrameTime)
        .addProperty("CancelAtNextInterrupt", &GCSceneEntity::GetCancelAtNextInterrupt, &GCSceneEntity::SetCancelAtNextInterrupt)
        .addProperty("Pitch", &GCSceneEntity::GetPitch, &GCSceneEntity::SetPitch)
        .addProperty("Automated", &GCSceneEntity::GetAutomated, &GCSceneEntity::SetAutomated)
        .addProperty("AutomatedAction", &GCSceneEntity::GetAutomatedAction, &GCSceneEntity::SetAutomatedAction)
        .addProperty("AutomationDelay", &GCSceneEntity::GetAutomationDelay, &GCSceneEntity::SetAutomationDelay)
        .addProperty("AutomationTime", &GCSceneEntity::GetAutomationTime, &GCSceneEntity::SetAutomationTime)
        .addProperty("WaitingForThisResumeScene", &GCSceneEntity::GetWaitingForThisResumeScene, &GCSceneEntity::SetWaitingForThisResumeScene)
        .addProperty("WaitingForResumeScene", &GCSceneEntity::GetWaitingForResumeScene, &GCSceneEntity::SetWaitingForResumeScene)
        .addProperty("PausedViaInput", &GCSceneEntity::GetPausedViaInput, &GCSceneEntity::SetPausedViaInput)
        .addProperty("PauseAtNextInterrupt", &GCSceneEntity::GetPauseAtNextInterrupt, &GCSceneEntity::SetPauseAtNextInterrupt)
        .addProperty("WaitingForActor", &GCSceneEntity::GetWaitingForActor, &GCSceneEntity::SetWaitingForActor)
        .addProperty("WaitingForInterrupt", &GCSceneEntity::GetWaitingForInterrupt, &GCSceneEntity::SetWaitingForInterrupt)
        .addProperty("InterruptedActorsScenes", &GCSceneEntity::GetInterruptedActorsScenes, &GCSceneEntity::SetInterruptedActorsScenes)
        .addProperty("BreakOnNonIdle", &GCSceneEntity::GetBreakOnNonIdle, &GCSceneEntity::SetBreakOnNonIdle)
        .addProperty("SceneFinished", &GCSceneEntity::GetSceneFinished, &GCSceneEntity::SetSceneFinished)
        .addProperty("ActorList", &GCSceneEntity::GetActorList, &GCSceneEntity::SetActorList)
        .addProperty("SceneFlushCounter", &GCSceneEntity::GetSceneFlushCounter, &GCSceneEntity::SetSceneFlushCounter)
        .addProperty("SceneStringIndex", &GCSceneEntity::GetSceneStringIndex, &GCSceneEntity::SetSceneStringIndex)
        .addProperty("OnStart", &GCSceneEntity::GetOnStart, &GCSceneEntity::SetOnStart)
        .addProperty("OnCompletion", &GCSceneEntity::GetOnCompletion, &GCSceneEntity::SetOnCompletion)
        .addProperty("OnCanceled", &GCSceneEntity::GetOnCanceled, &GCSceneEntity::SetOnCanceled)
        .addProperty("OnPaused", &GCSceneEntity::GetOnPaused, &GCSceneEntity::SetOnPaused)
        .addProperty("OnResumed", &GCSceneEntity::GetOnResumed, &GCSceneEntity::SetOnResumed)
        .addProperty("OnTrigger", &GCSceneEntity::GetOnTrigger, &GCSceneEntity::SetOnTrigger)
        .addProperty("InterruptScene", &GCSceneEntity::GetInterruptScene, &GCSceneEntity::SetInterruptScene)
        .addProperty("InterruptCount", &GCSceneEntity::GetInterruptCount, &GCSceneEntity::SetInterruptCount)
        .addProperty("SceneMissing", &GCSceneEntity::GetSceneMissing, &GCSceneEntity::SetSceneMissing)
        .addProperty("Interrupted", &GCSceneEntity::GetInterrupted, &GCSceneEntity::SetInterrupted)
        .addProperty("CompletedEarly", &GCSceneEntity::GetCompletedEarly, &GCSceneEntity::SetCompletedEarly)
        .addProperty("InterruptSceneFinished", &GCSceneEntity::GetInterruptSceneFinished, &GCSceneEntity::SetInterruptSceneFinished)
        .addProperty("Restoring", &GCSceneEntity::GetRestoring, &GCSceneEntity::SetRestoring)
        .addProperty("SoundName", &GCSceneEntity::GetSoundName, &GCSceneEntity::SetSoundName)
        .addProperty("SequenceName", &GCSceneEntity::GetSequenceName, &GCSceneEntity::SetSequenceName)
        .addProperty("Actor", &GCSceneEntity::GetActor, &GCSceneEntity::SetActor)
        .addProperty("Activator", &GCSceneEntity::GetActivator, &GCSceneEntity::SetActivator)
        .addProperty("BusyActor", &GCSceneEntity::GetBusyActor, &GCSceneEntity::SetBusyActor)
        .addProperty("PlayerDeathBehavior", &GCSceneEntity::GetPlayerDeathBehavior, &GCSceneEntity::SetPlayerDeathBehavior)
        .addProperty("Parent", &GCSceneEntity::GetParent, &GCSceneEntity::SetParent)
        .addFunction("ToPtr", &GCSceneEntity::ToPtr)
        .addFunction("IsValid", &GCSceneEntity::IsValid)
        .endClass();
}