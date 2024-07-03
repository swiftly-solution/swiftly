#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmVirtualParameterFloatNode::GCNmVirtualParameterFloatNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmVirtualParameterFloatNode::GCNmVirtualParameterFloatNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmVirtualParameterFloatNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterFloatNode", "m_nChildNodeIdx");
}
void GCNmVirtualParameterFloatNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmVirtualParameterFloatNode", "m_nChildNodeIdx", false, value);
}
std::string GCNmVirtualParameterFloatNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmVirtualParameterFloatNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmFloatValueNode GCNmVirtualParameterFloatNode::GetParent() const {
    GCNmFloatValueNode value(m_ptr);
    return value;
}
void GCNmVirtualParameterFloatNode::SetParent(GCNmFloatValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmVirtualParameterFloatNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterFloatNode>("CNmVirtualParameterFloatNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterFloatNode::GetChildNodeIdx, &GCNmVirtualParameterFloatNode::SetChildNodeIdx)
        .addProperty("Parent", &GCNmVirtualParameterFloatNode::GetParent, &GCNmVirtualParameterFloatNode::SetParent)
        .addFunction("ToPtr", &GCNmVirtualParameterFloatNode::ToPtr)
        .addFunction("IsValid", &GCNmVirtualParameterFloatNode::IsValid)
        .endClass();
}