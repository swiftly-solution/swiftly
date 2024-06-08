#include "../../../core/scripting/generated/classes/GCEnvVolumetricFogVolume.h"
#include "../core.h"

void SetupLuaClassGCEnvVolumetricFogVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvVolumetricFogVolume>("CEnvVolumetricFogVolume")
        .addProperty("Active", &GCEnvVolumetricFogVolume::GetActive, &GCEnvVolumetricFogVolume::SetActive)
        .addProperty("BoxMins", &GCEnvVolumetricFogVolume::GetBoxMins, &GCEnvVolumetricFogVolume::SetBoxMins)
        .addProperty("BoxMaxs", &GCEnvVolumetricFogVolume::GetBoxMaxs, &GCEnvVolumetricFogVolume::SetBoxMaxs)
        .addProperty("StartDisabled", &GCEnvVolumetricFogVolume::GetStartDisabled, &GCEnvVolumetricFogVolume::SetStartDisabled)
        .addProperty("Strength", &GCEnvVolumetricFogVolume::GetStrength, &GCEnvVolumetricFogVolume::SetStrength)
        .addProperty("FalloffShape", &GCEnvVolumetricFogVolume::GetFalloffShape, &GCEnvVolumetricFogVolume::SetFalloffShape)
        .addProperty("FalloffExponent", &GCEnvVolumetricFogVolume::GetFalloffExponent, &GCEnvVolumetricFogVolume::SetFalloffExponent)
        .addProperty("HeightFogDepth", &GCEnvVolumetricFogVolume::GetHeightFogDepth, &GCEnvVolumetricFogVolume::SetHeightFogDepth)
        .addProperty("HeightFogEdgeWidth", &GCEnvVolumetricFogVolume::GetHeightFogEdgeWidth, &GCEnvVolumetricFogVolume::SetHeightFogEdgeWidth)
        .addProperty("IndirectLightStrength", &GCEnvVolumetricFogVolume::GetIndirectLightStrength, &GCEnvVolumetricFogVolume::SetIndirectLightStrength)
        .addProperty("SunLightStrength", &GCEnvVolumetricFogVolume::GetSunLightStrength, &GCEnvVolumetricFogVolume::SetSunLightStrength)
        .addProperty("NoiseStrength", &GCEnvVolumetricFogVolume::GetNoiseStrength, &GCEnvVolumetricFogVolume::SetNoiseStrength)
        .addProperty("OverrideIndirectLightStrength", &GCEnvVolumetricFogVolume::GetOverrideIndirectLightStrength, &GCEnvVolumetricFogVolume::SetOverrideIndirectLightStrength)
        .addProperty("OverrideSunLightStrength", &GCEnvVolumetricFogVolume::GetOverrideSunLightStrength, &GCEnvVolumetricFogVolume::SetOverrideSunLightStrength)
        .addProperty("OverrideNoiseStrength", &GCEnvVolumetricFogVolume::GetOverrideNoiseStrength, &GCEnvVolumetricFogVolume::SetOverrideNoiseStrength)
        .endClass();
}