#include "../../../core/scripting/generated/classes/GCPointCamera.h"
#include "../core.h"

void SetupLuaClassGCPointCamera(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointCamera>("CPointCamera")
        .addProperty("FOV", &GCPointCamera::GetFOV, &GCPointCamera::SetFOV)
        .addProperty("Resolution", &GCPointCamera::GetResolution, &GCPointCamera::SetResolution)
        .addProperty("FogEnable", &GCPointCamera::GetFogEnable, &GCPointCamera::SetFogEnable)
        .addProperty("FogColor", &GCPointCamera::GetFogColor, &GCPointCamera::SetFogColor)
        .addProperty("FogStart", &GCPointCamera::GetFogStart, &GCPointCamera::SetFogStart)
        .addProperty("FogEnd", &GCPointCamera::GetFogEnd, &GCPointCamera::SetFogEnd)
        .addProperty("FogMaxDensity", &GCPointCamera::GetFogMaxDensity, &GCPointCamera::SetFogMaxDensity)
        .addProperty("Active", &GCPointCamera::GetActive, &GCPointCamera::SetActive)
        .addProperty("UseScreenAspectRatio", &GCPointCamera::GetUseScreenAspectRatio, &GCPointCamera::SetUseScreenAspectRatio)
        .addProperty("AspectRatio", &GCPointCamera::GetAspectRatio, &GCPointCamera::SetAspectRatio)
        .addProperty("NoSky", &GCPointCamera::GetNoSky, &GCPointCamera::SetNoSky)
        .addProperty("Brightness", &GCPointCamera::GetBrightness, &GCPointCamera::SetBrightness)
        .addProperty("ZFar", &GCPointCamera::GetZFar, &GCPointCamera::SetZFar)
        .addProperty("ZNear", &GCPointCamera::GetZNear, &GCPointCamera::SetZNear)
        .addProperty("CanHLTVUse", &GCPointCamera::GetCanHLTVUse, &GCPointCamera::SetCanHLTVUse)
        .addProperty("DofEnabled", &GCPointCamera::GetDofEnabled, &GCPointCamera::SetDofEnabled)
        .addProperty("DofNearBlurry", &GCPointCamera::GetDofNearBlurry, &GCPointCamera::SetDofNearBlurry)
        .addProperty("DofNearCrisp", &GCPointCamera::GetDofNearCrisp, &GCPointCamera::SetDofNearCrisp)
        .addProperty("DofFarCrisp", &GCPointCamera::GetDofFarCrisp, &GCPointCamera::SetDofFarCrisp)
        .addProperty("DofFarBlurry", &GCPointCamera::GetDofFarBlurry, &GCPointCamera::SetDofFarBlurry)
        .addProperty("DofTiltToGround", &GCPointCamera::GetDofTiltToGround, &GCPointCamera::SetDofTiltToGround)
        .addProperty("TargetFOV", &GCPointCamera::GetTargetFOV, &GCPointCamera::SetTargetFOV)
        .addProperty("DegreesPerSecond", &GCPointCamera::GetDegreesPerSecond, &GCPointCamera::SetDegreesPerSecond)
        .addProperty("IsOn", &GCPointCamera::GetIsOn, &GCPointCamera::SetIsOn)
        .addProperty("Next", &GCPointCamera::GetNext, &GCPointCamera::SetNext)
        .endClass();
}