#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunctionConstraint::GCParticleFunctionConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunctionConstraint::GCParticleFunctionConstraint(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleFunctionConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunctionConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunction GCParticleFunctionConstraint::GetParent() const {
    GCParticleFunction value(m_ptr);
    return value;
}
void GCParticleFunctionConstraint::SetParent(GCParticleFunction value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFunctionConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionConstraint>("CParticleFunctionConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCParticleFunctionConstraint::GetParent, &GCParticleFunctionConstraint::SetParent)
        .addFunction("ToPtr", &GCParticleFunctionConstraint::ToPtr)
        .addFunction("IsValid", &GCParticleFunctionConstraint::IsValid)
        .endClass();
}