#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmControlParameterFloatNode::GCNmControlParameterFloatNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmControlParameterFloatNode::GCNmControlParameterFloatNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmControlParameterFloatNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmControlParameterFloatNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmFloatValueNode GCNmControlParameterFloatNode::GetParent() const {
    GCNmFloatValueNode value(m_ptr);
    return value;
}
void GCNmControlParameterFloatNode::SetParent(GCNmFloatValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmControlParameterFloatNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterFloatNode>("CNmControlParameterFloatNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmControlParameterFloatNode::GetParent, &GCNmControlParameterFloatNode::SetParent)
        .addFunction("ToPtr", &GCNmControlParameterFloatNode::ToPtr)
        .addFunction("IsValid", &GCNmControlParameterFloatNode::IsValid)
        .endClass();
}