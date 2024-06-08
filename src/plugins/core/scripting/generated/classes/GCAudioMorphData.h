class GCAudioMorphData;

#ifndef _gccaudiomorphdata_h
#define _gccaudiomorphdata_h

#include "../../../scripting.h"




class GCAudioMorphData
{
private:
    void *m_ptr;

public:
    GCAudioMorphData() {}
    GCAudioMorphData(void *ptr) : m_ptr(ptr) {}

    std::vector<float32> GetTimes() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CAudioMorphData", "m_times"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTimes(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CAudioMorphData", "m_times", false, value); }
    std::vector<uint32> GetNameHashCodes() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAudioMorphData", "m_nameHashCodes"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNameHashCodes(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CAudioMorphData", "m_nameHashCodes", false, value); }
    std::vector<CUtlString> GetNameStrings() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CAudioMorphData", "m_nameStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNameStrings(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CAudioMorphData", "m_nameStrings", false, value); }
    float GetEaseIn() const { return GetSchemaValue<float>(m_ptr, "CAudioMorphData", "m_flEaseIn"); }
    void SetEaseIn(float value) { SetSchemaValue(m_ptr, "CAudioMorphData", "m_flEaseIn", false, value); }
    float GetEaseOut() const { return GetSchemaValue<float>(m_ptr, "CAudioMorphData", "m_flEaseOut"); }
    void SetEaseOut(float value) { SetSchemaValue(m_ptr, "CAudioMorphData", "m_flEaseOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif