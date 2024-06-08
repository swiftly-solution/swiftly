class GSequenceWeightedList_t;

#ifndef _gcsequenceweightedlist_t_h
#define _gcsequenceweightedlist_t_h

#include "../../../scripting.h"




class GSequenceWeightedList_t
{
private:
    void *m_ptr;

public:
    GSequenceWeightedList_t() {}
    GSequenceWeightedList_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetSequence() const { return GetSchemaValue<int32_t>(m_ptr, "SequenceWeightedList_t", "m_nSequence"); }
    void SetSequence(int32_t value) { SetSchemaValue(m_ptr, "SequenceWeightedList_t", "m_nSequence", true, value); }
    float GetRelativeWeight() const { return GetSchemaValue<float>(m_ptr, "SequenceWeightedList_t", "m_flRelativeWeight"); }
    void SetRelativeWeight(float value) { SetSchemaValue(m_ptr, "SequenceWeightedList_t", "m_flRelativeWeight", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif