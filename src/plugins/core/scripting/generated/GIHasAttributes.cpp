#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIHasAttributes::GIHasAttributes(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIHasAttributes::GIHasAttributes(void *ptr) {
    m_ptr = ptr;
}
std::string GIHasAttributes::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIHasAttributes::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIHasAttributes(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIHasAttributes>("IHasAttributes")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIHasAttributes::ToPtr)
        .addFunction("IsValid", &GIHasAttributes::IsValid)
        .endClass();
}