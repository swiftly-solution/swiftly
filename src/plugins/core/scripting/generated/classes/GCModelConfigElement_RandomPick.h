class GCModelConfigElement_RandomPick;

#ifndef _gccmodelconfigelement_randompick_h
#define _gccmodelconfigelement_randompick_h

#include "../../../scripting.h"




class GCModelConfigElement_RandomPick
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_RandomPick() {}
    GCModelConfigElement_RandomPick(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetChoices() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CModelConfigElement_RandomPick", "m_Choices"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChoices(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CModelConfigElement_RandomPick", "m_Choices", false, value); }
    std::vector<float32> GetChoiceWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CModelConfigElement_RandomPick", "m_ChoiceWeights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChoiceWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CModelConfigElement_RandomPick", "m_ChoiceWeights", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif