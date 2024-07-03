#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseAnimGraphController::GCBaseAnimGraphController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseAnimGraphController::GCBaseAnimGraphController(void *ptr) {
    m_ptr = ptr;
}
GCAnimGraphNetworkedVariables GCBaseAnimGraphController::GetAnimGraphNetworkedVars() const {
    GCAnimGraphNetworkedVariables value(GetSchemaPtr(m_ptr, "CBaseAnimGraphController", "m_animGraphNetworkedVars"));
    return value;
}
void GCBaseAnimGraphController::SetAnimGraphNetworkedVars(GCAnimGraphNetworkedVariables value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_animGraphNetworkedVars", false, value);
}
bool GCBaseAnimGraphController::GetSequenceFinished() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bSequenceFinished");
}
void GCBaseAnimGraphController::SetSequenceFinished(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bSequenceFinished", false, value);
}
float GCBaseAnimGraphController::GetSoundSyncTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flSoundSyncTime");
}
void GCBaseAnimGraphController::SetSoundSyncTime(float value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flSoundSyncTime", false, value);
}
uint32_t GCBaseAnimGraphController::GetActiveIKChainMask() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseAnimGraphController", "m_nActiveIKChainMask");
}
void GCBaseAnimGraphController::SetActiveIKChainMask(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_nActiveIKChainMask", false, value);
}
float GCBaseAnimGraphController::GetSeqStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flSeqStartTime");
}
void GCBaseAnimGraphController::SetSeqStartTime(float value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flSeqStartTime", false, value);
}
float GCBaseAnimGraphController::GetSeqFixedCycle() const {
    return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flSeqFixedCycle");
}
void GCBaseAnimGraphController::SetSeqFixedCycle(float value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flSeqFixedCycle", false, value);
}
uint64_t GCBaseAnimGraphController::GetAnimLoopMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseAnimGraphController", "m_nAnimLoopMode");
}
void GCBaseAnimGraphController::SetAnimLoopMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_nAnimLoopMode", false, value);
}
float GCBaseAnimGraphController::GetPlaybackRate() const {
    return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flPlaybackRate");
}
void GCBaseAnimGraphController::SetPlaybackRate(float value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flPlaybackRate", false, value);
}
uint64_t GCBaseAnimGraphController::GetNotifyState() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseAnimGraphController", "m_nNotifyState");
}
void GCBaseAnimGraphController::SetNotifyState(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_nNotifyState", false, value);
}
bool GCBaseAnimGraphController::GetNetworkedAnimationInputsChanged() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bNetworkedAnimationInputsChanged");
}
void GCBaseAnimGraphController::SetNetworkedAnimationInputsChanged(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bNetworkedAnimationInputsChanged", false, value);
}
bool GCBaseAnimGraphController::GetNetworkedSequenceChanged() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bNetworkedSequenceChanged");
}
void GCBaseAnimGraphController::SetNetworkedSequenceChanged(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bNetworkedSequenceChanged", false, value);
}
bool GCBaseAnimGraphController::GetLastUpdateSkipped() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraphController", "m_bLastUpdateSkipped");
}
void GCBaseAnimGraphController::SetLastUpdateSkipped(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_bLastUpdateSkipped", false, value);
}
float GCBaseAnimGraphController::GetPrevAnimUpdateTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseAnimGraphController", "m_flPrevAnimUpdateTime");
}
void GCBaseAnimGraphController::SetPrevAnimUpdateTime(float value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraphController", "m_flPrevAnimUpdateTime", false, value);
}
std::string GCBaseAnimGraphController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseAnimGraphController::IsValid() {
    return (m_ptr != nullptr);
}
GCSkeletonAnimationController GCBaseAnimGraphController::GetParent() const {
    GCSkeletonAnimationController value(m_ptr);
    return value;
}
void GCBaseAnimGraphController::SetParent(GCSkeletonAnimationController value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseAnimGraphController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseAnimGraphController>("CBaseAnimGraphController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AnimGraphNetworkedVars", &GCBaseAnimGraphController::GetAnimGraphNetworkedVars, &GCBaseAnimGraphController::SetAnimGraphNetworkedVars)
        .addProperty("SequenceFinished", &GCBaseAnimGraphController::GetSequenceFinished, &GCBaseAnimGraphController::SetSequenceFinished)
        .addProperty("SoundSyncTime", &GCBaseAnimGraphController::GetSoundSyncTime, &GCBaseAnimGraphController::SetSoundSyncTime)
        .addProperty("ActiveIKChainMask", &GCBaseAnimGraphController::GetActiveIKChainMask, &GCBaseAnimGraphController::SetActiveIKChainMask)
        .addProperty("SeqStartTime", &GCBaseAnimGraphController::GetSeqStartTime, &GCBaseAnimGraphController::SetSeqStartTime)
        .addProperty("SeqFixedCycle", &GCBaseAnimGraphController::GetSeqFixedCycle, &GCBaseAnimGraphController::SetSeqFixedCycle)
        .addProperty("AnimLoopMode", &GCBaseAnimGraphController::GetAnimLoopMode, &GCBaseAnimGraphController::SetAnimLoopMode)
        .addProperty("PlaybackRate", &GCBaseAnimGraphController::GetPlaybackRate, &GCBaseAnimGraphController::SetPlaybackRate)
        .addProperty("NotifyState", &GCBaseAnimGraphController::GetNotifyState, &GCBaseAnimGraphController::SetNotifyState)
        .addProperty("NetworkedAnimationInputsChanged", &GCBaseAnimGraphController::GetNetworkedAnimationInputsChanged, &GCBaseAnimGraphController::SetNetworkedAnimationInputsChanged)
        .addProperty("NetworkedSequenceChanged", &GCBaseAnimGraphController::GetNetworkedSequenceChanged, &GCBaseAnimGraphController::SetNetworkedSequenceChanged)
        .addProperty("LastUpdateSkipped", &GCBaseAnimGraphController::GetLastUpdateSkipped, &GCBaseAnimGraphController::SetLastUpdateSkipped)
        .addProperty("PrevAnimUpdateTime", &GCBaseAnimGraphController::GetPrevAnimUpdateTime, &GCBaseAnimGraphController::SetPrevAnimUpdateTime)
        .addProperty("Parent", &GCBaseAnimGraphController::GetParent, &GCBaseAnimGraphController::SetParent)
        .addFunction("ToPtr", &GCBaseAnimGraphController::ToPtr)
        .addFunction("IsValid", &GCBaseAnimGraphController::IsValid)
        .endClass();
}