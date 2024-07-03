#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventServerPostAdvanceTick_t::GEventServerPostAdvanceTick_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventServerPostAdvanceTick_t::GEventServerPostAdvanceTick_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventServerPostAdvanceTick_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventServerPostAdvanceTick_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventPostAdvanceTick_t GEventServerPostAdvanceTick_t::GetParent() const {
    GEventPostAdvanceTick_t value(m_ptr);
    return value;
}
void GEventServerPostAdvanceTick_t::SetParent(GEventPostAdvanceTick_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventServerPostAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerPostAdvanceTick_t>("EventServerPostAdvanceTick_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventServerPostAdvanceTick_t::GetParent, &GEventServerPostAdvanceTick_t::SetParent)
        .addFunction("ToPtr", &GEventServerPostAdvanceTick_t::ToPtr)
        .addFunction("IsValid", &GEventServerPostAdvanceTick_t::IsValid)
        .endClass();
}