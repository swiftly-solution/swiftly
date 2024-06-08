class GWorldNode_t;

#ifndef _gcworldnode_t_h
#define _gcworldnode_t_h

#include "../../../scripting.h"


#include "GSceneObject_t.h"
#include "GInfoOverlayData_t.h"
#include "GAggregateSceneObject_t.h"
#include "GClutterSceneObject_t.h"
#include "GExtraVertexStreamOverride_t.h"
#include "GMaterialOverride_t.h"
#include "GWorldNodeOnDiskBufferData_t.h"
#include "GBakedLightingInfo_t.h"

class GWorldNode_t
{
private:
    void *m_ptr;

public:
    GWorldNode_t() {}
    GWorldNode_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GSceneObject_t> GetSceneObjects() const { CUtlVector<GSceneObject_t>* vec = GetSchemaValue<CUtlVector<GSceneObject_t>*>(m_ptr, "WorldNode_t", "m_sceneObjects"); std::vector<GSceneObject_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSceneObjects(std::vector<GSceneObject_t> value) { SetSchemaValueCUtlVector<GSceneObject_t>(m_ptr, "WorldNode_t", "m_sceneObjects", true, value); }
    std::vector<GInfoOverlayData_t> GetInfoOverlays() const { CUtlVector<GInfoOverlayData_t>* vec = GetSchemaValue<CUtlVector<GInfoOverlayData_t>*>(m_ptr, "WorldNode_t", "m_infoOverlays"); std::vector<GInfoOverlayData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInfoOverlays(std::vector<GInfoOverlayData_t> value) { SetSchemaValueCUtlVector<GInfoOverlayData_t>(m_ptr, "WorldNode_t", "m_infoOverlays", true, value); }
    std::vector<uint16> GetVisClusterMembership() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "WorldNode_t", "m_visClusterMembership"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVisClusterMembership(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "WorldNode_t", "m_visClusterMembership", true, value); }
    std::vector<GAggregateSceneObject_t> GetAggregateSceneObjects() const { CUtlVector<GAggregateSceneObject_t>* vec = GetSchemaValue<CUtlVector<GAggregateSceneObject_t>*>(m_ptr, "WorldNode_t", "m_aggregateSceneObjects"); std::vector<GAggregateSceneObject_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAggregateSceneObjects(std::vector<GAggregateSceneObject_t> value) { SetSchemaValueCUtlVector<GAggregateSceneObject_t>(m_ptr, "WorldNode_t", "m_aggregateSceneObjects", true, value); }
    std::vector<GClutterSceneObject_t> GetClutterSceneObjects() const { CUtlVector<GClutterSceneObject_t>* vec = GetSchemaValue<CUtlVector<GClutterSceneObject_t>*>(m_ptr, "WorldNode_t", "m_clutterSceneObjects"); std::vector<GClutterSceneObject_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetClutterSceneObjects(std::vector<GClutterSceneObject_t> value) { SetSchemaValueCUtlVector<GClutterSceneObject_t>(m_ptr, "WorldNode_t", "m_clutterSceneObjects", true, value); }
    std::vector<GExtraVertexStreamOverride_t> GetExtraVertexStreamOverrides() const { CUtlVector<GExtraVertexStreamOverride_t>* vec = GetSchemaValue<CUtlVector<GExtraVertexStreamOverride_t>*>(m_ptr, "WorldNode_t", "m_extraVertexStreamOverrides"); std::vector<GExtraVertexStreamOverride_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetExtraVertexStreamOverrides(std::vector<GExtraVertexStreamOverride_t> value) { SetSchemaValueCUtlVector<GExtraVertexStreamOverride_t>(m_ptr, "WorldNode_t", "m_extraVertexStreamOverrides", true, value); }
    std::vector<GMaterialOverride_t> GetMaterialOverrides() const { CUtlVector<GMaterialOverride_t>* vec = GetSchemaValue<CUtlVector<GMaterialOverride_t>*>(m_ptr, "WorldNode_t", "m_materialOverrides"); std::vector<GMaterialOverride_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterialOverrides(std::vector<GMaterialOverride_t> value) { SetSchemaValueCUtlVector<GMaterialOverride_t>(m_ptr, "WorldNode_t", "m_materialOverrides", true, value); }
    std::vector<GWorldNodeOnDiskBufferData_t> GetExtraVertexStreams() const { CUtlVector<GWorldNodeOnDiskBufferData_t>* vec = GetSchemaValue<CUtlVector<GWorldNodeOnDiskBufferData_t>*>(m_ptr, "WorldNode_t", "m_extraVertexStreams"); std::vector<GWorldNodeOnDiskBufferData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetExtraVertexStreams(std::vector<GWorldNodeOnDiskBufferData_t> value) { SetSchemaValueCUtlVector<GWorldNodeOnDiskBufferData_t>(m_ptr, "WorldNode_t", "m_extraVertexStreams", true, value); }
    std::vector<CUtlString> GetLayerNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "WorldNode_t", "m_layerNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLayerNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "WorldNode_t", "m_layerNames", true, value); }
    std::vector<uint8> GetSceneObjectLayerIndices() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "WorldNode_t", "m_sceneObjectLayerIndices"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSceneObjectLayerIndices(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "WorldNode_t", "m_sceneObjectLayerIndices", true, value); }
    std::vector<uint8> GetOverlayLayerIndices() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "WorldNode_t", "m_overlayLayerIndices"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOverlayLayerIndices(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "WorldNode_t", "m_overlayLayerIndices", true, value); }
    CUtlString GetGrassFileName() const { return GetSchemaValue<CUtlString>(m_ptr, "WorldNode_t", "m_grassFileName"); }
    void SetGrassFileName(CUtlString value) { SetSchemaValue(m_ptr, "WorldNode_t", "m_grassFileName", true, value); }
    GBakedLightingInfo_t GetNodeLightingInfo() const { return GetSchemaValue<GBakedLightingInfo_t>(m_ptr, "WorldNode_t", "m_nodeLightingInfo"); }
    void SetNodeLightingInfo(GBakedLightingInfo_t value) { SetSchemaValue(m_ptr, "WorldNode_t", "m_nodeLightingInfo", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif