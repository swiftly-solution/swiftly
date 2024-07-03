#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunctionOperator::GCParticleFunctionOperator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunctionOperator::GCParticleFunctionOperator(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleFunctionOperator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunctionOperator::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunction GCParticleFunctionOperator::GetParent() const {
    GCParticleFunction value(m_ptr);
    return value;
}
void GCParticleFunctionOperator::SetParent(GCParticleFunction value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFunctionOperator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionOperator>("CParticleFunctionOperator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCParticleFunctionOperator::GetParent, &GCParticleFunctionOperator::SetParent)
        .addFunction("ToPtr", &GCParticleFunctionOperator::ToPtr)
        .addFunction("IsValid", &GCParticleFunctionOperator::IsValid)
        .endClass();
}