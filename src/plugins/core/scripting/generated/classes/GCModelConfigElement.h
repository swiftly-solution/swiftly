class GCModelConfigElement;

#ifndef _gccmodelconfigelement_h
#define _gccmodelconfigelement_h

#include "../../../scripting.h"


#include "GCModelConfigElement.h"
#include "GCModelConfig.h"

class GCModelConfigElement
{
private:
    void *m_ptr;

public:
    GCModelConfigElement() {}
    GCModelConfigElement(void *ptr) : m_ptr(ptr) {}

    CUtlString GetElementName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement", "m_ElementName"); }
    void SetElementName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement", "m_ElementName", false, value); }
    std::vector<GCModelConfigElement*> GetNestedElements() const { CUtlVector<GCModelConfigElement*>* vec = GetSchemaValue<CUtlVector<GCModelConfigElement*>*>(m_ptr, "CModelConfigElement", "m_NestedElements"); std::vector<GCModelConfigElement*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNestedElements(std::vector<GCModelConfigElement*> value) { SetSchemaValueCUtlVector<GCModelConfigElement*>(m_ptr, "CModelConfigElement", "m_NestedElements", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif