class GC_INIT_RandomSequence;

#ifndef _gcc_init_randomsequence_h
#define _gcc_init_randomsequence_h

#include "../../../scripting.h"


#include "GSequenceWeightedList_t.h"

class GC_INIT_RandomSequence
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomSequence() {}
    GC_INIT_RandomSequence(void *ptr) : m_ptr(ptr) {}

    int32_t GetSequenceMin() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomSequence", "m_nSequenceMin"); }
    void SetSequenceMin(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomSequence", "m_nSequenceMin", false, value); }
    int32_t GetSequenceMax() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomSequence", "m_nSequenceMax"); }
    void SetSequenceMax(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomSequence", "m_nSequenceMax", false, value); }
    bool GetShuffle() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RandomSequence", "m_bShuffle"); }
    void SetShuffle(bool value) { SetSchemaValue(m_ptr, "C_INIT_RandomSequence", "m_bShuffle", false, value); }
    bool GetLinear() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_RandomSequence", "m_bLinear"); }
    void SetLinear(bool value) { SetSchemaValue(m_ptr, "C_INIT_RandomSequence", "m_bLinear", false, value); }
    std::vector<GSequenceWeightedList_t> GetWeightedList() const { CUtlVector<GSequenceWeightedList_t>* vec = GetSchemaValue<CUtlVector<GSequenceWeightedList_t>*>(m_ptr, "C_INIT_RandomSequence", "m_WeightedList"); std::vector<GSequenceWeightedList_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeightedList(std::vector<GSequenceWeightedList_t> value) { SetSchemaValueCUtlVector<GSequenceWeightedList_t>(m_ptr, "C_INIT_RandomSequence", "m_WeightedList", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif