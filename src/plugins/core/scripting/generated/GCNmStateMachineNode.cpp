#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmStateMachineNode::GCNmStateMachineNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmStateMachineNode::GCNmStateMachineNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmStateMachineNode::GetDefaultStateIndex() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmStateMachineNode", "m_nDefaultStateIndex");
}
void GCNmStateMachineNode::SetDefaultStateIndex(int16_t value) {
    SetSchemaValue(m_ptr, "CNmStateMachineNode", "m_nDefaultStateIndex", false, value);
}
std::string GCNmStateMachineNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmStateMachineNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmStateMachineNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmStateMachineNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmStateMachineNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmStateMachineNode>("CNmStateMachineNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefaultStateIndex", &GCNmStateMachineNode::GetDefaultStateIndex, &GCNmStateMachineNode::SetDefaultStateIndex)
        .addProperty("Parent", &GCNmStateMachineNode::GetParent, &GCNmStateMachineNode::SetParent)
        .addFunction("ToPtr", &GCNmStateMachineNode::ToPtr)
        .addFunction("IsValid", &GCNmStateMachineNode::IsValid)
        .endClass();
}