#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCycleControlClipUpdateNode::GCCycleControlClipUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCycleControlClipUpdateNode::GCCycleControlClipUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::vector<GTagSpan_t> GCCycleControlClipUpdateNode::GetTags() const {
    CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CCycleControlClipUpdateNode", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCycleControlClipUpdateNode::SetTags(std::vector<GTagSpan_t> value) {
    SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CCycleControlClipUpdateNode", "m_tags", false, value);
}
float GCCycleControlClipUpdateNode::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CCycleControlClipUpdateNode", "m_duration");
}
void GCCycleControlClipUpdateNode::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CCycleControlClipUpdateNode", "m_duration", false, value);
}
uint64_t GCCycleControlClipUpdateNode::GetValueSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCycleControlClipUpdateNode", "m_valueSource");
}
void GCCycleControlClipUpdateNode::SetValueSource(uint64_t value) {
    SetSchemaValue(m_ptr, "CCycleControlClipUpdateNode", "m_valueSource", false, value);
}
GCAnimParamHandle GCCycleControlClipUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CCycleControlClipUpdateNode", "m_paramIndex"));
    return value;
}
void GCCycleControlClipUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CCycleControlClipUpdateNode", "m_paramIndex", false, value);
}
std::string GCCycleControlClipUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCycleControlClipUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCCycleControlClipUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCCycleControlClipUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCycleControlClipUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCycleControlClipUpdateNode>("CCycleControlClipUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Tags", &GCCycleControlClipUpdateNode::GetTags, &GCCycleControlClipUpdateNode::SetTags)
        .addProperty("Duration", &GCCycleControlClipUpdateNode::GetDuration, &GCCycleControlClipUpdateNode::SetDuration)
        .addProperty("ValueSource", &GCCycleControlClipUpdateNode::GetValueSource, &GCCycleControlClipUpdateNode::SetValueSource)
        .addProperty("ParamIndex", &GCCycleControlClipUpdateNode::GetParamIndex, &GCCycleControlClipUpdateNode::SetParamIndex)
        .addProperty("Parent", &GCCycleControlClipUpdateNode::GetParent, &GCCycleControlClipUpdateNode::SetParent)
        .addFunction("ToPtr", &GCCycleControlClipUpdateNode::ToPtr)
        .addFunction("IsValid", &GCCycleControlClipUpdateNode::IsValid)
        .endClass();
}