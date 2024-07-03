#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIEconItemInterface::GIEconItemInterface(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIEconItemInterface::GIEconItemInterface(void *ptr) {
    m_ptr = ptr;
}
std::string GIEconItemInterface::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIEconItemInterface::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIEconItemInterface(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIEconItemInterface>("IEconItemInterface")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIEconItemInterface::ToPtr)
        .addFunction("IsValid", &GIEconItemInterface::IsValid)
        .endClass();
}