#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmControlParameterIDNode::GCNmControlParameterIDNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmControlParameterIDNode::GCNmControlParameterIDNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmControlParameterIDNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmControlParameterIDNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmIDValueNode GCNmControlParameterIDNode::GetParent() const {
    GCNmIDValueNode value(m_ptr);
    return value;
}
void GCNmControlParameterIDNode::SetParent(GCNmIDValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmControlParameterIDNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterIDNode>("CNmControlParameterIDNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmControlParameterIDNode::GetParent, &GCNmControlParameterIDNode::SetParent)
        .addFunction("ToPtr", &GCNmControlParameterIDNode::ToPtr)
        .addFunction("IsValid", &GCNmControlParameterIDNode::IsValid)
        .endClass();
}