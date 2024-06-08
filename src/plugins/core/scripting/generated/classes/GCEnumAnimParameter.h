class GCEnumAnimParameter;

#ifndef _gccenumanimparameter_h
#define _gccenumanimparameter_h

#include "../../../scripting.h"




class GCEnumAnimParameter
{
private:
    void *m_ptr;

public:
    GCEnumAnimParameter() {}
    GCEnumAnimParameter(void *ptr) : m_ptr(ptr) {}

    uint8_t GetDefaultValue() const { return GetSchemaValue<uint8_t>(m_ptr, "CEnumAnimParameter", "m_defaultValue"); }
    void SetDefaultValue(uint8_t value) { SetSchemaValue(m_ptr, "CEnumAnimParameter", "m_defaultValue", false, value); }
    std::vector<CUtlString> GetEnumOptions() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CEnumAnimParameter", "m_enumOptions"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEnumOptions(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CEnumAnimParameter", "m_enumOptions", false, value); }
    std::vector<uint64> GetEnumReferenced() const { CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "CEnumAnimParameter", "m_vecEnumReferenced"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEnumReferenced(std::vector<uint64> value) { SetSchemaValueCUtlVector<uint64>(m_ptr, "CEnumAnimParameter", "m_vecEnumReferenced", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif