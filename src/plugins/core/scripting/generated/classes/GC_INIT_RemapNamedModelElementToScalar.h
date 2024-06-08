class GC_INIT_RemapNamedModelElementToScalar;

#ifndef _gcc_init_remapnamedmodelelementtoscalar_h
#define _gcc_init_remapnamedmodelelementtoscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_RemapNamedModelElementToScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapNamedModelElementToScalar() {}
    GC_INIT_RemapNamedModelElementToScalar(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_names"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_names", false, value); }
    std::vector<float32> GetValues() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_values"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetValues(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_values", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_nFieldOutput", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_nSetMethod", false, value); }
    bool GetModelFromRenderer() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_bModelFromRenderer"); }
    void SetModelFromRenderer(bool value) { SetSchemaValue(m_ptr, "C_INIT_RemapNamedModelElementToScalar", "m_bModelFromRenderer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif