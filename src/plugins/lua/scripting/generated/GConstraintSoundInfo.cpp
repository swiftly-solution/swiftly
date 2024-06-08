#include "../../../core/scripting/generated/classes/GConstraintSoundInfo.h"
#include "../core.h"

void SetupLuaClassGConstraintSoundInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConstraintSoundInfo>("ConstraintSoundInfo")
        .addProperty("Sampler", &GConstraintSoundInfo::GetSampler, &GConstraintSoundInfo::SetSampler)
        .addProperty("SoundProfile", &GConstraintSoundInfo::GetSoundProfile, &GConstraintSoundInfo::SetSoundProfile)
        .addProperty("ForwardAxis", &GConstraintSoundInfo::GetForwardAxis, &GConstraintSoundInfo::SetForwardAxis)
        .addProperty("TravelSoundFwd", &GConstraintSoundInfo::GetTravelSoundFwd, &GConstraintSoundInfo::SetTravelSoundFwd)
        .addProperty("TravelSoundBack", &GConstraintSoundInfo::GetTravelSoundBack, &GConstraintSoundInfo::SetTravelSoundBack)
        .addProperty("ReversalSounds", &GConstraintSoundInfo::GetReversalSounds, &GConstraintSoundInfo::SetReversalSounds)
        .addProperty("PlayTravelSound", &GConstraintSoundInfo::GetPlayTravelSound, &GConstraintSoundInfo::SetPlayTravelSound)
        .addProperty("PlayReversalSound", &GConstraintSoundInfo::GetPlayReversalSound, &GConstraintSoundInfo::SetPlayReversalSound)
        .endClass();
}