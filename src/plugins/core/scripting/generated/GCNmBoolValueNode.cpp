#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmBoolValueNode::GCNmBoolValueNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmBoolValueNode::GCNmBoolValueNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmBoolValueNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmBoolValueNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmValueNode GCNmBoolValueNode::GetParent() const {
    GCNmValueNode value(m_ptr);
    return value;
}
void GCNmBoolValueNode::SetParent(GCNmValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmBoolValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmBoolValueNode>("CNmBoolValueNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmBoolValueNode::GetParent, &GCNmBoolValueNode::SetParent)
        .addFunction("ToPtr", &GCNmBoolValueNode::ToPtr)
        .addFunction("IsValid", &GCNmBoolValueNode::IsValid)
        .endClass();
}