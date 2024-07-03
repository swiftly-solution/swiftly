#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientProcessNetworking_t::GEventClientProcessNetworking_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientProcessNetworking_t::GEventClientProcessNetworking_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientProcessNetworking_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientProcessNetworking_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientProcessNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientProcessNetworking_t>("EventClientProcessNetworking_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GEventClientProcessNetworking_t::ToPtr)
        .addFunction("IsValid", &GEventClientProcessNetworking_t::IsValid)
        .endClass();
}