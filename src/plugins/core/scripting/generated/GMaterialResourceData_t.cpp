#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GMaterialResourceData_t::GMaterialResourceData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GMaterialResourceData_t::GMaterialResourceData_t(void *ptr) {
    m_ptr = ptr;
}
std::string GMaterialResourceData_t::GetMaterialName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "MaterialResourceData_t", "m_materialName").Get();
}
void GMaterialResourceData_t::SetMaterialName(std::string value) {
    SetSchemaValue(m_ptr, "MaterialResourceData_t", "m_materialName", true, CUtlString(value.c_str()));
}
std::string GMaterialResourceData_t::GetShaderName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "MaterialResourceData_t", "m_shaderName").Get();
}
void GMaterialResourceData_t::SetShaderName(std::string value) {
    SetSchemaValue(m_ptr, "MaterialResourceData_t", "m_shaderName", true, CUtlString(value.c_str()));
}
std::vector<GMaterialParamInt_t> GMaterialResourceData_t::GetIntParams() const {
    CUtlVector<GMaterialParamInt_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamInt_t>*>(m_ptr, "MaterialResourceData_t", "m_intParams"); std::vector<GMaterialParamInt_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetIntParams(std::vector<GMaterialParamInt_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamInt_t>(m_ptr, "MaterialResourceData_t", "m_intParams", true, value);
}
std::vector<GMaterialParamFloat_t> GMaterialResourceData_t::GetFloatParams() const {
    CUtlVector<GMaterialParamFloat_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamFloat_t>*>(m_ptr, "MaterialResourceData_t", "m_floatParams"); std::vector<GMaterialParamFloat_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetFloatParams(std::vector<GMaterialParamFloat_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamFloat_t>(m_ptr, "MaterialResourceData_t", "m_floatParams", true, value);
}
std::vector<GMaterialParamVector_t> GMaterialResourceData_t::GetVectorParams() const {
    CUtlVector<GMaterialParamVector_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamVector_t>*>(m_ptr, "MaterialResourceData_t", "m_vectorParams"); std::vector<GMaterialParamVector_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetVectorParams(std::vector<GMaterialParamVector_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamVector_t>(m_ptr, "MaterialResourceData_t", "m_vectorParams", true, value);
}
std::vector<GMaterialParamTexture_t> GMaterialResourceData_t::GetTextureParams() const {
    CUtlVector<GMaterialParamTexture_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamTexture_t>*>(m_ptr, "MaterialResourceData_t", "m_textureParams"); std::vector<GMaterialParamTexture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetTextureParams(std::vector<GMaterialParamTexture_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamTexture_t>(m_ptr, "MaterialResourceData_t", "m_textureParams", true, value);
}
std::vector<GMaterialParamBuffer_t> GMaterialResourceData_t::GetDynamicParams() const {
    CUtlVector<GMaterialParamBuffer_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamBuffer_t>*>(m_ptr, "MaterialResourceData_t", "m_dynamicParams"); std::vector<GMaterialParamBuffer_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetDynamicParams(std::vector<GMaterialParamBuffer_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamBuffer_t>(m_ptr, "MaterialResourceData_t", "m_dynamicParams", true, value);
}
std::vector<GMaterialParamBuffer_t> GMaterialResourceData_t::GetDynamicTextureParams() const {
    CUtlVector<GMaterialParamBuffer_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamBuffer_t>*>(m_ptr, "MaterialResourceData_t", "m_dynamicTextureParams"); std::vector<GMaterialParamBuffer_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetDynamicTextureParams(std::vector<GMaterialParamBuffer_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamBuffer_t>(m_ptr, "MaterialResourceData_t", "m_dynamicTextureParams", true, value);
}
std::vector<GMaterialParamInt_t> GMaterialResourceData_t::GetIntAttributes() const {
    CUtlVector<GMaterialParamInt_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamInt_t>*>(m_ptr, "MaterialResourceData_t", "m_intAttributes"); std::vector<GMaterialParamInt_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetIntAttributes(std::vector<GMaterialParamInt_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamInt_t>(m_ptr, "MaterialResourceData_t", "m_intAttributes", true, value);
}
std::vector<GMaterialParamFloat_t> GMaterialResourceData_t::GetFloatAttributes() const {
    CUtlVector<GMaterialParamFloat_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamFloat_t>*>(m_ptr, "MaterialResourceData_t", "m_floatAttributes"); std::vector<GMaterialParamFloat_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetFloatAttributes(std::vector<GMaterialParamFloat_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamFloat_t>(m_ptr, "MaterialResourceData_t", "m_floatAttributes", true, value);
}
std::vector<GMaterialParamVector_t> GMaterialResourceData_t::GetVectorAttributes() const {
    CUtlVector<GMaterialParamVector_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamVector_t>*>(m_ptr, "MaterialResourceData_t", "m_vectorAttributes"); std::vector<GMaterialParamVector_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetVectorAttributes(std::vector<GMaterialParamVector_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamVector_t>(m_ptr, "MaterialResourceData_t", "m_vectorAttributes", true, value);
}
std::vector<GMaterialParamTexture_t> GMaterialResourceData_t::GetTextureAttributes() const {
    CUtlVector<GMaterialParamTexture_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamTexture_t>*>(m_ptr, "MaterialResourceData_t", "m_textureAttributes"); std::vector<GMaterialParamTexture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetTextureAttributes(std::vector<GMaterialParamTexture_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamTexture_t>(m_ptr, "MaterialResourceData_t", "m_textureAttributes", true, value);
}
std::vector<GMaterialParamString_t> GMaterialResourceData_t::GetStringAttributes() const {
    CUtlVector<GMaterialParamString_t>* vec = GetSchemaValue<CUtlVector<GMaterialParamString_t>*>(m_ptr, "MaterialResourceData_t", "m_stringAttributes"); std::vector<GMaterialParamString_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetStringAttributes(std::vector<GMaterialParamString_t> value) {
    SetSchemaValueCUtlVector<GMaterialParamString_t>(m_ptr, "MaterialResourceData_t", "m_stringAttributes", true, value);
}
std::vector<CUtlString> GMaterialResourceData_t::GetRenderAttributesUsed() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "MaterialResourceData_t", "m_renderAttributesUsed"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GMaterialResourceData_t::SetRenderAttributesUsed(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "MaterialResourceData_t", "m_renderAttributesUsed", true, value);
}
std::string GMaterialResourceData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GMaterialResourceData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassMaterialResourceData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialResourceData_t>("MaterialResourceData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaterialName", &GMaterialResourceData_t::GetMaterialName, &GMaterialResourceData_t::SetMaterialName)
        .addProperty("ShaderName", &GMaterialResourceData_t::GetShaderName, &GMaterialResourceData_t::SetShaderName)
        .addProperty("IntParams", &GMaterialResourceData_t::GetIntParams, &GMaterialResourceData_t::SetIntParams)
        .addProperty("FloatParams", &GMaterialResourceData_t::GetFloatParams, &GMaterialResourceData_t::SetFloatParams)
        .addProperty("VectorParams", &GMaterialResourceData_t::GetVectorParams, &GMaterialResourceData_t::SetVectorParams)
        .addProperty("TextureParams", &GMaterialResourceData_t::GetTextureParams, &GMaterialResourceData_t::SetTextureParams)
        .addProperty("DynamicParams", &GMaterialResourceData_t::GetDynamicParams, &GMaterialResourceData_t::SetDynamicParams)
        .addProperty("DynamicTextureParams", &GMaterialResourceData_t::GetDynamicTextureParams, &GMaterialResourceData_t::SetDynamicTextureParams)
        .addProperty("IntAttributes", &GMaterialResourceData_t::GetIntAttributes, &GMaterialResourceData_t::SetIntAttributes)
        .addProperty("FloatAttributes", &GMaterialResourceData_t::GetFloatAttributes, &GMaterialResourceData_t::SetFloatAttributes)
        .addProperty("VectorAttributes", &GMaterialResourceData_t::GetVectorAttributes, &GMaterialResourceData_t::SetVectorAttributes)
        .addProperty("TextureAttributes", &GMaterialResourceData_t::GetTextureAttributes, &GMaterialResourceData_t::SetTextureAttributes)
        .addProperty("StringAttributes", &GMaterialResourceData_t::GetStringAttributes, &GMaterialResourceData_t::SetStringAttributes)
        .addProperty("RenderAttributesUsed", &GMaterialResourceData_t::GetRenderAttributesUsed, &GMaterialResourceData_t::SetRenderAttributesUsed)
        .addFunction("ToPtr", &GMaterialResourceData_t::ToPtr)
        .addFunction("IsValid", &GMaterialResourceData_t::IsValid)
        .endClass();
}