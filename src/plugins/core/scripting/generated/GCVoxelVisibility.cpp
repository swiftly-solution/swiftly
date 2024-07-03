#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoxelVisibility::GCVoxelVisibility(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoxelVisibility::GCVoxelVisibility(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCVoxelVisibility::GetBaseClusterCount() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nBaseClusterCount");
}
void GCVoxelVisibility::SetBaseClusterCount(uint32_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nBaseClusterCount", false, value);
}
uint32_t GCVoxelVisibility::GetPVSBytesPerCluster() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nPVSBytesPerCluster");
}
void GCVoxelVisibility::SetPVSBytesPerCluster(uint32_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nPVSBytesPerCluster", false, value);
}
Vector GCVoxelVisibility::GetMinBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "CVoxelVisibility", "m_vMinBounds");
}
void GCVoxelVisibility::SetMinBounds(Vector value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_vMinBounds", false, value);
}
Vector GCVoxelVisibility::GetMaxBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "CVoxelVisibility", "m_vMaxBounds");
}
void GCVoxelVisibility::SetMaxBounds(Vector value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_vMaxBounds", false, value);
}
float GCVoxelVisibility::GetGridSize() const {
    return GetSchemaValue<float>(m_ptr, "CVoxelVisibility", "m_flGridSize");
}
void GCVoxelVisibility::SetGridSize(float value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_flGridSize", false, value);
}
uint32_t GCVoxelVisibility::GetSkyVisibilityCluster() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nSkyVisibilityCluster");
}
void GCVoxelVisibility::SetSkyVisibilityCluster(uint32_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nSkyVisibilityCluster", false, value);
}
uint32_t GCVoxelVisibility::GetSunVisibilityCluster() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nSunVisibilityCluster");
}
void GCVoxelVisibility::SetSunVisibilityCluster(uint32_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nSunVisibilityCluster", false, value);
}
GVoxelVisBlockOffset_t GCVoxelVisibility::GetNodeBlock() const {
    GVoxelVisBlockOffset_t value(GetSchemaPtr(m_ptr, "CVoxelVisibility", "m_NodeBlock"));
    return value;
}
void GCVoxelVisibility::SetNodeBlock(GVoxelVisBlockOffset_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_NodeBlock", false, value);
}
GVoxelVisBlockOffset_t GCVoxelVisibility::GetRegionBlock() const {
    GVoxelVisBlockOffset_t value(GetSchemaPtr(m_ptr, "CVoxelVisibility", "m_RegionBlock"));
    return value;
}
void GCVoxelVisibility::SetRegionBlock(GVoxelVisBlockOffset_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_RegionBlock", false, value);
}
GVoxelVisBlockOffset_t GCVoxelVisibility::GetEnclosedClusterListBlock() const {
    GVoxelVisBlockOffset_t value(GetSchemaPtr(m_ptr, "CVoxelVisibility", "m_EnclosedClusterListBlock"));
    return value;
}
void GCVoxelVisibility::SetEnclosedClusterListBlock(GVoxelVisBlockOffset_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_EnclosedClusterListBlock", false, value);
}
GVoxelVisBlockOffset_t GCVoxelVisibility::GetEnclosedClustersBlock() const {
    GVoxelVisBlockOffset_t value(GetSchemaPtr(m_ptr, "CVoxelVisibility", "m_EnclosedClustersBlock"));
    return value;
}
void GCVoxelVisibility::SetEnclosedClustersBlock(GVoxelVisBlockOffset_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_EnclosedClustersBlock", false, value);
}
GVoxelVisBlockOffset_t GCVoxelVisibility::GetMasksBlock() const {
    GVoxelVisBlockOffset_t value(GetSchemaPtr(m_ptr, "CVoxelVisibility", "m_MasksBlock"));
    return value;
}
void GCVoxelVisibility::SetMasksBlock(GVoxelVisBlockOffset_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_MasksBlock", false, value);
}
GVoxelVisBlockOffset_t GCVoxelVisibility::GetVisBlocks() const {
    GVoxelVisBlockOffset_t value(GetSchemaPtr(m_ptr, "CVoxelVisibility", "m_nVisBlocks"));
    return value;
}
void GCVoxelVisibility::SetVisBlocks(GVoxelVisBlockOffset_t value) {
    SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nVisBlocks", false, value);
}
std::string GCVoxelVisibility::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoxelVisibility::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCVoxelVisibility(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoxelVisibility>("CVoxelVisibility")
        .addConstructor<void (*)(std::string)>()
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
        .addFunction("ToPtr", &GCVoxelVisibility::ToPtr)
        .addFunction("IsValid", &GCVoxelVisibility::IsValid)
        .endClass();
}