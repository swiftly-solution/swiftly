#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmChildGraphNode::GCNmChildGraphNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmChildGraphNode::GCNmChildGraphNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmChildGraphNode::GetChildGraphIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmChildGraphNode", "m_nChildGraphIdx");
}
void GCNmChildGraphNode::SetChildGraphIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmChildGraphNode", "m_nChildGraphIdx", false, value);
}
std::string GCNmChildGraphNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmChildGraphNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmChildGraphNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmChildGraphNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmChildGraphNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmChildGraphNode>("CNmChildGraphNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildGraphIdx", &GCNmChildGraphNode::GetChildGraphIdx, &GCNmChildGraphNode::SetChildGraphIdx)
        .addProperty("Parent", &GCNmChildGraphNode::GetParent, &GCNmChildGraphNode::SetParent)
        .addFunction("ToPtr", &GCNmChildGraphNode::ToPtr)
        .addFunction("IsValid", &GCNmChildGraphNode::IsValid)
        .endClass();
}