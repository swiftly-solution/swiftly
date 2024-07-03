#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmFloatValueNode::GCNmFloatValueNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmFloatValueNode::GCNmFloatValueNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmFloatValueNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmFloatValueNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmValueNode GCNmFloatValueNode::GetParent() const {
    GCNmValueNode value(m_ptr);
    return value;
}
void GCNmFloatValueNode::SetParent(GCNmValueNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmFloatValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmFloatValueNode>("CNmFloatValueNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmFloatValueNode::GetParent, &GCNmFloatValueNode::SetParent)
        .addFunction("ToPtr", &GCNmFloatValueNode::ToPtr)
        .addFunction("IsValid", &GCNmFloatValueNode::IsValid)
        .endClass();
}