class GVsInputSignatureElement_t;

#ifndef _gcvsinputsignatureelement_t_h
#define _gcvsinputsignatureelement_t_h

#include "../../../scripting.h"




class GVsInputSignatureElement_t
{
private:
    void *m_ptr;

public:
    GVsInputSignatureElement_t() {}
    GVsInputSignatureElement_t(void *ptr) : m_ptr(ptr) {}

    std::string GetName() const { return GetSchemaValue<char*>(m_ptr, "VsInputSignatureElement_t", "m_pName"); }
    void SetName(std::string value) { SetSchemaValue(m_ptr, "VsInputSignatureElement_t", "m_pName", true, value); }
    std::string GetSemantic() const { return GetSchemaValue<char*>(m_ptr, "VsInputSignatureElement_t", "m_pSemantic"); }
    void SetSemantic(std::string value) { SetSchemaValue(m_ptr, "VsInputSignatureElement_t", "m_pSemantic", true, value); }
    std::string GetD3DSemanticName() const { return GetSchemaValue<char*>(m_ptr, "VsInputSignatureElement_t", "m_pD3DSemanticName"); }
    void SetD3DSemanticName(std::string value) { SetSchemaValue(m_ptr, "VsInputSignatureElement_t", "m_pD3DSemanticName", true, value); }
    int32_t GetD3DSemanticIndex() const { return GetSchemaValue<int32_t>(m_ptr, "VsInputSignatureElement_t", "m_nD3DSemanticIndex"); }
    void SetD3DSemanticIndex(int32_t value) { SetSchemaValue(m_ptr, "VsInputSignatureElement_t", "m_nD3DSemanticIndex", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif