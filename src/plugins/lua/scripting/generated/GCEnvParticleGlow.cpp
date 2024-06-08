#include "../../../core/scripting/generated/classes/GCEnvParticleGlow.h"
#include "../core.h"

void SetupLuaClassGCEnvParticleGlow(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvParticleGlow>("CEnvParticleGlow")
        .addProperty("AlphaScale", &GCEnvParticleGlow::GetAlphaScale, &GCEnvParticleGlow::SetAlphaScale)
        .addProperty("RadiusScale", &GCEnvParticleGlow::GetRadiusScale, &GCEnvParticleGlow::SetRadiusScale)
        .addProperty("SelfIllumScale", &GCEnvParticleGlow::GetSelfIllumScale, &GCEnvParticleGlow::SetSelfIllumScale)
        .addProperty("ColorTint", &GCEnvParticleGlow::GetColorTint, &GCEnvParticleGlow::SetColorTint)
        .endClass();
}