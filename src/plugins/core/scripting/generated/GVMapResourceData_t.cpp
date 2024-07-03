#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVMapResourceData_t::GVMapResourceData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVMapResourceData_t::GVMapResourceData_t(void *ptr) {
    m_ptr = ptr;
}
std::string GVMapResourceData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVMapResourceData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVMapResourceData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMapResourceData_t>("VMapResourceData_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GVMapResourceData_t::ToPtr)
        .addFunction("IsValid", &GVMapResourceData_t::IsValid)
        .endClass();
}