#include "../../../core/scripting/generated/classes/GC_INIT_ColorLitPerParticle.h"
#include "../core.h"

void SetupLuaClassGC_INIT_ColorLitPerParticle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_ColorLitPerParticle>("C_INIT_ColorLitPerParticle")
        .addProperty("ColorMin", &GC_INIT_ColorLitPerParticle::GetColorMin, &GC_INIT_ColorLitPerParticle::SetColorMin)
        .addProperty("ColorMax", &GC_INIT_ColorLitPerParticle::GetColorMax, &GC_INIT_ColorLitPerParticle::SetColorMax)
        .addProperty("TintMin", &GC_INIT_ColorLitPerParticle::GetTintMin, &GC_INIT_ColorLitPerParticle::SetTintMin)
        .addProperty("TintMax", &GC_INIT_ColorLitPerParticle::GetTintMax, &GC_INIT_ColorLitPerParticle::SetTintMax)
        .addProperty("TintPerc", &GC_INIT_ColorLitPerParticle::GetTintPerc, &GC_INIT_ColorLitPerParticle::SetTintPerc)
        .addProperty("TintBlendMode", &GC_INIT_ColorLitPerParticle::GetTintBlendMode, &GC_INIT_ColorLitPerParticle::SetTintBlendMode)
        .addProperty("LightAmplification", &GC_INIT_ColorLitPerParticle::GetLightAmplification, &GC_INIT_ColorLitPerParticle::SetLightAmplification)
        .endClass();
}