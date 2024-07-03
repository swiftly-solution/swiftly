#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEntOutput_t::GEntOutput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEntOutput_t::GEntOutput_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEntOutput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEntOutput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEntOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntOutput_t>("EntOutput_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GEntOutput_t::ToPtr)
        .addFunction("IsValid", &GEntOutput_t::IsValid)
        .endClass();
}