#include "../../../core/scripting/generated/classes/GC_OP_RenderTrails.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderTrails(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderTrails>("C_OP_RenderTrails")
        .addProperty("EnableFadingAndClamping", &GC_OP_RenderTrails::GetEnableFadingAndClamping, &GC_OP_RenderTrails::SetEnableFadingAndClamping)
        .addProperty("StartFadeDot", &GC_OP_RenderTrails::GetStartFadeDot, &GC_OP_RenderTrails::SetStartFadeDot)
        .addProperty("EndFadeDot", &GC_OP_RenderTrails::GetEndFadeDot, &GC_OP_RenderTrails::SetEndFadeDot)
        .addProperty("PrevPntSource", &GC_OP_RenderTrails::GetPrevPntSource, &GC_OP_RenderTrails::SetPrevPntSource)
        .addProperty("MaxLength", &GC_OP_RenderTrails::GetMaxLength, &GC_OP_RenderTrails::SetMaxLength)
        .addProperty("MinLength", &GC_OP_RenderTrails::GetMinLength, &GC_OP_RenderTrails::SetMinLength)
        .addProperty("IgnoreDT", &GC_OP_RenderTrails::GetIgnoreDT, &GC_OP_RenderTrails::SetIgnoreDT)
        .addProperty("ConstrainRadiusToLengthRatio", &GC_OP_RenderTrails::GetConstrainRadiusToLengthRatio, &GC_OP_RenderTrails::SetConstrainRadiusToLengthRatio)
        .addProperty("LengthScale", &GC_OP_RenderTrails::GetLengthScale, &GC_OP_RenderTrails::SetLengthScale)
        .addProperty("LengthFadeInTime", &GC_OP_RenderTrails::GetLengthFadeInTime, &GC_OP_RenderTrails::SetLengthFadeInTime)
        .addProperty("RadiusHeadTaper", &GC_OP_RenderTrails::GetRadiusHeadTaper, &GC_OP_RenderTrails::SetRadiusHeadTaper)
        .addProperty("HeadAlphaScale", &GC_OP_RenderTrails::GetHeadAlphaScale, &GC_OP_RenderTrails::SetHeadAlphaScale)
        .addProperty("RadiusTaper", &GC_OP_RenderTrails::GetRadiusTaper, &GC_OP_RenderTrails::SetRadiusTaper)
        .addProperty("TailAlphaScale", &GC_OP_RenderTrails::GetTailAlphaScale, &GC_OP_RenderTrails::SetTailAlphaScale)
        .addProperty("HorizCropField", &GC_OP_RenderTrails::GetHorizCropField, &GC_OP_RenderTrails::SetHorizCropField)
        .addProperty("VertCropField", &GC_OP_RenderTrails::GetVertCropField, &GC_OP_RenderTrails::SetVertCropField)
        .addProperty("ForwardShift", &GC_OP_RenderTrails::GetForwardShift, &GC_OP_RenderTrails::SetForwardShift)
        .addProperty("FlipUVBasedOnPitchYaw", &GC_OP_RenderTrails::GetFlipUVBasedOnPitchYaw, &GC_OP_RenderTrails::SetFlipUVBasedOnPitchYaw)
        .endClass();
}