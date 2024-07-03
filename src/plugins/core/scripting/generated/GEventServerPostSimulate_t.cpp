#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventServerPostSimulate_t::GEventServerPostSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventServerPostSimulate_t::GEventServerPostSimulate_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventServerPostSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventServerPostSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventServerPostSimulate_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventServerPostSimulate_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventServerPostSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerPostSimulate_t>("EventServerPostSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventServerPostSimulate_t::GetParent, &GEventServerPostSimulate_t::SetParent)
        .addFunction("ToPtr", &GEventServerPostSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventServerPostSimulate_t::IsValid)
        .endClass();
}