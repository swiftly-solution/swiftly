class GCompositeMaterialInputContainer_t;

#ifndef _gccompositematerialinputcontainer_t_h
#define _gccompositematerialinputcontainer_t_h

#include "../../../scripting.h"

#include "../types/GCompositeMaterialInputContainerSourceType_t.h"
#include "GCompositeMaterialInputLooseVariable_t.h"

class GCompositeMaterialInputContainer_t
{
private:
    void *m_ptr;

public:
    GCompositeMaterialInputContainer_t() {}
    GCompositeMaterialInputContainer_t(void *ptr) : m_ptr(ptr) {}

    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputContainer_t", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_bEnabled", true, value); }
    CompositeMaterialInputContainerSourceType_t GetCompositeMaterialInputContainerSourceType() const { return GetSchemaValue<CompositeMaterialInputContainerSourceType_t>(m_ptr, "CompositeMaterialInputContainer_t", "m_nCompositeMaterialInputContainerSourceType"); }
    void SetCompositeMaterialInputContainerSourceType(CompositeMaterialInputContainerSourceType_t value) { SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_nCompositeMaterialInputContainerSourceType", true, value); }
    CUtlString GetStrAttrName() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrName"); }
    void SetStrAttrName(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrName", true, value); }
    CUtlString GetStrAlias() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputContainer_t", "m_strAlias"); }
    void SetStrAlias(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_strAlias", true, value); }
    std::vector<GCompositeMaterialInputLooseVariable_t> GetLooseVariables() const { CUtlVector<GCompositeMaterialInputLooseVariable_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialInputLooseVariable_t>*>(m_ptr, "CompositeMaterialInputContainer_t", "m_vecLooseVariables"); std::vector<GCompositeMaterialInputLooseVariable_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLooseVariables(std::vector<GCompositeMaterialInputLooseVariable_t> value) { SetSchemaValueCUtlVector<GCompositeMaterialInputLooseVariable_t>(m_ptr, "CompositeMaterialInputContainer_t", "m_vecLooseVariables", true, value); }
    CUtlString GetStrAttrNameForVar() const { return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrNameForVar"); }
    void SetStrAttrNameForVar(CUtlString value) { SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_strAttrNameForVar", true, value); }
    bool GetExposeExternally() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputContainer_t", "m_bExposeExternally"); }
    void SetExposeExternally(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialInputContainer_t", "m_bExposeExternally", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif