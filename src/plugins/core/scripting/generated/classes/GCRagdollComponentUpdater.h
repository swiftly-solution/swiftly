class GCRagdollComponentUpdater;

#ifndef _gccragdollcomponentupdater_h
#define _gccragdollcomponentupdater_h

#include "../../../scripting.h"


#include "GCAnimNodePath.h"
#include "GWeightList.h"

class GCRagdollComponentUpdater
{
private:
    void *m_ptr;

public:
    GCRagdollComponentUpdater() {}
    GCRagdollComponentUpdater(void *ptr) : m_ptr(ptr) {}

    std::vector<GCAnimNodePath> GetRagdollNodePaths() const { CUtlVector<GCAnimNodePath>* vec = GetSchemaValue<CUtlVector<GCAnimNodePath>*>(m_ptr, "CRagdollComponentUpdater", "m_ragdollNodePaths"); std::vector<GCAnimNodePath> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRagdollNodePaths(std::vector<GCAnimNodePath> value) { SetSchemaValueCUtlVector<GCAnimNodePath>(m_ptr, "CRagdollComponentUpdater", "m_ragdollNodePaths", false, value); }
    std::vector<int32> GetBoneIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CRagdollComponentUpdater", "m_boneIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CRagdollComponentUpdater", "m_boneIndices", false, value); }
    std::vector<CUtlString> GetBoneNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CRagdollComponentUpdater", "m_boneNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CRagdollComponentUpdater", "m_boneNames", false, value); }
    std::vector<GWeightList> GetWeightLists() const { CUtlVector<GWeightList>* vec = GetSchemaValue<CUtlVector<GWeightList>*>(m_ptr, "CRagdollComponentUpdater", "m_weightLists"); std::vector<GWeightList> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeightLists(std::vector<GWeightList> value) { SetSchemaValueCUtlVector<GWeightList>(m_ptr, "CRagdollComponentUpdater", "m_weightLists", false, value); }
    float GetSpringFrequencyMin() const { return GetSchemaValue<float>(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMin"); }
    void SetSpringFrequencyMin(float value) { SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMin", false, value); }
    float GetSpringFrequencyMax() const { return GetSchemaValue<float>(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMax"); }
    void SetSpringFrequencyMax(float value) { SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMax", false, value); }
    float GetMaxStretch() const { return GetSchemaValue<float>(m_ptr, "CRagdollComponentUpdater", "m_flMaxStretch"); }
    void SetMaxStretch(float value) { SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_flMaxStretch", false, value); }
    bool GetSolidCollisionAtZeroWeight() const { return GetSchemaValue<bool>(m_ptr, "CRagdollComponentUpdater", "m_bSolidCollisionAtZeroWeight"); }
    void SetSolidCollisionAtZeroWeight(bool value) { SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_bSolidCollisionAtZeroWeight", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif