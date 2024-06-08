class GCCompositeMaterialEditorDoc;

#ifndef _gcccompositematerialeditordoc_h
#define _gcccompositematerialeditordoc_h

#include "../../../scripting.h"


#include "GCompositeMaterialEditorPoint_t.h"

class GCCompositeMaterialEditorDoc
{
private:
    void *m_ptr;

public:
    GCCompositeMaterialEditorDoc() {}
    GCCompositeMaterialEditorDoc(void *ptr) : m_ptr(ptr) {}

    int32_t GetVersion() const { return GetSchemaValue<int32_t>(m_ptr, "CCompositeMaterialEditorDoc", "m_nVersion"); }
    void SetVersion(int32_t value) { SetSchemaValue(m_ptr, "CCompositeMaterialEditorDoc", "m_nVersion", false, value); }
    std::vector<GCompositeMaterialEditorPoint_t> GetPoints() const { CUtlVector<GCompositeMaterialEditorPoint_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialEditorPoint_t>*>(m_ptr, "CCompositeMaterialEditorDoc", "m_Points"); std::vector<GCompositeMaterialEditorPoint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPoints(std::vector<GCompositeMaterialEditorPoint_t> value) { SetSchemaValueCUtlVector<GCompositeMaterialEditorPoint_t>(m_ptr, "CCompositeMaterialEditorDoc", "m_Points", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif