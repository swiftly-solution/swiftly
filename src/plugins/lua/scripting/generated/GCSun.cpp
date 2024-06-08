#include "../../../core/scripting/generated/classes/GCSun.h"
#include "../core.h"

void SetupLuaClassGCSun(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSun>("CSun")
        .addProperty("Direction", &GCSun::GetDirection, &GCSun::SetDirection)
        .addProperty("Overlay", &GCSun::GetOverlay, &GCSun::SetOverlay)
        .addProperty("EffectName", &GCSun::GetEffectName, &GCSun::SetEffectName)
        .addProperty("SSEffectName", &GCSun::GetSSEffectName, &GCSun::SetSSEffectName)
        .addProperty("On", &GCSun::GetOn, &GCSun::SetOn)
        .addProperty("BmaxColor", &GCSun::GetBmaxColor, &GCSun::SetBmaxColor)
        .addProperty("Size", &GCSun::GetSize, &GCSun::SetSize)
        .addProperty("Rotation", &GCSun::GetRotation, &GCSun::SetRotation)
        .addProperty("HazeScale", &GCSun::GetHazeScale, &GCSun::SetHazeScale)
        .addProperty("AlphaHaze", &GCSun::GetAlphaHaze, &GCSun::SetAlphaHaze)
        .addProperty("AlphaHdr", &GCSun::GetAlphaHdr, &GCSun::SetAlphaHdr)
        .addProperty("AlphaScale", &GCSun::GetAlphaScale, &GCSun::SetAlphaScale)
        .addProperty("HDRColorScale", &GCSun::GetHDRColorScale, &GCSun::SetHDRColorScale)
        .addProperty("FarZScale", &GCSun::GetFarZScale, &GCSun::SetFarZScale)
        .endClass();
}