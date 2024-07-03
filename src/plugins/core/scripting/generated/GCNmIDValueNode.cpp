#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmIDValueNode::GCNmIDValueNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmIDValueNode::GCNmIDValueNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmIDValueNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmIDValueNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmValueNode GCNmIDValueNode::GetParent() const {
    GCNmValueNode value(m_ptr);
    return value;
}
void GCNmIDValueNode::SetParent(GCNmValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmIDValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmIDValueNode>("CNmIDValueNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmIDValueNode::GetParent, &GCNmIDValueNode::SetParent)
        .addFunction("ToPtr", &GCNmIDValueNode::ToPtr)
        .addFunction("IsValid", &GCNmIDValueNode::IsValid)
        .endClass();
}