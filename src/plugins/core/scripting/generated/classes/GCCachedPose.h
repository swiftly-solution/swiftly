class GCCachedPose;

#ifndef _gcccachedpose_h
#define _gcccachedpose_h

#include "../../../scripting.h"




class GCCachedPose
{
private:
    void *m_ptr;

public:
    GCCachedPose() {}
    GCCachedPose(void *ptr) : m_ptr(ptr) {}

    std::vector<float32> GetMorphWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CCachedPose", "m_morphWeights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CCachedPose", "m_morphWeights", false, value); }
    float GetCycle() const { return GetSchemaValue<float>(m_ptr, "CCachedPose", "m_flCycle"); }
    void SetCycle(float value) { SetSchemaValue(m_ptr, "CCachedPose", "m_flCycle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif