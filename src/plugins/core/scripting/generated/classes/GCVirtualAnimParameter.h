class GCVirtualAnimParameter;

#ifndef _gccvirtualanimparameter_h
#define _gccvirtualanimparameter_h

#include "../../../scripting.h"

#include "../types/GAnimParamType_t.h"


class GCVirtualAnimParameter
{
private:
    void *m_ptr;

public:
    GCVirtualAnimParameter() {}
    GCVirtualAnimParameter(void *ptr) : m_ptr(ptr) {}

    CUtlString GetExpressionString() const { return GetSchemaValue<CUtlString>(m_ptr, "CVirtualAnimParameter", "m_expressionString"); }
    void SetExpressionString(CUtlString value) { SetSchemaValue(m_ptr, "CVirtualAnimParameter", "m_expressionString", false, value); }
    AnimParamType_t GetParamType() const { return GetSchemaValue<AnimParamType_t>(m_ptr, "CVirtualAnimParameter", "m_eParamType"); }
    void SetParamType(AnimParamType_t value) { SetSchemaValue(m_ptr, "CVirtualAnimParameter", "m_eParamType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif