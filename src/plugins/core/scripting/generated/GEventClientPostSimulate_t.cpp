#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPostSimulate_t::GEventClientPostSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPostSimulate_t::GEventClientPostSimulate_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientPostSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPostSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventClientPostSimulate_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventClientPostSimulate_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventClientPostSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPostSimulate_t>("EventClientPostSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventClientPostSimulate_t::GetParent, &GEventClientPostSimulate_t::SetParent)
        .addFunction("ToPtr", &GEventClientPostSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventClientPostSimulate_t::IsValid)
        .endClass();
}