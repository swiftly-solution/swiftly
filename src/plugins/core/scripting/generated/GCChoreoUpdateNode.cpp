#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCChoreoUpdateNode::GCChoreoUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCChoreoUpdateNode::GCChoreoUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCChoreoUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCChoreoUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCChoreoUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCChoreoUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCChoreoUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCChoreoUpdateNode>("CChoreoUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCChoreoUpdateNode::GetParent, &GCChoreoUpdateNode::SetParent)
        .addFunction("ToPtr", &GCChoreoUpdateNode::ToPtr)
        .addFunction("IsValid", &GCChoreoUpdateNode::IsValid)
        .endClass();
}