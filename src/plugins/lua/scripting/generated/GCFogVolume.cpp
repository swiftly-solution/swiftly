#include "../../../core/scripting/generated/classes/GCFogVolume.h"
#include "../core.h"

void SetupLuaClassGCFogVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFogVolume>("CFogVolume")
        .addProperty("FogName", &GCFogVolume::GetFogName, &GCFogVolume::SetFogName)
        .addProperty("PostProcessName", &GCFogVolume::GetPostProcessName, &GCFogVolume::SetPostProcessName)
        .addProperty("ColorCorrectionName", &GCFogVolume::GetColorCorrectionName, &GCFogVolume::SetColorCorrectionName)
        .addProperty("Disabled", &GCFogVolume::GetDisabled, &GCFogVolume::SetDisabled)
        .addProperty("InFogVolumesList", &GCFogVolume::GetInFogVolumesList, &GCFogVolume::SetInFogVolumesList)
        .endClass();
}