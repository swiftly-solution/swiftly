#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAI_Expresser::GCAI_Expresser(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAI_Expresser::GCAI_Expresser(void *ptr) {
    m_ptr = ptr;
}
float GCAI_Expresser::GetStopTalkTime() const {
    return GetSchemaValue<float>(m_ptr, "CAI_Expresser", "m_flStopTalkTime");
}
void GCAI_Expresser::SetStopTalkTime(float value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_flStopTalkTime", false, value);
}
float GCAI_Expresser::GetStopTalkTimeWithoutDelay() const {
    return GetSchemaValue<float>(m_ptr, "CAI_Expresser", "m_flStopTalkTimeWithoutDelay");
}
void GCAI_Expresser::SetStopTalkTimeWithoutDelay(float value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_flStopTalkTimeWithoutDelay", false, value);
}
float GCAI_Expresser::GetBlockedTalkTime() const {
    return GetSchemaValue<float>(m_ptr, "CAI_Expresser", "m_flBlockedTalkTime");
}
void GCAI_Expresser::SetBlockedTalkTime(float value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_flBlockedTalkTime", false, value);
}
int32_t GCAI_Expresser::GetVoicePitch() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAI_Expresser", "m_voicePitch");
}
void GCAI_Expresser::SetVoicePitch(int32_t value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_voicePitch", false, value);
}
float GCAI_Expresser::GetLastTimeAcceptedSpeak() const {
    return GetSchemaValue<float>(m_ptr, "CAI_Expresser", "m_flLastTimeAcceptedSpeak");
}
void GCAI_Expresser::SetLastTimeAcceptedSpeak(float value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_flLastTimeAcceptedSpeak", false, value);
}
bool GCAI_Expresser::GetAllowSpeakingInterrupts() const {
    return GetSchemaValue<bool>(m_ptr, "CAI_Expresser", "m_bAllowSpeakingInterrupts");
}
void GCAI_Expresser::SetAllowSpeakingInterrupts(bool value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_bAllowSpeakingInterrupts", false, value);
}
bool GCAI_Expresser::GetConsiderSceneInvolvementAsSpeech() const {
    return GetSchemaValue<bool>(m_ptr, "CAI_Expresser", "m_bConsiderSceneInvolvementAsSpeech");
}
void GCAI_Expresser::SetConsiderSceneInvolvementAsSpeech(bool value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_bConsiderSceneInvolvementAsSpeech", false, value);
}
bool GCAI_Expresser::GetSceneEntityDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CAI_Expresser", "m_bSceneEntityDisabled");
}
void GCAI_Expresser::SetSceneEntityDisabled(bool value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_bSceneEntityDisabled", false, value);
}
int32_t GCAI_Expresser::GetLastSpokenPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAI_Expresser", "m_nLastSpokenPriority");
}
void GCAI_Expresser::SetLastSpokenPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CAI_Expresser", "m_nLastSpokenPriority", false, value);
}
GCBaseFlex GCAI_Expresser::GetOuter() const {
    GCBaseFlex value(*GetSchemaValuePtr<void*>(m_ptr, "CAI_Expresser", "m_pOuter"));
    return value;
}
void GCAI_Expresser::SetOuter(GCBaseFlex* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Outer' is not possible.\n");
}
std::string GCAI_Expresser::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAI_Expresser::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAI_Expresser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAI_Expresser>("CAI_Expresser")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StopTalkTime", &GCAI_Expresser::GetStopTalkTime, &GCAI_Expresser::SetStopTalkTime)
        .addProperty("StopTalkTimeWithoutDelay", &GCAI_Expresser::GetStopTalkTimeWithoutDelay, &GCAI_Expresser::SetStopTalkTimeWithoutDelay)
        .addProperty("BlockedTalkTime", &GCAI_Expresser::GetBlockedTalkTime, &GCAI_Expresser::SetBlockedTalkTime)
        .addProperty("VoicePitch", &GCAI_Expresser::GetVoicePitch, &GCAI_Expresser::SetVoicePitch)
        .addProperty("LastTimeAcceptedSpeak", &GCAI_Expresser::GetLastTimeAcceptedSpeak, &GCAI_Expresser::SetLastTimeAcceptedSpeak)
        .addProperty("AllowSpeakingInterrupts", &GCAI_Expresser::GetAllowSpeakingInterrupts, &GCAI_Expresser::SetAllowSpeakingInterrupts)
        .addProperty("ConsiderSceneInvolvementAsSpeech", &GCAI_Expresser::GetConsiderSceneInvolvementAsSpeech, &GCAI_Expresser::SetConsiderSceneInvolvementAsSpeech)
        .addProperty("SceneEntityDisabled", &GCAI_Expresser::GetSceneEntityDisabled, &GCAI_Expresser::SetSceneEntityDisabled)
        .addProperty("LastSpokenPriority", &GCAI_Expresser::GetLastSpokenPriority, &GCAI_Expresser::SetLastSpokenPriority)
        .addProperty("Outer", &GCAI_Expresser::GetOuter, &GCAI_Expresser::SetOuter)
        .addFunction("ToPtr", &GCAI_Expresser::ToPtr)
        .addFunction("IsValid", &GCAI_Expresser::IsValid)
        .endClass();
}