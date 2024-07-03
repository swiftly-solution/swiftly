#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBodyComponentPoint::GCBodyComponentPoint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBodyComponentPoint::GCBodyComponentPoint(void *ptr) {
    m_ptr = ptr;
}
GCGameSceneNode GCBodyComponentPoint::GetSceneNode() const {
    GCGameSceneNode value(GetSchemaPtr(m_ptr, "CBodyComponentPoint", "m_sceneNode"));
    return value;
}
void GCBodyComponentPoint::SetSceneNode(GCGameSceneNode value) {
    SetSchemaValue(m_ptr, "CBodyComponentPoint", "m_sceneNode", false, value);
}
std::string GCBodyComponentPoint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBodyComponentPoint::IsValid() {
    return (m_ptr != nullptr);
}
GCBodyComponent GCBodyComponentPoint::GetParent() const {
    GCBodyComponent value(m_ptr);
    return value;
}
void GCBodyComponentPoint::SetParent(GCBodyComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBodyComponentPoint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentPoint>("CBodyComponentPoint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SceneNode", &GCBodyComponentPoint::GetSceneNode, &GCBodyComponentPoint::SetSceneNode)
        .addProperty("Parent", &GCBodyComponentPoint::GetParent, &GCBodyComponentPoint::SetParent)
        .addFunction("ToPtr", &GCBodyComponentPoint::ToPtr)
        .addFunction("IsValid", &GCBodyComponentPoint::IsValid)
        .endClass();
}