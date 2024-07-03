#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GIParticleCollection::GIParticleCollection(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GIParticleCollection::GIParticleCollection(void *ptr) {
    m_ptr = ptr;
}
std::string GIParticleCollection::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GIParticleCollection::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassIParticleCollection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIParticleCollection>("IParticleCollection")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GIParticleCollection::ToPtr)
        .addFunction("IsValid", &GIParticleCollection::IsValid)
        .endClass();
}