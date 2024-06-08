class GCFuseSymbolTable;

#ifndef _gccfusesymboltable_h
#define _gccfusesymboltable_h

#include "../../../scripting.h"


#include "GConstantInfo_t.h"
#include "GVariableInfo_t.h"
#include "GFunctionInfo_t.h"

class GCFuseSymbolTable
{
private:
    void *m_ptr;

public:
    GCFuseSymbolTable() {}
    GCFuseSymbolTable(void *ptr) : m_ptr(ptr) {}

    std::vector<GConstantInfo_t> GetConstants() const { CUtlVector<GConstantInfo_t>* vec = GetSchemaValue<CUtlVector<GConstantInfo_t>*>(m_ptr, "CFuseSymbolTable", "m_constants"); std::vector<GConstantInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConstants(std::vector<GConstantInfo_t> value) { SetSchemaValueCUtlVector<GConstantInfo_t>(m_ptr, "CFuseSymbolTable", "m_constants", false, value); }
    std::vector<GVariableInfo_t> GetVariables() const { CUtlVector<GVariableInfo_t>* vec = GetSchemaValue<CUtlVector<GVariableInfo_t>*>(m_ptr, "CFuseSymbolTable", "m_variables"); std::vector<GVariableInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVariables(std::vector<GVariableInfo_t> value) { SetSchemaValueCUtlVector<GVariableInfo_t>(m_ptr, "CFuseSymbolTable", "m_variables", false, value); }
    std::vector<GFunctionInfo_t> GetFunctions() const { CUtlVector<GFunctionInfo_t>* vec = GetSchemaValue<CUtlVector<GFunctionInfo_t>*>(m_ptr, "CFuseSymbolTable", "m_functions"); std::vector<GFunctionInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFunctions(std::vector<GFunctionInfo_t> value) { SetSchemaValueCUtlVector<GFunctionInfo_t>(m_ptr, "CFuseSymbolTable", "m_functions", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif