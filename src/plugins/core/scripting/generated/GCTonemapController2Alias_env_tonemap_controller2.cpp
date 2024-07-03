#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTonemapController2Alias_env_tonemap_controller2::GCTonemapController2Alias_env_tonemap_controller2(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTonemapController2Alias_env_tonemap_controller2::GCTonemapController2Alias_env_tonemap_controller2(void *ptr) {
    m_ptr = ptr;
}
std::string GCTonemapController2Alias_env_tonemap_controller2::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTonemapController2Alias_env_tonemap_controller2::IsValid() {
    return (m_ptr != nullptr);
}
GCTonemapController2 GCTonemapController2Alias_env_tonemap_controller2::GetParent() const {
    GCTonemapController2 value(m_ptr);
    return value;
}
void GCTonemapController2Alias_env_tonemap_controller2::SetParent(GCTonemapController2 value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTonemapController2Alias_env_tonemap_controller2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTonemapController2Alias_env_tonemap_controller2>("CTonemapController2Alias_env_tonemap_controller2")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTonemapController2Alias_env_tonemap_controller2::GetParent, &GCTonemapController2Alias_env_tonemap_controller2::SetParent)
        .addFunction("ToPtr", &GCTonemapController2Alias_env_tonemap_controller2::ToPtr)
        .addFunction("IsValid", &GCTonemapController2Alias_env_tonemap_controller2::IsValid)
        .endClass();
}