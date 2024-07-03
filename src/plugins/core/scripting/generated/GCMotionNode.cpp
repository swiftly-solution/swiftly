#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionNode::GCMotionNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionNode::GCMotionNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCMotionNode::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CMotionNode", "m_name").Get();
}
void GCMotionNode::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CMotionNode", "m_name", false, CUtlString(value.c_str()));
}
GAnimNodeID GCMotionNode::GetId() const {
    GAnimNodeID value(GetSchemaPtr(m_ptr, "CMotionNode", "m_id"));
    return value;
}
void GCMotionNode::SetId(GAnimNodeID value) {
    SetSchemaValue(m_ptr, "CMotionNode", "m_id", false, value);
}
std::string GCMotionNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionNode::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionNode>("CMotionNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCMotionNode::GetName, &GCMotionNode::SetName)
        .addProperty("Id", &GCMotionNode::GetId, &GCMotionNode::SetId)
        .addFunction("ToPtr", &GCMotionNode::ToPtr)
        .addFunction("IsValid", &GCMotionNode::IsValid)
        .endClass();
}