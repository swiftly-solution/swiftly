#include "../../../core/scripting/generated/classes/GCSound.h"
#include "../core.h"

void SetupLuaClassGCSound(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSound>("CSound")
        .addProperty("Owner", &GCSound::GetOwner, &GCSound::SetOwner)
        .addProperty("Target", &GCSound::GetTarget, &GCSound::SetTarget)
        .addProperty("Volume", &GCSound::GetVolume, &GCSound::SetVolume)
        .addProperty("OcclusionScale", &GCSound::GetOcclusionScale, &GCSound::SetOcclusionScale)
        .addProperty("NextAudible", &GCSound::GetNextAudible, &GCSound::SetNextAudible)
        .addProperty("Next", &GCSound::GetNext, &GCSound::SetNext)
        .addProperty("NoExpirationTime", &GCSound::GetNoExpirationTime, &GCSound::SetNoExpirationTime)
        .addProperty("OwnerChannelIndex", &GCSound::GetOwnerChannelIndex, &GCSound::SetOwnerChannelIndex)
        .addProperty("Origin", &GCSound::GetOrigin, &GCSound::SetOrigin)
        .addProperty("HasOwner", &GCSound::GetHasOwner, &GCSound::SetHasOwner)
        .endClass();
}