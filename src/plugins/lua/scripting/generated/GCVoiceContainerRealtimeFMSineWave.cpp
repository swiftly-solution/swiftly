#include "../../../core/scripting/generated/classes/GCVoiceContainerRealtimeFMSineWave.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerRealtimeFMSineWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerRealtimeFMSineWave>("CVoiceContainerRealtimeFMSineWave")
        .addProperty("CarrierFrequency", &GCVoiceContainerRealtimeFMSineWave::GetCarrierFrequency, &GCVoiceContainerRealtimeFMSineWave::SetCarrierFrequency)
        .addProperty("ModulatorFrequency", &GCVoiceContainerRealtimeFMSineWave::GetModulatorFrequency, &GCVoiceContainerRealtimeFMSineWave::SetModulatorFrequency)
        .addProperty("ModulatorAmount", &GCVoiceContainerRealtimeFMSineWave::GetModulatorAmount, &GCVoiceContainerRealtimeFMSineWave::SetModulatorAmount)
        .endClass();
}