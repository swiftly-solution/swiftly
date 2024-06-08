#include "../../../core/scripting/generated/classes/GC_OP_RenderCables.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderCables(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderCables>("C_OP_RenderCables")
        .addProperty("RadiusScale", &GC_OP_RenderCables::GetRadiusScale, &GC_OP_RenderCables::SetRadiusScale)
        .addProperty("AlphaScale", &GC_OP_RenderCables::GetAlphaScale, &GC_OP_RenderCables::SetAlphaScale)
        .addProperty("ColorBlendType", &GC_OP_RenderCables::GetColorBlendType, &GC_OP_RenderCables::SetColorBlendType)
        .addProperty("TextureRepetitionMode", &GC_OP_RenderCables::GetTextureRepetitionMode, &GC_OP_RenderCables::SetTextureRepetitionMode)
        .addProperty("TextureRepeatsPerSegment", &GC_OP_RenderCables::GetTextureRepeatsPerSegment, &GC_OP_RenderCables::SetTextureRepeatsPerSegment)
        .addProperty("TextureRepeatsCircumference", &GC_OP_RenderCables::GetTextureRepeatsCircumference, &GC_OP_RenderCables::SetTextureRepeatsCircumference)
        .addProperty("ColorMapOffsetV", &GC_OP_RenderCables::GetColorMapOffsetV, &GC_OP_RenderCables::SetColorMapOffsetV)
        .addProperty("ColorMapOffsetU", &GC_OP_RenderCables::GetColorMapOffsetU, &GC_OP_RenderCables::SetColorMapOffsetU)
        .addProperty("NormalMapOffsetV", &GC_OP_RenderCables::GetNormalMapOffsetV, &GC_OP_RenderCables::SetNormalMapOffsetV)
        .addProperty("NormalMapOffsetU", &GC_OP_RenderCables::GetNormalMapOffsetU, &GC_OP_RenderCables::SetNormalMapOffsetU)
        .addProperty("DrawCableCaps", &GC_OP_RenderCables::GetDrawCableCaps, &GC_OP_RenderCables::SetDrawCableCaps)
        .addProperty("CapRoundness", &GC_OP_RenderCables::GetCapRoundness, &GC_OP_RenderCables::SetCapRoundness)
        .addProperty("CapOffsetAmount", &GC_OP_RenderCables::GetCapOffsetAmount, &GC_OP_RenderCables::SetCapOffsetAmount)
        .addProperty("TessScale", &GC_OP_RenderCables::GetTessScale, &GC_OP_RenderCables::SetTessScale)
        .addProperty("MinTesselation", &GC_OP_RenderCables::GetMinTesselation, &GC_OP_RenderCables::SetMinTesselation)
        .addProperty("MaxTesselation", &GC_OP_RenderCables::GetMaxTesselation, &GC_OP_RenderCables::SetMaxTesselation)
        .addProperty("Roundness", &GC_OP_RenderCables::GetRoundness, &GC_OP_RenderCables::SetRoundness)
        .addProperty("LightingTransform", &GC_OP_RenderCables::GetLightingTransform, &GC_OP_RenderCables::SetLightingTransform)
        .addProperty("MaterialVecVars", &GC_OP_RenderCables::GetMaterialVecVars, &GC_OP_RenderCables::SetMaterialVecVars)
        .endClass();
}