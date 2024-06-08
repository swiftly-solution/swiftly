#include "../../../core/scripting/generated/classes/GCVoiceContainerStaticAdditiveSynth.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerStaticAdditiveSynth(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerStaticAdditiveSynth>("CVoiceContainerStaticAdditiveSynth")
        .addProperty("MinVolume", &GCVoiceContainerStaticAdditiveSynth::GetMinVolume, &GCVoiceContainerStaticAdditiveSynth::SetMinVolume)
        .addProperty("InstancesAtMinVolume", &GCVoiceContainerStaticAdditiveSynth::GetInstancesAtMinVolume, &GCVoiceContainerStaticAdditiveSynth::SetInstancesAtMinVolume)
        .addProperty("MaxVolume", &GCVoiceContainerStaticAdditiveSynth::GetMaxVolume, &GCVoiceContainerStaticAdditiveSynth::SetMaxVolume)
        .addProperty("InstancesAtMaxVolume", &GCVoiceContainerStaticAdditiveSynth::GetInstancesAtMaxVolume, &GCVoiceContainerStaticAdditiveSynth::SetInstancesAtMaxVolume)
        .endClass();
}