class GCompositeMaterialAssemblyProcedure_t;

#ifndef _gccompositematerialassemblyprocedure_t_h
#define _gccompositematerialassemblyprocedure_t_h

#include "../../../scripting.h"


#include "GCompositeMaterialMatchFilter_t.h"
#include "GCompositeMaterialInputContainer_t.h"
#include "GCompMatPropertyMutator_t.h"

class GCompositeMaterialAssemblyProcedure_t
{
private:
    void *m_ptr;

public:
    GCompositeMaterialAssemblyProcedure_t() {}
    GCompositeMaterialAssemblyProcedure_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GCompositeMaterialMatchFilter_t> GetMatchFilters() const { CUtlVector<GCompositeMaterialMatchFilter_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialMatchFilter_t>*>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecMatchFilters"); std::vector<GCompositeMaterialMatchFilter_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMatchFilters(std::vector<GCompositeMaterialMatchFilter_t> value) { SetSchemaValueCUtlVector<GCompositeMaterialMatchFilter_t>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecMatchFilters", true, value); }
    std::vector<GCompositeMaterialInputContainer_t> GetCompositeInputContainers() const { CUtlVector<GCompositeMaterialInputContainer_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialInputContainer_t>*>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecCompositeInputContainers"); std::vector<GCompositeMaterialInputContainer_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCompositeInputContainers(std::vector<GCompositeMaterialInputContainer_t> value) { SetSchemaValueCUtlVector<GCompositeMaterialInputContainer_t>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecCompositeInputContainers", true, value); }
    std::vector<GCompMatPropertyMutator_t> GetPropertyMutators() const { CUtlVector<GCompMatPropertyMutator_t>* vec = GetSchemaValue<CUtlVector<GCompMatPropertyMutator_t>*>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecPropertyMutators"); std::vector<GCompMatPropertyMutator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPropertyMutators(std::vector<GCompMatPropertyMutator_t> value) { SetSchemaValueCUtlVector<GCompMatPropertyMutator_t>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecPropertyMutators", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif