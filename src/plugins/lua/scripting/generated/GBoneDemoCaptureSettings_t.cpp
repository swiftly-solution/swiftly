#include "../../../core/scripting/generated/classes/GBoneDemoCaptureSettings_t.h"
#include "../core.h"

void SetupLuaClassGBoneDemoCaptureSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBoneDemoCaptureSettings_t>("BoneDemoCaptureSettings_t")
        .addProperty("BoneName", &GBoneDemoCaptureSettings_t::GetBoneName, &GBoneDemoCaptureSettings_t::SetBoneName)
        .addProperty("ErrorSplineRotationMax", &GBoneDemoCaptureSettings_t::GetErrorSplineRotationMax, &GBoneDemoCaptureSettings_t::SetErrorSplineRotationMax)
        .addProperty("ErrorSplineTranslationMax", &GBoneDemoCaptureSettings_t::GetErrorSplineTranslationMax, &GBoneDemoCaptureSettings_t::SetErrorSplineTranslationMax)
        .addProperty("ErrorSplineScaleMax", &GBoneDemoCaptureSettings_t::GetErrorSplineScaleMax, &GBoneDemoCaptureSettings_t::SetErrorSplineScaleMax)
        .addProperty("ErrorQuantizationRotationMax", &GBoneDemoCaptureSettings_t::GetErrorQuantizationRotationMax, &GBoneDemoCaptureSettings_t::SetErrorQuantizationRotationMax)
        .addProperty("ErrorQuantizationTranslationMax", &GBoneDemoCaptureSettings_t::GetErrorQuantizationTranslationMax, &GBoneDemoCaptureSettings_t::SetErrorQuantizationTranslationMax)
        .addProperty("ErrorQuantizationScaleMax", &GBoneDemoCaptureSettings_t::GetErrorQuantizationScaleMax, &GBoneDemoCaptureSettings_t::SetErrorQuantizationScaleMax)
        .endClass();
}