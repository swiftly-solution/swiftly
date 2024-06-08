class GFootStepTrigger;

#ifndef _gcfootsteptrigger_h
#define _gcfootsteptrigger_h

#include "../../../scripting.h"

#include "../types/GStepPhase.h"


class GFootStepTrigger
{
private:
    void *m_ptr;

public:
    GFootStepTrigger() {}
    GFootStepTrigger(void *ptr) : m_ptr(ptr) {}

    std::vector<int32> GetTags() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "FootStepTrigger", "m_tags"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTags(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "FootStepTrigger", "m_tags", false, value); }
    int32_t GetFootIndex() const { return GetSchemaValue<int32_t>(m_ptr, "FootStepTrigger", "m_nFootIndex"); }
    void SetFootIndex(int32_t value) { SetSchemaValue(m_ptr, "FootStepTrigger", "m_nFootIndex", false, value); }
    StepPhase GetTriggerPhase() const { return GetSchemaValue<StepPhase>(m_ptr, "FootStepTrigger", "m_triggerPhase"); }
    void SetTriggerPhase(StepPhase value) { SetSchemaValue(m_ptr, "FootStepTrigger", "m_triggerPhase", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif