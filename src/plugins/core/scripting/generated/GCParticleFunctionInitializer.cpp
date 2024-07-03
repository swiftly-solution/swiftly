#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunctionInitializer::GCParticleFunctionInitializer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunctionInitializer::GCParticleFunctionInitializer(void *ptr) {
    m_ptr = ptr;
}
int32_t GCParticleFunctionInitializer::GetAssociatedEmitterIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFunctionInitializer", "m_nAssociatedEmitterIndex");
}
void GCParticleFunctionInitializer::SetAssociatedEmitterIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFunctionInitializer", "m_nAssociatedEmitterIndex", false, value);
}
std::string GCParticleFunctionInitializer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunctionInitializer::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunction GCParticleFunctionInitializer::GetParent() const {
    GCParticleFunction value(m_ptr);
    return value;
}
void GCParticleFunctionInitializer::SetParent(GCParticleFunction value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFunctionInitializer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionInitializer>("CParticleFunctionInitializer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AssociatedEmitterIndex", &GCParticleFunctionInitializer::GetAssociatedEmitterIndex, &GCParticleFunctionInitializer::SetAssociatedEmitterIndex)
        .addProperty("Parent", &GCParticleFunctionInitializer::GetParent, &GCParticleFunctionInitializer::SetParent)
        .addFunction("ToPtr", &GCParticleFunctionInitializer::ToPtr)
        .addFunction("IsValid", &GCParticleFunctionInitializer::IsValid)
        .endClass();
}