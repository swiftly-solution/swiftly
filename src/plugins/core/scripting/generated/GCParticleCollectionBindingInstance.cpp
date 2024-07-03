#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleCollectionBindingInstance::GCParticleCollectionBindingInstance(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleCollectionBindingInstance::GCParticleCollectionBindingInstance(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleCollectionBindingInstance::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleCollectionBindingInstance::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleCollectionBindingInstance(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionBindingInstance>("CParticleCollectionBindingInstance")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCParticleCollectionBindingInstance::ToPtr)
        .addFunction("IsValid", &GCParticleCollectionBindingInstance::IsValid)
        .endClass();
}