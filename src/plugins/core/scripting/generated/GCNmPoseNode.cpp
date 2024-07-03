#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmPoseNode::GCNmPoseNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmPoseNode::GCNmPoseNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmPoseNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmPoseNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmGraphNode GCNmPoseNode::GetParent() const {
    GCNmGraphNode value(m_ptr);
    return value;
}
void GCNmPoseNode::SetParent(GCNmGraphNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmPoseNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmPoseNode>("CNmPoseNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmPoseNode::GetParent, &GCNmPoseNode::SetParent)
        .addFunction("ToPtr", &GCNmPoseNode::ToPtr)
        .addFunction("IsValid", &GCNmPoseNode::IsValid)
        .endClass();
}