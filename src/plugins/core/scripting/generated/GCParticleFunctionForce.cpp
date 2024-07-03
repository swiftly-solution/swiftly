#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunctionForce::GCParticleFunctionForce(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunctionForce::GCParticleFunctionForce(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleFunctionForce::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunctionForce::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunction GCParticleFunctionForce::GetParent() const {
    GCParticleFunction value(m_ptr);
    return value;
}
void GCParticleFunctionForce::SetParent(GCParticleFunction value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFunctionForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionForce>("CParticleFunctionForce")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCParticleFunctionForce::GetParent, &GCParticleFunctionForce::SetParent)
        .addFunction("ToPtr", &GCParticleFunctionForce::ToPtr)
        .addFunction("IsValid", &GCParticleFunctionForce::IsValid)
        .endClass();
}