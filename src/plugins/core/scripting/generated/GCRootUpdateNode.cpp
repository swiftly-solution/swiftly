#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRootUpdateNode::GCRootUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRootUpdateNode::GCRootUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCRootUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRootUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCRootUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCRootUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRootUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRootUpdateNode>("CRootUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCRootUpdateNode::GetParent, &GCRootUpdateNode::SetParent)
        .addFunction("ToPtr", &GCRootUpdateNode::ToPtr)
        .addFunction("IsValid", &GCRootUpdateNode::IsValid)
        .endClass();
}