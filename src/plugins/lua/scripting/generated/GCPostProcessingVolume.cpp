#include "../../../core/scripting/generated/classes/GCPostProcessingVolume.h"
#include "../core.h"

void SetupLuaClassGCPostProcessingVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPostProcessingVolume>("CPostProcessingVolume")
        .addProperty("FadeDuration", &GCPostProcessingVolume::GetFadeDuration, &GCPostProcessingVolume::SetFadeDuration)
        .addProperty("MinLogExposure", &GCPostProcessingVolume::GetMinLogExposure, &GCPostProcessingVolume::SetMinLogExposure)
        .addProperty("MaxLogExposure", &GCPostProcessingVolume::GetMaxLogExposure, &GCPostProcessingVolume::SetMaxLogExposure)
        .addProperty("MinExposure", &GCPostProcessingVolume::GetMinExposure, &GCPostProcessingVolume::SetMinExposure)
        .addProperty("MaxExposure", &GCPostProcessingVolume::GetMaxExposure, &GCPostProcessingVolume::SetMaxExposure)
        .addProperty("ExposureCompensation", &GCPostProcessingVolume::GetExposureCompensation, &GCPostProcessingVolume::SetExposureCompensation)
        .addProperty("ExposureFadeSpeedUp", &GCPostProcessingVolume::GetExposureFadeSpeedUp, &GCPostProcessingVolume::SetExposureFadeSpeedUp)
        .addProperty("ExposureFadeSpeedDown", &GCPostProcessingVolume::GetExposureFadeSpeedDown, &GCPostProcessingVolume::SetExposureFadeSpeedDown)
        .addProperty("TonemapEVSmoothingRange", &GCPostProcessingVolume::GetTonemapEVSmoothingRange, &GCPostProcessingVolume::SetTonemapEVSmoothingRange)
        .addProperty("Master", &GCPostProcessingVolume::GetMaster, &GCPostProcessingVolume::SetMaster)
        .addProperty("ExposureControl", &GCPostProcessingVolume::GetExposureControl, &GCPostProcessingVolume::SetExposureControl)
        .addProperty("Rate", &GCPostProcessingVolume::GetRate, &GCPostProcessingVolume::SetRate)
        .addProperty("TonemapPercentTarget", &GCPostProcessingVolume::GetTonemapPercentTarget, &GCPostProcessingVolume::SetTonemapPercentTarget)
        .addProperty("TonemapPercentBrightPixels", &GCPostProcessingVolume::GetTonemapPercentBrightPixels, &GCPostProcessingVolume::SetTonemapPercentBrightPixels)
        .addProperty("TonemapMinAvgLum", &GCPostProcessingVolume::GetTonemapMinAvgLum, &GCPostProcessingVolume::SetTonemapMinAvgLum)
        .endClass();
}