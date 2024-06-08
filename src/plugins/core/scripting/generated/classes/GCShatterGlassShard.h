class GCShatterGlassShard;

#ifndef _gccshatterglassshard_h
#define _gccshatterglassshard_h

#include "../../../scripting.h"

#include "../types/GShatterGlassStressType.h"
#include "../types/GOnFrame.h"
#include "GCShatterGlassShardPhysics.h"
#include "GCShatterGlassShard.h"
#include "GCFuncShatterglass.h"
#include "GCBaseEntity.h"

class GCShatterGlassShard
{
private:
    void *m_ptr;

public:
    GCShatterGlassShard() {}
    GCShatterGlassShard(void *ptr) : m_ptr(ptr) {}

    uint32_t GetShardHandle() const { return GetSchemaValue<uint32_t>(m_ptr, "CShatterGlassShard", "m_hShardHandle"); }
    void SetShardHandle(uint32_t value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_hShardHandle", false, value); }
    std::vector<Vector2D> GetPanelVertices() const { CUtlVector<Vector2D>* vec = GetSchemaValue<CUtlVector<Vector2D>*>(m_ptr, "CShatterGlassShard", "m_vecPanelVertices"); std::vector<Vector2D> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPanelVertices(std::vector<Vector2D> value) { SetSchemaValueCUtlVector<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecPanelVertices", false, value); }
    Vector2D GetLocalPanelSpaceOrigin() const { return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vLocalPanelSpaceOrigin"); }
    void SetLocalPanelSpaceOrigin(Vector2D value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vLocalPanelSpaceOrigin", false, value); }
    GCShatterGlassShardPhysics* GetPhysicsEntity() const { return GetSchemaValue<GCShatterGlassShardPhysics*>(m_ptr, "CShatterGlassShard", "m_hPhysicsEntity"); }
    void SetPhysicsEntity(GCShatterGlassShardPhysics* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsEntity' is not possible.\n"); }
    GCFuncShatterglass* GetParentPanel() const { return GetSchemaValue<GCFuncShatterglass*>(m_ptr, "CShatterGlassShard", "m_hParentPanel"); }
    void SetParentPanel(GCFuncShatterglass* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ParentPanel' is not possible.\n"); }
    uint32_t GetParentShard() const { return GetSchemaValue<uint32_t>(m_ptr, "CShatterGlassShard", "m_hParentShard"); }
    void SetParentShard(uint32_t value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_hParentShard", false, value); }
    ShatterGlassStressType GetShatterStressType() const { return GetSchemaValue<ShatterGlassStressType>(m_ptr, "CShatterGlassShard", "m_ShatterStressType"); }
    void SetShatterStressType(ShatterGlassStressType value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_ShatterStressType", false, value); }
    Vector GetStressVelocity() const { return GetSchemaValue<Vector>(m_ptr, "CShatterGlassShard", "m_vecStressVelocity"); }
    void SetStressVelocity(Vector value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecStressVelocity", false, value); }
    bool GetCreatedModel() const { return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bCreatedModel"); }
    void SetCreatedModel(bool value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bCreatedModel", false, value); }
    float GetLongestEdge() const { return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flLongestEdge"); }
    void SetLongestEdge(float value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flLongestEdge", false, value); }
    float GetShortestEdge() const { return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flShortestEdge"); }
    void SetShortestEdge(float value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flShortestEdge", false, value); }
    float GetLongestAcross() const { return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flLongestAcross"); }
    void SetLongestAcross(float value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flLongestAcross", false, value); }
    float GetShortestAcross() const { return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flShortestAcross"); }
    void SetShortestAcross(float value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flShortestAcross", false, value); }
    float GetSumOfAllEdges() const { return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flSumOfAllEdges"); }
    void SetSumOfAllEdges(float value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flSumOfAllEdges", false, value); }
    float GetArea() const { return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flArea"); }
    void SetArea(float value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flArea", false, value); }
    OnFrame GetOnFrameEdge() const { return GetSchemaValue<OnFrame>(m_ptr, "CShatterGlassShard", "m_nOnFrameEdge"); }
    void SetOnFrameEdge(OnFrame value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_nOnFrameEdge", false, value); }
    int32_t GetParentPanelsNthShard() const { return GetSchemaValue<int32_t>(m_ptr, "CShatterGlassShard", "m_nParentPanelsNthShard"); }
    void SetParentPanelsNthShard(int32_t value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_nParentPanelsNthShard", false, value); }
    int32_t GetSubShardGeneration() const { return GetSchemaValue<int32_t>(m_ptr, "CShatterGlassShard", "m_nSubShardGeneration"); }
    void SetSubShardGeneration(int32_t value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_nSubShardGeneration", false, value); }
    Vector2D GetAverageVertPosition() const { return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecAverageVertPosition"); }
    void SetAverageVertPosition(Vector2D value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecAverageVertPosition", false, value); }
    bool GetAverageVertPositionIsValid() const { return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bAverageVertPositionIsValid"); }
    void SetAverageVertPositionIsValid(bool value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bAverageVertPositionIsValid", false, value); }
    Vector2D GetPanelSpaceStressPositionA() const { return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionA"); }
    void SetPanelSpaceStressPositionA(Vector2D value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionA", false, value); }
    Vector2D GetPanelSpaceStressPositionB() const { return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionB"); }
    void SetPanelSpaceStressPositionB(Vector2D value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionB", false, value); }
    bool GetStressPositionAIsValid() const { return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bStressPositionAIsValid"); }
    void SetStressPositionAIsValid(bool value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bStressPositionAIsValid", false, value); }
    bool GetStressPositionBIsValid() const { return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bStressPositionBIsValid"); }
    void SetStressPositionBIsValid(bool value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bStressPositionBIsValid", false, value); }
    bool GetFlaggedForRemoval() const { return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bFlaggedForRemoval"); }
    void SetFlaggedForRemoval(bool value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bFlaggedForRemoval", false, value); }
    bool GetShatterRateLimited() const { return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bShatterRateLimited"); }
    void SetShatterRateLimited(bool value) { SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bShatterRateLimited", false, value); }
    GCBaseEntity* GetEntityHittingMe() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CShatterGlassShard", "m_hEntityHittingMe"); }
    void SetEntityHittingMe(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityHittingMe' is not possible.\n"); }
    std::vector<uint32> GetNeighbors() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CShatterGlassShard", "m_vecNeighbors"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNeighbors(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CShatterGlassShard", "m_vecNeighbors", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif