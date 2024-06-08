class GCVoxelVisibility;

#ifndef _gccvoxelvisibility_h
#define _gccvoxelvisibility_h

#include "../../../scripting.h"


#include "GVoxelVisBlockOffset_t.h"

class GCVoxelVisibility
{
private:
    void *m_ptr;

public:
    GCVoxelVisibility() {}
    GCVoxelVisibility(void *ptr) : m_ptr(ptr) {}

    uint32_t GetBaseClusterCount() const { return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nBaseClusterCount"); }
    void SetBaseClusterCount(uint32_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nBaseClusterCount", false, value); }
    uint32_t GetPVSBytesPerCluster() const { return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nPVSBytesPerCluster"); }
    void SetPVSBytesPerCluster(uint32_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nPVSBytesPerCluster", false, value); }
    Vector GetMinBounds() const { return GetSchemaValue<Vector>(m_ptr, "CVoxelVisibility", "m_vMinBounds"); }
    void SetMinBounds(Vector value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_vMinBounds", false, value); }
    Vector GetMaxBounds() const { return GetSchemaValue<Vector>(m_ptr, "CVoxelVisibility", "m_vMaxBounds"); }
    void SetMaxBounds(Vector value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_vMaxBounds", false, value); }
    float GetGridSize() const { return GetSchemaValue<float>(m_ptr, "CVoxelVisibility", "m_flGridSize"); }
    void SetGridSize(float value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_flGridSize", false, value); }
    uint32_t GetSkyVisibilityCluster() const { return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nSkyVisibilityCluster"); }
    void SetSkyVisibilityCluster(uint32_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nSkyVisibilityCluster", false, value); }
    uint32_t GetSunVisibilityCluster() const { return GetSchemaValue<uint32_t>(m_ptr, "CVoxelVisibility", "m_nSunVisibilityCluster"); }
    void SetSunVisibilityCluster(uint32_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nSunVisibilityCluster", false, value); }
    GVoxelVisBlockOffset_t GetNodeBlock() const { return GetSchemaValue<GVoxelVisBlockOffset_t>(m_ptr, "CVoxelVisibility", "m_NodeBlock"); }
    void SetNodeBlock(GVoxelVisBlockOffset_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_NodeBlock", false, value); }
    GVoxelVisBlockOffset_t GetRegionBlock() const { return GetSchemaValue<GVoxelVisBlockOffset_t>(m_ptr, "CVoxelVisibility", "m_RegionBlock"); }
    void SetRegionBlock(GVoxelVisBlockOffset_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_RegionBlock", false, value); }
    GVoxelVisBlockOffset_t GetEnclosedClusterListBlock() const { return GetSchemaValue<GVoxelVisBlockOffset_t>(m_ptr, "CVoxelVisibility", "m_EnclosedClusterListBlock"); }
    void SetEnclosedClusterListBlock(GVoxelVisBlockOffset_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_EnclosedClusterListBlock", false, value); }
    GVoxelVisBlockOffset_t GetEnclosedClustersBlock() const { return GetSchemaValue<GVoxelVisBlockOffset_t>(m_ptr, "CVoxelVisibility", "m_EnclosedClustersBlock"); }
    void SetEnclosedClustersBlock(GVoxelVisBlockOffset_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_EnclosedClustersBlock", false, value); }
    GVoxelVisBlockOffset_t GetMasksBlock() const { return GetSchemaValue<GVoxelVisBlockOffset_t>(m_ptr, "CVoxelVisibility", "m_MasksBlock"); }
    void SetMasksBlock(GVoxelVisBlockOffset_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_MasksBlock", false, value); }
    GVoxelVisBlockOffset_t GetVisBlocks() const { return GetSchemaValue<GVoxelVisBlockOffset_t>(m_ptr, "CVoxelVisibility", "m_nVisBlocks"); }
    void SetVisBlocks(GVoxelVisBlockOffset_t value) { SetSchemaValue(m_ptr, "CVoxelVisibility", "m_nVisBlocks", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif