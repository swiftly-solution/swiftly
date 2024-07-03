#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimTagManagerUpdater::GCAnimTagManagerUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimTagManagerUpdater::GCAnimTagManagerUpdater(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimTagManagerUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimTagManagerUpdater::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimTagManagerUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimTagManagerUpdater>("CAnimTagManagerUpdater")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCAnimTagManagerUpdater::ToPtr)
        .addFunction("IsValid", &GCAnimTagManagerUpdater::IsValid)
        .endClass();
}