class GCChoiceUpdateNode;

#ifndef _gccchoiceupdatenode_h
#define _gccchoiceupdatenode_h

#include "../../../scripting.h"

#include "../types/GChoiceMethod.h"
#include "../types/GChoiceChangeMethod.h"
#include "../types/GChoiceBlendMethod.h"
#include "GCAnimUpdateNodeRef.h"

class GCChoiceUpdateNode
{
private:
    void *m_ptr;

public:
    GCChoiceUpdateNode() {}
    GCChoiceUpdateNode(void *ptr) : m_ptr(ptr) {}

    std::vector<GCAnimUpdateNodeRef> GetChildren() const { CUtlVector<GCAnimUpdateNodeRef>* vec = GetSchemaValue<CUtlVector<GCAnimUpdateNodeRef>*>(m_ptr, "CChoiceUpdateNode", "m_children"); std::vector<GCAnimUpdateNodeRef> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChildren(std::vector<GCAnimUpdateNodeRef> value) { SetSchemaValueCUtlVector<GCAnimUpdateNodeRef>(m_ptr, "CChoiceUpdateNode", "m_children", false, value); }
    std::vector<float32> GetWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CChoiceUpdateNode", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CChoiceUpdateNode", "m_weights", false, value); }
    std::vector<float32> GetBlendTimes() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CChoiceUpdateNode", "m_blendTimes"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBlendTimes(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CChoiceUpdateNode", "m_blendTimes", false, value); }
    ChoiceMethod GetChoiceMethod() const { return GetSchemaValue<ChoiceMethod>(m_ptr, "CChoiceUpdateNode", "m_choiceMethod"); }
    void SetChoiceMethod(ChoiceMethod value) { SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_choiceMethod", false, value); }
    ChoiceChangeMethod GetChoiceChangeMethod() const { return GetSchemaValue<ChoiceChangeMethod>(m_ptr, "CChoiceUpdateNode", "m_choiceChangeMethod"); }
    void SetChoiceChangeMethod(ChoiceChangeMethod value) { SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_choiceChangeMethod", false, value); }
    ChoiceBlendMethod GetBlendMethod() const { return GetSchemaValue<ChoiceBlendMethod>(m_ptr, "CChoiceUpdateNode", "m_blendMethod"); }
    void SetBlendMethod(ChoiceBlendMethod value) { SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_blendMethod", false, value); }
    float GetBlendTime() const { return GetSchemaValue<float>(m_ptr, "CChoiceUpdateNode", "m_blendTime"); }
    void SetBlendTime(float value) { SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_blendTime", false, value); }
    bool GetCrossFade() const { return GetSchemaValue<bool>(m_ptr, "CChoiceUpdateNode", "m_bCrossFade"); }
    void SetCrossFade(bool value) { SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_bCrossFade", false, value); }
    bool GetResetChosen() const { return GetSchemaValue<bool>(m_ptr, "CChoiceUpdateNode", "m_bResetChosen"); }
    void SetResetChosen(bool value) { SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_bResetChosen", false, value); }
    bool GetDontResetSameSelection() const { return GetSchemaValue<bool>(m_ptr, "CChoiceUpdateNode", "m_bDontResetSameSelection"); }
    void SetDontResetSameSelection(bool value) { SetSchemaValue(m_ptr, "CChoiceUpdateNode", "m_bDontResetSameSelection", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif