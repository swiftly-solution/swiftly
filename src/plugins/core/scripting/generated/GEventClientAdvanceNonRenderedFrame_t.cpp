#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientAdvanceNonRenderedFrame_t::GEventClientAdvanceNonRenderedFrame_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientAdvanceNonRenderedFrame_t::GEventClientAdvanceNonRenderedFrame_t(void *ptr) {
    m_ptr = ptr;
}
std::string GEventClientAdvanceNonRenderedFrame_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientAdvanceNonRenderedFrame_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientAdvanceNonRenderedFrame_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientAdvanceNonRenderedFrame_t>("EventClientAdvanceNonRenderedFrame_t")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GEventClientAdvanceNonRenderedFrame_t::ToPtr)
        .addFunction("IsValid", &GEventClientAdvanceNonRenderedFrame_t::IsValid)
        .endClass();
}