#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSceneEntityAlias_logic_choreographed_scene::GCSceneEntityAlias_logic_choreographed_scene(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSceneEntityAlias_logic_choreographed_scene::GCSceneEntityAlias_logic_choreographed_scene(void *ptr) {
    m_ptr = ptr;
}
std::string GCSceneEntityAlias_logic_choreographed_scene::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSceneEntityAlias_logic_choreographed_scene::IsValid() {
    return (m_ptr != nullptr);
}
GCSceneEntity GCSceneEntityAlias_logic_choreographed_scene::GetParent() const {
    GCSceneEntity value(m_ptr);
    return value;
}
void GCSceneEntityAlias_logic_choreographed_scene::SetParent(GCSceneEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSceneEntityAlias_logic_choreographed_scene(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneEntityAlias_logic_choreographed_scene>("CSceneEntityAlias_logic_choreographed_scene")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSceneEntityAlias_logic_choreographed_scene::GetParent, &GCSceneEntityAlias_logic_choreographed_scene::SetParent)
        .addFunction("ToPtr", &GCSceneEntityAlias_logic_choreographed_scene::ToPtr)
        .addFunction("IsValid", &GCSceneEntityAlias_logic_choreographed_scene::IsValid)
        .endClass();
}