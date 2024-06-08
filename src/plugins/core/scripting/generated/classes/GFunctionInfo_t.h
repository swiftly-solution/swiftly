class GFunctionInfo_t;

#ifndef _gcfunctioninfo_t_h
#define _gcfunctioninfo_t_h

#include "../../../scripting.h"


#include "GFuseFunctionIndex_t.h"

class GFunctionInfo_t
{
private:
    void *m_ptr;

public:
    GFunctionInfo_t() {}
    GFunctionInfo_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "FunctionInfo_t", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "FunctionInfo_t", "m_name", true, value); }
    CUtlStringToken GetNameToken() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "FunctionInfo_t", "m_nameToken"); }
    void SetNameToken(CUtlStringToken value) { SetSchemaValue(m_ptr, "FunctionInfo_t", "m_nameToken", true, value); }
    int32_t GetParamCount() const { return GetSchemaValue<int32_t>(m_ptr, "FunctionInfo_t", "m_nParamCount"); }
    void SetParamCount(int32_t value) { SetSchemaValue(m_ptr, "FunctionInfo_t", "m_nParamCount", true, value); }
    GFuseFunctionIndex_t GetIndex() const { return GetSchemaValue<GFuseFunctionIndex_t>(m_ptr, "FunctionInfo_t", "m_nIndex"); }
    void SetIndex(GFuseFunctionIndex_t value) { SetSchemaValue(m_ptr, "FunctionInfo_t", "m_nIndex", true, value); }
    bool GetIsPure() const { return GetSchemaValue<bool>(m_ptr, "FunctionInfo_t", "m_bIsPure"); }
    void SetIsPure(bool value) { SetSchemaValue(m_ptr, "FunctionInfo_t", "m_bIsPure", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif