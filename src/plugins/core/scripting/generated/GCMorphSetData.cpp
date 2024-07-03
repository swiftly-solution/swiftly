#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMorphSetData::GCMorphSetData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMorphSetData::GCMorphSetData(void *ptr) {
    m_ptr = ptr;
}
int32_t GCMorphSetData::GetWidth() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMorphSetData", "m_nWidth");
}
void GCMorphSetData::SetWidth(int32_t value) {
    SetSchemaValue(m_ptr, "CMorphSetData", "m_nWidth", false, value);
}
int32_t GCMorphSetData::GetHeight() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMorphSetData", "m_nHeight");
}
void GCMorphSetData::SetHeight(int32_t value) {
    SetSchemaValue(m_ptr, "CMorphSetData", "m_nHeight", false, value);
}
std::vector<MorphBundleType_t> GCMorphSetData::GetBundleTypes() const {
    CUtlVector<MorphBundleType_t>* vec = GetSchemaValue<CUtlVector<MorphBundleType_t>*>(m_ptr, "CMorphSetData", "m_bundleTypes"); std::vector<MorphBundleType_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphSetData::SetBundleTypes(std::vector<MorphBundleType_t> value) {
    SetSchemaValueCUtlVector<MorphBundleType_t>(m_ptr, "CMorphSetData", "m_bundleTypes", false, value);
}
std::vector<GCMorphData> GCMorphSetData::GetMorphDatas() const {
    CUtlVector<GCMorphData>* vec = GetSchemaValue<CUtlVector<GCMorphData>*>(m_ptr, "CMorphSetData", "m_morphDatas"); std::vector<GCMorphData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphSetData::SetMorphDatas(std::vector<GCMorphData> value) {
    SetSchemaValueCUtlVector<GCMorphData>(m_ptr, "CMorphSetData", "m_morphDatas", false, value);
}
std::vector<GCFlexDesc> GCMorphSetData::GetFlexDesc() const {
    CUtlVector<GCFlexDesc>* vec = GetSchemaValue<CUtlVector<GCFlexDesc>*>(m_ptr, "CMorphSetData", "m_FlexDesc"); std::vector<GCFlexDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphSetData::SetFlexDesc(std::vector<GCFlexDesc> value) {
    SetSchemaValueCUtlVector<GCFlexDesc>(m_ptr, "CMorphSetData", "m_FlexDesc", false, value);
}
std::vector<GCFlexController> GCMorphSetData::GetFlexControllers() const {
    CUtlVector<GCFlexController>* vec = GetSchemaValue<CUtlVector<GCFlexController>*>(m_ptr, "CMorphSetData", "m_FlexControllers"); std::vector<GCFlexController> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphSetData::SetFlexControllers(std::vector<GCFlexController> value) {
    SetSchemaValueCUtlVector<GCFlexController>(m_ptr, "CMorphSetData", "m_FlexControllers", false, value);
}
std::vector<GCFlexRule> GCMorphSetData::GetFlexRules() const {
    CUtlVector<GCFlexRule>* vec = GetSchemaValue<CUtlVector<GCFlexRule>*>(m_ptr, "CMorphSetData", "m_FlexRules"); std::vector<GCFlexRule> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphSetData::SetFlexRules(std::vector<GCFlexRule> value) {
    SetSchemaValueCUtlVector<GCFlexRule>(m_ptr, "CMorphSetData", "m_FlexRules", false, value);
}
std::string GCMorphSetData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMorphSetData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMorphSetData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphSetData>("CMorphSetData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Width", &GCMorphSetData::GetWidth, &GCMorphSetData::SetWidth)
        .addProperty("Height", &GCMorphSetData::GetHeight, &GCMorphSetData::SetHeight)
        .addProperty("BundleTypes", &GCMorphSetData::GetBundleTypes, &GCMorphSetData::SetBundleTypes)
        .addProperty("MorphDatas", &GCMorphSetData::GetMorphDatas, &GCMorphSetData::SetMorphDatas)
        .addProperty("FlexDesc", &GCMorphSetData::GetFlexDesc, &GCMorphSetData::SetFlexDesc)
        .addProperty("FlexControllers", &GCMorphSetData::GetFlexControllers, &GCMorphSetData::SetFlexControllers)
        .addProperty("FlexRules", &GCMorphSetData::GetFlexRules, &GCMorphSetData::SetFlexRules)
        .addFunction("ToPtr", &GCMorphSetData::ToPtr)
        .addFunction("IsValid", &GCMorphSetData::IsValid)
        .endClass();
}