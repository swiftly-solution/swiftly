#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientAdvanceTick_t::GEventClientAdvanceTick_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientAdvanceTick_t::GEventClientAdvanceTick_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientAdvanceTick_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientAdvanceTick_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventAdvanceTick_t GEventClientAdvanceTick_t::GetParent() const {
    GEventAdvanceTick_t value(m_ptr);
    return value;
}
void GEventClientAdvanceTick_t::SetParent(GEventAdvanceTick_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventClientAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientAdvanceTick_t>("EventClientAdvanceTick_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventClientAdvanceTick_t::GetParent, &GEventClientAdvanceTick_t::SetParent)
        .addFunction("ToPtr", &GEventClientAdvanceTick_t::ToPtr)
        .addFunction("IsValid", &GEventClientAdvanceTick_t::IsValid)
        .endClass();
}