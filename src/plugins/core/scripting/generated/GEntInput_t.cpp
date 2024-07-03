#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEntInput_t::GEntInput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEntInput_t::GEntInput_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEntInput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEntInput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEntInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntInput_t>("EntInput_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GEntInput_t::ToPtr)
        .addFunction("IsValid", &GEntInput_t::IsValid)
        .endClass();
}