#include "../../../core/scripting/generated/classes/GCColorCorrectionVolume.h"
#include "../core.h"

void SetupLuaClassGCColorCorrectionVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCColorCorrectionVolume>("CColorCorrectionVolume")
        .addProperty("Enabled", &GCColorCorrectionVolume::GetEnabled, &GCColorCorrectionVolume::SetEnabled)
        .addProperty("MaxWeight", &GCColorCorrectionVolume::GetMaxWeight, &GCColorCorrectionVolume::SetMaxWeight)
        .addProperty("FadeDuration", &GCColorCorrectionVolume::GetFadeDuration, &GCColorCorrectionVolume::SetFadeDuration)
        .addProperty("StartDisabled", &GCColorCorrectionVolume::GetStartDisabled, &GCColorCorrectionVolume::SetStartDisabled)
        .addProperty("Weight", &GCColorCorrectionVolume::GetWeight, &GCColorCorrectionVolume::SetWeight)
        .addProperty("LookupFilename", &GCColorCorrectionVolume::GetLookupFilename, &GCColorCorrectionVolume::SetLookupFilename)
        .addProperty("LastEnterWeight", &GCColorCorrectionVolume::GetLastEnterWeight, &GCColorCorrectionVolume::SetLastEnterWeight)
        .addProperty("LastExitWeight", &GCColorCorrectionVolume::GetLastExitWeight, &GCColorCorrectionVolume::SetLastExitWeight)
        .endClass();
}