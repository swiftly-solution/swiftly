#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPostAdvanceTick_t::GEventClientPostAdvanceTick_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPostAdvanceTick_t::GEventClientPostAdvanceTick_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientPostAdvanceTick_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPostAdvanceTick_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventPostAdvanceTick_t GEventClientPostAdvanceTick_t::GetParent() const {
    GEventPostAdvanceTick_t value(m_ptr);
    return value;
}
void GEventClientPostAdvanceTick_t::SetParent(GEventPostAdvanceTick_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventClientPostAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPostAdvanceTick_t>("EventClientPostAdvanceTick_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventClientPostAdvanceTick_t::GetParent, &GEventClientPostAdvanceTick_t::SetParent)
        .addFunction("ToPtr", &GEventClientPostAdvanceTick_t::ToPtr)
        .addFunction("IsValid", &GEventClientPostAdvanceTick_t::IsValid)
        .endClass();
}