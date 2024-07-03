#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmVirtualParameterVectorNode::GCNmVirtualParameterVectorNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmVirtualParameterVectorNode::GCNmVirtualParameterVectorNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmVirtualParameterVectorNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterVectorNode", "m_nChildNodeIdx");
}
void GCNmVirtualParameterVectorNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmVirtualParameterVectorNode", "m_nChildNodeIdx", false, value);
}
std::string GCNmVirtualParameterVectorNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmVirtualParameterVectorNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmVectorValueNode GCNmVirtualParameterVectorNode::GetParent() const {
    GCNmVectorValueNode value(m_ptr);
    return value;
}
void GCNmVirtualParameterVectorNode::SetParent(GCNmVectorValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmVirtualParameterVectorNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterVectorNode>("CNmVirtualParameterVectorNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterVectorNode::GetChildNodeIdx, &GCNmVirtualParameterVectorNode::SetChildNodeIdx)
        .addProperty("Parent", &GCNmVirtualParameterVectorNode::GetParent, &GCNmVirtualParameterVectorNode::SetParent)
        .addFunction("ToPtr", &GCNmVirtualParameterVectorNode::ToPtr)
        .addFunction("IsValid", &GCNmVirtualParameterVectorNode::IsValid)
        .endClass();
}