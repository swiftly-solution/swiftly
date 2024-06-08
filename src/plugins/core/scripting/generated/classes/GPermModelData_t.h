class GPermModelData_t;

#ifndef _gcpermmodeldata_t_h
#define _gcpermmodeldata_t_h

#include "../../../scripting.h"


#include "GPermModelInfo_t.h"
#include "GPermModelExtPart_t.h"
#include "GMaterialGroup_t.h"
#include "GModelSkeletonData_t.h"
#include "GModelBoneFlexDriver_t.h"
#include "GCModelConfig.h"
#include "GCModelConfigList.h"
#include "GPermModelDataAnimatedMaterialAttribute_t.h"

class GPermModelData_t
{
private:
    void *m_ptr;

public:
    GPermModelData_t() {}
    GPermModelData_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "PermModelData_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "PermModelData_t", "m_name", true, value); }
    GPermModelInfo_t GetModelInfo() const { return GetSchemaValue<GPermModelInfo_t>(m_ptr, "PermModelData_t", "m_modelInfo"); }
    void SetModelInfo(GPermModelInfo_t value) { SetSchemaValue(m_ptr, "PermModelData_t", "m_modelInfo", true, value); }
    std::vector<GPermModelExtPart_t> GetExtParts() const { CUtlVector<GPermModelExtPart_t>* vec = GetSchemaValue<CUtlVector<GPermModelExtPart_t>*>(m_ptr, "PermModelData_t", "m_ExtParts"); std::vector<GPermModelExtPart_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetExtParts(std::vector<GPermModelExtPart_t> value) { SetSchemaValueCUtlVector<GPermModelExtPart_t>(m_ptr, "PermModelData_t", "m_ExtParts", true, value); }
    std::vector<uint64> GetRefMeshGroupMasks() const { CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "PermModelData_t", "m_refMeshGroupMasks"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRefMeshGroupMasks(std::vector<uint64> value) { SetSchemaValueCUtlVector<uint64>(m_ptr, "PermModelData_t", "m_refMeshGroupMasks", true, value); }
    std::vector<uint64> GetRefPhysGroupMasks() const { CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "PermModelData_t", "m_refPhysGroupMasks"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRefPhysGroupMasks(std::vector<uint64> value) { SetSchemaValueCUtlVector<uint64>(m_ptr, "PermModelData_t", "m_refPhysGroupMasks", true, value); }
    std::vector<uint8> GetRefLODGroupMasks() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PermModelData_t", "m_refLODGroupMasks"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRefLODGroupMasks(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "PermModelData_t", "m_refLODGroupMasks", true, value); }
    std::vector<float32> GetLodGroupSwitchDistances() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PermModelData_t", "m_lodGroupSwitchDistances"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLodGroupSwitchDistances(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "PermModelData_t", "m_lodGroupSwitchDistances", true, value); }
    std::vector<CUtlString> GetMeshGroups() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PermModelData_t", "m_meshGroups"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMeshGroups(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PermModelData_t", "m_meshGroups", true, value); }
    std::vector<GMaterialGroup_t> GetMaterialGroups() const { CUtlVector<GMaterialGroup_t>* vec = GetSchemaValue<CUtlVector<GMaterialGroup_t>*>(m_ptr, "PermModelData_t", "m_materialGroups"); std::vector<GMaterialGroup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterialGroups(std::vector<GMaterialGroup_t> value) { SetSchemaValueCUtlVector<GMaterialGroup_t>(m_ptr, "PermModelData_t", "m_materialGroups", true, value); }
    uint64_t GetDefaultMeshGroupMask() const { return GetSchemaValue<uint64_t>(m_ptr, "PermModelData_t", "m_nDefaultMeshGroupMask"); }
    void SetDefaultMeshGroupMask(uint64_t value) { SetSchemaValue(m_ptr, "PermModelData_t", "m_nDefaultMeshGroupMask", true, value); }
    GModelSkeletonData_t GetModelSkeleton() const { return GetSchemaValue<GModelSkeletonData_t>(m_ptr, "PermModelData_t", "m_modelSkeleton"); }
    void SetModelSkeleton(GModelSkeletonData_t value) { SetSchemaValue(m_ptr, "PermModelData_t", "m_modelSkeleton", true, value); }
    std::vector<int16> GetRemappingTable() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "PermModelData_t", "m_remappingTable"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRemappingTable(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "PermModelData_t", "m_remappingTable", true, value); }
    std::vector<uint16> GetRemappingTableStarts() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PermModelData_t", "m_remappingTableStarts"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRemappingTableStarts(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PermModelData_t", "m_remappingTableStarts", true, value); }
    std::vector<GModelBoneFlexDriver_t> GetBoneFlexDrivers() const { CUtlVector<GModelBoneFlexDriver_t>* vec = GetSchemaValue<CUtlVector<GModelBoneFlexDriver_t>*>(m_ptr, "PermModelData_t", "m_boneFlexDrivers"); std::vector<GModelBoneFlexDriver_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneFlexDrivers(std::vector<GModelBoneFlexDriver_t> value) { SetSchemaValueCUtlVector<GModelBoneFlexDriver_t>(m_ptr, "PermModelData_t", "m_boneFlexDrivers", true, value); }
    GCModelConfigList* GetModelConfigList() const { return GetSchemaValue<GCModelConfigList*>(m_ptr, "PermModelData_t", "m_pModelConfigList"); }
    void SetModelConfigList(GCModelConfigList* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ModelConfigList' is not possible.\n"); }
    std::vector<CUtlString> GetBodyGroupsHiddenInTools() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PermModelData_t", "m_BodyGroupsHiddenInTools"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBodyGroupsHiddenInTools(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PermModelData_t", "m_BodyGroupsHiddenInTools", true, value); }
    std::vector<GPermModelDataAnimatedMaterialAttribute_t> GetAnimatedMaterialAttributes() const { CUtlVector<GPermModelDataAnimatedMaterialAttribute_t>* vec = GetSchemaValue<CUtlVector<GPermModelDataAnimatedMaterialAttribute_t>*>(m_ptr, "PermModelData_t", "m_AnimatedMaterialAttributes"); std::vector<GPermModelDataAnimatedMaterialAttribute_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAnimatedMaterialAttributes(std::vector<GPermModelDataAnimatedMaterialAttribute_t> value) { SetSchemaValueCUtlVector<GPermModelDataAnimatedMaterialAttribute_t>(m_ptr, "PermModelData_t", "m_AnimatedMaterialAttributes", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif