#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmPassthroughNode::GCNmPassthroughNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmPassthroughNode::GCNmPassthroughNode(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmPassthroughNode::GetChildNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmPassthroughNode", "m_nChildNodeIdx");
}
void GCNmPassthroughNode::SetChildNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmPassthroughNode", "m_nChildNodeIdx", false, value);
}
std::string GCNmPassthroughNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmPassthroughNode::IsValid() {
    return (m_ptr != nullptr);
}
GCNmPoseNode GCNmPassthroughNode::GetParent() const {
    GCNmPoseNode value(m_ptr);
    return value;
}
void GCNmPassthroughNode::SetParent(GCNmPoseNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmPassthroughNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmPassthroughNode>("CNmPassthroughNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChildNodeIdx", &GCNmPassthroughNode::GetChildNodeIdx, &GCNmPassthroughNode::SetChildNodeIdx)
        .addProperty("Parent", &GCNmPassthroughNode::GetParent, &GCNmPassthroughNode::SetParent)
        .addFunction("ToPtr", &GCNmPassthroughNode::ToPtr)
        .addFunction("IsValid", &GCNmPassthroughNode::IsValid)
        .endClass();
}