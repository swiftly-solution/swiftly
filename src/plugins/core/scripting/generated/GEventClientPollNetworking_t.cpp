#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPollNetworking_t::GEventClientPollNetworking_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPollNetworking_t::GEventClientPollNetworking_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEventClientPollNetworking_t::GetTickCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventClientPollNetworking_t", "m_nTickCount");
}
void GEventClientPollNetworking_t::SetTickCount(int32_t value) {
    SetSchemaValue(m_ptr, "EventClientPollNetworking_t", "m_nTickCount", true, value);
}
std::string GEventClientPollNetworking_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPollNetworking_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientPollNetworking_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPollNetworking_t>("EventClientPollNetworking_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TickCount", &GEventClientPollNetworking_t::GetTickCount, &GEventClientPollNetworking_t::SetTickCount)
        .addFunction("ToPtr", &GEventClientPollNetworking_t::ToPtr)
        .addFunction("IsValid", &GEventClientPollNetworking_t::IsValid)
        .endClass();
}