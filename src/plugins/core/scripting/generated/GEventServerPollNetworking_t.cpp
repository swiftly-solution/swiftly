#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventServerPollNetworking_t::GEventServerPollNetworking_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventServerPollNetworking_t::GEventServerPollNetworking_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventServerPollNetworking_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventServerPollNetworking_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventServerPollNetworking_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventServerPollNetworking_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventServerPollNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerPollNetworking_t>("EventServerPollNetworking_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GEventServerPollNetworking_t::GetParent, &GEventServerPollNetworking_t::SetParent)
        .addFunction("ToPtr", &GEventServerPollNetworking_t::ToPtr)
        .addFunction("IsValid", &GEventServerPollNetworking_t::IsValid)
        .endClass();
}