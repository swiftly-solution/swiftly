#include "../../../core/scripting/generated/classes/GCEnvMicrophone.h"
#include "../core.h"

void SetupLuaClassGCEnvMicrophone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvMicrophone>("CEnvMicrophone")
        .addProperty("Disabled", &GCEnvMicrophone::GetDisabled, &GCEnvMicrophone::SetDisabled)
        .addProperty("MeasureTarget", &GCEnvMicrophone::GetMeasureTarget, &GCEnvMicrophone::SetMeasureTarget)
        .addProperty("SoundType", &GCEnvMicrophone::GetSoundType, &GCEnvMicrophone::SetSoundType)
        .addProperty("SoundFlags", &GCEnvMicrophone::GetSoundFlags, &GCEnvMicrophone::SetSoundFlags)
        .addProperty("Sensitivity", &GCEnvMicrophone::GetSensitivity, &GCEnvMicrophone::SetSensitivity)
        .addProperty("SmoothFactor", &GCEnvMicrophone::GetSmoothFactor, &GCEnvMicrophone::SetSmoothFactor)
        .addProperty("MaxRange", &GCEnvMicrophone::GetMaxRange, &GCEnvMicrophone::SetMaxRange)
        .addProperty("SpeakerName", &GCEnvMicrophone::GetSpeakerName, &GCEnvMicrophone::SetSpeakerName)
        .addProperty("Speaker", &GCEnvMicrophone::GetSpeaker, &GCEnvMicrophone::SetSpeaker)
        .addProperty("AvoidFeedback", &GCEnvMicrophone::GetAvoidFeedback, &GCEnvMicrophone::SetAvoidFeedback)
        .addProperty("SpeakerDSPPreset", &GCEnvMicrophone::GetSpeakerDSPPreset, &GCEnvMicrophone::SetSpeakerDSPPreset)
        .addProperty("ListenFilter", &GCEnvMicrophone::GetListenFilter, &GCEnvMicrophone::SetListenFilter)
        .addProperty("ListenFilter1", &GCEnvMicrophone::GetListenFilter1, &GCEnvMicrophone::SetListenFilter1)
        .addProperty("OnRoutedSound", &GCEnvMicrophone::GetOnRoutedSound, &GCEnvMicrophone::SetOnRoutedSound)
        .addProperty("OnHeardSound", &GCEnvMicrophone::GetOnHeardSound, &GCEnvMicrophone::SetOnHeardSound)
        .addProperty("LastSound", &GCEnvMicrophone::GetLastSound, &GCEnvMicrophone::SetLastSound)
        .addProperty("LastRoutedFrame", &GCEnvMicrophone::GetLastRoutedFrame, &GCEnvMicrophone::SetLastRoutedFrame)
        .endClass();
}