#include "../../../core/scripting/generated/classes/GCVoxelVisibility.h"
#include "../core.h"

void SetupLuaClassGCVoxelVisibility(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoxelVisibility>("CVoxelVisibility")
        .addProperty("BaseClusterCount", &GCVoxelVisibility::GetBaseClusterCount, &GCVoxelVisibility::SetBaseClusterCount)
        .addProperty("PVSBytesPerCluster", &GCVoxelVisibility::GetPVSBytesPerCluster, &GCVoxelVisibility::SetPVSBytesPerCluster)
        .addProperty("MinBounds", &GCVoxelVisibility::GetMinBounds, &GCVoxelVisibility::SetMinBounds)
        .addProperty("MaxBounds", &GCVoxelVisibility::GetMaxBounds, &GCVoxelVisibility::SetMaxBounds)
        .addProperty("GridSize", &GCVoxelVisibility::GetGridSize, &GCVoxelVisibility::SetGridSize)
        .addProperty("SkyVisibilityCluster", &GCVoxelVisibility::GetSkyVisibilityCluster, &GCVoxelVisibility::SetSkyVisibilityCluster)
        .addProperty("SunVisibilityCluster", &GCVoxelVisibility::GetSunVisibilityCluster, &GCVoxelVisibility::SetSunVisibilityCluster)
        .addProperty("NodeBlock", &GCVoxelVisibility::GetNodeBlock, &GCVoxelVisibility::SetNodeBlock)
        .addProperty("RegionBlock", &GCVoxelVisibility::GetRegionBlock, &GCVoxelVisibility::SetRegionBlock)
        .addProperty("EnclosedClusterListBlock", &GCVoxelVisibility::GetEnclosedClusterListBlock, &GCVoxelVisibility::SetEnclosedClusterListBlock)
        .addProperty("EnclosedClustersBlock", &GCVoxelVisibility::GetEnclosedClustersBlock, &GCVoxelVisibility::SetEnclosedClustersBlock)
        .addProperty("MasksBlock", &GCVoxelVisibility::GetMasksBlock, &GCVoxelVisibility::SetMasksBlock)
        .addProperty("VisBlocks", &GCVoxelVisibility::GetVisBlocks, &GCVoxelVisibility::SetVisBlocks)
        .endClass();
}