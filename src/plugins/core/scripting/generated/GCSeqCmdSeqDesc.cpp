#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqCmdSeqDesc::GCSeqCmdSeqDesc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqCmdSeqDesc::GCSeqCmdSeqDesc(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSeqCmdSeqDesc::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqCmdSeqDesc", "m_sName");
}
void GCSeqCmdSeqDesc::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_sName", false, value);
}
GCSeqSeqDescFlag GCSeqCmdSeqDesc::GetFlags() const {
    GCSeqSeqDescFlag value(GetSchemaPtr(m_ptr, "CSeqCmdSeqDesc", "m_flags"));
    return value;
}
void GCSeqCmdSeqDesc::SetFlags(GCSeqSeqDescFlag value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_flags", false, value);
}
GCSeqTransition GCSeqCmdSeqDesc::GetTransition() const {
    GCSeqTransition value(GetSchemaPtr(m_ptr, "CSeqCmdSeqDesc", "m_transition"));
    return value;
}
void GCSeqCmdSeqDesc::SetTransition(GCSeqTransition value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_transition", false, value);
}
int16_t GCSeqCmdSeqDesc::GetFrameRangeSequence() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_nFrameRangeSequence");
}
void GCSeqCmdSeqDesc::SetFrameRangeSequence(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_nFrameRangeSequence", false, value);
}
int16_t GCSeqCmdSeqDesc::GetFrameCount() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_nFrameCount");
}
void GCSeqCmdSeqDesc::SetFrameCount(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_nFrameCount", false, value);
}
float GCSeqCmdSeqDesc::GetFPS() const {
    return GetSchemaValue<float>(m_ptr, "CSeqCmdSeqDesc", "m_flFPS");
}
void GCSeqCmdSeqDesc::SetFPS(float value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_flFPS", false, value);
}
int16_t GCSeqCmdSeqDesc::GetSubCycles() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_nSubCycles");
}
void GCSeqCmdSeqDesc::SetSubCycles(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_nSubCycles", false, value);
}
int16_t GCSeqCmdSeqDesc::GetNumLocalResults() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdSeqDesc", "m_numLocalResults");
}
void GCSeqCmdSeqDesc::SetNumLocalResults(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqCmdSeqDesc", "m_numLocalResults", false, value);
}
std::vector<GCSeqCmdLayer> GCSeqCmdSeqDesc::GetCmdLayerArray() const {
    CUtlVector<GCSeqCmdLayer>* vec = GetSchemaValue<CUtlVector<GCSeqCmdLayer>*>(m_ptr, "CSeqCmdSeqDesc", "m_cmdLayerArray"); std::vector<GCSeqCmdLayer> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqCmdSeqDesc::SetCmdLayerArray(std::vector<GCSeqCmdLayer> value) {
    SetSchemaValueCUtlVector<GCSeqCmdLayer>(m_ptr, "CSeqCmdSeqDesc", "m_cmdLayerArray", false, value);
}
std::vector<GCAnimEventDefinition> GCSeqCmdSeqDesc::GetEventArray() const {
    CUtlVector<GCAnimEventDefinition>* vec = GetSchemaValue<CUtlVector<GCAnimEventDefinition>*>(m_ptr, "CSeqCmdSeqDesc", "m_eventArray"); std::vector<GCAnimEventDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqCmdSeqDesc::SetEventArray(std::vector<GCAnimEventDefinition> value) {
    SetSchemaValueCUtlVector<GCAnimEventDefinition>(m_ptr, "CSeqCmdSeqDesc", "m_eventArray", false, value);
}
std::vector<GCAnimActivity> GCSeqCmdSeqDesc::GetActivityArray() const {
    CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CSeqCmdSeqDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqCmdSeqDesc::SetActivityArray(std::vector<GCAnimActivity> value) {
    SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CSeqCmdSeqDesc", "m_activityArray", false, value);
}
std::vector<GCSeqPoseSetting> GCSeqCmdSeqDesc::GetPoseSettingArray() const {
    CUtlVector<GCSeqPoseSetting>* vec = GetSchemaValue<CUtlVector<GCSeqPoseSetting>*>(m_ptr, "CSeqCmdSeqDesc", "m_poseSettingArray"); std::vector<GCSeqPoseSetting> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqCmdSeqDesc::SetPoseSettingArray(std::vector<GCSeqPoseSetting> value) {
    SetSchemaValueCUtlVector<GCSeqPoseSetting>(m_ptr, "CSeqCmdSeqDesc", "m_poseSettingArray", false, value);
}
std::string GCSeqCmdSeqDesc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqCmdSeqDesc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqCmdSeqDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqCmdSeqDesc>("CSeqCmdSeqDesc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSeqCmdSeqDesc::GetName, &GCSeqCmdSeqDesc::SetName)
        .addProperty("Flags", &GCSeqCmdSeqDesc::GetFlags, &GCSeqCmdSeqDesc::SetFlags)
        .addProperty("Transition", &GCSeqCmdSeqDesc::GetTransition, &GCSeqCmdSeqDesc::SetTransition)
        .addProperty("FrameRangeSequence", &GCSeqCmdSeqDesc::GetFrameRangeSequence, &GCSeqCmdSeqDesc::SetFrameRangeSequence)
        .addProperty("FrameCount", &GCSeqCmdSeqDesc::GetFrameCount, &GCSeqCmdSeqDesc::SetFrameCount)
        .addProperty("FPS", &GCSeqCmdSeqDesc::GetFPS, &GCSeqCmdSeqDesc::SetFPS)
        .addProperty("SubCycles", &GCSeqCmdSeqDesc::GetSubCycles, &GCSeqCmdSeqDesc::SetSubCycles)
        .addProperty("NumLocalResults", &GCSeqCmdSeqDesc::GetNumLocalResults, &GCSeqCmdSeqDesc::SetNumLocalResults)
        .addProperty("CmdLayerArray", &GCSeqCmdSeqDesc::GetCmdLayerArray, &GCSeqCmdSeqDesc::SetCmdLayerArray)
        .addProperty("EventArray", &GCSeqCmdSeqDesc::GetEventArray, &GCSeqCmdSeqDesc::SetEventArray)
        .addProperty("ActivityArray", &GCSeqCmdSeqDesc::GetActivityArray, &GCSeqCmdSeqDesc::SetActivityArray)
        .addProperty("PoseSettingArray", &GCSeqCmdSeqDesc::GetPoseSettingArray, &GCSeqCmdSeqDesc::SetPoseSettingArray)
        .addFunction("ToPtr", &GCSeqCmdSeqDesc::ToPtr)
        .addFunction("IsValid", &GCSeqCmdSeqDesc::IsValid)
        .endClass();
}