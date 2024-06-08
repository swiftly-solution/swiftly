#include "../../../core/scripting/generated/classes/GPermModelData_t.h"
#include "../core.h"

void SetupLuaClassGPermModelData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelData_t>("PermModelData_t")
        .addProperty("Name", &GPermModelData_t::GetName, &GPermModelData_t::SetName)
        .addProperty("ModelInfo", &GPermModelData_t::GetModelInfo, &GPermModelData_t::SetModelInfo)
        .addProperty("ExtParts", &GPermModelData_t::GetExtParts, &GPermModelData_t::SetExtParts)
        .addProperty("RefMeshGroupMasks", &GPermModelData_t::GetRefMeshGroupMasks, &GPermModelData_t::SetRefMeshGroupMasks)
        .addProperty("RefPhysGroupMasks", &GPermModelData_t::GetRefPhysGroupMasks, &GPermModelData_t::SetRefPhysGroupMasks)
        .addProperty("RefLODGroupMasks", &GPermModelData_t::GetRefLODGroupMasks, &GPermModelData_t::SetRefLODGroupMasks)
        .addProperty("LodGroupSwitchDistances", &GPermModelData_t::GetLodGroupSwitchDistances, &GPermModelData_t::SetLodGroupSwitchDistances)
        .addProperty("MeshGroups", &GPermModelData_t::GetMeshGroups, &GPermModelData_t::SetMeshGroups)
        .addProperty("MaterialGroups", &GPermModelData_t::GetMaterialGroups, &GPermModelData_t::SetMaterialGroups)
        .addProperty("DefaultMeshGroupMask", &GPermModelData_t::GetDefaultMeshGroupMask, &GPermModelData_t::SetDefaultMeshGroupMask)
        .addProperty("ModelSkeleton", &GPermModelData_t::GetModelSkeleton, &GPermModelData_t::SetModelSkeleton)
        .addProperty("RemappingTable", &GPermModelData_t::GetRemappingTable, &GPermModelData_t::SetRemappingTable)
        .addProperty("RemappingTableStarts", &GPermModelData_t::GetRemappingTableStarts, &GPermModelData_t::SetRemappingTableStarts)
        .addProperty("BoneFlexDrivers", &GPermModelData_t::GetBoneFlexDrivers, &GPermModelData_t::SetBoneFlexDrivers)
        .addProperty("ModelConfigList", &GPermModelData_t::GetModelConfigList, &GPermModelData_t::SetModelConfigList)
        .addProperty("BodyGroupsHiddenInTools", &GPermModelData_t::GetBodyGroupsHiddenInTools, &GPermModelData_t::SetBodyGroupsHiddenInTools)
        .addProperty("AnimatedMaterialAttributes", &GPermModelData_t::GetAnimatedMaterialAttributes, &GPermModelData_t::SetAnimatedMaterialAttributes)
        .endClass();
}