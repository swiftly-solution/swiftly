#include "../../../core/scripting/generated/classes/GCParticleAnimTag.h"
#include "../core.h"

void SetupLuaClassGCParticleAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleAnimTag>("CParticleAnimTag")
        .addProperty("ParticleSystemName", &GCParticleAnimTag::GetParticleSystemName, &GCParticleAnimTag::SetParticleSystemName)
        .addProperty("ConfigName", &GCParticleAnimTag::GetConfigName, &GCParticleAnimTag::SetConfigName)
        .addProperty("DetachFromOwner", &GCParticleAnimTag::GetDetachFromOwner, &GCParticleAnimTag::SetDetachFromOwner)
        .addProperty("StopWhenTagEnds", &GCParticleAnimTag::GetStopWhenTagEnds, &GCParticleAnimTag::SetStopWhenTagEnds)
        .addProperty("TagEndStopIsInstant", &GCParticleAnimTag::GetTagEndStopIsInstant, &GCParticleAnimTag::SetTagEndStopIsInstant)
        .addProperty("AttachmentName", &GCParticleAnimTag::GetAttachmentName, &GCParticleAnimTag::SetAttachmentName)
        .addProperty("AttachmentType", &GCParticleAnimTag::GetAttachmentType, &GCParticleAnimTag::SetAttachmentType)
        .addProperty("AttachmentCP1Name", &GCParticleAnimTag::GetAttachmentCP1Name, &GCParticleAnimTag::SetAttachmentCP1Name)
        .addProperty("AttachmentCP1Type", &GCParticleAnimTag::GetAttachmentCP1Type, &GCParticleAnimTag::SetAttachmentCP1Type)
        .endClass();
}