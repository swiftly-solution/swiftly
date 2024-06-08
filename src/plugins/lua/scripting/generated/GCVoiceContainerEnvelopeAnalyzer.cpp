#include "../../../core/scripting/generated/classes/GCVoiceContainerEnvelopeAnalyzer.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerEnvelopeAnalyzer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerEnvelopeAnalyzer>("CVoiceContainerEnvelopeAnalyzer")
        .addProperty("Mode", &GCVoiceContainerEnvelopeAnalyzer::GetMode, &GCVoiceContainerEnvelopeAnalyzer::SetMode)
        .addProperty("Samples", &GCVoiceContainerEnvelopeAnalyzer::GetSamples, &GCVoiceContainerEnvelopeAnalyzer::SetSamples)
        .addProperty("Threshold", &GCVoiceContainerEnvelopeAnalyzer::GetThreshold, &GCVoiceContainerEnvelopeAnalyzer::SetThreshold)
        .endClass();
}