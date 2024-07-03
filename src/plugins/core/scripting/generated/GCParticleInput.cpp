#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleInput::GCParticleInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleInput::GCParticleInput(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleInput::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleInput>("CParticleInput")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCParticleInput::ToPtr)
        .addFunction("IsValid", &GCParticleInput::IsValid)
        .endClass();
}