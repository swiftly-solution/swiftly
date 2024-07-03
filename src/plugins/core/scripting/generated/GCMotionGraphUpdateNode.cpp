#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionGraphUpdateNode::GCMotionGraphUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionGraphUpdateNode::GCMotionGraphUpdateNode(void *ptr) {
    m_ptr = ptr;
}
std::string GCMotionGraphUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionGraphUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCMotionGraphUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCMotionGraphUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMotionGraphUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraphUpdateNode>("CMotionGraphUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCMotionGraphUpdateNode::GetParent, &GCMotionGraphUpdateNode::SetParent)
        .addFunction("ToPtr", &GCMotionGraphUpdateNode::ToPtr)
        .addFunction("IsValid", &GCMotionGraphUpdateNode::IsValid)
        .endClass();
}