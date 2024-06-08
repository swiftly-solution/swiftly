#include "../../../core/scripting/generated/classes/GParticleNamedValueSource_t.h"
#include "../core.h"

void SetupLuaClassGParticleNamedValueSource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleNamedValueSource_t>("ParticleNamedValueSource_t")
        .addProperty("Name", &GParticleNamedValueSource_t::GetName, &GParticleNamedValueSource_t::SetName)
        .addProperty("IsPublic", &GParticleNamedValueSource_t::GetIsPublic, &GParticleNamedValueSource_t::SetIsPublic)
        .addProperty("ValueType", &GParticleNamedValueSource_t::GetValueType, &GParticleNamedValueSource_t::SetValueType)
        .addProperty("DefaultConfig", &GParticleNamedValueSource_t::GetDefaultConfig, &GParticleNamedValueSource_t::SetDefaultConfig)
        .addProperty("NamedConfigs", &GParticleNamedValueSource_t::GetNamedConfigs, &GParticleNamedValueSource_t::SetNamedConfigs)
        .endClass();
}