#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScriptExtensions_player_controller::GCCSPointScriptExtensions_player_controller(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScriptExtensions_player_controller::GCCSPointScriptExtensions_player_controller(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPointScriptExtensions_player_controller::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScriptExtensions_player_controller::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSPointScriptExtensions_player_controller(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_player_controller>("CCSPointScriptExtensions_player_controller")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCCSPointScriptExtensions_player_controller::ToPtr)
        .addFunction("IsValid", &GCCSPointScriptExtensions_player_controller::IsValid)
        .endClass();
}