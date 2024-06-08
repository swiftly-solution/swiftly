class GClutterSceneObject_t;

#ifndef _gccluttersceneobject_t_h
#define _gccluttersceneobject_t_h

#include "../../../scripting.h"

#include "../types/GObjectTypeFlags_t.h"
#include "GAABB_t.h"
#include "GClutterTile_t.h"

class GClutterSceneObject_t
{
private:
    void *m_ptr;

public:
    GClutterSceneObject_t() {}
    GClutterSceneObject_t(void *ptr) : m_ptr(ptr) {}

    GAABB_t GetBounds() const { return GetSchemaValue<GAABB_t>(m_ptr, "ClutterSceneObject_t", "m_Bounds"); }
    void SetBounds(GAABB_t value) { SetSchemaValue(m_ptr, "ClutterSceneObject_t", "m_Bounds", true, value); }
    ObjectTypeFlags_t GetFlags() const { return GetSchemaValue<ObjectTypeFlags_t>(m_ptr, "ClutterSceneObject_t", "m_flags"); }
    void SetFlags(ObjectTypeFlags_t value) { SetSchemaValue(m_ptr, "ClutterSceneObject_t", "m_flags", true, value); }
    int16_t GetLayer() const { return GetSchemaValue<int16_t>(m_ptr, "ClutterSceneObject_t", "m_nLayer"); }
    void SetLayer(int16_t value) { SetSchemaValue(m_ptr, "ClutterSceneObject_t", "m_nLayer", true, value); }
    std::vector<Vector> GetInstancePositions() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "ClutterSceneObject_t", "m_instancePositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInstancePositions(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "ClutterSceneObject_t", "m_instancePositions", true, value); }
    std::vector<float32> GetInstanceScales() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "ClutterSceneObject_t", "m_instanceScales"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInstanceScales(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "ClutterSceneObject_t", "m_instanceScales", true, value); }
    std::vector<Color> GetInstanceTintSrgb() const { CUtlVector<Color>* vec = GetSchemaValue<CUtlVector<Color>*>(m_ptr, "ClutterSceneObject_t", "m_instanceTintSrgb"); std::vector<Color> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInstanceTintSrgb(std::vector<Color> value) { SetSchemaValueCUtlVector<Color>(m_ptr, "ClutterSceneObject_t", "m_instanceTintSrgb", true, value); }
    std::vector<GClutterTile_t> GetTiles() const { CUtlVector<GClutterTile_t>* vec = GetSchemaValue<CUtlVector<GClutterTile_t>*>(m_ptr, "ClutterSceneObject_t", "m_tiles"); std::vector<GClutterTile_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTiles(std::vector<GClutterTile_t> value) { SetSchemaValueCUtlVector<GClutterTile_t>(m_ptr, "ClutterSceneObject_t", "m_tiles", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif