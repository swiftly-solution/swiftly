#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmBoneMaskValueNode::GCNmBoneMaskValueNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmBoneMaskValueNode::GCNmBoneMaskValueNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmBoneMaskValueNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmBoneMaskValueNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmValueNode GCNmBoneMaskValueNode::GetParent() const {
    GCNmValueNode value(m_ptr);
    return value;
}
void GCNmBoneMaskValueNode::SetParent(GCNmValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmBoneMaskValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmBoneMaskValueNode>("CNmBoneMaskValueNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmBoneMaskValueNode::GetParent, &GCNmBoneMaskValueNode::SetParent)
        .addFunction("ToPtr", &GCNmBoneMaskValueNode::ToPtr)
        .addFunction("IsValid", &GCNmBoneMaskValueNode::IsValid)
        .endClass();
}