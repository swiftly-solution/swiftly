#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMapVetoPickController::GCMapVetoPickController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMapVetoPickController::GCMapVetoPickController(void *ptr) {
    m_ptr = ptr;
}
bool GCMapVetoPickController::GetPlayedIntroVcd() const {
    return GetSchemaValue<bool>(m_ptr, "CMapVetoPickController", "m_bPlayedIntroVcd");
}
void GCMapVetoPickController::SetPlayedIntroVcd(bool value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_bPlayedIntroVcd", false, value);
}
bool GCMapVetoPickController::GetNeedToPlayFiveSecondsRemaining() const {
    return GetSchemaValue<bool>(m_ptr, "CMapVetoPickController", "m_bNeedToPlayFiveSecondsRemaining");
}
void GCMapVetoPickController::SetNeedToPlayFiveSecondsRemaining(bool value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_bNeedToPlayFiveSecondsRemaining", false, value);
}
double GCMapVetoPickController::GetDblPreMatchDraftSequenceTime() const {
    return GetSchemaValue<double>(m_ptr, "CMapVetoPickController", "m_dblPreMatchDraftSequenceTime");
}
void GCMapVetoPickController::SetDblPreMatchDraftSequenceTime(double value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_dblPreMatchDraftSequenceTime", false, value);
}
bool GCMapVetoPickController::GetPreMatchDraftStateChanged() const {
    return GetSchemaValue<bool>(m_ptr, "CMapVetoPickController", "m_bPreMatchDraftStateChanged");
}
void GCMapVetoPickController::SetPreMatchDraftStateChanged(bool value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_bPreMatchDraftStateChanged", false, value);
}
int32_t GCMapVetoPickController::GetDraftType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nDraftType");
}
void GCMapVetoPickController::SetDraftType(int32_t value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nDraftType", false, value);
}
int32_t GCMapVetoPickController::GetTeamWinningCoinToss() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nTeamWinningCoinToss");
}
void GCMapVetoPickController::SetTeamWinningCoinToss(int32_t value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nTeamWinningCoinToss", false, value);
}
std::vector<int32_t> GCMapVetoPickController::GetTeamWithFirstChoice() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nTeamWithFirstChoice"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetTeamWithFirstChoice(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nTeamWithFirstChoice"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nTeamWithFirstChoice", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetVoteMapIdsList() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nVoteMapIdsList"); std::vector<int32_t> ret; for(int i = 0; i < 7; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetVoteMapIdsList(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nVoteMapIdsList"); for(int i = 0; i < 7; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nVoteMapIdsList", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetAccountIDs() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nAccountIDs"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetAccountIDs(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nAccountIDs"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nAccountIDs", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetMapId0() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId0"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetMapId0(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId0"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId0", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetMapId1() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId1"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetMapId1(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId1"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId1", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetMapId2() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId2"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetMapId2(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId2"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId2", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetMapId3() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId3"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetMapId3(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId3"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId3", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetMapId4() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId4"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetMapId4(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId4"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId4", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetMapId5() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId5"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetMapId5(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nMapId5"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nMapId5", false, outValue);
}
std::vector<int32_t> GCMapVetoPickController::GetStartingSide0() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nStartingSide0"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMapVetoPickController::SetStartingSide0(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMapVetoPickController", "m_nStartingSide0"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nStartingSide0", false, outValue);
}
int32_t GCMapVetoPickController::GetCurrentPhase() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nCurrentPhase");
}
void GCMapVetoPickController::SetCurrentPhase(int32_t value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nCurrentPhase", false, value);
}
int32_t GCMapVetoPickController::GetPhaseStartTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nPhaseStartTick");
}
void GCMapVetoPickController::SetPhaseStartTick(int32_t value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nPhaseStartTick", false, value);
}
int32_t GCMapVetoPickController::GetPhaseDurationTicks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMapVetoPickController", "m_nPhaseDurationTicks");
}
void GCMapVetoPickController::SetPhaseDurationTicks(int32_t value) {
    SetSchemaValue(m_ptr, "CMapVetoPickController", "m_nPhaseDurationTicks", false, value);
}
std::string GCMapVetoPickController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMapVetoPickController::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCMapVetoPickController::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCMapVetoPickController::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMapVetoPickController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMapVetoPickController>("CMapVetoPickController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlayedIntroVcd", &GCMapVetoPickController::GetPlayedIntroVcd, &GCMapVetoPickController::SetPlayedIntroVcd)
        .addProperty("NeedToPlayFiveSecondsRemaining", &GCMapVetoPickController::GetNeedToPlayFiveSecondsRemaining, &GCMapVetoPickController::SetNeedToPlayFiveSecondsRemaining)
        .addProperty("DblPreMatchDraftSequenceTime", &GCMapVetoPickController::GetDblPreMatchDraftSequenceTime, &GCMapVetoPickController::SetDblPreMatchDraftSequenceTime)
        .addProperty("PreMatchDraftStateChanged", &GCMapVetoPickController::GetPreMatchDraftStateChanged, &GCMapVetoPickController::SetPreMatchDraftStateChanged)
        .addProperty("DraftType", &GCMapVetoPickController::GetDraftType, &GCMapVetoPickController::SetDraftType)
        .addProperty("TeamWinningCoinToss", &GCMapVetoPickController::GetTeamWinningCoinToss, &GCMapVetoPickController::SetTeamWinningCoinToss)
        .addProperty("TeamWithFirstChoice", &GCMapVetoPickController::GetTeamWithFirstChoice, &GCMapVetoPickController::SetTeamWithFirstChoice)
        .addProperty("VoteMapIdsList", &GCMapVetoPickController::GetVoteMapIdsList, &GCMapVetoPickController::SetVoteMapIdsList)
        .addProperty("AccountIDs", &GCMapVetoPickController::GetAccountIDs, &GCMapVetoPickController::SetAccountIDs)
        .addProperty("MapId0", &GCMapVetoPickController::GetMapId0, &GCMapVetoPickController::SetMapId0)
        .addProperty("MapId1", &GCMapVetoPickController::GetMapId1, &GCMapVetoPickController::SetMapId1)
        .addProperty("MapId2", &GCMapVetoPickController::GetMapId2, &GCMapVetoPickController::SetMapId2)
        .addProperty("MapId3", &GCMapVetoPickController::GetMapId3, &GCMapVetoPickController::SetMapId3)
        .addProperty("MapId4", &GCMapVetoPickController::GetMapId4, &GCMapVetoPickController::SetMapId4)
        .addProperty("MapId5", &GCMapVetoPickController::GetMapId5, &GCMapVetoPickController::SetMapId5)
        .addProperty("StartingSide0", &GCMapVetoPickController::GetStartingSide0, &GCMapVetoPickController::SetStartingSide0)
        .addProperty("CurrentPhase", &GCMapVetoPickController::GetCurrentPhase, &GCMapVetoPickController::SetCurrentPhase)
        .addProperty("PhaseStartTick", &GCMapVetoPickController::GetPhaseStartTick, &GCMapVetoPickController::SetPhaseStartTick)
        .addProperty("PhaseDurationTicks", &GCMapVetoPickController::GetPhaseDurationTicks, &GCMapVetoPickController::SetPhaseDurationTicks)
        .addProperty("Parent", &GCMapVetoPickController::GetParent, &GCMapVetoPickController::SetParent)
        .addFunction("ToPtr", &GCMapVetoPickController::ToPtr)
        .addFunction("IsValid", &GCMapVetoPickController::IsValid)
        .endClass();
}