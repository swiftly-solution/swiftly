#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientSimulate_t::GEventClientSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientSimulate_t::GEventClientSimulate_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventClientSimulate_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventClientSimulate_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventClientSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientSimulate_t>("EventClientSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventClientSimulate_t::GetParent, &GEventClientSimulate_t::SetParent)
        .addFunction("ToPtr", &GEventClientSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventClientSimulate_t::IsValid)
        .endClass();
}