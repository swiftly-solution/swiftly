#include "../../../core/scripting/generated/classes/GC_OP_RenderProjected.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderProjected(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderProjected>("C_OP_RenderProjected")
        .addProperty("ProjectCharacter", &GC_OP_RenderProjected::GetProjectCharacter, &GC_OP_RenderProjected::SetProjectCharacter)
        .addProperty("ProjectWorld", &GC_OP_RenderProjected::GetProjectWorld, &GC_OP_RenderProjected::SetProjectWorld)
        .addProperty("ProjectWater", &GC_OP_RenderProjected::GetProjectWater, &GC_OP_RenderProjected::SetProjectWater)
        .addProperty("FlipHorizontal", &GC_OP_RenderProjected::GetFlipHorizontal, &GC_OP_RenderProjected::SetFlipHorizontal)
        .addProperty("EnableProjectedDepthControls", &GC_OP_RenderProjected::GetEnableProjectedDepthControls, &GC_OP_RenderProjected::SetEnableProjectedDepthControls)
        .addProperty("MinProjectionDepth", &GC_OP_RenderProjected::GetMinProjectionDepth, &GC_OP_RenderProjected::SetMinProjectionDepth)
        .addProperty("MaxProjectionDepth", &GC_OP_RenderProjected::GetMaxProjectionDepth, &GC_OP_RenderProjected::SetMaxProjectionDepth)
        .addProperty("ProjectedMaterials", &GC_OP_RenderProjected::GetProjectedMaterials, &GC_OP_RenderProjected::SetProjectedMaterials)
        .addProperty("MaterialSelection", &GC_OP_RenderProjected::GetMaterialSelection, &GC_OP_RenderProjected::SetMaterialSelection)
        .addProperty("AnimationTimeScale", &GC_OP_RenderProjected::GetAnimationTimeScale, &GC_OP_RenderProjected::SetAnimationTimeScale)
        .addProperty("OrientToNormal", &GC_OP_RenderProjected::GetOrientToNormal, &GC_OP_RenderProjected::SetOrientToNormal)
        .addProperty("MaterialVars", &GC_OP_RenderProjected::GetMaterialVars, &GC_OP_RenderProjected::SetMaterialVars)
        .addProperty("RadiusScale", &GC_OP_RenderProjected::GetRadiusScale, &GC_OP_RenderProjected::SetRadiusScale)
        .addProperty("AlphaScale", &GC_OP_RenderProjected::GetAlphaScale, &GC_OP_RenderProjected::SetAlphaScale)
        .addProperty("RollScale", &GC_OP_RenderProjected::GetRollScale, &GC_OP_RenderProjected::SetRollScale)
        .addProperty("Alpha2Field", &GC_OP_RenderProjected::GetAlpha2Field, &GC_OP_RenderProjected::SetAlpha2Field)
        .addProperty("ColorBlendType", &GC_OP_RenderProjected::GetColorBlendType, &GC_OP_RenderProjected::SetColorBlendType)
        .endClass();
}