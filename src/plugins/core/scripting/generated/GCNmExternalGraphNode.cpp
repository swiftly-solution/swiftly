#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmExternalGraphNode::GCNmExternalGraphNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmExternalGraphNode::GCNmExternalGraphNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmExternalGraphNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmExternalGraphNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmExternalGraphNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmExternalGraphNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmExternalGraphNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmExternalGraphNode>("CNmExternalGraphNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmExternalGraphNode::GetParent, &GCNmExternalGraphNode::SetParent)
        .addFunction("ToPtr", &GCNmExternalGraphNode::ToPtr)
        .addFunction("IsValid", &GCNmExternalGraphNode::IsValid)
        .endClass();
}