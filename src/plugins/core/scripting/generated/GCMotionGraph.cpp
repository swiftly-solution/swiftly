#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionGraph::GCMotionGraph(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionGraph::GCMotionGraph(void *ptr) {
    m_ptr = ptr;
}
GCParamSpanUpdater GCMotionGraph::GetParamSpans() const {
    GCParamSpanUpdater value(GetSchemaPtr(m_ptr, "CMotionGraph", "m_paramSpans"));
    return value;
}
void GCMotionGraph::SetParamSpans(GCParamSpanUpdater value) {
    SetSchemaValue(m_ptr, "CMotionGraph", "m_paramSpans", false, value);
}
std::vector<GTagSpan_t> GCMotionGraph::GetTags() const {
    CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CMotionGraph", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionGraph::SetTags(std::vector<GTagSpan_t> value) {
    SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CMotionGraph", "m_tags", false, value);
}
int32_t GCMotionGraph::GetParameterCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionGraph", "m_nParameterCount");
}
void GCMotionGraph::SetParameterCount(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionGraph", "m_nParameterCount", false, value);
}
int32_t GCMotionGraph::GetConfigStartIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionGraph", "m_nConfigStartIndex");
}
void GCMotionGraph::SetConfigStartIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionGraph", "m_nConfigStartIndex", false, value);
}
int32_t GCMotionGraph::GetConfigCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionGraph", "m_nConfigCount");
}
void GCMotionGraph::SetConfigCount(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionGraph", "m_nConfigCount", false, value);
}
bool GCMotionGraph::GetLoop() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionGraph", "m_bLoop");
}
void GCMotionGraph::SetLoop(bool value) {
    SetSchemaValue(m_ptr, "CMotionGraph", "m_bLoop", false, value);
}
std::string GCMotionGraph::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionGraph::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraph>("CMotionGraph")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParamSpans", &GCMotionGraph::GetParamSpans, &GCMotionGraph::SetParamSpans)
        .addProperty("Tags", &GCMotionGraph::GetTags, &GCMotionGraph::SetTags)
        .addProperty("ParameterCount", &GCMotionGraph::GetParameterCount, &GCMotionGraph::SetParameterCount)
        .addProperty("ConfigStartIndex", &GCMotionGraph::GetConfigStartIndex, &GCMotionGraph::SetConfigStartIndex)
        .addProperty("ConfigCount", &GCMotionGraph::GetConfigCount, &GCMotionGraph::SetConfigCount)
        .addProperty("Loop", &GCMotionGraph::GetLoop, &GCMotionGraph::SetLoop)
        .addFunction("ToPtr", &GCMotionGraph::ToPtr)
        .addFunction("IsValid", &GCMotionGraph::IsValid)
        .endClass();
}