#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimGraphSettingsManager::GCAnimGraphSettingsManager(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimGraphSettingsManager::GCAnimGraphSettingsManager(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimGraphSettingsManager::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimGraphSettingsManager::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimGraphSettingsManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphSettingsManager>("CAnimGraphSettingsManager")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCAnimGraphSettingsManager::ToPtr)
        .addFunction("IsValid", &GCAnimGraphSettingsManager::IsValid)
        .endClass();
}