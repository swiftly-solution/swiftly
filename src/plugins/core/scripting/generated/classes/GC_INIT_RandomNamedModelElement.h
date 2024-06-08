class GC_INIT_RandomNamedModelElement;

#ifndef _gcc_init_randomnamedmodelelement_h
#define _gcc_init_randomnamedmodelelement_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_RandomNamedModelElement
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomNamedModelElement() {}
    GC_INIT_RandomNamedModelElement(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "C_INIT_RandomNamedModelElement", "m_names"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "C_INIT_RandomNamedModelElement", "m_names", false, value); }
    bool GetShuffle() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RandomNamedModelElement", "m_bShuffle"); }
    void SetShuffle(bool value) { SetSchemaValue(m_ptr, "C_INIT_RandomNamedModelElement", "m_bShuffle", false, value); }
    bool GetLinear() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RandomNamedModelElement", "m_bLinear"); }
    void SetLinear(bool value) { SetSchemaValue(m_ptr, "C_INIT_RandomNamedModelElement", "m_bLinear", false, value); }
    bool GetModelFromRenderer() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RandomNamedModelElement", "m_bModelFromRenderer"); }
    void SetModelFromRenderer(bool value) { SetSchemaValue(m_ptr, "C_INIT_RandomNamedModelElement", "m_bModelFromRenderer", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RandomNamedModelElement", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomNamedModelElement", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif