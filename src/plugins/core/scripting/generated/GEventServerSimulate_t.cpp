#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventServerSimulate_t::GEventServerSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventServerSimulate_t::GEventServerSimulate_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventServerSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventServerSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventServerSimulate_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventServerSimulate_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventServerSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerSimulate_t>("EventServerSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventServerSimulate_t::GetParent, &GEventServerSimulate_t::SetParent)
        .addFunction("ToPtr", &GEventServerSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventServerSimulate_t::IsValid)
        .endClass();
}