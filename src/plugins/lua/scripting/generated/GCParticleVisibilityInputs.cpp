#include "../../../core/scripting/generated/classes/GCParticleVisibilityInputs.h"
#include "../core.h"

void SetupLuaClassGCParticleVisibilityInputs(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleVisibilityInputs>("CParticleVisibilityInputs")
        .addProperty("CameraBias", &GCParticleVisibilityInputs::GetCameraBias, &GCParticleVisibilityInputs::SetCameraBias)
        .addProperty("CPin", &GCParticleVisibilityInputs::GetCPin, &GCParticleVisibilityInputs::SetCPin)
        .addProperty("ProxyRadius", &GCParticleVisibilityInputs::GetProxyRadius, &GCParticleVisibilityInputs::SetProxyRadius)
        .addProperty("InputMin", &GCParticleVisibilityInputs::GetInputMin, &GCParticleVisibilityInputs::SetInputMin)
        .addProperty("InputMax", &GCParticleVisibilityInputs::GetInputMax, &GCParticleVisibilityInputs::SetInputMax)
        .addProperty("InputPixelVisFade", &GCParticleVisibilityInputs::GetInputPixelVisFade, &GCParticleVisibilityInputs::SetInputPixelVisFade)
        .addProperty("NoPixelVisibilityFallback", &GCParticleVisibilityInputs::GetNoPixelVisibilityFallback, &GCParticleVisibilityInputs::SetNoPixelVisibilityFallback)
        .addProperty("DistanceInputMin", &GCParticleVisibilityInputs::GetDistanceInputMin, &GCParticleVisibilityInputs::SetDistanceInputMin)
        .addProperty("DistanceInputMax", &GCParticleVisibilityInputs::GetDistanceInputMax, &GCParticleVisibilityInputs::SetDistanceInputMax)
        .addProperty("DotInputMin", &GCParticleVisibilityInputs::GetDotInputMin, &GCParticleVisibilityInputs::SetDotInputMin)
        .addProperty("DotInputMax", &GCParticleVisibilityInputs::GetDotInputMax, &GCParticleVisibilityInputs::SetDotInputMax)
        .addProperty("DotCPAngles", &GCParticleVisibilityInputs::GetDotCPAngles, &GCParticleVisibilityInputs::SetDotCPAngles)
        .addProperty("DotCameraAngles", &GCParticleVisibilityInputs::GetDotCameraAngles, &GCParticleVisibilityInputs::SetDotCameraAngles)
        .addProperty("AlphaScaleMin", &GCParticleVisibilityInputs::GetAlphaScaleMin, &GCParticleVisibilityInputs::SetAlphaScaleMin)
        .addProperty("AlphaScaleMax", &GCParticleVisibilityInputs::GetAlphaScaleMax, &GCParticleVisibilityInputs::SetAlphaScaleMax)
        .addProperty("RadiusScaleMin", &GCParticleVisibilityInputs::GetRadiusScaleMin, &GCParticleVisibilityInputs::SetRadiusScaleMin)
        .addProperty("RadiusScaleMax", &GCParticleVisibilityInputs::GetRadiusScaleMax, &GCParticleVisibilityInputs::SetRadiusScaleMax)
        .addProperty("RadiusScaleFOVBase", &GCParticleVisibilityInputs::GetRadiusScaleFOVBase, &GCParticleVisibilityInputs::SetRadiusScaleFOVBase)
        .addProperty("RightEye", &GCParticleVisibilityInputs::GetRightEye, &GCParticleVisibilityInputs::SetRightEye)
        .endClass();
}