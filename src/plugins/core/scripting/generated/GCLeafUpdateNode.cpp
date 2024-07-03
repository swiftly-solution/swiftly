#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLeafUpdateNode::GCLeafUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLeafUpdateNode::GCLeafUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCLeafUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLeafUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCLeafUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCLeafUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLeafUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLeafUpdateNode>("CLeafUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLeafUpdateNode::GetParent, &GCLeafUpdateNode::SetParent)
        .addFunction("ToPtr", &GCLeafUpdateNode::ToPtr)
        .addFunction("IsValid", &GCLeafUpdateNode::IsValid)
        .endClass();
}