#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmTargetValueNode::GCNmTargetValueNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmTargetValueNode::GCNmTargetValueNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmTargetValueNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmTargetValueNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmValueNode GCNmTargetValueNode::GetParent() const {
    GCNmValueNode value(m_ptr);
    return value;
}
void GCNmTargetValueNode::SetParent(GCNmValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmTargetValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTargetValueNode>("CNmTargetValueNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmTargetValueNode::GetParent, &GCNmTargetValueNode::SetParent)
        .addFunction("ToPtr", &GCNmTargetValueNode::ToPtr)
        .addFunction("IsValid", &GCNmTargetValueNode::IsValid)
        .endClass();
}