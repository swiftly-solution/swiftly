class GMaterialResourceData_t;

#ifndef _gcmaterialresourcedata_t_h
#define _gcmaterialresourcedata_t_h

#include "../../../scripting.h"


#include "GMaterialParamInt_t.h"
#include "GMaterialParamFloat_t.h"
#include "GMaterialParamVector_t.h"
#include "GMaterialParamTexture_t.h"
#include "GMaterialParamBuffer_t.h"
#include "GMaterialParamString_t.h"

class GMaterialResourceData_t
{
private:
    void *m_ptr;

public:
    GMaterialResourceData_t() {}
    GMaterialResourceData_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetMaterialName() const { return GetSchemaValue<CUtlString>(m_ptr, "MaterialResourceData_t", "m_materialName"); }
    void SetMaterialName(CUtlString value) { SetSchemaValue(m_ptr, "MaterialResourceData_t", "m_materialName", true, value); }
    CUtlString GetShaderName() const { return GetSchemaValue<CUtlString>(m_ptr, "MaterialResourceData_t", "m_shaderName"); }
    void SetShaderName(CUtlString value) { SetSchemaValue(m_ptr, "MaterialResourceData_t", "m_shaderName", true, value); }
    std::vector<GMaterialParamInt_t> GetIntParams() const { CUtlVector<GMaterialParamInt_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamInt_t>*>(m_ptr, "MaterialResourceData_t", "m_intParams"); std::vector<GMaterialParamInt_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetIntParams(std::vector<GMaterialParamInt_t> value) { SetSchemaValueCUtlVector<GMaterialParamInt_t>(m_ptr, "MaterialResourceData_t", "m_intParams", true, value); }
    std::vector<GMaterialParamFloat_t> GetFloatParams() const { CUtlVector<GMaterialParamFloat_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamFloat_t>*>(m_ptr, "MaterialResourceData_t", "m_floatParams"); std::vector<GMaterialParamFloat_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFloatParams(std::vector<GMaterialParamFloat_t> value) { SetSchemaValueCUtlVector<GMaterialParamFloat_t>(m_ptr, "MaterialResourceData_t", "m_floatParams", true, value); }
    std::vector<GMaterialParamVector_t> GetVectorParams() const { CUtlVector<GMaterialParamVector_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamVector_t>*>(m_ptr, "MaterialResourceData_t", "m_vectorParams"); std::vector<GMaterialParamVector_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVectorParams(std::vector<GMaterialParamVector_t> value) { SetSchemaValueCUtlVector<GMaterialParamVector_t>(m_ptr, "MaterialResourceData_t", "m_vectorParams", true, value); }
    std::vector<GMaterialParamTexture_t> GetTextureParams() const { CUtlVector<GMaterialParamTexture_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamTexture_t>*>(m_ptr, "MaterialResourceData_t", "m_textureParams"); std::vector<GMaterialParamTexture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTextureParams(std::vector<GMaterialParamTexture_t> value) { SetSchemaValueCUtlVector<GMaterialParamTexture_t>(m_ptr, "MaterialResourceData_t", "m_textureParams", true, value); }
    std::vector<GMaterialParamBuffer_t> GetDynamicParams() const { CUtlVector<GMaterialParamBuffer_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamBuffer_t>*>(m_ptr, "MaterialResourceData_t", "m_dynamicParams"); std::vector<GMaterialParamBuffer_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDynamicParams(std::vector<GMaterialParamBuffer_t> value) { SetSchemaValueCUtlVector<GMaterialParamBuffer_t>(m_ptr, "MaterialResourceData_t", "m_dynamicParams", true, value); }
    std::vector<GMaterialParamBuffer_t> GetDynamicTextureParams() const { CUtlVector<GMaterialParamBuffer_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamBuffer_t>*>(m_ptr, "MaterialResourceData_t", "m_dynamicTextureParams"); std::vector<GMaterialParamBuffer_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDynamicTextureParams(std::vector<GMaterialParamBuffer_t> value) { SetSchemaValueCUtlVector<GMaterialParamBuffer_t>(m_ptr, "MaterialResourceData_t", "m_dynamicTextureParams", true, value); }
    std::vector<GMaterialParamInt_t> GetIntAttributes() const { CUtlVector<GMaterialParamInt_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamInt_t>*>(m_ptr, "MaterialResourceData_t", "m_intAttributes"); std::vector<GMaterialParamInt_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetIntAttributes(std::vector<GMaterialParamInt_t> value) { SetSchemaValueCUtlVector<GMaterialParamInt_t>(m_ptr, "MaterialResourceData_t", "m_intAttributes", true, value); }
    std::vector<GMaterialParamFloat_t> GetFloatAttributes() const { CUtlVector<GMaterialParamFloat_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamFloat_t>*>(m_ptr, "MaterialResourceData_t", "m_floatAttributes"); std::vector<GMaterialParamFloat_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFloatAttributes(std::vector<GMaterialParamFloat_t> value) { SetSchemaValueCUtlVector<GMaterialParamFloat_t>(m_ptr, "MaterialResourceData_t", "m_floatAttributes", true, value); }
    std::vector<GMaterialParamVector_t> GetVectorAttributes() const { CUtlVector<GMaterialParamVector_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamVector_t>*>(m_ptr, "MaterialResourceData_t", "m_vectorAttributes"); std::vector<GMaterialParamVector_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVectorAttributes(std::vector<GMaterialParamVector_t> value) { SetSchemaValueCUtlVector<GMaterialParamVector_t>(m_ptr, "MaterialResourceData_t", "m_vectorAttributes", true, value); }
    std::vector<GMaterialParamTexture_t> GetTextureAttributes() const { CUtlVector<GMaterialParamTexture_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamTexture_t>*>(m_ptr, "MaterialResourceData_t", "m_textureAttributes"); std::vector<GMaterialParamTexture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTextureAttributes(std::vector<GMaterialParamTexture_t> value) { SetSchemaValueCUtlVector<GMaterialParamTexture_t>(m_ptr, "MaterialResourceData_t", "m_textureAttributes", true, value); }
    std::vector<GMaterialParamString_t> GetStringAttributes() const { CUtlVector<GMaterialParamString_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamString_t>*>(m_ptr, "MaterialResourceData_t", "m_stringAttributes"); std::vector<GMaterialParamString_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetStringAttributes(std::vector<GMaterialParamString_t> value) { SetSchemaValueCUtlVector<GMaterialParamString_t>(m_ptr, "MaterialResourceData_t", "m_stringAttributes", true, value); }
    std::vector<CUtlString> GetRenderAttributesUsed() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "MaterialResourceData_t", "m_renderAttributesUsed"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRenderAttributesUsed(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "MaterialResourceData_t", "m_renderAttributesUsed", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif