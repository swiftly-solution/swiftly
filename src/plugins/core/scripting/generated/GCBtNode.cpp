#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtNode::GCBtNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtNode::GCBtNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCBtNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtNode::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBtNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNode>("CBtNode")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCBtNode::ToPtr)
        .addFunction("IsValid", &GCBtNode::IsValid)
        .endClass();
}