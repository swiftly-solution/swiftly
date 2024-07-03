#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleCollectionRendererVecInput::GCParticleCollectionRendererVecInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleCollectionRendererVecInput::GCParticleCollectionRendererVecInput(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleCollectionRendererVecInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleCollectionRendererVecInput::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleCollectionRendererVecInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionRendererVecInput>("CParticleCollectionRendererVecInput")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GCParticleCollectionRendererVecInput::ToPtr)
        .addFunction("IsValid", &GCParticleCollectionRendererVecInput::IsValid)
        .endClass();
}