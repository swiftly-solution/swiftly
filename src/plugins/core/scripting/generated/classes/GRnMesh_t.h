class GRnMesh_t;

#ifndef _gcrnmesh_t_h
#define _gcrnmesh_t_h

#include "../../../scripting.h"


#include "GRnNode_t.h"
#include "GRnTriangle_t.h"
#include "GRnWing_t.h"

class GRnMesh_t
{
private:
    void *m_ptr;

public:
    GRnMesh_t() {}
    GRnMesh_t(void *ptr) : m_ptr(ptr) {}

    Vector GetMin() const { return GetSchemaValue<Vector>(m_ptr, "RnMesh_t", "m_vMin"); }
    void SetMin(Vector value) { SetSchemaValue(m_ptr, "RnMesh_t", "m_vMin", true, value); }
    Vector GetMax() const { return GetSchemaValue<Vector>(m_ptr, "RnMesh_t", "m_vMax"); }
    void SetMax(Vector value) { SetSchemaValue(m_ptr, "RnMesh_t", "m_vMax", true, value); }
    std::vector<GRnNode_t> GetNodes() const { CUtlVector<GRnNode_t>* vec = GetSchemaValue<CUtlVector<GRnNode_t>*>(m_ptr, "RnMesh_t", "m_Nodes"); std::vector<GRnNode_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodes(std::vector<GRnNode_t> value) { SetSchemaValueCUtlVector<GRnNode_t>(m_ptr, "RnMesh_t", "m_Nodes", true, value); }
    std::vector<GRnTriangle_t> GetTriangles() const { CUtlVector<GRnTriangle_t>* vec = GetSchemaValue<CUtlVector<GRnTriangle_t>*>(m_ptr, "RnMesh_t", "m_Triangles"); std::vector<GRnTriangle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTriangles(std::vector<GRnTriangle_t> value) { SetSchemaValueCUtlVector<GRnTriangle_t>(m_ptr, "RnMesh_t", "m_Triangles", true, value); }
    std::vector<GRnWing_t> GetWings() const { CUtlVector<GRnWing_t>* vec = GetSchemaValue<CUtlVector<GRnWing_t>*>(m_ptr, "RnMesh_t", "m_Wings"); std::vector<GRnWing_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWings(std::vector<GRnWing_t> value) { SetSchemaValueCUtlVector<GRnWing_t>(m_ptr, "RnMesh_t", "m_Wings", true, value); }
    std::vector<uint8> GetMaterials() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "RnMesh_t", "m_Materials"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterials(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "RnMesh_t", "m_Materials", true, value); }
    Vector GetOrthographicAreas() const { return GetSchemaValue<Vector>(m_ptr, "RnMesh_t", "m_vOrthographicAreas"); }
    void SetOrthographicAreas(Vector value) { SetSchemaValue(m_ptr, "RnMesh_t", "m_vOrthographicAreas", true, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "RnMesh_t", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "RnMesh_t", "m_nFlags", true, value); }
    uint32_t GetDebugFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "RnMesh_t", "m_nDebugFlags"); }
    void SetDebugFlags(uint32_t value) { SetSchemaValue(m_ptr, "RnMesh_t", "m_nDebugFlags", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif