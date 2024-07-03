#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventAppShutdown_t::GEventAppShutdown_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventAppShutdown_t::GEventAppShutdown_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEventAppShutdown_t::GetDummy0() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventAppShutdown_t", "m_nDummy0");
}
void GEventAppShutdown_t::SetDummy0(int32_t value) {
    SetSchemaValue(m_ptr, "EventAppShutdown_t", "m_nDummy0", true, value);
}
std::string GEventAppShutdown_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventAppShutdown_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventAppShutdown_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventAppShutdown_t>("EventAppShutdown_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Dummy0", &GEventAppShutdown_t::GetDummy0, &GEventAppShutdown_t::SetDummy0)
        .addFunction("ToPtr", &GEventAppShutdown_t::ToPtr)
        .addFunction("IsValid", &GEventAppShutdown_t::IsValid)
        .endClass();
}