#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmControlParameterTargetNode::GCNmControlParameterTargetNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmControlParameterTargetNode::GCNmControlParameterTargetNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmControlParameterTargetNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmControlParameterTargetNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmTargetValueNode GCNmControlParameterTargetNode::GetParent() const {
    GCNmTargetValueNode value(m_ptr);
    return value;
}
void GCNmControlParameterTargetNode::SetParent(GCNmTargetValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmControlParameterTargetNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterTargetNode>("CNmControlParameterTargetNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmControlParameterTargetNode::GetParent, &GCNmControlParameterTargetNode::SetParent)
        .addFunction("ToPtr", &GCNmControlParameterTargetNode::ToPtr)
        .addFunction("IsValid", &GCNmControlParameterTargetNode::IsValid)
        .endClass();
}