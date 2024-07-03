#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInputStreamUpdateNode::GCInputStreamUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInputStreamUpdateNode::GCInputStreamUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCInputStreamUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInputStreamUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCInputStreamUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCInputStreamUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInputStreamUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInputStreamUpdateNode>("CInputStreamUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInputStreamUpdateNode::GetParent, &GCInputStreamUpdateNode::SetParent)
        .addFunction("ToPtr", &GCInputStreamUpdateNode::ToPtr)
        .addFunction("IsValid", &GCInputStreamUpdateNode::IsValid)
        .endClass();
}