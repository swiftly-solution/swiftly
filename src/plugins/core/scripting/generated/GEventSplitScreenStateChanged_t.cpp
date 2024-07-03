#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventSplitScreenStateChanged_t::GEventSplitScreenStateChanged_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventSplitScreenStateChanged_t::GEventSplitScreenStateChanged_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventSplitScreenStateChanged_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventSplitScreenStateChanged_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventSplitScreenStateChanged_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSplitScreenStateChanged_t>("EventSplitScreenStateChanged_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GEventSplitScreenStateChanged_t::ToPtr)
        .addFunction("IsValid", &GEventSplitScreenStateChanged_t::IsValid)
        .endClass();
}