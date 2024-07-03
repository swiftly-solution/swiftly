#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBindPoseUpdateNode::GCBindPoseUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBindPoseUpdateNode::GCBindPoseUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCBindPoseUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBindPoseUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCBindPoseUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCBindPoseUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBindPoseUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBindPoseUpdateNode>("CBindPoseUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBindPoseUpdateNode::GetParent, &GCBindPoseUpdateNode::SetParent)
        .addFunction("ToPtr", &GCBindPoseUpdateNode::ToPtr)
        .addFunction("IsValid", &GCBindPoseUpdateNode::IsValid)
        .endClass();
}