class GRnHull_t;

#ifndef _gcrnhull_t_h
#define _gcrnhull_t_h

#include "../../../scripting.h"


#include "GAABB_t.h"
#include "GRnVertex_t.h"
#include "GRnHalfEdge_t.h"
#include "GRnFace_t.h"
#include "GRnPlane_t.h"
#include "GCRegionSVM.h"

class GRnHull_t
{
private:
    void *m_ptr;

public:
    GRnHull_t() {}
    GRnHull_t(void *ptr) : m_ptr(ptr) {}

    Vector GetCentroid() const { return GetSchemaValue<Vector>(m_ptr, "RnHull_t", "m_vCentroid"); }
    void SetCentroid(Vector value) { SetSchemaValue(m_ptr, "RnHull_t", "m_vCentroid", true, value); }
    float GetMaxAngularRadius() const { return GetSchemaValue<float>(m_ptr, "RnHull_t", "m_flMaxAngularRadius"); }
    void SetMaxAngularRadius(float value) { SetSchemaValue(m_ptr, "RnHull_t", "m_flMaxAngularRadius", true, value); }
    GAABB_t GetBounds() const { return GetSchemaValue<GAABB_t>(m_ptr, "RnHull_t", "m_Bounds"); }
    void SetBounds(GAABB_t value) { SetSchemaValue(m_ptr, "RnHull_t", "m_Bounds", true, value); }
    Vector GetOrthographicAreas() const { return GetSchemaValue<Vector>(m_ptr, "RnHull_t", "m_vOrthographicAreas"); }
    void SetOrthographicAreas(Vector value) { SetSchemaValue(m_ptr, "RnHull_t", "m_vOrthographicAreas", true, value); }
    matrix3x4_t GetMassProperties() const { return GetSchemaValue<matrix3x4_t>(m_ptr, "RnHull_t", "m_MassProperties"); }
    void SetMassProperties(matrix3x4_t value) { SetSchemaValue(m_ptr, "RnHull_t", "m_MassProperties", true, value); }
    float GetVolume() const { return GetSchemaValue<float>(m_ptr, "RnHull_t", "m_flVolume"); }
    void SetVolume(float value) { SetSchemaValue(m_ptr, "RnHull_t", "m_flVolume", true, value); }
    float GetSurfaceArea() const { return GetSchemaValue<float>(m_ptr, "RnHull_t", "m_flSurfaceArea"); }
    void SetSurfaceArea(float value) { SetSchemaValue(m_ptr, "RnHull_t", "m_flSurfaceArea", true, value); }
    std::vector<GRnVertex_t> GetVertices() const { CUtlVector<GRnVertex_t>* vec = GetSchemaValue<CUtlVector<GRnVertex_t>*>(m_ptr, "RnHull_t", "m_Vertices"); std::vector<GRnVertex_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVertices(std::vector<GRnVertex_t> value) { SetSchemaValueCUtlVector<GRnVertex_t>(m_ptr, "RnHull_t", "m_Vertices", true, value); }
    std::vector<Vector> GetVertexPositions() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "RnHull_t", "m_VertexPositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVertexPositions(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "RnHull_t", "m_VertexPositions", true, value); }
    std::vector<GRnHalfEdge_t> GetEdges() const { CUtlVector<GRnHalfEdge_t>* vec = GetSchemaValue<CUtlVector<GRnHalfEdge_t>*>(m_ptr, "RnHull_t", "m_Edges"); std::vector<GRnHalfEdge_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEdges(std::vector<GRnHalfEdge_t> value) { SetSchemaValueCUtlVector<GRnHalfEdge_t>(m_ptr, "RnHull_t", "m_Edges", true, value); }
    std::vector<GRnFace_t> GetFaces() const { CUtlVector<GRnFace_t>* vec = GetSchemaValue<CUtlVector<GRnFace_t>*>(m_ptr, "RnHull_t", "m_Faces"); std::vector<GRnFace_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFaces(std::vector<GRnFace_t> value) { SetSchemaValueCUtlVector<GRnFace_t>(m_ptr, "RnHull_t", "m_Faces", true, value); }
    std::vector<GRnPlane_t> GetFacePlanes() const { CUtlVector<GRnPlane_t>* vec = GetSchemaValue<CUtlVector<GRnPlane_t>*>(m_ptr, "RnHull_t", "m_FacePlanes"); std::vector<GRnPlane_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFacePlanes(std::vector<GRnPlane_t> value) { SetSchemaValueCUtlVector<GRnPlane_t>(m_ptr, "RnHull_t", "m_FacePlanes", true, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "RnHull_t", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "RnHull_t", "m_nFlags", true, value); }
    GCRegionSVM* GetRegionSVM() const { return GetSchemaValue<GCRegionSVM*>(m_ptr, "RnHull_t", "m_pRegionSVM"); }
    void SetRegionSVM(GCRegionSVM* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RegionSVM' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif