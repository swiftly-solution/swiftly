#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventServerProcessNetworking_t::GEventServerProcessNetworking_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventServerProcessNetworking_t::GEventServerProcessNetworking_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventServerProcessNetworking_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventServerProcessNetworking_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventServerProcessNetworking_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventServerProcessNetworking_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventServerProcessNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerProcessNetworking_t>("EventServerProcessNetworking_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventServerProcessNetworking_t::GetParent, &GEventServerProcessNetworking_t::SetParent)
        .addFunction("ToPtr", &GEventServerProcessNetworking_t::ToPtr)
        .addFunction("IsValid", &GEventServerProcessNetworking_t::IsValid)
        .endClass();
}