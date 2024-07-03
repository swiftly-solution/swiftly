#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPointScriptExtensions_entity::GCCSPointScriptExtensions_entity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPointScriptExtensions_entity::GCCSPointScriptExtensions_entity(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSPointScriptExtensions_entity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPointScriptExtensions_entity::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCSPointScriptExtensions_entity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_entity>("CCSPointScriptExtensions_entity")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCCSPointScriptExtensions_entity::ToPtr)
        .addFunction("IsValid", &GCCSPointScriptExtensions_entity::IsValid)
        .endClass();
}