class GCAnimSkeleton;

#ifndef _gccanimskeleton_h
#define _gccanimskeleton_h

#include "../../../scripting.h"


#include "GCAnimFoot.h"

class GCAnimSkeleton
{
private:
    void *m_ptr;

public:
    GCAnimSkeleton() {}
    GCAnimSkeleton(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetBoneNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CAnimSkeleton", "m_boneNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoneNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CAnimSkeleton", "m_boneNames", false, value); }
    std::vector<int32> GetParents() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimSkeleton", "m_parents"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParents(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimSkeleton", "m_parents", false, value); }
    std::vector<GCAnimFoot> GetFeet() const { CUtlVector<GCAnimFoot>* vec = GetSchemaValue<CUtlVector<GCAnimFoot>*>(m_ptr, "CAnimSkeleton", "m_feet"); std::vector<GCAnimFoot> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFeet(std::vector<GCAnimFoot> value) { SetSchemaValueCUtlVector<GCAnimFoot>(m_ptr, "CAnimSkeleton", "m_feet", false, value); }
    std::vector<CUtlString> GetMorphNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CAnimSkeleton", "m_morphNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CAnimSkeleton", "m_morphNames", false, value); }
    std::vector<int32> GetLodBoneCounts() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimSkeleton", "m_lodBoneCounts"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLodBoneCounts(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimSkeleton", "m_lodBoneCounts", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif