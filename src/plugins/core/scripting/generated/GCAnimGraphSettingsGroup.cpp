#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimGraphSettingsGroup::GCAnimGraphSettingsGroup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimGraphSettingsGroup::GCAnimGraphSettingsGroup(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimGraphSettingsGroup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimGraphSettingsGroup::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimGraphSettingsGroup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphSettingsGroup>("CAnimGraphSettingsGroup")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCAnimGraphSettingsGroup::ToPtr)
        .addFunction("IsValid", &GCAnimGraphSettingsGroup::IsValid)
        .endClass();
}