class GCModelConfigElement_UserPick;

#ifndef _gccmodelconfigelement_userpick_h
#define _gccmodelconfigelement_userpick_h

#include "../../../scripting.h"




class GCModelConfigElement_UserPick
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_UserPick() {}
    GCModelConfigElement_UserPick(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetChoices() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CModelConfigElement_UserPick", "m_Choices"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChoices(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CModelConfigElement_UserPick", "m_Choices", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif