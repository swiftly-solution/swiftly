#include "../../../core/scripting/generated/classes/GTextureControls_t.h"
#include "../core.h"

void SetupLuaClassGTextureControls_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTextureControls_t>("TextureControls_t")
        .addProperty("FinalTextureScaleU", &GTextureControls_t::GetFinalTextureScaleU, &GTextureControls_t::SetFinalTextureScaleU)
        .addProperty("FinalTextureScaleV", &GTextureControls_t::GetFinalTextureScaleV, &GTextureControls_t::SetFinalTextureScaleV)
        .addProperty("FinalTextureOffsetU", &GTextureControls_t::GetFinalTextureOffsetU, &GTextureControls_t::SetFinalTextureOffsetU)
        .addProperty("FinalTextureOffsetV", &GTextureControls_t::GetFinalTextureOffsetV, &GTextureControls_t::SetFinalTextureOffsetV)
        .addProperty("FinalTextureUVRotation", &GTextureControls_t::GetFinalTextureUVRotation, &GTextureControls_t::SetFinalTextureUVRotation)
        .addProperty("ZoomScale", &GTextureControls_t::GetZoomScale, &GTextureControls_t::SetZoomScale)
        .addProperty("Distortion", &GTextureControls_t::GetDistortion, &GTextureControls_t::SetDistortion)
        .addProperty("RandomizeOffsets", &GTextureControls_t::GetRandomizeOffsets, &GTextureControls_t::SetRandomizeOffsets)
        .addProperty("ClampUVs", &GTextureControls_t::GetClampUVs, &GTextureControls_t::SetClampUVs)
        .addProperty("PerParticleBlend", &GTextureControls_t::GetPerParticleBlend, &GTextureControls_t::SetPerParticleBlend)
        .addProperty("PerParticleScale", &GTextureControls_t::GetPerParticleScale, &GTextureControls_t::SetPerParticleScale)
        .addProperty("PerParticleOffsetU", &GTextureControls_t::GetPerParticleOffsetU, &GTextureControls_t::SetPerParticleOffsetU)
        .addProperty("PerParticleOffsetV", &GTextureControls_t::GetPerParticleOffsetV, &GTextureControls_t::SetPerParticleOffsetV)
        .addProperty("PerParticleRotation", &GTextureControls_t::GetPerParticleRotation, &GTextureControls_t::SetPerParticleRotation)
        .addProperty("PerParticleZoom", &GTextureControls_t::GetPerParticleZoom, &GTextureControls_t::SetPerParticleZoom)
        .addProperty("PerParticleDistortion", &GTextureControls_t::GetPerParticleDistortion, &GTextureControls_t::SetPerParticleDistortion)
        .endClass();
}