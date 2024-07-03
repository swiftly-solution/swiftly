#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIParticleEffect::GIParticleEffect(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIParticleEffect::GIParticleEffect(void *ptr) {
    m_ptr = ptr;
}
std::string GIParticleEffect::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIParticleEffect::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIParticleEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIParticleEffect>("IParticleEffect")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIParticleEffect::ToPtr)
        .addFunction("IsValid", &GIParticleEffect::IsValid)
        .endClass();
}