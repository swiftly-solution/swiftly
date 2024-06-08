class GCRenderMesh;

#ifndef _gccrendermesh_h
#define _gccrendermesh_h

#include "../../../scripting.h"


#include "GCBaseConstraint.h"
#include "GCRenderSkeleton.h"
#include "GDynamicMeshDeformParams_t.h"
#include "GCRenderGroom.h"

class GCRenderMesh
{
private:
    void *m_ptr;

public:
    GCRenderMesh() {}
    GCRenderMesh(void *ptr) : m_ptr(ptr) {}

    std::vector<GCBaseConstraint*> GetConstraints() const { CUtlVector<GCBaseConstraint*>* vec = GetSchemaValue<CUtlVector<GCBaseConstraint*>*>(m_ptr, "CRenderMesh", "m_constraints"); std::vector<GCBaseConstraint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConstraints(std::vector<GCBaseConstraint*> value) { SetSchemaValueCUtlVector<GCBaseConstraint*>(m_ptr, "CRenderMesh", "m_constraints", false, value); }
    GCRenderSkeleton GetSkeleton() const { return GetSchemaValue<GCRenderSkeleton>(m_ptr, "CRenderMesh", "m_skeleton"); }
    void SetSkeleton(GCRenderSkeleton value) { SetSchemaValue(m_ptr, "CRenderMesh", "m_skeleton", false, value); }
    GDynamicMeshDeformParams_t GetMeshDeformParams() const { return GetSchemaValue<GDynamicMeshDeformParams_t>(m_ptr, "CRenderMesh", "m_meshDeformParams"); }
    void SetMeshDeformParams(GDynamicMeshDeformParams_t value) { SetSchemaValue(m_ptr, "CRenderMesh", "m_meshDeformParams", false, value); }
    GCRenderGroom* GetGroomData() const { return GetSchemaValue<GCRenderGroom*>(m_ptr, "CRenderMesh", "m_pGroomData"); }
    void SetGroomData(GCRenderGroom* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'GroomData' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif