#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIClientAlphaProperty::GIClientAlphaProperty(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIClientAlphaProperty::GIClientAlphaProperty(void *ptr) {
    m_ptr = ptr;
}
std::string GIClientAlphaProperty::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIClientAlphaProperty::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIClientAlphaProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIClientAlphaProperty>("IClientAlphaProperty")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIClientAlphaProperty::ToPtr)
        .addFunction("IsValid", &GIClientAlphaProperty::IsValid)
        .endClass();
}