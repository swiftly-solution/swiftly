class GVsInputSignature_t;

#ifndef _gcvsinputsignature_t_h
#define _gcvsinputsignature_t_h

#include "../../../scripting.h"


#include "GVsInputSignatureElement_t.h"

class GVsInputSignature_t
{
private:
    void *m_ptr;

public:
    GVsInputSignature_t() {}
    GVsInputSignature_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GVsInputSignatureElement_t> GetElems() const { CUtlVector<GVsInputSignatureElement_t>* vec = GetSchemaValue<CUtlVector<GVsInputSignatureElement_t>*>(m_ptr, "VsInputSignature_t", "m_elems"); std::vector<GVsInputSignatureElement_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetElems(std::vector<GVsInputSignatureElement_t> value) { SetSchemaValueCUtlVector<GVsInputSignatureElement_t>(m_ptr, "VsInputSignature_t", "m_elems", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif