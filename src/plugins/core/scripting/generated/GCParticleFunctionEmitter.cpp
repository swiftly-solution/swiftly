#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunctionEmitter::GCParticleFunctionEmitter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunctionEmitter::GCParticleFunctionEmitter(void *ptr) {
    m_ptr = ptr;
}
int32_t GCParticleFunctionEmitter::GetEmitterIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFunctionEmitter", "m_nEmitterIndex");
}
void GCParticleFunctionEmitter::SetEmitterIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFunctionEmitter", "m_nEmitterIndex", false, value);
}
std::string GCParticleFunctionEmitter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunctionEmitter::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunction GCParticleFunctionEmitter::GetParent() const {
    GCParticleFunction value(m_ptr);
    return value;
}
void GCParticleFunctionEmitter::SetParent(GCParticleFunction value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFunctionEmitter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionEmitter>("CParticleFunctionEmitter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EmitterIndex", &GCParticleFunctionEmitter::GetEmitterIndex, &GCParticleFunctionEmitter::SetEmitterIndex)
        .addProperty("Parent", &GCParticleFunctionEmitter::GetParent, &GCParticleFunctionEmitter::SetParent)
        .addFunction("ToPtr", &GCParticleFunctionEmitter::ToPtr)
        .addFunction("IsValid", &GCParticleFunctionEmitter::IsValid)
        .endClass();
}