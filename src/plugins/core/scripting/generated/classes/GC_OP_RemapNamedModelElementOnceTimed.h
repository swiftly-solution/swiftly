class GC_OP_RemapNamedModelElementOnceTimed;

#ifndef _gcc_op_remapnamedmodelelementoncetimed_h
#define _gcc_op_remapnamedmodelelementoncetimed_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapNamedModelElementOnceTimed
{
private:
    void *m_ptr;

public:
    GC_OP_RemapNamedModelElementOnceTimed() {}
    GC_OP_RemapNamedModelElementOnceTimed(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetInNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_inNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_inNames", false, value); }
    std::vector<CUtlString> GetOutNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_outNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOutNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_outNames", false, value); }
    std::vector<CUtlString> GetFallbackNames() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_fallbackNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFallbackNames(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_fallbackNames", false, value); }
    bool GetModelFromRenderer() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_bModelFromRenderer"); }
    void SetModelFromRenderer(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_bModelFromRenderer", false, value); }
    bool GetProportional() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_bProportional"); }
    void SetProportional(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_bProportional", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_nFieldOutput", false, value); }
    float GetRemapTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_flRemapTime"); }
    void SetRemapTime(float value) { SetSchemaValue(m_ptr, "C_OP_RemapNamedModelElementOnceTimed", "m_flRemapTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif