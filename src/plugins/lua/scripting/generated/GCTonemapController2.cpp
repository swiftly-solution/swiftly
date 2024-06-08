#include "../../../core/scripting/generated/classes/GCTonemapController2.h"
#include "../core.h"

void SetupLuaClassGCTonemapController2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTonemapController2>("CTonemapController2")
        .addProperty("AutoExposureMin", &GCTonemapController2::GetAutoExposureMin, &GCTonemapController2::SetAutoExposureMin)
        .addProperty("AutoExposureMax", &GCTonemapController2::GetAutoExposureMax, &GCTonemapController2::SetAutoExposureMax)
        .addProperty("TonemapPercentTarget", &GCTonemapController2::GetTonemapPercentTarget, &GCTonemapController2::SetTonemapPercentTarget)
        .addProperty("TonemapPercentBrightPixels", &GCTonemapController2::GetTonemapPercentBrightPixels, &GCTonemapController2::SetTonemapPercentBrightPixels)
        .addProperty("TonemapMinAvgLum", &GCTonemapController2::GetTonemapMinAvgLum, &GCTonemapController2::SetTonemapMinAvgLum)
        .addProperty("ExposureAdaptationSpeedUp", &GCTonemapController2::GetExposureAdaptationSpeedUp, &GCTonemapController2::SetExposureAdaptationSpeedUp)
        .addProperty("ExposureAdaptationSpeedDown", &GCTonemapController2::GetExposureAdaptationSpeedDown, &GCTonemapController2::SetExposureAdaptationSpeedDown)
        .addProperty("TonemapEVSmoothingRange", &GCTonemapController2::GetTonemapEVSmoothingRange, &GCTonemapController2::SetTonemapEVSmoothingRange)
        .endClass();
}