#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPreSimulate_t::GEventClientPreSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPreSimulate_t::GEventClientPreSimulate_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientPreSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPreSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventClientPreSimulate_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventClientPreSimulate_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventClientPreSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPreSimulate_t>("EventClientPreSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventClientPreSimulate_t::GetParent, &GEventClientPreSimulate_t::SetParent)
        .addFunction("ToPtr", &GEventClientPreSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventClientPreSimulate_t::IsValid)
        .endClass();
}