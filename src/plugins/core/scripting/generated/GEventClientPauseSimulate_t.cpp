#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPauseSimulate_t::GEventClientPauseSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPauseSimulate_t::GEventClientPauseSimulate_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientPauseSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPauseSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventClientPauseSimulate_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventClientPauseSimulate_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventClientPauseSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPauseSimulate_t>("EventClientPauseSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventClientPauseSimulate_t::GetParent, &GEventClientPauseSimulate_t::SetParent)
        .addFunction("ToPtr", &GEventClientPauseSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventClientPauseSimulate_t::IsValid)
        .endClass();
}