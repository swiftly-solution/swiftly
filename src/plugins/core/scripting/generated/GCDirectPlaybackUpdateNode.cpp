#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDirectPlaybackUpdateNode::GCDirectPlaybackUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDirectPlaybackUpdateNode::GCDirectPlaybackUpdateNode(void *ptr) {
    m_ptr = ptr;
}
bool GCDirectPlaybackUpdateNode::GetFinishEarly() const {
    return GetSchemaValue<bool>(m_ptr, "CDirectPlaybackUpdateNode", "m_bFinishEarly");
}
void GCDirectPlaybackUpdateNode::SetFinishEarly(bool value) {
    SetSchemaValue(m_ptr, "CDirectPlaybackUpdateNode", "m_bFinishEarly", false, value);
}
bool GCDirectPlaybackUpdateNode::GetResetOnFinish() const {
    return GetSchemaValue<bool>(m_ptr, "CDirectPlaybackUpdateNode", "m_bResetOnFinish");
}
void GCDirectPlaybackUpdateNode::SetResetOnFinish(bool value) {
    SetSchemaValue(m_ptr, "CDirectPlaybackUpdateNode", "m_bResetOnFinish", false, value);
}
std::vector<GCDirectPlaybackTagData> GCDirectPlaybackUpdateNode::GetAllTags() const {
    CUtlVector<GCDirectPlaybackTagData>* vec = GetSchemaValue<CUtlVector<GCDirectPlaybackTagData>*>(m_ptr, "CDirectPlaybackUpdateNode", "m_allTags"); std::vector<GCDirectPlaybackTagData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCDirectPlaybackUpdateNode::SetAllTags(std::vector<GCDirectPlaybackTagData> value) {
    SetSchemaValueCUtlVector<GCDirectPlaybackTagData>(m_ptr, "CDirectPlaybackUpdateNode", "m_allTags", false, value);
}
std::string GCDirectPlaybackUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDirectPlaybackUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCDirectPlaybackUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCDirectPlaybackUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDirectPlaybackUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDirectPlaybackUpdateNode>("CDirectPlaybackUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FinishEarly", &GCDirectPlaybackUpdateNode::GetFinishEarly, &GCDirectPlaybackUpdateNode::SetFinishEarly)
        .addProperty("ResetOnFinish", &GCDirectPlaybackUpdateNode::GetResetOnFinish, &GCDirectPlaybackUpdateNode::SetResetOnFinish)
        .addProperty("AllTags", &GCDirectPlaybackUpdateNode::GetAllTags, &GCDirectPlaybackUpdateNode::SetAllTags)
        .addProperty("Parent", &GCDirectPlaybackUpdateNode::GetParent, &GCDirectPlaybackUpdateNode::SetParent)
        .addFunction("ToPtr", &GCDirectPlaybackUpdateNode::ToPtr)
        .addFunction("IsValid", &GCDirectPlaybackUpdateNode::IsValid)
        .endClass();
}