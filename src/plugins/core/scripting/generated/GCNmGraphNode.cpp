#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmGraphNode::GCNmGraphNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmGraphNode::GCNmGraphNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmGraphNode::GetNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmGraphNode", "m_nNodeIdx");
}
void GCNmGraphNode::SetNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmGraphNode", "m_nNodeIdx", false, value);
}
std::string GCNmGraphNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmGraphNode::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmGraphNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphNode>("CNmGraphNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NodeIdx", &GCNmGraphNode::GetNodeIdx, &GCNmGraphNode::SetNodeIdx)
        .addFunction("ToPtr", &GCNmGraphNode::ToPtr)
        .addFunction("IsValid", &GCNmGraphNode::IsValid)
        .endClass();
}