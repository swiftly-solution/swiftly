#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlantedC4::GCPlantedC4(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlantedC4::GCPlantedC4(void *ptr) {
    m_ptr = ptr;
}
bool GCPlantedC4::GetBombTicking() const {
    return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bBombTicking");
}
void GCPlantedC4::SetBombTicking(bool value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_bBombTicking", false, value);
}
float GCPlantedC4::GetC4Blow() const {
    return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flC4Blow");
}
void GCPlantedC4::SetC4Blow(float value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_flC4Blow", false, value);
}
int32_t GCPlantedC4::GetBombSite() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_nBombSite");
}
void GCPlantedC4::SetBombSite(int32_t value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_nBombSite", false, value);
}
int32_t GCPlantedC4::GetSourceSoundscapeHash() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_nSourceSoundscapeHash");
}
void GCPlantedC4::SetSourceSoundscapeHash(int32_t value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_nSourceSoundscapeHash", false, value);
}
GCEntityIOOutput GCPlantedC4::GetOnBombDefused() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPlantedC4", "m_OnBombDefused"));
    return value;
}
void GCPlantedC4::SetOnBombDefused(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_OnBombDefused", false, value);
}
GCEntityIOOutput GCPlantedC4::GetOnBombBeginDefuse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPlantedC4", "m_OnBombBeginDefuse"));
    return value;
}
void GCPlantedC4::SetOnBombBeginDefuse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_OnBombBeginDefuse", false, value);
}
GCEntityIOOutput GCPlantedC4::GetOnBombDefuseAborted() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPlantedC4", "m_OnBombDefuseAborted"));
    return value;
}
void GCPlantedC4::SetOnBombDefuseAborted(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_OnBombDefuseAborted", false, value);
}
bool GCPlantedC4::GetCannotBeDefused() const {
    return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bCannotBeDefused");
}
void GCPlantedC4::SetCannotBeDefused(bool value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_bCannotBeDefused", false, value);
}
GEntitySpottedState_t GCPlantedC4::GetEntitySpottedState() const {
    GEntitySpottedState_t value(GetSchemaPtr(m_ptr, "CPlantedC4", "m_entitySpottedState"));
    return value;
}
void GCPlantedC4::SetEntitySpottedState(GEntitySpottedState_t value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_entitySpottedState", false, value);
}
int32_t GCPlantedC4::GetSpotRules() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_nSpotRules");
}
void GCPlantedC4::SetSpotRules(int32_t value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_nSpotRules", false, value);
}
bool GCPlantedC4::GetTrainingPlacedByPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bTrainingPlacedByPlayer");
}
void GCPlantedC4::SetTrainingPlacedByPlayer(bool value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_bTrainingPlacedByPlayer", false, value);
}
bool GCPlantedC4::GetHasExploded() const {
    return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bHasExploded");
}
void GCPlantedC4::SetHasExploded(bool value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_bHasExploded", false, value);
}
float GCPlantedC4::GetTimerLength() const {
    return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flTimerLength");
}
void GCPlantedC4::SetTimerLength(float value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_flTimerLength", false, value);
}
bool GCPlantedC4::GetBeingDefused() const {
    return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bBeingDefused");
}
void GCPlantedC4::SetBeingDefused(bool value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_bBeingDefused", false, value);
}
float GCPlantedC4::GetLastDefuseTime() const {
    return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_fLastDefuseTime");
}
void GCPlantedC4::SetLastDefuseTime(float value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_fLastDefuseTime", false, value);
}
float GCPlantedC4::GetDefuseLength() const {
    return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flDefuseLength");
}
void GCPlantedC4::SetDefuseLength(float value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_flDefuseLength", false, value);
}
float GCPlantedC4::GetDefuseCountDown() const {
    return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flDefuseCountDown");
}
void GCPlantedC4::SetDefuseCountDown(float value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_flDefuseCountDown", false, value);
}
bool GCPlantedC4::GetBombDefused() const {
    return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bBombDefused");
}
void GCPlantedC4::SetBombDefused(bool value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_bBombDefused", false, value);
}
GCCSPlayerPawn GCPlantedC4::GetBombDefuser() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CPlantedC4", "m_hBombDefuser"));
    return value;
}
void GCPlantedC4::SetBombDefuser(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'BombDefuser' is not possible.\n");
}
GCBaseEntity GCPlantedC4::GetControlPanel() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPlantedC4", "m_hControlPanel"));
    return value;
}
void GCPlantedC4::SetControlPanel(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ControlPanel' is not possible.\n");
}
int32_t GCPlantedC4::GetProgressBarTime() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlantedC4", "m_iProgressBarTime");
}
void GCPlantedC4::SetProgressBarTime(int32_t value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_iProgressBarTime", false, value);
}
bool GCPlantedC4::GetVoiceAlertFired() const {
    return GetSchemaValue<bool>(m_ptr, "CPlantedC4", "m_bVoiceAlertFired");
}
void GCPlantedC4::SetVoiceAlertFired(bool value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_bVoiceAlertFired", false, value);
}
std::vector<bool> GCPlantedC4::GetVoiceAlertPlayed() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CPlantedC4", "m_bVoiceAlertPlayed"); std::vector<bool> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCPlantedC4::SetVoiceAlertPlayed(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CPlantedC4", "m_bVoiceAlertPlayed"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlantedC4", "m_bVoiceAlertPlayed", false, outValue);
}
float GCPlantedC4::GetNextBotBeepTime() const {
    return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flNextBotBeepTime");
}
void GCPlantedC4::SetNextBotBeepTime(float value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_flNextBotBeepTime", false, value);
}
QAngle GCPlantedC4::GetCatchUpToPlayerEye() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPlantedC4", "m_angCatchUpToPlayerEye");
}
void GCPlantedC4::SetCatchUpToPlayerEye(QAngle value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_angCatchUpToPlayerEye", false, value);
}
float GCPlantedC4::GetLastSpinDetectionTime() const {
    return GetSchemaValue<float>(m_ptr, "CPlantedC4", "m_flLastSpinDetectionTime");
}
void GCPlantedC4::SetLastSpinDetectionTime(float value) {
    SetSchemaValue(m_ptr, "CPlantedC4", "m_flLastSpinDetectionTime", false, value);
}
std::string GCPlantedC4::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlantedC4::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCPlantedC4::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCPlantedC4::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlantedC4(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlantedC4>("CPlantedC4")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BombTicking", &GCPlantedC4::GetBombTicking, &GCPlantedC4::SetBombTicking)
        .addProperty("C4Blow", &GCPlantedC4::GetC4Blow, &GCPlantedC4::SetC4Blow)
        .addProperty("BombSite", &GCPlantedC4::GetBombSite, &GCPlantedC4::SetBombSite)
        .addProperty("SourceSoundscapeHash", &GCPlantedC4::GetSourceSoundscapeHash, &GCPlantedC4::SetSourceSoundscapeHash)
        .addProperty("OnBombDefused", &GCPlantedC4::GetOnBombDefused, &GCPlantedC4::SetOnBombDefused)
        .addProperty("OnBombBeginDefuse", &GCPlantedC4::GetOnBombBeginDefuse, &GCPlantedC4::SetOnBombBeginDefuse)
        .addProperty("OnBombDefuseAborted", &GCPlantedC4::GetOnBombDefuseAborted, &GCPlantedC4::SetOnBombDefuseAborted)
        .addProperty("CannotBeDefused", &GCPlantedC4::GetCannotBeDefused, &GCPlantedC4::SetCannotBeDefused)
        .addProperty("EntitySpottedState", &GCPlantedC4::GetEntitySpottedState, &GCPlantedC4::SetEntitySpottedState)
        .addProperty("SpotRules", &GCPlantedC4::GetSpotRules, &GCPlantedC4::SetSpotRules)
        .addProperty("TrainingPlacedByPlayer", &GCPlantedC4::GetTrainingPlacedByPlayer, &GCPlantedC4::SetTrainingPlacedByPlayer)
        .addProperty("HasExploded", &GCPlantedC4::GetHasExploded, &GCPlantedC4::SetHasExploded)
        .addProperty("TimerLength", &GCPlantedC4::GetTimerLength, &GCPlantedC4::SetTimerLength)
        .addProperty("BeingDefused", &GCPlantedC4::GetBeingDefused, &GCPlantedC4::SetBeingDefused)
        .addProperty("LastDefuseTime", &GCPlantedC4::GetLastDefuseTime, &GCPlantedC4::SetLastDefuseTime)
        .addProperty("DefuseLength", &GCPlantedC4::GetDefuseLength, &GCPlantedC4::SetDefuseLength)
        .addProperty("DefuseCountDown", &GCPlantedC4::GetDefuseCountDown, &GCPlantedC4::SetDefuseCountDown)
        .addProperty("BombDefused", &GCPlantedC4::GetBombDefused, &GCPlantedC4::SetBombDefused)
        .addProperty("BombDefuser", &GCPlantedC4::GetBombDefuser, &GCPlantedC4::SetBombDefuser)
        .addProperty("ControlPanel", &GCPlantedC4::GetControlPanel, &GCPlantedC4::SetControlPanel)
        .addProperty("ProgressBarTime", &GCPlantedC4::GetProgressBarTime, &GCPlantedC4::SetProgressBarTime)
        .addProperty("VoiceAlertFired", &GCPlantedC4::GetVoiceAlertFired, &GCPlantedC4::SetVoiceAlertFired)
        .addProperty("VoiceAlertPlayed", &GCPlantedC4::GetVoiceAlertPlayed, &GCPlantedC4::SetVoiceAlertPlayed)
        .addProperty("NextBotBeepTime", &GCPlantedC4::GetNextBotBeepTime, &GCPlantedC4::SetNextBotBeepTime)
        .addProperty("CatchUpToPlayerEye", &GCPlantedC4::GetCatchUpToPlayerEye, &GCPlantedC4::SetCatchUpToPlayerEye)
        .addProperty("LastSpinDetectionTime", &GCPlantedC4::GetLastSpinDetectionTime, &GCPlantedC4::SetLastSpinDetectionTime)
        .addProperty("Parent", &GCPlantedC4::GetParent, &GCPlantedC4::SetParent)
        .addFunction("ToPtr", &GCPlantedC4::ToPtr)
        .addFunction("IsValid", &GCPlantedC4::IsValid)
        .endClass();
}