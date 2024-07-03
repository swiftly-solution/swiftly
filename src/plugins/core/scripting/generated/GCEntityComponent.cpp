#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEntityComponent::GCEntityComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEntityComponent::GCEntityComponent(void *ptr) {
    m_ptr = ptr;
}
std::string GCEntityComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEntityComponent::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEntityComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityComponent>("CEntityComponent")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCEntityComponent::ToPtr)
        .addFunction("IsValid", &GCEntityComponent::IsValid)
        .endClass();
}