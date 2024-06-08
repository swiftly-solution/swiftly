class Gshard_model_desc_t;

#ifndef _gcshard_model_desc_t_h
#define _gcshard_model_desc_t_h

#include "../../../scripting.h"

#include "../types/GShardSolid_t.h"
#include "../types/GShatterPanelMode.h"


class Gshard_model_desc_t
{
private:
    void *m_ptr;

public:
    Gshard_model_desc_t() {}
    Gshard_model_desc_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetModelID() const { return GetSchemaValue<int32_t>(m_ptr, "shard_model_desc_t", "m_nModelID"); }
    void SetModelID(int32_t value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_nModelID", true, value); }
    ShardSolid_t GetSolid() const { return GetSchemaValue<ShardSolid_t>(m_ptr, "shard_model_desc_t", "m_solid"); }
    void SetSolid(ShardSolid_t value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_solid", true, value); }
    ShatterPanelMode GetShatterPanelMode() const { return GetSchemaValue<ShatterPanelMode>(m_ptr, "shard_model_desc_t", "m_ShatterPanelMode"); }
    void SetShatterPanelMode(ShatterPanelMode value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_ShatterPanelMode", true, value); }
    Vector2D GetPanelSize() const { return GetSchemaValue<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecPanelSize"); }
    void SetPanelSize(Vector2D value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_vecPanelSize", true, value); }
    Vector2D GetStressPositionA() const { return GetSchemaValue<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecStressPositionA"); }
    void SetStressPositionA(Vector2D value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_vecStressPositionA", true, value); }
    Vector2D GetStressPositionB() const { return GetSchemaValue<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecStressPositionB"); }
    void SetStressPositionB(Vector2D value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_vecStressPositionB", true, value); }
    std::vector<Vector2D> GetPanelVertices() const { CUtlVector<Vector2D>* vec = GetSchemaValue<CUtlVector<Vector2D>*>(m_ptr, "shard_model_desc_t", "m_vecPanelVertices"); std::vector<Vector2D> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPanelVertices(std::vector<Vector2D> value) { SetSchemaValueCUtlVector<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecPanelVertices", true, value); }
    float GetGlassHalfThickness() const { return GetSchemaValue<float>(m_ptr, "shard_model_desc_t", "m_flGlassHalfThickness"); }
    void SetGlassHalfThickness(float value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_flGlassHalfThickness", true, value); }
    bool GetHasParent() const { return GetSchemaValue<bool>(m_ptr, "shard_model_desc_t", "m_bHasParent"); }
    void SetHasParent(bool value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_bHasParent", true, value); }
    bool GetParentFrozen() const { return GetSchemaValue<bool>(m_ptr, "shard_model_desc_t", "m_bParentFrozen"); }
    void SetParentFrozen(bool value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_bParentFrozen", true, value); }
    CUtlStringToken GetSurfacePropStringToken() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "shard_model_desc_t", "m_SurfacePropStringToken"); }
    void SetSurfacePropStringToken(CUtlStringToken value) { SetSchemaValue(m_ptr, "shard_model_desc_t", "m_SurfacePropStringToken", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif