#include "../../../core/scripting/generated/classes/GC_OP_RenderSound.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderSound(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderSound>("C_OP_RenderSound")
        .addProperty("DurationScale", &GC_OP_RenderSound::GetDurationScale, &GC_OP_RenderSound::SetDurationScale)
        .addProperty("SndLvlScale", &GC_OP_RenderSound::GetSndLvlScale, &GC_OP_RenderSound::SetSndLvlScale)
        .addProperty("PitchScale", &GC_OP_RenderSound::GetPitchScale, &GC_OP_RenderSound::SetPitchScale)
        .addProperty("VolumeScale", &GC_OP_RenderSound::GetVolumeScale, &GC_OP_RenderSound::SetVolumeScale)
        .addProperty("SndLvlField", &GC_OP_RenderSound::GetSndLvlField, &GC_OP_RenderSound::SetSndLvlField)
        .addProperty("DurationField", &GC_OP_RenderSound::GetDurationField, &GC_OP_RenderSound::SetDurationField)
        .addProperty("PitchField", &GC_OP_RenderSound::GetPitchField, &GC_OP_RenderSound::SetPitchField)
        .addProperty("VolumeField", &GC_OP_RenderSound::GetVolumeField, &GC_OP_RenderSound::SetVolumeField)
        .addProperty("Channel", &GC_OP_RenderSound::GetChannel, &GC_OP_RenderSound::SetChannel)
        .addProperty("CPReference", &GC_OP_RenderSound::GetCPReference, &GC_OP_RenderSound::SetCPReference)
        .addProperty("SoundName", &GC_OP_RenderSound::GetSoundName, &GC_OP_RenderSound::SetSoundName)
        .addProperty("SuppressStopSoundEvent", &GC_OP_RenderSound::GetSuppressStopSoundEvent, &GC_OP_RenderSound::SetSuppressStopSoundEvent)
        .endClass();
}