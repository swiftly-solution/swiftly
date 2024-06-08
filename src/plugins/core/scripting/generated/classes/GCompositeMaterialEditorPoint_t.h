class GCompositeMaterialEditorPoint_t;

#ifndef _gccompositematerialeditorpoint_t_h
#define _gccompositematerialeditorpoint_t_h

#include "../../../scripting.h"


#include "GCompositeMaterialAssemblyProcedure_t.h"
#include "GCompositeMaterial_t.h"

class GCompositeMaterialEditorPoint_t
{
private:
    void *m_ptr;

public:
    GCompositeMaterialEditorPoint_t() {}
    GCompositeMaterialEditorPoint_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetSequenceIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialEditorPoint_t", "m_nSequenceIndex"); }
    void SetSequenceIndex(int32_t value) { SetSchemaValue(m_ptr, "CompositeMaterialEditorPoint_t", "m_nSequenceIndex", true, value); }
    float GetCycle() const { return GetSchemaValue<float>(m_ptr, "CompositeMaterialEditorPoint_t", "m_flCycle"); }
    void SetCycle(float value) { SetSchemaValue(m_ptr, "CompositeMaterialEditorPoint_t", "m_flCycle", true, value); }
    bool GetEnableChildModel() const { return GetSchemaValue<bool>(m_ptr, "CompositeMaterialEditorPoint_t", "m_bEnableChildModel"); }
    void SetEnableChildModel(bool value) { SetSchemaValue(m_ptr, "CompositeMaterialEditorPoint_t", "m_bEnableChildModel", true, value); }
    std::vector<GCompositeMaterialAssemblyProcedure_t> GetCompositeMaterialAssemblyProcedures() const { CUtlVector<GCompositeMaterialAssemblyProcedure_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialAssemblyProcedure_t>*>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterialAssemblyProcedures"); std::vector<GCompositeMaterialAssemblyProcedure_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCompositeMaterialAssemblyProcedures(std::vector<GCompositeMaterialAssemblyProcedure_t> value) { SetSchemaValueCUtlVector<GCompositeMaterialAssemblyProcedure_t>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterialAssemblyProcedures", true, value); }
    std::vector<GCompositeMaterial_t> GetCompositeMaterials() const { CUtlVector<GCompositeMaterial_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterial_t>*>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterials"); std::vector<GCompositeMaterial_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCompositeMaterials(std::vector<GCompositeMaterial_t> value) { SetSchemaValueCUtlVector<GCompositeMaterial_t>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterials", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif