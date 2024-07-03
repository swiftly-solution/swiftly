#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmVectorValueNode::GCNmVectorValueNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmVectorValueNode::GCNmVectorValueNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmVectorValueNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmVectorValueNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmValueNode GCNmVectorValueNode::GetParent() const {
    GCNmValueNode value(m_ptr);
    return value;
}
void GCNmVectorValueNode::SetParent(GCNmValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmVectorValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVectorValueNode>("CNmVectorValueNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmVectorValueNode::GetParent, &GCNmVectorValueNode::SetParent)
        .addFunction("ToPtr", &GCNmVectorValueNode::ToPtr)
        .addFunction("IsValid", &GCNmVectorValueNode::IsValid)
        .endClass();
}