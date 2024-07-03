#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEditableMotionGraph::GCEditableMotionGraph(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEditableMotionGraph::GCEditableMotionGraph(void *ptr) {
    m_ptr = ptr;
}
std::string GCEditableMotionGraph::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEditableMotionGraph::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionGraph GCEditableMotionGraph::GetParent() const {
    GCMotionGraph value(m_ptr);
    return value;
}
void GCEditableMotionGraph::SetParent(GCMotionGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEditableMotionGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEditableMotionGraph>("CEditableMotionGraph")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEditableMotionGraph::GetParent, &GCEditableMotionGraph::SetParent)
        .addFunction("ToPtr", &GCEditableMotionGraph::ToPtr)
        .addFunction("IsValid", &GCEditableMotionGraph::IsValid)
        .endClass();
}