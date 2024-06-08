#include "../../../core/scripting/generated/classes/GCVoiceContainerAmpedDecayingSineWave.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerAmpedDecayingSineWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerAmpedDecayingSineWave>("CVoiceContainerAmpedDecayingSineWave")
        .addProperty("GainAmount", &GCVoiceContainerAmpedDecayingSineWave::GetGainAmount, &GCVoiceContainerAmpedDecayingSineWave::SetGainAmount)
        .endClass();
}