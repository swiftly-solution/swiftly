class GAggregateSceneObject_t;

#ifndef _gcaggregatesceneobject_t_h
#define _gcaggregatesceneobject_t_h

#include "../../../scripting.h"

#include "../types/GObjectTypeFlags_t.h"
#include "GAggregateMeshInfo_t.h"
#include "GAggregateLODSetup_t.h"

class GAggregateSceneObject_t
{
private:
    void *m_ptr;

public:
    GAggregateSceneObject_t() {}
    GAggregateSceneObject_t(void *ptr) : m_ptr(ptr) {}

    ObjectTypeFlags_t GetAllFlags() const { return GetSchemaValue<ObjectTypeFlags_t>(m_ptr, "AggregateSceneObject_t", "m_allFlags"); }
    void SetAllFlags(ObjectTypeFlags_t value) { SetSchemaValue(m_ptr, "AggregateSceneObject_t", "m_allFlags", true, value); }
    ObjectTypeFlags_t GetAnyFlags() const { return GetSchemaValue<ObjectTypeFlags_t>(m_ptr, "AggregateSceneObject_t", "m_anyFlags"); }
    void SetAnyFlags(ObjectTypeFlags_t value) { SetSchemaValue(m_ptr, "AggregateSceneObject_t", "m_anyFlags", true, value); }
    int16_t GetLayer() const { return GetSchemaValue<int16_t>(m_ptr, "AggregateSceneObject_t", "m_nLayer"); }
    void SetLayer(int16_t value) { SetSchemaValue(m_ptr, "AggregateSceneObject_t", "m_nLayer", true, value); }
    std::vector<GAggregateMeshInfo_t> GetAggregateMeshes() const { CUtlVector<GAggregateMeshInfo_t>* vec = GetSchemaValue<CUtlVector<GAggregateMeshInfo_t>*>(m_ptr, "AggregateSceneObject_t", "m_aggregateMeshes"); std::vector<GAggregateMeshInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAggregateMeshes(std::vector<GAggregateMeshInfo_t> value) { SetSchemaValueCUtlVector<GAggregateMeshInfo_t>(m_ptr, "AggregateSceneObject_t", "m_aggregateMeshes", true, value); }
    std::vector<GAggregateLODSetup_t> GetLodSetups() const { CUtlVector<GAggregateLODSetup_t>* vec = GetSchemaValue<CUtlVector<GAggregateLODSetup_t>*>(m_ptr, "AggregateSceneObject_t", "m_lodSetups"); std::vector<GAggregateLODSetup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLodSetups(std::vector<GAggregateLODSetup_t> value) { SetSchemaValueCUtlVector<GAggregateLODSetup_t>(m_ptr, "AggregateSceneObject_t", "m_lodSetups", true, value); }
    std::vector<uint16> GetVisClusterMembership() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "AggregateSceneObject_t", "m_visClusterMembership"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVisClusterMembership(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "AggregateSceneObject_t", "m_visClusterMembership", true, value); }
    std::vector<matrix3x4_t> GetFragmentTransforms() const { CUtlVector<matrix3x4_t>* vec = GetSchemaValue<CUtlVector<matrix3x4_t>*>(m_ptr, "AggregateSceneObject_t", "m_fragmentTransforms"); std::vector<matrix3x4_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFragmentTransforms(std::vector<matrix3x4_t> value) { SetSchemaValueCUtlVector<matrix3x4_t>(m_ptr, "AggregateSceneObject_t", "m_fragmentTransforms", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif