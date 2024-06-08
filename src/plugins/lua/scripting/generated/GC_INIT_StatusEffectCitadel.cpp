#include "../../../core/scripting/generated/classes/GC_INIT_StatusEffectCitadel.h"
#include "../core.h"

void SetupLuaClassGC_INIT_StatusEffectCitadel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_StatusEffectCitadel>("C_INIT_StatusEffectCitadel")
        .addProperty("SFXColorWarpAmount", &GC_INIT_StatusEffectCitadel::GetSFXColorWarpAmount, &GC_INIT_StatusEffectCitadel::SetSFXColorWarpAmount)
        .addProperty("SFXNormalAmount", &GC_INIT_StatusEffectCitadel::GetSFXNormalAmount, &GC_INIT_StatusEffectCitadel::SetSFXNormalAmount)
        .addProperty("SFXMetalnessAmount", &GC_INIT_StatusEffectCitadel::GetSFXMetalnessAmount, &GC_INIT_StatusEffectCitadel::SetSFXMetalnessAmount)
        .addProperty("SFXRoughnessAmount", &GC_INIT_StatusEffectCitadel::GetSFXRoughnessAmount, &GC_INIT_StatusEffectCitadel::SetSFXRoughnessAmount)
        .addProperty("SFXSelfIllumAmount", &GC_INIT_StatusEffectCitadel::GetSFXSelfIllumAmount, &GC_INIT_StatusEffectCitadel::SetSFXSelfIllumAmount)
        .addProperty("SFXSScale", &GC_INIT_StatusEffectCitadel::GetSFXSScale, &GC_INIT_StatusEffectCitadel::SetSFXSScale)
        .addProperty("SFXSScrollX", &GC_INIT_StatusEffectCitadel::GetSFXSScrollX, &GC_INIT_StatusEffectCitadel::SetSFXSScrollX)
        .addProperty("SFXSScrollY", &GC_INIT_StatusEffectCitadel::GetSFXSScrollY, &GC_INIT_StatusEffectCitadel::SetSFXSScrollY)
        .addProperty("SFXSScrollZ", &GC_INIT_StatusEffectCitadel::GetSFXSScrollZ, &GC_INIT_StatusEffectCitadel::SetSFXSScrollZ)
        .addProperty("SFXSOffsetX", &GC_INIT_StatusEffectCitadel::GetSFXSOffsetX, &GC_INIT_StatusEffectCitadel::SetSFXSOffsetX)
        .addProperty("SFXSOffsetY", &GC_INIT_StatusEffectCitadel::GetSFXSOffsetY, &GC_INIT_StatusEffectCitadel::SetSFXSOffsetY)
        .addProperty("SFXSOffsetZ", &GC_INIT_StatusEffectCitadel::GetSFXSOffsetZ, &GC_INIT_StatusEffectCitadel::SetSFXSOffsetZ)
        .addProperty("DetailCombo", &GC_INIT_StatusEffectCitadel::GetDetailCombo, &GC_INIT_StatusEffectCitadel::SetDetailCombo)
        .addProperty("SFXSDetailAmount", &GC_INIT_StatusEffectCitadel::GetSFXSDetailAmount, &GC_INIT_StatusEffectCitadel::SetSFXSDetailAmount)
        .addProperty("SFXSDetailScale", &GC_INIT_StatusEffectCitadel::GetSFXSDetailScale, &GC_INIT_StatusEffectCitadel::SetSFXSDetailScale)
        .addProperty("SFXSDetailScrollX", &GC_INIT_StatusEffectCitadel::GetSFXSDetailScrollX, &GC_INIT_StatusEffectCitadel::SetSFXSDetailScrollX)
        .addProperty("SFXSDetailScrollY", &GC_INIT_StatusEffectCitadel::GetSFXSDetailScrollY, &GC_INIT_StatusEffectCitadel::SetSFXSDetailScrollY)
        .addProperty("SFXSDetailScrollZ", &GC_INIT_StatusEffectCitadel::GetSFXSDetailScrollZ, &GC_INIT_StatusEffectCitadel::SetSFXSDetailScrollZ)
        .addProperty("SFXSUseModelUVs", &GC_INIT_StatusEffectCitadel::GetSFXSUseModelUVs, &GC_INIT_StatusEffectCitadel::SetSFXSUseModelUVs)
        .endClass();
}