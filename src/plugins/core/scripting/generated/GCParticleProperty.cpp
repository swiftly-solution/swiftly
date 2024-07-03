#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleProperty::GCParticleProperty(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleProperty::GCParticleProperty(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleProperty::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleProperty::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleProperty>("CParticleProperty")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCParticleProperty::ToPtr)
        .addFunction("IsValid", &GCParticleProperty::IsValid)
        .endClass();
}