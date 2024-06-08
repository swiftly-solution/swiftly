class GCAnimDesc;

#ifndef _gccanimdesc_h
#define _gccanimdesc_h

#include "../../../scripting.h"


#include "GCAnimDesc_Flag.h"
#include "GCAnimDesc.h"
#include "GCAnimEncodedFrames.h"
#include "GCAnimMovement.h"
#include "GCAnimEventDefinition.h"
#include "GCAnimActivity.h"
#include "GCAnimLocalHierarchy.h"
#include "GCAnimSequenceParams.h"

class GCAnimDesc
{
private:
    void *m_ptr;

public:
    GCAnimDesc() {}
    GCAnimDesc(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimDesc", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimDesc", "m_name", false, value); }
    GCAnimDesc_Flag GetFlags() const { return GetSchemaValue<GCAnimDesc_Flag>(m_ptr, "CAnimDesc", "m_flags"); }
    void SetFlags(GCAnimDesc_Flag value) { SetSchemaValue(m_ptr, "CAnimDesc", "m_flags", false, value); }
    float GetFps() const { return GetSchemaValue<float>(m_ptr, "CAnimDesc", "fps"); }
    void SetFps(float value) { SetSchemaValue(m_ptr, "CAnimDesc", "fps", false, value); }
    GCAnimEncodedFrames GetData() const { return GetSchemaValue<GCAnimEncodedFrames>(m_ptr, "CAnimDesc", "m_Data"); }
    void SetData(GCAnimEncodedFrames value) { SetSchemaValue(m_ptr, "CAnimDesc", "m_Data", false, value); }
    std::vector<GCAnimMovement> GetMovementArray() const { CUtlVector<GCAnimMovement>* vec = GetSchemaValue<CUtlVector<GCAnimMovement>*>(m_ptr, "CAnimDesc", "m_movementArray"); std::vector<GCAnimMovement> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMovementArray(std::vector<GCAnimMovement> value) { SetSchemaValueCUtlVector<GCAnimMovement>(m_ptr, "CAnimDesc", "m_movementArray", false, value); }
    std::vector<GCAnimEventDefinition> GetEventArray() const { CUtlVector<GCAnimEventDefinition>* vec = GetSchemaValue<CUtlVector<GCAnimEventDefinition>*>(m_ptr, "CAnimDesc", "m_eventArray"); std::vector<GCAnimEventDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEventArray(std::vector<GCAnimEventDefinition> value) { SetSchemaValueCUtlVector<GCAnimEventDefinition>(m_ptr, "CAnimDesc", "m_eventArray", false, value); }
    std::vector<GCAnimActivity> GetActivityArray() const { CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CAnimDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetActivityArray(std::vector<GCAnimActivity> value) { SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CAnimDesc", "m_activityArray", false, value); }
    std::vector<GCAnimLocalHierarchy> GetHierarchyArray() const { CUtlVector<GCAnimLocalHierarchy>* vec = GetSchemaValue<CUtlVector<GCAnimLocalHierarchy>*>(m_ptr, "CAnimDesc", "m_hierarchyArray"); std::vector<GCAnimLocalHierarchy> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHierarchyArray(std::vector<GCAnimLocalHierarchy> value) { SetSchemaValueCUtlVector<GCAnimLocalHierarchy>(m_ptr, "CAnimDesc", "m_hierarchyArray", false, value); }
    float GetFramestalltime() const { return GetSchemaValue<float>(m_ptr, "CAnimDesc", "framestalltime"); }
    void SetFramestalltime(float value) { SetSchemaValue(m_ptr, "CAnimDesc", "framestalltime", false, value); }
    Vector GetRootMin() const { return GetSchemaValue<Vector>(m_ptr, "CAnimDesc", "m_vecRootMin"); }
    void SetRootMin(Vector value) { SetSchemaValue(m_ptr, "CAnimDesc", "m_vecRootMin", false, value); }
    Vector GetRootMax() const { return GetSchemaValue<Vector>(m_ptr, "CAnimDesc", "m_vecRootMax"); }
    void SetRootMax(Vector value) { SetSchemaValue(m_ptr, "CAnimDesc", "m_vecRootMax", false, value); }
    std::vector<Vector> GetBoneWorldMin() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimDesc", "m_vecBoneWorldMin"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneWorldMin(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimDesc", "m_vecBoneWorldMin", false, value); }
    std::vector<Vector> GetBoneWorldMax() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimDesc", "m_vecBoneWorldMax"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneWorldMax(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimDesc", "m_vecBoneWorldMax", false, value); }
    GCAnimSequenceParams GetSequenceParams() const { return GetSchemaValue<GCAnimSequenceParams>(m_ptr, "CAnimDesc", "m_sequenceParams"); }
    void SetSequenceParams(GCAnimSequenceParams value) { SetSchemaValue(m_ptr, "CAnimDesc", "m_sequenceParams", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif