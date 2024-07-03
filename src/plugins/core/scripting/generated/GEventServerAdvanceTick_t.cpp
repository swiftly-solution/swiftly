#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventServerAdvanceTick_t::GEventServerAdvanceTick_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventServerAdvanceTick_t::GEventServerAdvanceTick_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventServerAdvanceTick_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventServerAdvanceTick_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventAdvanceTick_t GEventServerAdvanceTick_t::GetParent() const {
    GEventAdvanceTick_t value(m_ptr);
    return value;
}
void GEventServerAdvanceTick_t::SetParent(GEventAdvanceTick_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventServerAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerAdvanceTick_t>("EventServerAdvanceTick_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventServerAdvanceTick_t::GetParent, &GEventServerAdvanceTick_t::SetParent)
        .addFunction("ToPtr", &GEventServerAdvanceTick_t::ToPtr)
        .addFunction("IsValid", &GEventServerAdvanceTick_t::IsValid)
        .endClass();
}