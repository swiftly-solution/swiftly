#include "../../../core/scripting/generated/classes/GCVoiceContainerRandomSampler.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerRandomSampler(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerRandomSampler>("CVoiceContainerRandomSampler")
        .addProperty("Amplitude", &GCVoiceContainerRandomSampler::GetAmplitude, &GCVoiceContainerRandomSampler::SetAmplitude)
        .addProperty("AmplitudeJitter", &GCVoiceContainerRandomSampler::GetAmplitudeJitter, &GCVoiceContainerRandomSampler::SetAmplitudeJitter)
        .addProperty("TimeJitter", &GCVoiceContainerRandomSampler::GetTimeJitter, &GCVoiceContainerRandomSampler::SetTimeJitter)
        .addProperty("MaxLength", &GCVoiceContainerRandomSampler::GetMaxLength, &GCVoiceContainerRandomSampler::SetMaxLength)
        .addProperty("NumDelayVariations", &GCVoiceContainerRandomSampler::GetNumDelayVariations, &GCVoiceContainerRandomSampler::SetNumDelayVariations)
        .endClass();
}