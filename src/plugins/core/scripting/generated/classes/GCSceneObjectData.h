class GCSceneObjectData;

#ifndef _gccsceneobjectdata_h
#define _gccsceneobjectdata_h

#include "../../../scripting.h"


#include "GCMaterialDrawDescriptor.h"
#include "GAABB_t.h"
#include "GCMeshletDescriptor.h"

class GCSceneObjectData
{
private:
    void *m_ptr;

public:
    GCSceneObjectData() {}
    GCSceneObjectData(void *ptr) : m_ptr(ptr) {}

    Vector GetMinBounds() const { return GetSchemaValue<Vector>(m_ptr, "CSceneObjectData", "m_vMinBounds"); }
    void SetMinBounds(Vector value) { SetSchemaValue(m_ptr, "CSceneObjectData", "m_vMinBounds", false, value); }
    Vector GetMaxBounds() const { return GetSchemaValue<Vector>(m_ptr, "CSceneObjectData", "m_vMaxBounds"); }
    void SetMaxBounds(Vector value) { SetSchemaValue(m_ptr, "CSceneObjectData", "m_vMaxBounds", false, value); }
    std::vector<GCMaterialDrawDescriptor> GetDrawCalls() const { CUtlVector<GCMaterialDrawDescriptor>* vec = GetSchemaValue<CUtlVector<GCMaterialDrawDescriptor>*>(m_ptr, "CSceneObjectData", "m_drawCalls"); std::vector<GCMaterialDrawDescriptor> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDrawCalls(std::vector<GCMaterialDrawDescriptor> value) { SetSchemaValueCUtlVector<GCMaterialDrawDescriptor>(m_ptr, "CSceneObjectData", "m_drawCalls", false, value); }
    std::vector<GAABB_t> GetDrawBounds() const { CUtlVector<GAABB_t>* vec = GetSchemaValue<CUtlVector<GAABB_t>*>(m_ptr, "CSceneObjectData", "m_drawBounds"); std::vector<GAABB_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDrawBounds(std::vector<GAABB_t> value) { SetSchemaValueCUtlVector<GAABB_t>(m_ptr, "CSceneObjectData", "m_drawBounds", false, value); }
    std::vector<GCMeshletDescriptor> GetMeshlets() const { CUtlVector<GCMeshletDescriptor>* vec = GetSchemaValue<CUtlVector<GCMeshletDescriptor>*>(m_ptr, "CSceneObjectData", "m_meshlets"); std::vector<GCMeshletDescriptor> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMeshlets(std::vector<GCMeshletDescriptor> value) { SetSchemaValueCUtlVector<GCMeshletDescriptor>(m_ptr, "CSceneObjectData", "m_meshlets", false, value); }
    Vector4D GetTintColor() const { return GetSchemaValue<Vector4D>(m_ptr, "CSceneObjectData", "m_vTintColor"); }
    void SetTintColor(Vector4D value) { SetSchemaValue(m_ptr, "CSceneObjectData", "m_vTintColor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif