#include "../../../core/scripting/generated/classes/GCVoiceContainerDecayingSineWave.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerDecayingSineWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerDecayingSineWave>("CVoiceContainerDecayingSineWave")
        .addProperty("Frequency", &GCVoiceContainerDecayingSineWave::GetFrequency, &GCVoiceContainerDecayingSineWave::SetFrequency)
        .addProperty("DecayTime", &GCVoiceContainerDecayingSineWave::GetDecayTime, &GCVoiceContainerDecayingSineWave::SetDecayTime)
        .endClass();
}