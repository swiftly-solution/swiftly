#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBodyComponentBaseAnimGraph::GCBodyComponentBaseAnimGraph(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBodyComponentBaseAnimGraph::GCBodyComponentBaseAnimGraph(void *ptr) {
    m_ptr = ptr;
}
GCBaseAnimGraphController GCBodyComponentBaseAnimGraph::GetAnimationController() const {
    GCBaseAnimGraphController value(GetSchemaPtr(m_ptr, "CBodyComponentBaseAnimGraph", "m_animationController"));
    return value;
}
void GCBodyComponentBaseAnimGraph::SetAnimationController(GCBaseAnimGraphController value) {
    SetSchemaValue(m_ptr, "CBodyComponentBaseAnimGraph", "m_animationController", false, value);
}
std::string GCBodyComponentBaseAnimGraph::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBodyComponentBaseAnimGraph::IsValid() {
    return (m_ptr != nullptr);
}
GCBodyComponentSkeletonInstance GCBodyComponentBaseAnimGraph::GetParent() const {
    GCBodyComponentSkeletonInstance value(m_ptr);
    return value;
}
void GCBodyComponentBaseAnimGraph::SetParent(GCBodyComponentSkeletonInstance value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBodyComponentBaseAnimGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentBaseAnimGraph>("CBodyComponentBaseAnimGraph")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AnimationController", &GCBodyComponentBaseAnimGraph::GetAnimationController, &GCBodyComponentBaseAnimGraph::SetAnimationController)
        .addProperty("Parent", &GCBodyComponentBaseAnimGraph::GetParent, &GCBodyComponentBaseAnimGraph::SetParent)
        .addFunction("ToPtr", &GCBodyComponentBaseAnimGraph::ToPtr)
        .addFunction("IsValid", &GCBodyComponentBaseAnimGraph::IsValid)
        .endClass();
}