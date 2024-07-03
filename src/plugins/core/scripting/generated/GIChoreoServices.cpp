#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIChoreoServices::GIChoreoServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIChoreoServices::GIChoreoServices(void *ptr) {
    m_ptr = ptr;
}
std::string GIChoreoServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIChoreoServices::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIChoreoServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIChoreoServices>("IChoreoServices")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIChoreoServices::ToPtr)
        .addFunction("IsValid", &GIChoreoServices::IsValid)
        .endClass();
}