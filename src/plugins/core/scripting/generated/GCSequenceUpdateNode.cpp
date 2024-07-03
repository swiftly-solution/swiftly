#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSequenceUpdateNode::GCSequenceUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSequenceUpdateNode::GCSequenceUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCParamSpanUpdater GCSequenceUpdateNode::GetParamSpans() const {
    GCParamSpanUpdater value(GetSchemaPtr(m_ptr, "CSequenceUpdateNode", "m_paramSpans"));
    return value;
}
void GCSequenceUpdateNode::SetParamSpans(GCParamSpanUpdater value) {
    SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_paramSpans", false, value);
}
std::vector<GTagSpan_t> GCSequenceUpdateNode::GetTags() const {
    CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CSequenceUpdateNode", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceUpdateNode::SetTags(std::vector<GTagSpan_t> value) {
    SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CSequenceUpdateNode", "m_tags", false, value);
}
float GCSequenceUpdateNode::GetPlaybackSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CSequenceUpdateNode", "m_playbackSpeed");
}
void GCSequenceUpdateNode::SetPlaybackSpeed(float value) {
    SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_playbackSpeed", false, value);
}
float GCSequenceUpdateNode::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CSequenceUpdateNode", "m_duration");
}
void GCSequenceUpdateNode::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_duration", false, value);
}
bool GCSequenceUpdateNode::GetLoop() const {
    return GetSchemaValue<bool>(m_ptr, "CSequenceUpdateNode", "m_bLoop");
}
void GCSequenceUpdateNode::SetLoop(bool value) {
    SetSchemaValue(m_ptr, "CSequenceUpdateNode", "m_bLoop", false, value);
}
std::string GCSequenceUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSequenceUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCSequenceUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCSequenceUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSequenceUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSequenceUpdateNode>("CSequenceUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParamSpans", &GCSequenceUpdateNode::GetParamSpans, &GCSequenceUpdateNode::SetParamSpans)
        .addProperty("Tags", &GCSequenceUpdateNode::GetTags, &GCSequenceUpdateNode::SetTags)
        .addProperty("PlaybackSpeed", &GCSequenceUpdateNode::GetPlaybackSpeed, &GCSequenceUpdateNode::SetPlaybackSpeed)
        .addProperty("Duration", &GCSequenceUpdateNode::GetDuration, &GCSequenceUpdateNode::SetDuration)
        .addProperty("Loop", &GCSequenceUpdateNode::GetLoop, &GCSequenceUpdateNode::SetLoop)
        .addProperty("Parent", &GCSequenceUpdateNode::GetParent, &GCSequenceUpdateNode::SetParent)
        .addFunction("ToPtr", &GCSequenceUpdateNode::ToPtr)
        .addFunction("IsValid", &GCSequenceUpdateNode::IsValid)
        .endClass();
}