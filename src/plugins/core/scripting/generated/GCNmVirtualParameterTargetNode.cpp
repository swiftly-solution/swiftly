#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmVirtualParameterTargetNode::GCNmVirtualParameterTargetNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmVirtualParameterTargetNode::GCNmVirtualParameterTargetNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmVirtualParameterTargetNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterTargetNode", "m_nChildNodeIdx");
}
void GCNmVirtualParameterTargetNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmVirtualParameterTargetNode", "m_nChildNodeIdx", false, value);
}
std::string GCNmVirtualParameterTargetNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmVirtualParameterTargetNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmTargetValueNode GCNmVirtualParameterTargetNode::GetParent() const {
    GCNmTargetValueNode value(m_ptr);
    return value;
}
void GCNmVirtualParameterTargetNode::SetParent(GCNmTargetValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmVirtualParameterTargetNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterTargetNode>("CNmVirtualParameterTargetNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterTargetNode::GetChildNodeIdx, &GCNmVirtualParameterTargetNode::SetChildNodeIdx)
        .addProperty("Parent", &GCNmVirtualParameterTargetNode::GetParent, &GCNmVirtualParameterTargetNode::SetParent)
        .addFunction("ToPtr", &GCNmVirtualParameterTargetNode::ToPtr)
        .addFunction("IsValid", &GCNmVirtualParameterTargetNode::IsValid)
        .endClass();
}