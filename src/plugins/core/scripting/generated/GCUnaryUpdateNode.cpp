#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCUnaryUpdateNode::GCUnaryUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCUnaryUpdateNode::GCUnaryUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimUpdateNodeRef GCUnaryUpdateNode::GetChildNode() const {
    GCAnimUpdateNodeRef value(GetSchemaPtr(m_ptr, "CUnaryUpdateNode", "m_pChildNode"));
    return value;
}
void GCUnaryUpdateNode::SetChildNode(GCAnimUpdateNodeRef value) {
    SetSchemaValue(m_ptr, "CUnaryUpdateNode", "m_pChildNode", false, value);
}
std::string GCUnaryUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCUnaryUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimUpdateNodeBase GCUnaryUpdateNode::GetParent() const {
    GCAnimUpdateNodeBase value(m_ptr);
    return value;
}
void GCUnaryUpdateNode::SetParent(GCAnimUpdateNodeBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCUnaryUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCUnaryUpdateNode>("CUnaryUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNode", &GCUnaryUpdateNode::GetChildNode, &GCUnaryUpdateNode::SetChildNode)
        .addProperty("Parent", &GCUnaryUpdateNode::GetParent, &GCUnaryUpdateNode::SetParent)
        .addFunction("ToPtr", &GCUnaryUpdateNode::ToPtr)
        .addFunction("IsValid", &GCUnaryUpdateNode::IsValid)
        .endClass();
}