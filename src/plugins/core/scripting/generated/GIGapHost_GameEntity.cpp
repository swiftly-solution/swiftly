#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIGapHost_GameEntity::GIGapHost_GameEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIGapHost_GameEntity::GIGapHost_GameEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GIGapHost_GameEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIGapHost_GameEntity::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIGapHost_GameEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIGapHost_GameEntity>("IGapHost_GameEntity")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIGapHost_GameEntity::ToPtr)
        .addFunction("IsValid", &GIGapHost_GameEntity::IsValid)
        .endClass();
}