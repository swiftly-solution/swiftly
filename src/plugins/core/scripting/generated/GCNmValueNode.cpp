#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmValueNode::GCNmValueNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmValueNode::GCNmValueNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmValueNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmValueNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmGraphNode GCNmValueNode::GetParent() const {
    GCNmGraphNode value(m_ptr);
    return value;
}
void GCNmValueNode::SetParent(GCNmGraphNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmValueNode>("CNmValueNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmValueNode::GetParent, &GCNmValueNode::SetParent)
        .addFunction("ToPtr", &GCNmValueNode::ToPtr)
        .addFunction("IsValid", &GCNmValueNode::IsValid)
        .endClass();
}