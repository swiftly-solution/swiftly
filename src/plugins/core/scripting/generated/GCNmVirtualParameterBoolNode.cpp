#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmVirtualParameterBoolNode::GCNmVirtualParameterBoolNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmVirtualParameterBoolNode::GCNmVirtualParameterBoolNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmVirtualParameterBoolNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterBoolNode", "m_nChildNodeIdx");
}
void GCNmVirtualParameterBoolNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmVirtualParameterBoolNode", "m_nChildNodeIdx", false, value);
}
std::string GCNmVirtualParameterBoolNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmVirtualParameterBoolNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmBoolValueNode GCNmVirtualParameterBoolNode::GetParent() const {
    GCNmBoolValueNode value(m_ptr);
    return value;
}
void GCNmVirtualParameterBoolNode::SetParent(GCNmBoolValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmVirtualParameterBoolNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterBoolNode>("CNmVirtualParameterBoolNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterBoolNode::GetChildNodeIdx, &GCNmVirtualParameterBoolNode::SetChildNodeIdx)
        .addProperty("Parent", &GCNmVirtualParameterBoolNode::GetParent, &GCNmVirtualParameterBoolNode::SetParent)
        .addFunction("ToPtr", &GCNmVirtualParameterBoolNode::ToPtr)
        .addFunction("IsValid", &GCNmVirtualParameterBoolNode::IsValid)
        .endClass();
}