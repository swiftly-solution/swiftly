#include "../../../core/scripting/generated/classes/GParticleNamedValueConfiguration_t.h"
#include "../core.h"

void SetupLuaClassGParticleNamedValueConfiguration_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleNamedValueConfiguration_t>("ParticleNamedValueConfiguration_t")
        .addProperty("ConfigName", &GParticleNamedValueConfiguration_t::GetConfigName, &GParticleNamedValueConfiguration_t::SetConfigName)
        .addProperty("AttachType", &GParticleNamedValueConfiguration_t::GetAttachType, &GParticleNamedValueConfiguration_t::SetAttachType)
        .addProperty("BoundEntityPath", &GParticleNamedValueConfiguration_t::GetBoundEntityPath, &GParticleNamedValueConfiguration_t::SetBoundEntityPath)
        .addProperty("StrEntityScope", &GParticleNamedValueConfiguration_t::GetStrEntityScope, &GParticleNamedValueConfiguration_t::SetStrEntityScope)
        .addProperty("StrAttachmentName", &GParticleNamedValueConfiguration_t::GetStrAttachmentName, &GParticleNamedValueConfiguration_t::SetStrAttachmentName)
        .endClass();
}