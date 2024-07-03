#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmGraphVariation::GCNmGraphVariation(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmGraphVariation::GCNmGraphVariation(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmGraphVariation::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmGraphVariation::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmGraphVariation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphVariation>("CNmGraphVariation")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCNmGraphVariation::ToPtr)
        .addFunction("IsValid", &GCNmGraphVariation::IsValid)
        .endClass();
}