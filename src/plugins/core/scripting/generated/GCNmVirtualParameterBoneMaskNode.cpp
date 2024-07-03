#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmVirtualParameterBoneMaskNode::GCNmVirtualParameterBoneMaskNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmVirtualParameterBoneMaskNode::GCNmVirtualParameterBoneMaskNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmVirtualParameterBoneMaskNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmVirtualParameterBoneMaskNode", "m_nChildNodeIdx");
}
void GCNmVirtualParameterBoneMaskNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmVirtualParameterBoneMaskNode", "m_nChildNodeIdx", false, value);
}
std::string GCNmVirtualParameterBoneMaskNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmVirtualParameterBoneMaskNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmBoneMaskValueNode GCNmVirtualParameterBoneMaskNode::GetParent() const {
    GCNmBoneMaskValueNode value(m_ptr);
    return value;
}
void GCNmVirtualParameterBoneMaskNode::SetParent(GCNmBoneMaskValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmVirtualParameterBoneMaskNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVirtualParameterBoneMaskNode>("CNmVirtualParameterBoneMaskNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmVirtualParameterBoneMaskNode::GetChildNodeIdx, &GCNmVirtualParameterBoneMaskNode::SetChildNodeIdx)
        .addProperty("Parent", &GCNmVirtualParameterBoneMaskNode::GetParent, &GCNmVirtualParameterBoneMaskNode::SetParent)
        .addFunction("ToPtr", &GCNmVirtualParameterBoneMaskNode::ToPtr)
        .addFunction("IsValid", &GCNmVirtualParameterBoneMaskNode::IsValid)
        .endClass();
}