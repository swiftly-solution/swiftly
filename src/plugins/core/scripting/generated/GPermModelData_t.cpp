#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPermModelData_t::GPermModelData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPermModelData_t::GPermModelData_t(void *ptr) {
    m_ptr = ptr;
}
std::string GPermModelData_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "PermModelData_t", "m_name").Get();
}
void GPermModelData_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "PermModelData_t", "m_name", true, CUtlString(value.c_str()));
}
GPermModelInfo_t GPermModelData_t::GetModelInfo() const {
    GPermModelInfo_t value(GetSchemaPtr(m_ptr, "PermModelData_t", "m_modelInfo"));
    return value;
}
void GPermModelData_t::SetModelInfo(GPermModelInfo_t value) {
    SetSchemaValue(m_ptr, "PermModelData_t", "m_modelInfo", true, value);
}
std::vector<GPermModelExtPart_t> GPermModelData_t::GetExtParts() const {
    CUtlVector<GPermModelExtPart_t>* vec = GetSchemaValue<CUtlVector<GPermModelExtPart_t>*>(m_ptr, "PermModelData_t", "m_ExtParts"); std::vector<GPermModelExtPart_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetExtParts(std::vector<GPermModelExtPart_t> value) {
    SetSchemaValueCUtlVector<GPermModelExtPart_t>(m_ptr, "PermModelData_t", "m_ExtParts", true, value);
}
std::vector<uint64> GPermModelData_t::GetRefMeshGroupMasks() const {
    CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "PermModelData_t", "m_refMeshGroupMasks"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetRefMeshGroupMasks(std::vector<uint64> value) {
    SetSchemaValueCUtlVector<uint64>(m_ptr, "PermModelData_t", "m_refMeshGroupMasks", true, value);
}
std::vector<uint64> GPermModelData_t::GetRefPhysGroupMasks() const {
    CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "PermModelData_t", "m_refPhysGroupMasks"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetRefPhysGroupMasks(std::vector<uint64> value) {
    SetSchemaValueCUtlVector<uint64>(m_ptr, "PermModelData_t", "m_refPhysGroupMasks", true, value);
}
std::vector<uint8> GPermModelData_t::GetRefLODGroupMasks() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PermModelData_t", "m_refLODGroupMasks"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetRefLODGroupMasks(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "PermModelData_t", "m_refLODGroupMasks", true, value);
}
std::vector<float32> GPermModelData_t::GetLodGroupSwitchDistances() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PermModelData_t", "m_lodGroupSwitchDistances"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetLodGroupSwitchDistances(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "PermModelData_t", "m_lodGroupSwitchDistances", true, value);
}
std::vector<CUtlString> GPermModelData_t::GetMeshGroups() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PermModelData_t", "m_meshGroups"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetMeshGroups(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PermModelData_t", "m_meshGroups", true, value);
}
std::vector<GMaterialGroup_t> GPermModelData_t::GetMaterialGroups() const {
    CUtlVector<GMaterialGroup_t>* vec = GetSchemaValue<CUtlVector<GMaterialGroup_t>*>(m_ptr, "PermModelData_t", "m_materialGroups"); std::vector<GMaterialGroup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetMaterialGroups(std::vector<GMaterialGroup_t> value) {
    SetSchemaValueCUtlVector<GMaterialGroup_t>(m_ptr, "PermModelData_t", "m_materialGroups", true, value);
}
uint64_t GPermModelData_t::GetDefaultMeshGroupMask() const {
    return GetSchemaValue<uint64_t>(m_ptr, "PermModelData_t", "m_nDefaultMeshGroupMask");
}
void GPermModelData_t::SetDefaultMeshGroupMask(uint64_t value) {
    SetSchemaValue(m_ptr, "PermModelData_t", "m_nDefaultMeshGroupMask", true, value);
}
GModelSkeletonData_t GPermModelData_t::GetModelSkeleton() const {
    GModelSkeletonData_t value(GetSchemaPtr(m_ptr, "PermModelData_t", "m_modelSkeleton"));
    return value;
}
void GPermModelData_t::SetModelSkeleton(GModelSkeletonData_t value) {
    SetSchemaValue(m_ptr, "PermModelData_t", "m_modelSkeleton", true, value);
}
std::vector<int16> GPermModelData_t::GetRemappingTable() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "PermModelData_t", "m_remappingTable"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetRemappingTable(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "PermModelData_t", "m_remappingTable", true, value);
}
std::vector<uint16> GPermModelData_t::GetRemappingTableStarts() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PermModelData_t", "m_remappingTableStarts"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetRemappingTableStarts(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PermModelData_t", "m_remappingTableStarts", true, value);
}
std::vector<GModelBoneFlexDriver_t> GPermModelData_t::GetBoneFlexDrivers() const {
    CUtlVector<GModelBoneFlexDriver_t>* vec = GetSchemaValue<CUtlVector<GModelBoneFlexDriver_t>*>(m_ptr, "PermModelData_t", "m_boneFlexDrivers"); std::vector<GModelBoneFlexDriver_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetBoneFlexDrivers(std::vector<GModelBoneFlexDriver_t> value) {
    SetSchemaValueCUtlVector<GModelBoneFlexDriver_t>(m_ptr, "PermModelData_t", "m_boneFlexDrivers", true, value);
}
GCModelConfigList GPermModelData_t::GetModelConfigList() const {
    GCModelConfigList value(*GetSchemaValuePtr<void*>(m_ptr, "PermModelData_t", "m_pModelConfigList"));
    return value;
}
void GPermModelData_t::SetModelConfigList(GCModelConfigList* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ModelConfigList' is not possible.\n");
}
std::vector<CUtlString> GPermModelData_t::GetBodyGroupsHiddenInTools() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PermModelData_t", "m_BodyGroupsHiddenInTools"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetBodyGroupsHiddenInTools(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PermModelData_t", "m_BodyGroupsHiddenInTools", true, value);
}
std::vector<GPermModelDataAnimatedMaterialAttribute_t> GPermModelData_t::GetAnimatedMaterialAttributes() const {
    CUtlVector<GPermModelDataAnimatedMaterialAttribute_t>* vec = GetSchemaValue<CUtlVector<GPermModelDataAnimatedMaterialAttribute_t>*>(m_ptr, "PermModelData_t", "m_AnimatedMaterialAttributes"); std::vector<GPermModelDataAnimatedMaterialAttribute_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPermModelData_t::SetAnimatedMaterialAttributes(std::vector<GPermModelDataAnimatedMaterialAttribute_t> value) {
    SetSchemaValueCUtlVector<GPermModelDataAnimatedMaterialAttribute_t>(m_ptr, "PermModelData_t", "m_AnimatedMaterialAttributes", true, value);
}
std::string GPermModelData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPermModelData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPermModelData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelData_t>("PermModelData_t")
        .addConstructor<void (*)(std::string)>()
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
        .addFunction("ToPtr", &GPermModelData_t::ToPtr)
        .addFunction("IsValid", &GPermModelData_t::IsValid)
        .endClass();
}