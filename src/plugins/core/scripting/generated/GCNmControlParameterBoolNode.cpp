#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmControlParameterBoolNode::GCNmControlParameterBoolNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmControlParameterBoolNode::GCNmControlParameterBoolNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmControlParameterBoolNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmControlParameterBoolNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmBoolValueNode GCNmControlParameterBoolNode::GetParent() const {
    GCNmBoolValueNode value(m_ptr);
    return value;
}
void GCNmControlParameterBoolNode::SetParent(GCNmBoolValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmControlParameterBoolNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterBoolNode>("CNmControlParameterBoolNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmControlParameterBoolNode::GetParent, &GCNmControlParameterBoolNode::SetParent)
        .addFunction("ToPtr", &GCNmControlParameterBoolNode::ToPtr)
        .addFunction("IsValid", &GCNmControlParameterBoolNode::IsValid)
        .endClass();
}