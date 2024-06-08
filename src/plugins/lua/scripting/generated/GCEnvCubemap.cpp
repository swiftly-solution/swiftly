#include "../../../core/scripting/generated/classes/GCEnvCubemap.h"
#include "../core.h"

void SetupLuaClassGCEnvCubemap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCubemap>("CEnvCubemap")
        .addProperty("Entity_bCustomCubemapTexture", &GCEnvCubemap::GetEntity_bCustomCubemapTexture, &GCEnvCubemap::SetEntity_bCustomCubemapTexture)
        .addProperty("Entity_flInfluenceRadius", &GCEnvCubemap::GetEntity_flInfluenceRadius, &GCEnvCubemap::SetEntity_flInfluenceRadius)
        .addProperty("Entity_vBoxProjectMins", &GCEnvCubemap::GetEntity_vBoxProjectMins, &GCEnvCubemap::SetEntity_vBoxProjectMins)
        .addProperty("Entity_vBoxProjectMaxs", &GCEnvCubemap::GetEntity_vBoxProjectMaxs, &GCEnvCubemap::SetEntity_vBoxProjectMaxs)
        .addProperty("Entity_bMoveable", &GCEnvCubemap::GetEntity_bMoveable, &GCEnvCubemap::SetEntity_bMoveable)
        .addProperty("Entity_nHandshake", &GCEnvCubemap::GetEntity_nHandshake, &GCEnvCubemap::SetEntity_nHandshake)
        .addProperty("Entity_nEnvCubeMapArrayIndex", &GCEnvCubemap::GetEntity_nEnvCubeMapArrayIndex, &GCEnvCubemap::SetEntity_nEnvCubeMapArrayIndex)
        .addProperty("Entity_nPriority", &GCEnvCubemap::GetEntity_nPriority, &GCEnvCubemap::SetEntity_nPriority)
        .addProperty("Entity_flEdgeFadeDist", &GCEnvCubemap::GetEntity_flEdgeFadeDist, &GCEnvCubemap::SetEntity_flEdgeFadeDist)
        .addProperty("Entity_vEdgeFadeDists", &GCEnvCubemap::GetEntity_vEdgeFadeDists, &GCEnvCubemap::SetEntity_vEdgeFadeDists)
        .addProperty("Entity_flDiffuseScale", &GCEnvCubemap::GetEntity_flDiffuseScale, &GCEnvCubemap::SetEntity_flDiffuseScale)
        .addProperty("Entity_bStartDisabled", &GCEnvCubemap::GetEntity_bStartDisabled, &GCEnvCubemap::SetEntity_bStartDisabled)
        .addProperty("Entity_bDefaultEnvMap", &GCEnvCubemap::GetEntity_bDefaultEnvMap, &GCEnvCubemap::SetEntity_bDefaultEnvMap)
        .addProperty("Entity_bDefaultSpecEnvMap", &GCEnvCubemap::GetEntity_bDefaultSpecEnvMap, &GCEnvCubemap::SetEntity_bDefaultSpecEnvMap)
        .addProperty("Entity_bIndoorCubeMap", &GCEnvCubemap::GetEntity_bIndoorCubeMap, &GCEnvCubemap::SetEntity_bIndoorCubeMap)
        .addProperty("Entity_bCopyDiffuseFromDefaultCubemap", &GCEnvCubemap::GetEntity_bCopyDiffuseFromDefaultCubemap, &GCEnvCubemap::SetEntity_bCopyDiffuseFromDefaultCubemap)
        .addProperty("Entity_bEnabled", &GCEnvCubemap::GetEntity_bEnabled, &GCEnvCubemap::SetEntity_bEnabled)
        .endClass();
}