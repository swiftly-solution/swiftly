#include "../../../core/scripting/generated/classes/GCEnvLightProbeVolume.h"
#include "../core.h"

void SetupLuaClassGCEnvLightProbeVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvLightProbeVolume>("CEnvLightProbeVolume")
        .addProperty("Entity_vBoxMins", &GCEnvLightProbeVolume::GetEntity_vBoxMins, &GCEnvLightProbeVolume::SetEntity_vBoxMins)
        .addProperty("Entity_vBoxMaxs", &GCEnvLightProbeVolume::GetEntity_vBoxMaxs, &GCEnvLightProbeVolume::SetEntity_vBoxMaxs)
        .addProperty("Entity_bMoveable", &GCEnvLightProbeVolume::GetEntity_bMoveable, &GCEnvLightProbeVolume::SetEntity_bMoveable)
        .addProperty("Entity_nHandshake", &GCEnvLightProbeVolume::GetEntity_nHandshake, &GCEnvLightProbeVolume::SetEntity_nHandshake)
        .addProperty("Entity_nPriority", &GCEnvLightProbeVolume::GetEntity_nPriority, &GCEnvLightProbeVolume::SetEntity_nPriority)
        .addProperty("Entity_bStartDisabled", &GCEnvLightProbeVolume::GetEntity_bStartDisabled, &GCEnvLightProbeVolume::SetEntity_bStartDisabled)
        .addProperty("Entity_nLightProbeSizeX", &GCEnvLightProbeVolume::GetEntity_nLightProbeSizeX, &GCEnvLightProbeVolume::SetEntity_nLightProbeSizeX)
        .addProperty("Entity_nLightProbeSizeY", &GCEnvLightProbeVolume::GetEntity_nLightProbeSizeY, &GCEnvLightProbeVolume::SetEntity_nLightProbeSizeY)
        .addProperty("Entity_nLightProbeSizeZ", &GCEnvLightProbeVolume::GetEntity_nLightProbeSizeZ, &GCEnvLightProbeVolume::SetEntity_nLightProbeSizeZ)
        .addProperty("Entity_nLightProbeAtlasX", &GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasX, &GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasX)
        .addProperty("Entity_nLightProbeAtlasY", &GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasY, &GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasY)
        .addProperty("Entity_nLightProbeAtlasZ", &GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasZ, &GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasZ)
        .addProperty("Entity_bEnabled", &GCEnvLightProbeVolume::GetEntity_bEnabled, &GCEnvLightProbeVolume::SetEntity_bEnabled)
        .endClass();
}