#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmVirtualParameterIDNode::GCNmVirtualParameterIDNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmVirtualParameterIDNode::GCNmVirtualParameterIDNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmVirtualParameterIDNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterIDNode", "m_nChildNodeIdx");
}
void GCNmVirtualParameterIDNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmVirtualParameterIDNode", "m_nChildNodeIdx", false, value);
}
std::string GCNmVirtualParameterIDNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmVirtualParameterIDNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmIDValueNode GCNmVirtualParameterIDNode::GetParent() const {
    GCNmIDValueNode value(m_ptr);
    return value;
}
void GCNmVirtualParameterIDNode::SetParent(GCNmIDValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmVirtualParameterIDNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterIDNode>("CNmVirtualParameterIDNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterIDNode::GetChildNodeIdx, &GCNmVirtualParameterIDNode::SetChildNodeIdx)
        .addProperty("Parent", &GCNmVirtualParameterIDNode::GetParent, &GCNmVirtualParameterIDNode::SetParent)
        .addFunction("ToPtr", &GCNmVirtualParameterIDNode::ToPtr)
        .addFunction("IsValid", &GCNmVirtualParameterIDNode::IsValid)
        .endClass();
}