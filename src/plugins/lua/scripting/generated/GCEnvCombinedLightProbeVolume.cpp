#include "../../../core/scripting/generated/classes/GCEnvCombinedLightProbeVolume.h"
#include "../core.h"

void SetupLuaClassGCEnvCombinedLightProbeVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCombinedLightProbeVolume>("CEnvCombinedLightProbeVolume")
        .addProperty("Entity_Color", &GCEnvCombinedLightProbeVolume::GetEntity_Color, &GCEnvCombinedLightProbeVolume::SetEntity_Color)
        .addProperty("Entity_flBrightness", &GCEnvCombinedLightProbeVolume::GetEntity_flBrightness, &GCEnvCombinedLightProbeVolume::SetEntity_flBrightness)
        .addProperty("Entity_bCustomCubemapTexture", &GCEnvCombinedLightProbeVolume::GetEntity_bCustomCubemapTexture, &GCEnvCombinedLightProbeVolume::SetEntity_bCustomCubemapTexture)
        .addProperty("Entity_vBoxMins", &GCEnvCombinedLightProbeVolume::GetEntity_vBoxMins, &GCEnvCombinedLightProbeVolume::SetEntity_vBoxMins)
        .addProperty("Entity_vBoxMaxs", &GCEnvCombinedLightProbeVolume::GetEntity_vBoxMaxs, &GCEnvCombinedLightProbeVolume::SetEntity_vBoxMaxs)
        .addProperty("Entity_bMoveable", &GCEnvCombinedLightProbeVolume::GetEntity_bMoveable, &GCEnvCombinedLightProbeVolume::SetEntity_bMoveable)
        .addProperty("Entity_nHandshake", &GCEnvCombinedLightProbeVolume::GetEntity_nHandshake, &GCEnvCombinedLightProbeVolume::SetEntity_nHandshake)
        .addProperty("Entity_nEnvCubeMapArrayIndex", &GCEnvCombinedLightProbeVolume::GetEntity_nEnvCubeMapArrayIndex, &GCEnvCombinedLightProbeVolume::SetEntity_nEnvCubeMapArrayIndex)
        .addProperty("Entity_nPriority", &GCEnvCombinedLightProbeVolume::GetEntity_nPriority, &GCEnvCombinedLightProbeVolume::SetEntity_nPriority)
        .addProperty("Entity_bStartDisabled", &GCEnvCombinedLightProbeVolume::GetEntity_bStartDisabled, &GCEnvCombinedLightProbeVolume::SetEntity_bStartDisabled)
        .addProperty("Entity_flEdgeFadeDist", &GCEnvCombinedLightProbeVolume::GetEntity_flEdgeFadeDist, &GCEnvCombinedLightProbeVolume::SetEntity_flEdgeFadeDist)
        .addProperty("Entity_vEdgeFadeDists", &GCEnvCombinedLightProbeVolume::GetEntity_vEdgeFadeDists, &GCEnvCombinedLightProbeVolume::SetEntity_vEdgeFadeDists)
        .addProperty("Entity_nLightProbeSizeX", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeX, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeX)
        .addProperty("Entity_nLightProbeSizeY", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeY, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeY)
        .addProperty("Entity_nLightProbeSizeZ", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeZ, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeZ)
        .addProperty("Entity_nLightProbeAtlasX", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasX, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasX)
        .addProperty("Entity_nLightProbeAtlasY", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasY, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasY)
        .addProperty("Entity_nLightProbeAtlasZ", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasZ, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasZ)
        .addProperty("Entity_bEnabled", &GCEnvCombinedLightProbeVolume::GetEntity_bEnabled, &GCEnvCombinedLightProbeVolume::SetEntity_bEnabled)
        .endClass();
}