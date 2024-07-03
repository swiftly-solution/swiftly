#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimActionUpdater::GCAnimActionUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimActionUpdater::GCAnimActionUpdater(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimActionUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimActionUpdater::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimActionUpdater>("CAnimActionUpdater")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCAnimActionUpdater::ToPtr)
        .addFunction("IsValid", &GCAnimActionUpdater::IsValid)
        .endClass();
}