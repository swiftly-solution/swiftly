class GCMorphSetData;

#ifndef _gccmorphsetdata_h
#define _gccmorphsetdata_h

#include "../../../scripting.h"

#include "../types/GMorphBundleType_t.h"
#include "GCMorphData.h"
#include "GCFlexDesc.h"
#include "GCFlexController.h"
#include "GCFlexRule.h"

class GCMorphSetData
{
private:
    void *m_ptr;

public:
    GCMorphSetData() {}
    GCMorphSetData(void *ptr) : m_ptr(ptr) {}

    int32_t GetWidth() const { return GetSchemaValue<int32_t>(m_ptr, "CMorphSetData", "m_nWidth"); }
    void SetWidth(int32_t value) { SetSchemaValue(m_ptr, "CMorphSetData", "m_nWidth", false, value); }
    int32_t GetHeight() const { return GetSchemaValue<int32_t>(m_ptr, "CMorphSetData", "m_nHeight"); }
    void SetHeight(int32_t value) { SetSchemaValue(m_ptr, "CMorphSetData", "m_nHeight", false, value); }
    std::vector<MorphBundleType_t> GetBundleTypes() const { CUtlVector<MorphBundleType_t>* vec = GetSchemaValue<CUtlVector<MorphBundleType_t>*>(m_ptr, "CMorphSetData", "m_bundleTypes"); std::vector<MorphBundleType_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBundleTypes(std::vector<MorphBundleType_t> value) { SetSchemaValueCUtlVector<MorphBundleType_t>(m_ptr, "CMorphSetData", "m_bundleTypes", false, value); }
    std::vector<GCMorphData> GetMorphDatas() const { CUtlVector<GCMorphData>* vec = GetSchemaValue<CUtlVector<GCMorphData>*>(m_ptr, "CMorphSetData", "m_morphDatas"); std::vector<GCMorphData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphDatas(std::vector<GCMorphData> value) { SetSchemaValueCUtlVector<GCMorphData>(m_ptr, "CMorphSetData", "m_morphDatas", false, value); }
    std::vector<GCFlexDesc> GetFlexDesc() const { CUtlVector<GCFlexDesc>* vec = GetSchemaValue<CUtlVector<GCFlexDesc>*>(m_ptr, "CMorphSetData", "m_FlexDesc"); std::vector<GCFlexDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlexDesc(std::vector<GCFlexDesc> value) { SetSchemaValueCUtlVector<GCFlexDesc>(m_ptr, "CMorphSetData", "m_FlexDesc", false, value); }
    std::vector<GCFlexController> GetFlexControllers() const { CUtlVector<GCFlexController>* vec = GetSchemaValue<CUtlVector<GCFlexController>*>(m_ptr, "CMorphSetData", "m_FlexControllers"); std::vector<GCFlexController> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlexControllers(std::vector<GCFlexController> value) { SetSchemaValueCUtlVector<GCFlexController>(m_ptr, "CMorphSetData", "m_FlexControllers", false, value); }
    std::vector<GCFlexRule> GetFlexRules() const { CUtlVector<GCFlexRule>* vec = GetSchemaValue<CUtlVector<GCFlexRule>*>(m_ptr, "CMorphSetData", "m_FlexRules"); std::vector<GCFlexRule> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFlexRules(std::vector<GCFlexRule> value) { SetSchemaValueCUtlVector<GCFlexRule>(m_ptr, "CMorphSetData", "m_FlexRules", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif