class GCFuseProgram;

#ifndef _gccfuseprogram_h
#define _gccfuseprogram_h

#include "../../../scripting.h"


#include "GFuseVariableIndex_t.h"

class GCFuseProgram
{
private:
    void *m_ptr;

public:
    GCFuseProgram() {}
    GCFuseProgram(void *ptr) : m_ptr(ptr) {}

    std::vector<uint8> GetProgramBuffer() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CFuseProgram", "m_programBuffer"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetProgramBuffer(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CFuseProgram", "m_programBuffer", false, value); }
    std::vector<GFuseVariableIndex_t> GetVariablesRead() const { CUtlVector<GFuseVariableIndex_t>* vec = GetSchemaValue<CUtlVector<GFuseVariableIndex_t>*>(m_ptr, "CFuseProgram", "m_variablesRead"); std::vector<GFuseVariableIndex_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVariablesRead(std::vector<GFuseVariableIndex_t> value) { SetSchemaValueCUtlVector<GFuseVariableIndex_t>(m_ptr, "CFuseProgram", "m_variablesRead", false, value); }
    std::vector<GFuseVariableIndex_t> GetVariablesWritten() const { CUtlVector<GFuseVariableIndex_t>* vec = GetSchemaValue<CUtlVector<GFuseVariableIndex_t>*>(m_ptr, "CFuseProgram", "m_variablesWritten"); std::vector<GFuseVariableIndex_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVariablesWritten(std::vector<GFuseVariableIndex_t> value) { SetSchemaValueCUtlVector<GFuseVariableIndex_t>(m_ptr, "CFuseProgram", "m_variablesWritten", false, value); }
    int32_t GetMaxTempVarsUsed() const { return GetSchemaValue<int32_t>(m_ptr, "CFuseProgram", "m_nMaxTempVarsUsed"); }
    void SetMaxTempVarsUsed(int32_t value) { SetSchemaValue(m_ptr, "CFuseProgram", "m_nMaxTempVarsUsed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif