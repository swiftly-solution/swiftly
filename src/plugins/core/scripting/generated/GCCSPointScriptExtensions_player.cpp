#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScriptExtensions_player::GCCSPointScriptExtensions_player(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScriptExtensions_player::GCCSPointScriptExtensions_player(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPointScriptExtensions_player::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScriptExtensions_player::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSPointScriptExtensions_player(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_player>("CCSPointScriptExtensions_player")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCCSPointScriptExtensions_player::ToPtr)
        .addFunction("IsValid", &GCCSPointScriptExtensions_player::IsValid)
        .endClass();
}