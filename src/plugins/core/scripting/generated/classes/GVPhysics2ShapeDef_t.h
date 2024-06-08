class GVPhysics2ShapeDef_t;

#ifndef _gcvphysics2shapedef_t_h
#define _gcvphysics2shapedef_t_h

#include "../../../scripting.h"


#include "GRnSphereDesc_t.h"
#include "GRnCapsuleDesc_t.h"
#include "GRnHullDesc_t.h"
#include "GRnMeshDesc_t.h"

class GVPhysics2ShapeDef_t
{
private:
    void *m_ptr;

public:
    GVPhysics2ShapeDef_t() {}
    GVPhysics2ShapeDef_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GRnSphereDesc_t> GetSpheres() const { CUtlVector<GRnSphereDesc_t>* vec = GetSchemaValue<CUtlVector<GRnSphereDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_spheres"); std::vector<GRnSphereDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSpheres(std::vector<GRnSphereDesc_t> value) { SetSchemaValueCUtlVector<GRnSphereDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_spheres", true, value); }
    std::vector<GRnCapsuleDesc_t> GetCapsules() const { CUtlVector<GRnCapsuleDesc_t>* vec = GetSchemaValue<CUtlVector<GRnCapsuleDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_capsules"); std::vector<GRnCapsuleDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCapsules(std::vector<GRnCapsuleDesc_t> value) { SetSchemaValueCUtlVector<GRnCapsuleDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_capsules", true, value); }
    std::vector<GRnHullDesc_t> GetHulls() const { CUtlVector<GRnHullDesc_t>* vec = GetSchemaValue<CUtlVector<GRnHullDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_hulls"); std::vector<GRnHullDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHulls(std::vector<GRnHullDesc_t> value) { SetSchemaValueCUtlVector<GRnHullDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_hulls", true, value); }
    std::vector<GRnMeshDesc_t> GetMeshes() const { CUtlVector<GRnMeshDesc_t>* vec = GetSchemaValue<CUtlVector<GRnMeshDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_meshes"); std::vector<GRnMeshDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMeshes(std::vector<GRnMeshDesc_t> value) { SetSchemaValueCUtlVector<GRnMeshDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_meshes", true, value); }
    std::vector<uint16> GetCollisionAttributeIndices() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysics2ShapeDef_t", "m_CollisionAttributeIndices"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCollisionAttributeIndices(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysics2ShapeDef_t", "m_CollisionAttributeIndices", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif