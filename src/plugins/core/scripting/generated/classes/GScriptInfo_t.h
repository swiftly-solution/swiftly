class GScriptInfo_t;

#ifndef _gcscriptinfo_t_h
#define _gcscriptinfo_t_h

#include "../../../scripting.h"

#include "../types/GAnimScriptType.h"
#include "GCAnimParamHandle.h"

class GScriptInfo_t
{
private:
    void *m_ptr;

public:
    GScriptInfo_t() {}
    GScriptInfo_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetCode() const { return GetSchemaValue<CUtlString>(m_ptr, "ScriptInfo_t", "m_code"); }
    void SetCode(CUtlString value) { SetSchemaValue(m_ptr, "ScriptInfo_t", "m_code", true, value); }
    std::vector<GCAnimParamHandle> GetParamsModified() const { CUtlVector<GCAnimParamHandle>* vec = GetSchemaValue<CUtlVector<GCAnimParamHandle>*>(m_ptr, "ScriptInfo_t", "m_paramsModified"); std::vector<GCAnimParamHandle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParamsModified(std::vector<GCAnimParamHandle> value) { SetSchemaValueCUtlVector<GCAnimParamHandle>(m_ptr, "ScriptInfo_t", "m_paramsModified", true, value); }
    std::vector<int32> GetProxyReadParams() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "ScriptInfo_t", "m_proxyReadParams"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetProxyReadParams(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "ScriptInfo_t", "m_proxyReadParams", true, value); }
    std::vector<int32> GetProxyWriteParams() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "ScriptInfo_t", "m_proxyWriteParams"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetProxyWriteParams(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "ScriptInfo_t", "m_proxyWriteParams", true, value); }
    AnimScriptType GetScriptType() const { return GetSchemaValue<AnimScriptType>(m_ptr, "ScriptInfo_t", "m_eScriptType"); }
    void SetScriptType(AnimScriptType value) { SetSchemaValue(m_ptr, "ScriptInfo_t", "m_eScriptType", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif