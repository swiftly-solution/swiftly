#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmControlParameterVectorNode::GCNmControlParameterVectorNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmControlParameterVectorNode::GCNmControlParameterVectorNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmControlParameterVectorNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmControlParameterVectorNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmVectorValueNode GCNmControlParameterVectorNode::GetParent() const {
    GCNmVectorValueNode value(m_ptr);
    return value;
}
void GCNmControlParameterVectorNode::SetParent(GCNmVectorValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmControlParameterVectorNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterVectorNode>("CNmControlParameterVectorNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmControlParameterVectorNode::GetParent, &GCNmControlParameterVectorNode::SetParent)
        .addFunction("ToPtr", &GCNmControlParameterVectorNode::ToPtr)
        .addFunction("IsValid", &GCNmControlParameterVectorNode::IsValid)
        .endClass();
}