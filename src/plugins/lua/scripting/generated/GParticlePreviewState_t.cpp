#include "../../../core/scripting/generated/classes/GParticlePreviewState_t.h"
#include "../core.h"

void SetupLuaClassGParticlePreviewState_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticlePreviewState_t>("ParticlePreviewState_t")
        .addProperty("PreviewModel", &GParticlePreviewState_t::GetPreviewModel, &GParticlePreviewState_t::SetPreviewModel)
        .addProperty("ModSpecificData", &GParticlePreviewState_t::GetModSpecificData, &GParticlePreviewState_t::SetModSpecificData)
        .addProperty("GroundType", &GParticlePreviewState_t::GetGroundType, &GParticlePreviewState_t::SetGroundType)
        .addProperty("SequenceName", &GParticlePreviewState_t::GetSequenceName, &GParticlePreviewState_t::SetSequenceName)
        .addProperty("FireParticleOnSequenceFrame", &GParticlePreviewState_t::GetFireParticleOnSequenceFrame, &GParticlePreviewState_t::SetFireParticleOnSequenceFrame)
        .addProperty("HitboxSetName", &GParticlePreviewState_t::GetHitboxSetName, &GParticlePreviewState_t::SetHitboxSetName)
        .addProperty("MaterialGroupName", &GParticlePreviewState_t::GetMaterialGroupName, &GParticlePreviewState_t::SetMaterialGroupName)
        .addProperty("BodyGroups", &GParticlePreviewState_t::GetBodyGroups, &GParticlePreviewState_t::SetBodyGroups)
        .addProperty("PlaybackSpeed", &GParticlePreviewState_t::GetPlaybackSpeed, &GParticlePreviewState_t::SetPlaybackSpeed)
        .addProperty("ParticleSimulationRate", &GParticlePreviewState_t::GetParticleSimulationRate, &GParticlePreviewState_t::SetParticleSimulationRate)
        .addProperty("ShouldDrawHitboxes", &GParticlePreviewState_t::GetShouldDrawHitboxes, &GParticlePreviewState_t::SetShouldDrawHitboxes)
        .addProperty("ShouldDrawAttachments", &GParticlePreviewState_t::GetShouldDrawAttachments, &GParticlePreviewState_t::SetShouldDrawAttachments)
        .addProperty("ShouldDrawAttachmentNames", &GParticlePreviewState_t::GetShouldDrawAttachmentNames, &GParticlePreviewState_t::SetShouldDrawAttachmentNames)
        .addProperty("ShouldDrawControlPointAxes", &GParticlePreviewState_t::GetShouldDrawControlPointAxes, &GParticlePreviewState_t::SetShouldDrawControlPointAxes)
        .addProperty("AnimationNonLooping", &GParticlePreviewState_t::GetAnimationNonLooping, &GParticlePreviewState_t::SetAnimationNonLooping)
        .addProperty("PreviewGravity", &GParticlePreviewState_t::GetPreviewGravity, &GParticlePreviewState_t::SetPreviewGravity)
        .endClass();
}