#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventModInitialized_t::GEventModInitialized_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventModInitialized_t::GEventModInitialized_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventModInitialized_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventModInitialized_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventModInitialized_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventModInitialized_t>("EventModInitialized_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GEventModInitialized_t::ToPtr)
        .addFunction("IsValid", &GEventModInitialized_t::IsValid)
        .endClass();
}